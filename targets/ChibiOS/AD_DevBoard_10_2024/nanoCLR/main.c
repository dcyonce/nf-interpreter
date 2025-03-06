//
// Copyright (c) .NET Foundation and Contributors
// See LICENSE file in the project root for full license information.
//

#include <ch.h>
#include <hal.h>
#include <hal_nf_community.h>
#include <cmsis_os.h>

#include <serialcfg.h>
//#include "usbcfg.h"
#include <swo.h>
#include <targetHAL.h>
#include <CLR_Startup_Thread.h>
#include <WireProtocol_ReceiverThread.h>
#include <nanoCLR_Application.h>
#include <nanoPAL_BlockStorage.h>
#include <nanoHAL_v2.h>
#include <targetPAL.h>

// need to declare the Receiver thread here
osThreadDef(ReceiverThread, osPriorityHigh, 2048, "ReceiverThread");
// declare CLRStartup thread here 
osThreadDef(CLRStartupThread, osPriorityNormal, 4096, "CLRStartupThread"); 

void DetermineWakeupSource();

//  Application entry point.
int main(void) {

  bool _blink_LEDS = true;

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

  // The kernel is initialized but not started yet, this means that
  // main() is executing with absolute priority but interrupts are already enabled.
  osKernelInitialize();

  // start watchdog
  Watchdog_Init();

  #if (HAL_NF_USE_STM32_CRC == TRUE)
  // startup crc
  crcStart(NULL);
  #endif

  // starts the serial driver for Visual Studio debugger
  sdStart(&SERIAL_DRIVER, NULL);
  // starts the serial driver for trace messages
  //sdStart(&SDU1, NULL);

  // //  Initializes a serial-over-USB CDC driver.
  // sduObjectInit(&SDU1);
  // sduStart(&SDU1, &serusbcfg);

  //   // Activates the USB driver and then the USB bus pull-up on D+.
  //   // Note, a delay is inserted in order to not have to disconnect the cable after a reset
  //   usbDisconnectBus(serusbcfg.usbp);
  //   chThdSleepMilliseconds(1500);
  //   usbStart(serusbcfg.usbp, &usbcfg);
  //   usbConnectBus(serusbcfg.usbp);

  const char *msg = "\r\n\r\nAtlantis Development nanoFramework CLR\r\n";
  sdWrite(&SERIAL_DRIVER, (const uint8_t *)msg, strlen(msg));
  
  //chnWrite(&SDU1, (const uint8_t *)msg, strlen(msg));
  //sdWrite(&TRACE_DRIVER, (const uint8_t *)msg, strlen(msg));
  
  // create the receiver thread
  osThreadCreate(osThread(ReceiverThread), NULL);

  // CLR settings to launch CLR thread
  CLR_SETTINGS clrSettings;
  (void)memset(&clrSettings, 0, sizeof(CLR_SETTINGS));

  clrSettings.MaxContextSwitches         = 50;
  clrSettings.WaitForDebugger            = false;
  clrSettings.EnterDebuggerLoopAfterExit = true;


   // if the ENTER button is pressed, do NOT start the CLR application
  // ENTER Pressed=Low, Not Pressed=High
  if (palReadLine(KEYPAD_ENTER))
  {
    _blink_LEDS = false;
    clrSettings.WaitForDebugger = false;
  }
  else
    clrSettings.WaitForDebugger = true;

  // create the CLR Startup thread 
  osThreadCreate(osThread(CLRStartupThread), &clrSettings);

  // start kernel, after this main() will behave like a thread with priority osPriorityNormal
  osKernelStart();

  // blink LED1 and LED4 to show that the board is running
  if (_blink_LEDS) 
  {
    palSetLine(LINE_LED1);
    palSetLine(LINE_LED4);
  }
   while (true) { 
       //  Normal main() thread
        if (_blink_LEDS) {
          palToggleLine(LINE_LED1);
          palToggleLine(LINE_LED4);
        }
        osDelay(500);
  //     //chnWrite(&SDU1, (const uint8_t *)msg, strlen(msg));
   }
}

void DetermineWakeupSource()
{
  uint32_t flags = PWR->SR1;

  // find out wakeup reason
    if ((RTC->ISR & RTC_ISR_ALRAF) == RTC_ISR_ALRAF)
    {
        // standby, match WakeupReason_FromStandby enum
        WakeupReasonStore = 10;
    }
    else if ((flags & PWR_SR1_WUF1) == PWR_SR1_WUF1)
    {
        // Wakeup Pin #1 - PA0 - User Button
        WakeupReasonStore = 1;
    }
    else if ((flags & PWR_SR1_WUF2) == PWR_SR1_WUF2)
    {
        // Wakeup Pin #2 - PC13 - LCD Touch
        WakeupReasonStore = 2;
    }
    else if ((flags & PWR_SR1_WUF3) == PWR_SR1_WUF3)
    {
        // Wakeup Pin #3 - PE6 - Battery Controller
        WakeupReasonStore = 3;
    }
    else if ((flags & PWR_SR1_WUF4) == PWR_SR1_WUF4)
    {
        // Wakeup Pin #4 - PA2 - Accelerometer
        WakeupReasonStore = 4;
    }
    else if ((flags & PWR_SR1_WUF5) == PWR_SR1_WUF5)
    {
        // Wakeup Pin #5 - PC5 - Keypad Escape
        WakeupReasonStore = 5;
    }
    else
    {
        // undetermined reason, match WakeupReason_Undetermined enum
        WakeupReasonStore = 0;
    }

    // first things first: need to clear any possible wakeup flags
    // if this is not done here the next standby -> wakeup sequence won't work
    // CLEAR_BIT(RTC->CR, RTC_CR_ALRAIE);
    // CLEAR_BIT(RTC->ISR, RTC_ISR_ALRAF);
    SET_BIT(PWR->SCR, PWR_SCR_CWUF1);
    SET_BIT(PWR->SCR, PWR_SCR_CWUF2);
    SET_BIT(PWR->SCR, PWR_SCR_CWUF3);
    SET_BIT(PWR->SCR, PWR_SCR_CWUF4);
    SET_BIT(PWR->SCR, PWR_SCR_CWUF5);

}
