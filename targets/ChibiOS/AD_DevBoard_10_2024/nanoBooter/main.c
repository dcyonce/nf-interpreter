//
// Copyright (c) .NET Foundation and Contributors
// See LICENSE file in the project root for full license information.
//

#include <ch.h>
#include <hal.h>
#include <hal_nf_community.h>
#include <cmsis_os.h>

#include <serialcfg.h>
#include <swo.h>
#include <targetHAL.h>
#include <WireProtocol_ReceiverThread.h>
#include <nanoPAL_BlockStorage.h>
#include <nanoHAL_ConfigurationManager.h>
//#include <nanoHAL_v2.h>
#include <LaunchCLR.h>
//#include <string.h>
#include <stdio.h>

int	snprintf (char *__restrict, size_t, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));


// // Simple hex-to-string function
// static void hex_to_str(uint8_t value, char *buf) {
//   const char hex[] = "0123456789ABCDEF";
//   buf[0] = hex[(value >> 4) & 0xF];
//   buf[1] = hex[value & 0xF];
//   buf[2] = '\0';
// }

// need to declare the Receiver thread here
osThreadDef(ReceiverThread, osPriorityHigh, 2048, "ReceiverThread");
// void DetermineWakeupSource();
// //uint32_t WakeupReasonStore;

// static void InitW25Q128JV(void) {
// // Configure OCTOSPI1 pins for W25Q128JVSIQ
// palSetPadMode(GPIOF, 10, PAL_MODE_ALTERNATE(3));    // PF10: CLK
// palSetPadMode(GPIOF, 9,  PAL_MODE_ALTERNATE(10));   // PF9: IO1
// palSetPadMode(GPIOF, 8,  PAL_MODE_ALTERNATE(10));   // PF8: IO0
// palSetPadMode(GPIOF, 7,  PAL_MODE_ALTERNATE(10));   // PF7: IO2
// palSetPadMode(GPIOF, 6,  PAL_MODE_ALTERNATE(10));   // PF6: IO3
// palSetPadMode(GPIOA, 4,  PAL_MODE_ALTERNATE(3));    // PA4: CS

//   // Define WSPI configuration for OCTOSPIv1
//   const WSPIConfig wspi_cfg = {
//     .dcr1 = STM32_DCR1_CSHT(1) | STM32_DCR1_DEVSIZE(23) | STM32_DCR1_MTYP(1), // 16 MB (2^24, FSIZE=23)
//     .dcr2 = STM32_DCR2_PRESCALER(35),                     // Prescaler: 2 (80 MHz / 2 = 40 MHz)
//     .dcr3 = 0,
//     .dcr4 = 0
// };

//   // Start WSPI driver
//   wspiStart(&WSPID1, &wspi_cfg);

//   // Enable Quad mode on W25Q128JV
//   wspi_command_t cmd = {
//       .cfg   = WSPI_CFG_CMD_MODE_ONE_LINE |
//                WSPI_CFG_ADDR_MODE_NONE |
//                WSPI_CFG_ALT_MODE_NONE |
//                WSPI_CFG_DATA_MODE_NONE,
//       .cmd   = 0x06,                       // Write Enable
//       .addr  = 0,
//       .alt   = 0,
//       .dummy = 0
//   };
//   wspiCommand(&WSPID1, &cmd);

//   uint8_t quad_enable_data[] = {0x00, 0x02}; // SR1=0x00, SR2=0x02 (QE=1)
//   cmd.cfg  = WSPI_CFG_CMD_MODE_ONE_LINE |
//              WSPI_CFG_ADDR_MODE_NONE |
//              WSPI_CFG_ALT_MODE_NONE |
//              WSPI_CFG_DATA_MODE_ONE_LINE;
//   cmd.cmd  = 0x01;                          // Write Status Register
//   cmd.dummy = 0;
//   wspiSend(&WSPID1, &cmd, sizeof(quad_enable_data), quad_enable_data);

//   // Wait for write completion
//   cmd.cfg  = WSPI_CFG_CMD_MODE_ONE_LINE |
//              WSPI_CFG_ADDR_MODE_NONE |
//              WSPI_CFG_ALT_MODE_NONE |
//              WSPI_CFG_DATA_MODE_ONE_LINE;
//   cmd.cmd  = 0x05;                          // Read Status Register 1
//   cmd.dummy = 0;
//   uint8_t status;
//   do {
//       wspiReceive(&WSPID1, &cmd, 1, &status);
//   } while (status & 0x01);                  // Busy bit

//   // cmd.cmd = 0x9F;
//   // uint8_t id[3];
//   // wspiReceive(&WSPID1, &cmd, 3, id); // Should return 0xEF, 0x40, 0x17

//   // JEDEC ID read
//   wspi_command_t cmd2 = {
//     .cfg   = WSPI_CFG_CMD_MODE_ONE_LINE |
//              WSPI_CFG_ADDR_MODE_NONE |
//              WSPI_CFG_ALT_MODE_NONE |
//              WSPI_CFG_DATA_MODE_ONE_LINE,
//     .cmd   = 0x9F,
//     .addr  = 0,
//     .alt   = 0,
//     .dummy = 0
// };
// uint8_t id[3] = {0};
// sdWrite(&SERIAL_DRIVER, (const uint8_t *)"Sending JEDEC cmd\r\n", 19);
// if (wspiReceive(&WSPID1, &cmd2, 3, id) == 0) {
//   char msg[64] = "JEDEC ID: 0x";
//   char hex_buf[3];
//   hex_to_str(id[0], hex_buf);
//   strcat(msg, hex_buf);
//   strcat(msg, " 0x");
//   hex_to_str(id[1], hex_buf);
//   strcat(msg, hex_buf);
//   strcat(msg, " 0x");
//   hex_to_str(id[2], hex_buf);
//   strcat(msg, hex_buf);
//   strcat(msg, "\r\n");
//   sdWrite(&SERIAL_DRIVER, (const uint8_t *)msg, strlen(msg));
// } else {
//     sdWrite(&SERIAL_DRIVER, (const uint8_t *)"JEDEC read failed\r\n", 19);
// }

// wspi_command_t cmd_status = {
//     .cmd = 0x05,
//     .cfg = WSPI_CFG_CMD_MODE_ONE_LINE | WSPI_CFG_DATA_MODE_ONE_LINE,
//     .addr = 0,
//     .dummy = 0
// };
// wspiReceive(&WSPID1, &cmd_status, 1, &status);
// char msg[64] = "Status Reg: 0x";
//   char hex_buf[3];
//   hex_to_str(status, hex_buf);
//   strcat(msg, hex_buf);
//   strcat(msg, "\r\n");
//   sdWrite(&SERIAL_DRIVER, (const uint8_t *)msg, strlen(msg));

//   // Configure memory-mapped mode (W25Q128JV Fast Read Quad I/O)
//   const wspi_command_t memmap_cmd = {
//       .cfg   = WSPI_CFG_CMD_MODE_ONE_LINE |
//                WSPI_CFG_ADDR_MODE_FOUR_LINES |
//                WSPI_CFG_ALT_MODE_FOUR_LINES |
//                WSPI_CFG_DATA_MODE_FOUR_LINES,
//       .cmd   = 0xEB,                           // Fast Read Quad I/O
//       .addr  = 0,                              // Starting address
//       .alt   = 0x00,                           // Mode bits
//       .dummy = 6                               // 6 dummy cycles for 80 MHz
//   };

//   // Switch to memory-mapped mode
//   wspiMapFlash(&WSPID1, &memmap_cmd, NULL);

// // Verify memory-mapped read
// volatile uint8_t *flash_base = (volatile uint8_t *)0x90000000;
// uint8_t test_read[3];
// test_read[0] = flash_base[0];
// test_read[1] = flash_base[1];
// test_read[2] = flash_base[2];
// char msg3[64] = "Flash mapped read: 0x";
//   char hex_buf3[3];
//   hex_to_str(test_read[0], hex_buf3);
//   strcat(msg3, hex_buf3);
//   strcat(msg3, ", 0x");
//   hex_to_str(test_read[1], hex_buf3);
//   strcat(msg3, hex_buf3);
//   strcat(msg3, ", 0x");
//   hex_to_str(test_read[2], hex_buf3);
//   strcat(msg3, hex_buf3);
//   strcat(msg3, "\r\n");
//   //chsnprintf(msg2, sizeof(msg2), "Flash mapped read: 0x%02X 0x%02X 0x%02X\r\n", test_read[0], test_read[1], test_read[2]);
// sdWrite(&SERIAL_DRIVER, (const uint8_t *)msg3, strlen(msg3));

// }

// static void InitIS66WVS4M8(void) { 
//   // Configure OCTOSPI2 pins for IS66WVS4M8ALL
//   palSetPadMode(GPIOF, 0,  PAL_MODE_ALTERNATE(5));  // PF0: IO0
//   palSetPadMode(GPIOF, 1,  PAL_MODE_ALTERNATE(5));  // PF1: IO1
//   palSetPadMode(GPIOF, 2,  PAL_MODE_ALTERNATE(5));  // PF2: IO2
//   palSetPadMode(GPIOF, 3,  PAL_MODE_ALTERNATE(5));  // PF3: IO3
//   palSetPadMode(GPIOF, 4,  PAL_MODE_ALTERNATE(5));  // PF4: CLK
//   palSetPadMode(GPIOG, 12, PAL_MODE_ALTERNATE(5));  // PG12: CS

//   // Define WSPI configuration for OCTOSPI2 (4 Mbit = 512 KB)
//   const WSPIConfig wspi_cfg = {
//     .dcr1 = STM32_DCR1_CSHT(1) | STM32_DCR1_DEVSIZE(21), // 4 MB (2^22, FSIZE=21)
//     .dcr2 = STM32_DCR2_PRESCALER(15),                     // Prescaler: 2 (80 MHz / 2 = 40 MHz)
//     .dcr3 = 0,
//     .dcr4 = 0
//   };
//   wspiStart(&WSPID2, &wspi_cfg);
//   osDelay(10);

//   // Enter QPI mode (IS66WVS4M8ALL command 0x35)
//   wspi_command_t cmd = {
//       .cfg   = WSPI_CFG_CMD_MODE_ONE_LINE |
//                WSPI_CFG_ADDR_MODE_NONE |
//                WSPI_CFG_ALT_MODE_NONE |
//                WSPI_CFG_DATA_MODE_NONE,
//       .cmd   = 0x35,                       // Enter QPI Mode
//       .addr  = 0,
//       .alt   = 0,
//       .dummy = 0
//   };
//   wspiCommand(&WSPID2, &cmd);

// //   // JEDEC ID read
// //   wspi_command_t cmd2 = {
// //     .cfg   = WSPI_CFG_CMD_MODE_ONE_LINE |
// //              WSPI_CFG_ADDR_MODE_NONE |
// //              WSPI_CFG_ALT_MODE_NONE |
// //              WSPI_CFG_DATA_MODE_ONE_LINE,
// //     .cmd   = 0x9F,
// //     .addr  = 0,
// //     .alt   = 0,
// //     .dummy = 0
// // };
// // uint8_t id[3] = {0};
// // sdWrite(&SERIAL_DRIVER, (const uint8_t *)"SRAM JEDEC cmd\r\n", 19);
// // if (wspiReceive(&WSPID1, &cmd2, 3, id) == 0) {
// //   char msg[64] = "SRAM JEDEC ID: 0x";
// //   char hex_buf[3];
// //   hex_to_str(id[0], hex_buf);
// //   strcat(msg, hex_buf);
// //   strcat(msg, " 0x");
// //   hex_to_str(id[1], hex_buf);
// //   strcat(msg, hex_buf);
// //   strcat(msg, " 0x");
// //   hex_to_str(id[2], hex_buf);
// //   strcat(msg, hex_buf);
// //   strcat(msg, "\r\n");
// //   sdWrite(&SERIAL_DRIVER, (const uint8_t *)msg, strlen(msg));
// // } else {
// //     sdWrite(&SERIAL_DRIVER, (const uint8_t *)"SRAM JEDEC read failed\r\n", 19);
// // }

//   // Configure memory-mapped mode (Fast Read Quad)
//   const wspi_command_t memmap_cmd = {
//       .cfg   = WSPI_CFG_CMD_MODE_FOUR_LINES | // QPI mode
//                WSPI_CFG_ADDR_MODE_FOUR_LINES |
//                WSPI_CFG_ALT_MODE_FOUR_LINES |
//                WSPI_CFG_DATA_MODE_FOUR_LINES,
//       .cmd   = 0xEB,                           // Fast Read Quad
//       .addr  = 0,
//       .alt   = 0x00,
//       .dummy = 10                              // 10 dummy cycles (adjust per clock)
//   };
//   wspiMapFlash(&WSPID2, &memmap_cmd, NULL);

//   // // Verify PSRAM write and read
//   // volatile uint32_t *psram_base = (volatile uint32_t *)0x70000000;
//   // uint32_t test_pattern = 0xA5A5A5A5;
//   // psram_base[0] = test_pattern;
//   // uint32_t read_back = psram_base[0];
//   // char msg[64];
//   // if (read_back == test_pattern) {
//   //   sdWrite(&SERIAL_DRIVER, (const uint8_t *)"PSRAM OK\r\n", 10);      
//   //   //chsnprintf(msg, sizeof(msg), "PSRAM test: Wrote 0x%08X, Read 0x%08X - OK\r\n", test_pattern, read_back);
//   // } else {
//   //   sdWrite(&SERIAL_DRIVER, (const uint8_t *)"PSRAM FAILED\r\n", 15);            
//   //   //chsnprintf(msg, sizeof(msg), "PSRAM test: Wrote 0x%08X, Read 0x%08X - FAILED\r\n", test_pattern, read_back);
//   // }
//   // sdWrite(&SERIAL_DRIVER, (const uint8_t *)msg, strlen(msg));
// }

// WSPI configuration for OctoSPI1 in Quad mode
// static const WSPIConfig wspi_cfg = {
//   .end_cb = NULL,
//   .dcr1 = STM32_DCR1_CSHT(1U) | STM32_DCR1_DEVSIZE(24U) | STM32_DCR1_MTYP(1U),  // 16 MB = 24-bit address
//   .dcr2 = STM32_DCR2_PRESCALER(35U),                                            // Prescaler: 2 (80 MHz / 2 = 40 MHz)
//   .dcr3 = 0U,
//   .dcr4 = 0U
// };

// SNOR configuration
// static SNORConfig snor_cfg = {
//   .busp = &WSPID1, // Link to OctoSPI1 driver
//   .buscfg = &wspi_cfg
// };

// SNORDriver snord1;

// void flash_init(void) {
//   // Start WSPI driver
//   wspiStart(&WSPID1, &wspi_cfg);

//   // Start SNOR driver
//   snorStart(&snord1, &snor_cfg);

//   // Enable Quad mode on W25Q128JVSIQ (if not automatic)
//   uint8_t status2 = 0x02; // QE bit set
//   wspiCommand(&WSPID1, 0x06, 0, NULL, 0); // Write Enable
//   wspiCommand(&WSPID1, 0x31, 1, &status2, 0); // Write Status Register 2
// }


//  Application entry point.
int main(void) {

  // Determine why the MCU wokeup.
  // RESET, one of the Wakeup Pins, RTC, UART etc.
  //DetermineWakeupSource();

  // HAL initialization, this also initializes the configured device drivers
  // and performs the board-specific initializations.
  halInit();

  // init boot clipboard
  InitBootClipboard();

  // init SWO as soon as possible to make it available to output ASAP
  #if (SWO_OUTPUT == TRUE)
  SwoInit();
  #endif

  // The kernel is initialized but not started yet, this means that
  // main() is executing with absolute priority but interrupts are already enabled.
  osKernelInitialize();
  osDelay(20); // Let init stabilize


    // check if there is a request to remain on nanoBooter
    if (!IsToRemainInBooter())
    {
        // if the ESCAPE button is pressed, skip the check for a valid CLR image and remain in booter
        // ESCAPE Pressed=Low, Not Pressed=High
        if (palReadLine(KEYPAD_ESCAPE))
        {
            // check for valid CLR image
            // we are checking for a valid image right after the configuration block
            if (CheckValidCLRImage((uint32_t)&__nanoConfig_end__))
            {
                // there seems to be a valid CLR image
                // launch nanoCLR
                LaunchCLR((uint32_t)&__nanoConfig_end__);
            }
        }
    }

    palSetLine(LINE_LED2);
    palSetLine(LINE_LED5);

  #if (HAL_NF_USE_STM32_CRC == TRUE)
  // startup crc
  crcStart(NULL);
  #endif

  // starts the serial driver
  sdStart(&SERIAL_DRIVER, NULL);


  char msg[64] = "\r\nAtlantis Development Booter\r\nVersion ";
  snprintf(&msg[strlen(msg)], sizeof(msg) - strlen(msg), "%d.%d.%d.%d\r\n", VERSION_MAJOR, VERSION_MINOR, VERSION_BUILD, VERSION_REVISION);
  sdWrite(&SERIAL_DRIVER, (const uint8_t *)msg, strlen(msg));

  // create the receiver thread
  osThreadCreate(osThread(ReceiverThread), NULL);

  // start kernel, after this main() will behave like a thread with priority osPriorityNormal
  osKernelStart();

  // InitW25Q128JV();  // Flash for storage
  // InitIS66WVS4M8(); // PSRAM for heap

  // initialize block storage list and devices
  // in CLR this is called in nanoHAL_Initialize()
  // for nanoBooter we have to init it in order to provide the flash map for Monitor_FlashSectorMap command
  BlockStorageList_Initialize();
  BlockStorage_AddDevices();

  // initialize configuration manager
  // in CLR this is called in nanoHAL_Initialize()
  // for nanoBooter we have to init it here to have access to network configuration blocks
  ConfigurationManager_Initialize();

  // report successfull nanoBooter execution
  ReportSuccessfullNanoBooter();

  //  Normal main() thread
  // Alternate LEDs between Green & Blue
  while (true) {
      palToggleLine(LINE_LED2);
      palToggleLine(LINE_LED5);
      osDelay(500);
  }
}


// Does not seem to work in nanoBooter
// Should go in CLR ??
// - DCY 2024-12-29
//
// void DetermineWakeupSource()
// {
//   uint32_t flags = PWR->SR1;

//   // find out wakeup reason
//     if ((RTC->ISR & RTC_ISR_ALRAF) == RTC_ISR_ALRAF)
//     {
//         // standby, match WakeupReason_FromStandby enum
//         WakeupReasonStore = 10;
//     }
//     else if ((flags & PWR_SR1_WUF1) == PWR_SR1_WUF1)
//     {
//         // Wakeup Pin #1 - PA0 - User Button
//         WakeupReasonStore = 1;
//     }
//     else if ((flags & PWR_SR1_WUF2) == PWR_SR1_WUF2)
//     {
//         // Wakeup Pin #2 - PC13 - LCD Touch
//         WakeupReasonStore = 2;
//     }
//     else if ((flags & PWR_SR1_WUF3) == PWR_SR1_WUF3)
//     {
//         // Wakeup Pin #3 - PE6 - Battery Controller
//         WakeupReasonStore = 3;
//     }
//     else if ((flags & PWR_SR1_WUF4) == PWR_SR1_WUF4)
//     {
//         // Wakeup Pin #4 - PA2 - Accelerometer
//         WakeupReasonStore = 4;
//     }
//     else if ((flags & PWR_SR1_WUF5) == PWR_SR1_WUF5)
//     {
//         // Wakeup Pin #5 - PC5 - Keypad Escape
//         WakeupReasonStore = 5;
//     }
//     else
//     {
//         // undetermined reason, match WakeupReason_Undetermined enum
//         WakeupReasonStore = 0;
//     }

//     // first things first: need to clear any possible wakeup flags
//     // if this is not done here the next standby -> wakeup sequence won't work
//     // CLEAR_BIT(RTC->CR, RTC_CR_ALRAIE);
//     // CLEAR_BIT(RTC->ISR, RTC_ISR_ALRAF);
//     SET_BIT(PWR->SCR, PWR_SCR_CWUF1);
//     SET_BIT(PWR->SCR, PWR_SCR_CWUF2);
//     SET_BIT(PWR->SCR, PWR_SCR_CWUF3);
//     SET_BIT(PWR->SCR, PWR_SCR_CWUF4);
//     SET_BIT(PWR->SCR, PWR_SCR_CWUF5);

// }

