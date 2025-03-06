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

// need to declare the Receiver thread here
osThreadDef(ReceiverThread, osPriorityHigh, 2048, "ReceiverThread");
// void DetermineWakeupSource();
// //uint32_t WakeupReasonStore;


//  Application entry point.
int main(void) {

  // Determine why the MCU wokeup.
  // RESET, one of the Wakeup Pins, RTC, UART etc.
  //DetermineWakeupSource();

  // HAL initialization, this also initializes the configured device drivers
  // and performs the board-specific initializations.
  halInit();


  // init SWO as soon as possible to make it available to output ASAP
  #if (SWO_OUTPUT == TRUE)
  SwoInit();
  #endif

  // the following IF is not mandatory, it's just providing a way for a user to 'force'
  // the board to remain in nanoBooter and not launching nanoCLR

  // if the ESCAPE button is pressed, skip the check for a valid CLR image and remain in booter
  // ESCAPE Pressed=Low, Not Pressed=High
  if (palReadLine(KEYPAD_ESCAPE))
  {
    // check for valid CLR image 
    // we are checking for a valid image right after the configuration block
    if(CheckValidCLRImage((uint32_t)&__nanoConfig_end__))
    {
      // there seems to be a valid CLR image
      // launch nanoCLR
      LaunchCLR((uint32_t)&__nanoConfig_end__);
    }
  }

  // The kernel is initialized but not started yet, this means that
  // main() is executing with absolute priority but interrupts are already enabled.
  osKernelInitialize();

  #if (HAL_NF_USE_STM32_CRC == TRUE)
  // startup crc
  crcStart(NULL);
  #endif

  // starts the serial driver
  sdStart(&SERIAL_DRIVER, NULL);

  const char *msg = "Atlantis Development Booter\r\n";
  sdWrite(&SERIAL_DRIVER, (const uint8_t *)msg, strlen(msg));

  // create the receiver thread
  osThreadCreate(osThread(ReceiverThread), NULL);

  // start kernel, after this main() will behave like a thread with priority osPriorityNormal
  osKernelStart();

  // initialize block storage list and devices
  // in CLR this is called in nanoHAL_Initialize()
  // for nanoBooter we have to init it in order to provide the flash map for Monitor_FlashSectorMap command
  BlockStorageList_Initialize();
  BlockStorage_AddDevices();

  // initialize configuration manager
  // in CLR this is called in nanoHAL_Initialize()
  // for nanoBooter we have to init it here to have access to network configuration blocks
  ConfigurationManager_Initialize();

  palSetLine(LINE_LED2);
  palSetLine(LINE_LED5);

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

