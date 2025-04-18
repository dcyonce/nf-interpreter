//
// Copyright (c) .NET Foundation and Contributors
// See LICENSE file in the project root for full license information.
//

#include <ch.h>
#include <hal.h>
#include <cmsis_os.h>
#include <LaunchCLR.h>
#include <string.h>
#include <targetPAL.h>

#include <sys_dev_spi_native_target.h>
#include <hal.h>

/////////////////////////////////////////////////////
// SPI PAL strucs declared in win_dev_spi_native.h //
/////////////////////////////////////////////////////
#if STM32_SPI_USE_SPI1
NF_PAL_SPI SPI1_PAL;
#endif
#if STM32_SPI_USE_SPI2
NF_PAL_SPI SPI2_PAL;
#endif
#if STM32_SPI_USE_SPI3
NF_PAL_SPI SPI3_PAL;
#endif
#if STM32_SPI_USE_SPI4
NF_PAL_SPI SPI4_PAL;
#endif
#if STM32_SPI_USE_SPI5
NF_PAL_SPI SPI5_PAL;
#endif
#if STM32_SPI_USE_SPI6
NF_PAL_SPI SPI6_PAL;
#endif

// Tidy up after completing tranfer
static void CompleteTranfer(NF_PAL_SPI *palSpi)
{
    // just to satisfy the driver ceremony, no actual implementation for STM32
    spiUnselect(palSpi->Driver);

    // Release the bus
    spiReleaseBus(palSpi->Driver);

    // event occurred
    if (palSpi->ReadSize > 0)
    {
        // because this was a Read transaction, need to copy from DMA buffer to managed buffer
        int ReadSize = palSpi->ReadSize;

        // Adjust read size for data width of 16bits
        if (palSpi->BufferIs16bits)
            ReadSize *= 2;

        // invalidate cache over read buffer to ensure that content from DMA is read
        // (only required for Cortex-M7)
        // get the pointer to the read buffer as UINT16 because it's really an UINT16 (2 bytes)
        cacheBufferInvalidate(palSpi->ReadBuffer, (palSpi->ReadSize * 2));
    }
}

// Callback used when a async opertion completes
static void SpiCallback(SPIDriver *spip)
{
    (void)spip;

    NATIVE_INTERRUPT_START

    NF_PAL_SPI *palSpi = NULL;

    // Find the NF_PAL_SPI * for driver
#if STM32_SPI_USE_SPI1
    if (spip == &SPID1)
    {
        palSpi = &SPI1_PAL;
    }
#endif
#if STM32_SPI_USE_SPI2
    if (spip == &SPID2)
    {
        palSpi = &SPI2_PAL;
    }
#endif
#if STM32_SPI_USE_SPI3
    if (spip == &SPID3)
    {
        palSpi = &SPI3_PAL;
    }
#endif
#if STM32_SPI_USE_SPI4
    if (spip == &SPID4)
    {
        palSpi = &SPI4_PAL;
    }
#endif
#if STM32_SPI_USE_SPI5
    if (spip == &SPID5)
    {
        palSpi = &SPI5_PAL;
    }
#endif
#if STM32_SPI_USE_SPI6
    if (spip == &SPID6)
    {
        palSpi = &SPI6_PAL;
    }
#endif

    // check if there is any Rx operation due
    if (palSpi->SequentialTxRx)
    {
        // yes there is!
        // clear flag and...
        palSpi->SequentialTxRx = false;

        // ... start it
        if (palSpi->BusConfiguration == SpiBusConfiguration_HalfDuplex)
        {
            // half duplex operation, clear output enable bit
            palSpi->Driver->spi->CR1 &= ~SPI_CR1_BIDIOE;
        }
        spiStartReceive(palSpi->Driver, palSpi->ReadSize, palSpi->ReadBuffer);
    }
    else
    {
        // all done here!

        // Tidy up, release etc
        CompleteTranfer(palSpi);

        // if CS is to be controlled by the driver, set the GPIO
        if (palSpi->ChipSelect >= 0)
        {
            // de-assert pin based on CS active level
            CPU_GPIO_TogglePinState(palSpi->ChipSelect);
        }

        // fire callback for SPI transaction complete
        // only if callback set
        if (palSpi->Callback)
        {
            palSpi->Callback(palSpi->BusIndex);
        }
    }

    NATIVE_INTERRUPT_END
};

// Computes the SPI peripheral baud rate according to the requested frequency
uint16_t ComputeBaudRate(SPI_DEVICE_CONFIGURATION &config, int32_t &actualFrequency)
{
    uint16_t divider = 0;
    int32_t maxSpiFrequency;
    int32_t requestedFrequency = config.Clock_RateHz;
    // bus index is 0 based, here it's 1 based
    int busIndex = config.Spi_Bus + 1;

#if defined(STM32L0XX)

    // SP1 is feed by APB2 (STM32_PCLK2)
    actualFrequency = STM32_PCLK2;

    // SPI2 is feed by APB1 (STM32_PCLK1)
    if (busIndex == 2)
    {
        actualFrequency = STM32_PCLK1;
    }

    // from datasheet
    maxSpiFrequency = 12000000;

#elif defined(STM32F0XX)

    (void)busIndex;

    // STM32F0 SPI is always feed by APB1
    actualFrequency = STM32_PCLK1;

    // from datasheet
    maxSpiFrequency = 18000000;

#elif defined(STM32F4XX) || defined(STM32F7XX)

    // SP1, SPI4, SPI5 and SPI6 are feed by APB2 (STM32_PCLK2)
    actualFrequency = STM32_PCLK2;

    // SPI2 and SPI3 are feed by APB1 (STM32_PCLK1)
    if (busIndex == 2 || busIndex == 3)
    {
        actualFrequency = STM32_PCLK1;
    }

    // this is not really accurate because there are different max SPI clocks depending on which APB clock source if
    // feeding the SPI because ChibiOS doesn't offer that we have to go with minimum common denominator
    maxSpiFrequency = STM32_SPII2S_MAX;

// JAT: Added Definition for L4
#elif defined(STM32L4XX)

    // SP1 is feed by APB2 (STM32_PCLK2)
    actualFrequency = STM32_PCLK2;

    // SPI2 and SPI3 are feed by APB1 (STM32_PCLK1)
    if (busIndex == 2 || busIndex == 3)
    {
        actualFrequency = STM32_PCLK1;
    }

    // this is not really accurate because there are different max SPI clocks depending on which APB clock source if
    // feeding the SPI because ChibiOS doesn't offer that we have to go with minimum common denominator
    maxSpiFrequency = 20000000U;

#elif defined(STM32H7XX)

    // SP1, SPI4, SPI5 and SPI6 are feed by APB2 (STM32_PCLK2)
    actualFrequency = STM32_PCLK2;
    maxSpiFrequency = STM32_SPI456_MAX;

    // SPI1, SPI2 and SPI3 are feed by APB1 (STM32_PCLK1)
    if (busIndex == 2 || busIndex == 3)
    {
        actualFrequency = STM32_PCLK1;
        maxSpiFrequency = STM32_SPI123_MAX;
    }

#else

#error "Error setting max SPI frequency. Check if the target series is defined."

#endif

    // when requested frequency is 0, means that the developer hasn't set ClockFrequency in SpiConnectionSettings
    // default to the max possible SPI frequency
    if (requestedFrequency == 0)
    {
        requestedFrequency = maxSpiFrequency;
    }

    for (; divider < 7; divider++)
    {
        actualFrequency = actualFrequency / 2;

        if (actualFrequency <= requestedFrequency)
        {
            // best match for the requested frequency
            // just check if it's below the max SPI frequency
            if (actualFrequency <= maxSpiFrequency)
            {
                // we are good with this value
                break;
            }
        }
    }

    // the baud rate bits are in the position B5:3 so need to left shit the divider value
    return divider << 3;
}

// Return the NF_PAL structure for busIndex
// Return NULL is invalid bus
NF_PAL_SPI *GetNfPalfromBusIndex(uint8_t busIndex)
{
    NF_PAL_SPI *palSpi = NULL;

    // get the PAL struct for the SPI bus
    // bus index is 0 based, here it's 1 based
    switch (busIndex + 1)
    {

#if STM32_SPI_USE_SPI1
        case 1:
            palSpi = &SPI1_PAL;
            break;
#endif

#if STM32_SPI_USE_SPI2
        case 2:
            palSpi = &SPI2_PAL;
            break;
#endif

#if STM32_SPI_USE_SPI3
        case 3:
            palSpi = &SPI3_PAL;
            break;
#endif

#if STM32_SPI_USE_SPI4
        case 4:
            palSpi = &SPI4_PAL;
            break;
#endif

#if STM32_SPI_USE_SPI5
        case 5:
            palSpi = &SPI5_PAL;
            break;
#endif

#if STM32_SPI_USE_SPI6
        case 6:
            palSpi = &SPI6_PAL;
            break;
#endif

        default:
            // the requested SPI bus is not valid
            break;
    }

    return palSpi;
}

// Give a complete low-level SPI configuration from passed SPI_DEVICE_CONFIGURATION
void GetSPIConfig(SPI_DEVICE_CONFIGURATION &config, SPI_WRITE_READ_SETTINGS &wrc, SPIConfig *llConfig)
{
    int32_t actualFrequency;

    // clear values
    llConfig->cr1 = 0;
    llConfig->cr2 = 0;

    // SPI mode
    switch (config.Spi_Mode)
    {
        case SpiMode_Mode1:
            llConfig->cr1 |= SPI_CR1_CPHA;
            break;

        case SpiMode_Mode2:
            llConfig->cr1 |= SPI_CR1_CPOL;
            break;

        case SpiMode_Mode3:
            llConfig->cr1 |= SPI_CR1_CPHA | SPI_CR1_CPOL;
            break;

        default: // Default to Mode0 if invalid mode specified
            break;
    }

    // compute baud rate of SPI peripheral according to the requested frequency
    llConfig->cr1 |= ComputeBaudRate(config, actualFrequency);

    // set data transfer length according passed setting
    if (wrc.Bits16ReadWrite)
    {
        // Set data transfer length to 16 bits
#ifdef STM32F4XX
        llConfig->cr1 |= SPI_CR1_DFF;
#endif
#ifdef STM32F7XX
        llConfig->cr2 = SPI_CR2_DS_3 | SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0;
#endif
        // Sets the order of bytes transmission : MSB first or LSB first
        int bitOrder = config.DataOrder16;
        if (bitOrder == DataBitOrder_LSB)
        {
            llConfig->cr1 |= SPI_CR1_LSBFIRST;
        }
    }
    else
    {
        // set transfer length to 8bits
#ifdef STM32F4XX
        llConfig->cr1 &= ~SPI_CR1_DFF;
#endif
#ifdef STM32F7XX
        llConfig->cr2 |= SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0;
#endif
#ifdef STM32L4XX
        llConfig->cr2 |= SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0;
#endif
    }

    // set bus configuration
    // only required for half duplex mode
    if (config.BusConfiguration == SpiBusConfiguration_HalfDuplex)
    {
#ifdef STM32F4XX
        llConfig->cr1 |= SPI_CR1_BIDIMODE;
#endif
#ifdef STM32F7XX
        llConfig->cr2 |= SPI_CR1_BIDIMODE;
#endif
#ifdef STM324LXX
        llConfig->cr2 |= SPI_CR1_BIDIMODE;
#endif
    }

    // Create the low level configuration
    llConfig->data_cb = SpiCallback;
}

// Performs a read/write operation on 8-bit word data.
//
// Parameters
//  deviceHandle
//      Device handle from add_device
//  sdev
//		reference to SPI_DEVICE_CONFIGURATION
//  wrc
//		reference to SPI_WRITE_READ_SETTINGS
//  writeData
//      A pointer to the buffer from which the data is to be written to the device.
//  writeSize
//      The number of elements(8 or 16) to be written.
//  readData
//      A pointer to the buffer into which the data is to be read from the device.
//  readSize
//      The number of elements(8 or 16) to be read.
//
// return S_OK=Successful, Async started=CLR_BUSY, Error=CLR_E_OUT_OF_MEMORY, CLR_E_INVALID_PARAMETER, CLR_E_FAIL
//
HRESULT CPU_SPI_nWrite_nRead(
    uint32_t deviceHandle,
    SPI_DEVICE_CONFIGURATION &sdev,
    SPI_WRITE_READ_SETTINGS &wrc,
    uint8_t *writeBuffer,
    int32_t writeSize,
    uint8_t *readBuffer,
    int32_t readSize)
{
    NANOCLR_HEADER();
    {
        bool busConfigIsHalfDuplex;
        NF_PAL_SPI *palSpi = (NF_PAL_SPI *)deviceHandle;
        bool sync = (wrc.callback == 0); // If callback then use aync operation

        // Save width of transfer
        palSpi->BufferIs16bits = wrc.Bits16ReadWrite;

        // Callback sync / async
        palSpi->Callback = wrc.callback;

        if (writeBuffer != NULL)
        {
            palSpi->WriteSize = writeSize;
        }

        // DCY: nanoFramework BUG found 02/04/2025
        // The readSize must be RESET, otherwise it will take whatever the last call had !
        //if (readBuffer != NULL)
        //{
            palSpi->ReadSize = readSize;
        //}

        // === Setup the operation and init buffers ===
        palSpi->BusIndex = sdev.Spi_Bus;

        // get the LL SPI configuration, depending on passed parameters and buffer element size
        GetSPIConfig(sdev, wrc, &palSpi->Configuration);

        // set bus config flag
        busConfigIsHalfDuplex = palSpi->BusConfiguration == SpiBusConfiguration_HalfDuplex;

        // Clear callback if sync
        if (sync)
        {
            palSpi->Configuration.data_cb = NULL;
        }

        if (writeBuffer != NULL)
        {
            // set the pointer to the write buffer as BYTE
            palSpi->WriteBuffer = (uint8_t *)writeBuffer;

            // set DMA write buffer
            if (palSpi->BufferIs16bits)
            {
                // flush DMA buffer to ensure cache coherency
                // (only required for Cortex-M7)
                cacheBufferFlush(palSpi->WriteBuffer, (palSpi->WriteSize * 2));
            }
            else
            {
                // flush DMA buffer to ensure cache coherency
                // (only required for Cortex-M7)
                cacheBufferFlush(palSpi->WriteBuffer, palSpi->WriteSize);
            }
        }

        if (readBuffer != NULL)
        {
            // set DMA read buffer
            if (palSpi->ReadSize > 0)
            {
                palSpi->ReadBuffer = (uint8_t *)readBuffer;
            }
        }

        // because the bus access is shared, acquire and select the appropriate bus
        spiAcquireBus(palSpi->Driver);
        spiStart(palSpi->Driver, &palSpi->Configuration);

        // just to satisfy the driver ceremony, no actual implementation for STM32
        spiSelect(palSpi->Driver);

        palSpi->ChipSelect = wrc.DeviceChipSelect;
        // if CS is to be controlled by the driver, set the GPIO
        if (wrc.DeviceChipSelect >= 0)
        {
            // assert pin based on CS active level
            CPU_GPIO_SetPinState(wrc.DeviceChipSelect, (GpioPinValue)wrc.ChipSelectActiveState);
        }

        if (sync)
        {
            // Sync operation
            // perform SPI operation using driver's SYNC API
            
            // Write AND Read from the SPI port ?
            if (palSpi->WriteSize != 0 && palSpi->ReadSize != 0)
            {
                // Transmit+Receive
                if (wrc.fullDuplex)
                {
                    // Full duplex
                    // Uses the largest buffer size as transfer size
                    spiExchange(
                        palSpi->Driver,
                        palSpi->WriteSize > palSpi->ReadSize ? palSpi->WriteSize : palSpi->ReadSize,
                        palSpi->WriteBuffer,
                        palSpi->ReadBuffer);
                }
                else
                {
                    // send operation
                    if (busConfigIsHalfDuplex)
                    {
                        // half duplex operation, set output enable
                        palSpi->Driver->spi->CR1 |= SPI_CR1_BIDIOE;
                    }

                    spiSend(palSpi->Driver, palSpi->WriteSize, palSpi->WriteBuffer);

                    // receive operation
                    if (busConfigIsHalfDuplex)
                    {
                        // half duplex operation, set output enable
                        palSpi->Driver->spi->CR1 &= ~SPI_CR1_BIDIOE;
                    }

                    spiReceive(palSpi->Driver, palSpi->ReadSize, palSpi->ReadBuffer);
                }
            }
            else
            {
                // Transmit only or Receive only
                if (palSpi->ReadSize != 0)
                {
                    // receive
                    if (busConfigIsHalfDuplex)
                    {
                        // half duplex operation, set output enable
                        palSpi->Driver->spi->CR1 &= ~SPI_CR1_BIDIOE;
                    }

                    spiReceive(palSpi->Driver, palSpi->ReadSize, palSpi->ReadBuffer);
                }
                else
                {
                    // send
                    if (busConfigIsHalfDuplex)
                    {
                        // half duplex operation, set output enable
                        palSpi->Driver->spi->CR1 |= SPI_CR1_BIDIOE;
                    }

                    spiSend(palSpi->Driver, palSpi->WriteSize, palSpi->WriteBuffer);
                }
            }

            // Release bus & cacheBufferInvalidate etc
            CompleteTranfer(palSpi);

            // if CS is to be controlled by the driver, set the GPIO
            if (wrc.DeviceChipSelect >= 0)
            {
                // de-assert pin based on CS active level
                CPU_GPIO_SetPinState(wrc.DeviceChipSelect, (GpioPinValue)!wrc.ChipSelectActiveState);
            }
        }
        else
        {
            // Start an Asyncronous SPI transfer
            // perform SPI operation using driver's ASYNC API
            // Completed on calling Spi Callback

            // if CS is to be controlled by the driver, set the GPIO
            if (wrc.DeviceChipSelect >= 0)
            {
                // assert pin based on CS active level
                CPU_GPIO_SetPinState(wrc.DeviceChipSelect, (GpioPinValue)wrc.ChipSelectActiveState);
            }

            // this is a Async operation
            // perform SPI operation using driver's ASYNC API
            if (palSpi->WriteSize != 0 && palSpi->ReadSize != 0)
            {
                // Transmit+Receive
                if (wrc.fullDuplex)
                {
                    // Full duplex
                    // single operation, clear flag
                    palSpi->SequentialTxRx = false;

                    // Uses the largest buffer size as transfer size
                    spiStartExchange(
                        palSpi->Driver,
                        palSpi->WriteSize > palSpi->ReadSize ? palSpi->WriteSize : palSpi->ReadSize,
                        palSpi->WriteBuffer,
                        palSpi->ReadBuffer);
                }
                else
                {
                    // flag that an Rx is required after the Tx operation completes
                    palSpi->SequentialTxRx = true;

                    // start send operation
                    if (busConfigIsHalfDuplex)
                    {
                        // half duplex operation, set output enable
                        palSpi->Driver->spi->CR1 |= SPI_CR1_BIDIOE;
                    }

                    spiStartSend(palSpi->Driver, palSpi->WriteSize, palSpi->WriteBuffer);
                    // receive operation will be started in the callback after the above completes
                }
            }
            else
            {
                // Transmit only or Receive only
                if (palSpi->ReadSize != 0)
                {
                    // single operation, clear flag
                    palSpi->SequentialTxRx = false;

                    // start receive
                    spiStartReceive(palSpi->Driver, palSpi->ReadSize, palSpi->ReadBuffer);
                }
                else
                {
                    // single operation, clear flag
                    palSpi->SequentialTxRx = false;

                    // start send
                    spiStartSend(palSpi->Driver, palSpi->WriteSize, palSpi->WriteBuffer);
                }
            }

            // Inform caller async operation started
            NANOCLR_SET_AND_LEAVE(CLR_E_BUSY);
        }
    }

    NANOCLR_NOCLEANUP();
}

SPI_OP_STATUS CPU_SPI_OP_Status(uint8_t busIndex, uint32_t deviceHandle)
{
    (void)busIndex;

    NF_PAL_SPI *palSpi = (NF_PAL_SPI *)deviceHandle;
    SPI_OP_STATUS os;

    switch (palSpi->Driver->state)
    {
        default:
        case SPI_UNINIT:
        case SPI_STOP:
        case SPI_READY:
            os = SPI_OP_READY;
            break;

        case SPI_ACTIVE:
            os = SPI_OP_RUNNING;
            break;

        case SPI_COMPLETE:
            os = SPI_OP_COMPLETE;
            break;
    }
    return os;
}

bool CPU_SPI_Initialize(uint8_t busIndex, const SPI_DEVICE_CONFIGURATION &spiDeviceConfig)
{
    // init the PAL struct for this SPI bus and assign the respective driver
    // all this occurs if not already done
    // why do we need this? because several SPIDevice objects can be created associated to the same bus

    // bus index is 0 based, here it's 1 based
    switch (busIndex + 1)
    {
#if STM32_SPI_USE_SPI1
        case 1:
            if (SPI1_PAL.Driver == NULL)
            {
                ConfigPins_SPI1(spiDeviceConfig);
                SPI1_PAL.Driver = &SPID1;
                SPI1_PAL.ChipSelect = spiDeviceConfig.DeviceChipSelect;
            }
            break;
#endif
#if STM32_SPI_USE_SPI2
        case 2:
            if (SPI2_PAL.Driver == NULL)
            {
                ConfigPins_SPI2(spiDeviceConfig);
                SPI2_PAL.Driver = &SPID2;
                SPI2_PAL.ChipSelect = spiDeviceConfig.DeviceChipSelect;
            }
            break;
#endif
#if STM32_SPI_USE_SPI3
        case 3:
            if (SPI3_PAL.Driver == NULL)
            {
                ConfigPins_SPI3(spiDeviceConfig);
                SPI3_PAL.Driver = &SPID3;
                SPI3_PAL.ChipSelect = spiDeviceConfig.DeviceChipSelect;
            }
            break;
#endif
#if STM32_SPI_USE_SPI4
        case 4:
            if (SPI4_PAL.Driver == NULL)
            {
                ConfigPins_SPI4(spiDeviceConfig);
                SPI4_PAL.Driver = &SPID4;
                SPI4_PAL.ChipSelect = spiDeviceConfig.DeviceChipSelect;
            }
            break;
#endif
#if STM32_SPI_USE_SPI5
        case 5:
            if (SPI5_PAL.Driver == NULL)
            {
                ConfigPins_SPI5(spiDeviceConfig);
                SPI5_PAL.Driver = &SPID5;
                SPI5_PAL.ChipSelect = spiDeviceConfig.DeviceChipSelect;
            }
            break;
#endif
#if STM32_SPI_USE_SPI6
        case 6:
            if (SPI6_PAL.Driver == NULL)
            {
                ConfigPins_SPI6(spiDeviceConfig);
                SPI6_PAL.Driver = &SPID6;
                SPI6_PAL.ChipSelect = spiDeviceConfig.DeviceChipSelect;
            }
            break;
#endif
        default:
            // this SPI bus is not valid
            return false;
    }

    return true;
}

bool CPU_SPI_Uninitialize(uint8_t busIndex)
{
    // get the PAL struct for the SPI bus
    // bus index is 0 based, here it's 1 based
    switch (busIndex + 1)
    {
#if STM32_SPI_USE_SPI1
        case 1:
            spiStop(&SPID1);
            SPI1_PAL.Driver = NULL;
            spiReleaseBus(&SPID1);
            break;
#endif

#if STM32_SPI_USE_SPI2
        case 2:
            spiStop(&SPID2);
            SPI2_PAL.Driver = NULL;
            spiReleaseBus(&SPID2);
            break;
#endif

#if STM32_SPI_USE_SPI3
        case 3:
            spiStop(&SPID3);
            SPI3_PAL.Driver = NULL;
            spiReleaseBus(&SPID3);
            break;
#endif

#if STM32_SPI_USE_SPI4
        case 4:
            spiStop(&SPID4);
            SPI4_PAL.Driver = NULL;
            spiReleaseBus(&SPID4);
            break;
#endif

#if STM32_SPI_USE_SPI5
        case 5:
            spiStop(&SPID5);
            SPI5_PAL.Driver = NULL;
            spiReleaseBus(&SPID5);
            break;
#endif

#if STM32_SPI_USE_SPI6
        case 6:
            spiStop(&SPID6);
            SPI6_PAL.Driver = NULL;
            spiReleaseBus(&SPID6);
            break;
#endif

        default:
            // the requested SPI bus is not valid
            return false;
    }

    return true;
}

// return Map of available SPI ports
uint32_t CPU_SPI_PortsMap()
{
    uint32_t map = 0;

#if STM32_SPI_USE_SPI1
    map |= 0x01;
#endif
#if STM32_SPI_USE_SPI2
    map |= 0x02;
#endif
#if STM32_SPI_USE_SPI3
    map |= 0x04;
#endif
#if STM32_SPI_USE_SPI4
    map |= 0x08;
#endif
#if STM32_SPI_USE_SPI5
    map |= 0x10;
#endif
#if STM32_SPI_USE_SPI6
    map |= 0x20;
#endif
    return map;
}

// Add a device to SPi Bus (Optional)
// Returns a device handle.  Returns 0 if error
HRESULT CPU_SPI_Add_Device(const SPI_DEVICE_CONFIGURATION &spiDeviceConfig, uint32_t &handle)
{
    // check supported bus configuration: all valid except simplex
    if (spiDeviceConfig.BusConfiguration == SpiBusConfiguration_Simplex)
    {
        return CLR_E_NOT_SUPPORTED;
    }

    handle = (uint32_t)GetNfPalfromBusIndex(spiDeviceConfig.Spi_Bus);

    return S_OK;
}

// Return pins used for SPI bus
void CPU_SPI_GetPins(uint32_t busIndex, GPIO_PIN &clk, GPIO_PIN &miso, GPIO_PIN &mosi)
{
    (void)busIndex;

    clk = (GPIO_PIN)-1;
    miso = (GPIO_PIN)-1;
    mosi = (GPIO_PIN)-1;
}

// Minimum and Maximum clock frequency available based on bus and configured pins
HRESULT CPU_SPI_MinClockFrequency(uint32_t spiBus, int32_t *frequency)
{
    // bus index is 0 based, here it's 1 based
    if (spiBus >= NUM_SPI_BUSES)
    {
        return CLR_E_INVALID_PARAMETER;
    }

    // Max prescaler value = 256
    // SPI2 or SPI3 are on APB1, so divide max frequency by four.
    // bus index is 0 based, here it's 1 based
    *frequency = (spiBus + 1 == 2 or spiBus + 1 == 3) ? SystemCoreClock >>= 9 : SystemCoreClock >> 8;

    return S_OK;
}

HRESULT CPU_SPI_MaxClockFrequency(uint32_t spiBus, int32_t *frequency)
{
    // bus index is 0 based, here it's 1 based
    if (spiBus >= NUM_SPI_BUSES)
    {
        return CLR_E_INVALID_PARAMETER;
    }

    // According to STM : "At a minimum, the clock frequency should be twice the required communication frequency."
    // So maximum useable frequency is CoreClock / 2.
    // SPI2 or SPI3 are on APB1, so divide max frequency by four.
    // bus index is 0 based, here it's 1 based
    *frequency = (spiBus + 1 == 2 or spiBus + 1 == 3) ? SystemCoreClock >>= 2 : SystemCoreClock >> 1;

    return S_OK;
}

// Maximum number of SPI devices that can be opened on a bus
uint32_t CPU_SPI_ChipSelectLineCount(uint32_t busIndex)
{
    (void)busIndex;

    return MAX_SPI_DEVICES;
}
