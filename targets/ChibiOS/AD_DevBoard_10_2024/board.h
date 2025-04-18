/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H 
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for STMicroelectronics STM32L4R9I-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_ST_STM32L4R9I_DISCOVERY
#define BOARD_NAME                  "Atlantis Development DevBoard STM32L4R7ZI"

/*
 * Board oscillators-related settings.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                32768U
#endif

#define STM32_LSEDRV                (3U << 3U)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                16000000U
#endif

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   300U

/*
 * MCU type as defined in the ST header.
 */
#define STM32L4R7xx

/*
 * IO pins assignments.
 */

#define GPIO_PA0_USER_BUTTON                0U
#define GPIO_PA1_PWRMON_SLOW                1U
#define GPIO_PA2_ACC_INT                    2U
#define GPIO_PA3_RGB_2_GREEN                3U
#define GPIO_PA4_FLASH_CS                   4U
#define GPIO_PA5_RGB_1_GREEN                5U
#define GPIO_PA6_KEYPAD_RIGHT               6U
#define GPIO_PA7_RGB_2_BLUE                 7U
#define GPIO_PA8_RGB_1_RED                  8U
#define GPIO_PA9_GPRS_USART1_TX             9U
#define GPIO_PA10_GPRS_USART1_RX            10U
#define GPIO_PA11_USB_DM                    11U
#define GPIO_PA12_USB_DP                    12U
#define GPIO_PA13_JTMS_SWDIO                13U
#define GPIO_PA14_JTMS_SWCLK                14U
#define GPIO_PA15_JTDI                      15U

#define GPIO_PB0_LCD_TOUCH_RST              0U
#define GPIO_PB1_LCD_PWR_EN                 1U
#define GPIO_PB2_LCD_LIGHT_EN               2U
#define GPIO_PB3_JTDO_SWO                   3U
#define GPIO_PB4_JTAG_RST                   4U
#define GPIO_PB5_EINK_BUSY                  5U
#define GPIO_PB6_EINK_DC                    6U
#define GPIO_PB7_EINK_CS                    7U
#define GPIO_PB8                            8U
#define GPIO_PB9                            9U
#define GPIO_PB10_GNSS_RST                  10U
#define GPIO_PB11_DCPWR_SW                  11U
#define GPIO_PB12_SDMMC_SW                  12U
#define GPIO_PB13_6VREG_PG                  13U
#define GPIO_PB14_EINK_PWR_EN               14U
#define GPIO_PB15                           15U

#define GPIO_PC0_CONVERT_LPUART_RX          0U
#define GPIO_PC1_CONVERT_LPUART_TX          1U
#define GPIO_PC2                            2U
#define GPIO_PC3_KEYPAD_ENTER               3U
#define GPIO_PC4_LCD_RST                    4U
#define GPIO_PC5_KEYPAD_ESCAPE              5U
#define GPIO_PC6_RGB_1_BLUE                 6U
#define GPIO_PC7                            7U
#define GPIO_PC8_SDMMC_D0                   8U
#define GPIO_PC9_SDMMC_D1                   9U
#define GPIO_PC10_SDMMC_D2                  10U
#define GPIO_PC11_SDMMC_D3                  11U
#define GPIO_PC12_SDMMC_CLK                 12U
#define GPIO_PC13_LCD_TOUCH_INT             13U
#define GPIO_PC14_OSC32_IN                  14U
#define GPIO_PC15_OSC32_OUT                 15U

#define GPIO_PD0                            0U
#define GPIO_PD1                            1U
#define GPIO_PD2_SDMMC_CMD                  2U
#define GPIO_PD3                            3U
#define GPIO_PD4                            4U
#define GPIO_PD5_STLINK_USART2_TX           5U
#define GPIO_PD6_STLINK_USART2_RX           6U
#define GPIO_PD7                            7U
#define GPIO_PD8_RS485_USART3_TX            8U
#define GPIO_PD9_RS485_USART3_RX            9U
#define GPIO_PD10_RS485_3V_DE               10U
#define GPIO_PD11_RS485_3V_RE               11U
#define GPIO_PD12_RGB_2_RED                 12U
#define GPIO_PD13                           13U
#define GPIO_PD14_RS485_5V_DE               14U
#define GPIO_PD15_RS485_5V_RE               15U

#define GPIO_PE0_KEYPAD_UP                  0U
#define GPIO_PE1_KEYPAD_DOWN                1U
#define GPIO_PE2_CONTAINER_EN               2U
#define GPIO_PE3_CONTAINER_NO               3U
#define GPIO_PE4_CONTAINER_NC               4U
#define GPIO_PE5                            5U
#define GPIO_PE6_BATTERY_INT                6U
#define GPIO_PE7_GPRS_RST                   7U
#define GPIO_PE8_GPRS_PWR_EN                8U
#define GPIO_PE9_GNSS_GEOFENCE              9U
#define GPIO_PE10_GNSS_PWR_EN               10U
#define GPIO_PE11_KEYPAD_LEFT               11U
#define GPIO_PE12_GNSS_VBCKP_EN             12U
#define GPIO_PE13_SPI1_SCK                  13U
#define GPIO_PE14_SPI1_MISO                 14U
#define GPIO_PE15_SPI1_MOSI                 15U

#define GPIO_PF0_SRAM_SIO0                  0U
#define GPIO_PF1_SRAM_SIO1                  1U
#define GPIO_PF2_SRAM_SIO2                  2U
#define GPIO_PF3_SRAM_SIO3                  3U
#define GPIO_PF4_SRAM_CLK                   4U
#define GPIO_PF5_BATTERY_CHRG_EN            5U
#define GPIO_PF6_FLASH_SIO3                 6U
#define GPIO_PF7_FLASH_SIO2                 7U
#define GPIO_PF8_FLASH_SIO0                 8U
#define GPIO_PF9_FLASH_SIO1                 9U
#define GPIO_PF10_FLASH_CLK                 10U
#define GPIO_PF11_LCD_DC                    11U
#define GPIO_PF12_LCD_CS                    12U
#define GPIO_PF13_GNSS_3D_FIX               13U
#define GPIO_PF14_I2C4_SCL                  14U
#define GPIO_PF15_I2C4_SDA                  15U

#define GPIO_PG0_CHARLCD_D0                 0U
#define GPIO_PG1_CHARLCD_D1                 1U
#define GPIO_PG2_CHARLCD_D2                 2U
#define GPIO_PG3_CHARLCD_D3                 3U
#define GPIO_PG4_CHARLCD_D4                 4U
#define GPIO_PG5_CHARLCD_D5                 5U
#define GPIO_PG6_CHARLCD_D6                 6U
#define GPIO_PG7_CHARLCD_D7                 7U
#define GPIO_PG8_CHARLCD_RS                 8U
#define GPIO_PG9_CHARLCD_RW                 9U
#define GPIO_PG10_CHARLCD_EN                10U
#define GPIO_PG11_GPRS_PWRKEY               11U
#define GPIO_PG12_SRAM_CE                   12U
#define GPIO_PG13_I2C1_SDA                  13U
#define GPIO_PG14_I2C1_SCL                  14U
#define GPIO_PG15_EINK_RST                  15U

#define GPIOH_OSC_IN                        0U
#define GPIOH_OSC_OUT                       1U
#define GPIOH_PIN2                  2U
#define GPIOH_BOOT0                         3U
#define GPIOH_PIN4                  4U
#define GPIOH_PIN5                  5U
#define GPIOH_PIN6                  6U
#define GPIOH_PIN7                  7U
#define GPIOH_PIN8                  8U
#define GPIOH_PIN9                  9U
#define GPIOH_PIN10                 10U
#define GPIOH_PIN11                 11U
#define GPIOH_PIN12                 12U
#define GPIOH_PIN13                 13U
#define GPIOH_PIN14                 14U
#define GPIOH_PIN15                 15U

#define GPIOI_PIN0                  0U
#define GPIOI_PIN1                  1U
#define GPIOI_PIN2                  2U
#define GPIOI_PIN3                  3U
#define GPIOI_PIN4                  4U
#define GPIOI_PIN5                  5U
#define GPIOI_PIN6                  6U
#define GPIOI_PIN7                  7U
#define GPIOI_PIN8                  8U
#define GPIOI_PIN9                  9U
#define GPIOI_PIN10                 10U
#define GPIOI_PIN11                 11U
#define GPIOI_PIN12                 12U
#define GPIOI_PIN13                 13U
#define GPIOI_PIN14                 14U
#define GPIOI_PIN15                 15U

/*
 * IO lines assignments.
 */
#define LINE_STLINK_USART2_TX       PAL_LINE(GPIOD, 5U)
#define LINE_STLINK_USART2_RX       PAL_LINE(GPIOD, 6U)
//#define LINE_USB_OTGFS_VBUS         PAL_LINE(GPIOA, 9U)
//#define LINE_USB_OTGFS_ID           PAL_LINE(GPIOA, 10U)
//#define LINE_USB_OTGFS_DM           PAL_LINE(GPIOA, 11U)
//#define LINE_USB_OTGFS_DP           PAL_LINE(GPIOA, 12U)
#define LINE_SWDIO                  PAL_LINE(GPIOA, 13U)
#define LINE_SWCLK                  PAL_LINE(GPIOA, 14U)
#define LINE_SWO                    PAL_LINE(GPIOB, 3U)
#define LINE_SDMMC_1_D0             PAL_LINE(GPIOC, 8U)
#define LINE_SDMMC_1_D1             PAL_LINE(GPIOC, 9U)
#define LINE_SDMMC_1_D2             PAL_LINE(GPIOC, 10U)
#define LINE_SDMMC_1_D3             PAL_LINE(GPIOC, 11U)
#define LINE_SDMMC_1_CK             PAL_LINE(GPIOC, 12U)
//#define LINE_JOY_SEL                PAL_LINE(GPIOC, 13U)
//#define LINE_BUTTON                 PAL_LINE(GPIOC, 5U)
#define KEYPAD_ESCAPE               PAL_LINE(GPIOC, 5U)
#define KEYPAD_ENTER                PAL_LINE(GPIOC, 3U)
#define LINE_SDMMC_1_CMD            PAL_LINE(GPIOD, 2U)
#define LINE_OCTOSPIM_P2_IO6        PAL_LINE(GPIOG, 9U)
#define LINE_OCTOSPIM_P2_IO7        PAL_LINE(GPIOG, 10U)
#define LINE_OCTOSPIM_P2_NCS        PAL_LINE(GPIOG, 12U)
#define LINE_OCTOSPIM_P2_DQS        PAL_LINE(GPIOG, 15U)
#define LINE_OSC_IN                 PAL_LINE(GPIOH, 0U)
#define LINE_OSC_OUT                PAL_LINE(GPIOH, 1U)
#define LINE_BOOT0                  PAL_LINE(GPIOH, 3U)
//#define LINE_LED                    PAL_LINE(GPIOH, 4U)
//#define LINE_LED_GREEN              PAL_LINE(GPIOH, 4U)
#define LINE_OCTOSPIM_P2_IO3        PAL_LINE(GPIOH, 8U)
#define LINE_OCTOSPIM_P2_IO4        PAL_LINE(GPIOH, 9U)
#define LINE_OCTOSPIM_P2_IO5        PAL_LINE(GPIOH, 10U)
#define LINE_OCTOSPIM_P2_CLK        PAL_LINE(GPIOI, 6U)
#define LINE_OCTOSPIM_P2_IO2        PAL_LINE(GPIOI, 9U)
#define LINE_OCTOSPIM_P2_IO1        PAL_LINE(GPIOI, 10U)
#define LINE_OCTOSPIM_P2_IO0        PAL_LINE(GPIOI, 11U)

// DCY: Redefined LED lines to match the actual board
#define LINE_LED1                   PAL_LINE(GPIOA, 8U)
#define LINE_LED2                   PAL_LINE(GPIOA, 5U)
#define LINE_LED3                   PAL_LINE(GPIOC, 6U)

// JAT: Defined 3 New LED lines to match 5050 LED
#define LINE_LED4                   PAL_LINE(GPIOA, 3U)
#define LINE_LED5                   PAL_LINE(GPIOA, 7U)
#define LINE_LED6                   PAL_LINE(GPIOD, 12U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))  //rename to match reference guide
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))  //rename to match reference guide
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))  //rename to match reference guide
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))  //rename to match reference guide
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))
#define PIN_ASCR_DISABLED(n)        (0U << (n))
#define PIN_ASCR_ENABLED(n)         (1U << (n))
#define PIN_LOCKR_DISABLED(n)       (0U << (n))
#define PIN_LOCKR_ENABLED(n)        (1U << (n))

/*
 * GPIOA setup:
 *
 * PA0  - User Button INT           (Input Pullup).    (Wakeup)
 * PA1  - PwrMon Slow/Alert 1       ().
 * PA2  - ACC INT                   (Input Pulldown).  (Wakeup)
 * PA3  - RGB 2 Green               (Output Low).
 * PA4  - Flash CS                  ().
 * PA5  - RGB 1 Green               (Output High).
 * PA6  - Keypad Right              (Input Pullup).
 * PA7  - RGB 2 Blue                (Output Low).
 * PA8  - RGB 1 Red                 (Output High).
 * PA9  - GPRS RX (USART 1 TX)      (Alternate 7).
 * PA10 - GPRS TX (USART 1 RX)      (Alternate 7).
 * PA11 - USB_OTGFS_DM              (Alternate 10).
 * PA12 - USB_OTGFS_DP              (Alternate 10).
 * PA13 - JTMS/SWDIO                (Alternate 0).
 * PA14 - JTCK/SWCLK                (Alternate 0).
 * PA15 - JTDI                      (Alternate 0).
 */

// JAT: Changed pin modes for LED pins from ANALOG to OUTPUT
#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(GPIO_PA0_USER_BUTTON) |             \
                                     PIN_MODE_ANALOG(GPIO_PA1_PWRMON_SLOW) |            \
                                     PIN_MODE_INPUT(GPIO_PA2_ACC_INT) |                 \
                                     PIN_MODE_OUTPUT(GPIO_PA3_RGB_2_GREEN) |            \
                                     PIN_MODE_OUTPUT(GPIO_PA4_FLASH_CS) |               \
                                     PIN_MODE_OUTPUT(GPIO_PA5_RGB_1_GREEN) |            \
                                     PIN_MODE_INPUT(GPIO_PA6_KEYPAD_RIGHT) |            \
                                     PIN_MODE_OUTPUT(GPIO_PA7_RGB_2_BLUE) |             \
                                     PIN_MODE_OUTPUT(GPIO_PA8_RGB_1_RED) |              \
                                     PIN_MODE_ALTERNATE(GPIO_PA9_GPRS_USART1_TX) |      \
                                     PIN_MODE_ALTERNATE(GPIO_PA10_GPRS_USART1_RX) |     \
                                     PIN_MODE_ALTERNATE(GPIO_PA11_USB_DM) |             \
                                     PIN_MODE_ALTERNATE(GPIO_PA12_USB_DP) |             \
                                     PIN_MODE_ALTERNATE(GPIO_PA13_JTMS_SWDIO) |         \
                                     PIN_MODE_ALTERNATE(GPIO_PA14_JTMS_SWCLK) |         \
                                     PIN_MODE_ALTERNATE(GPIO_PA15_JTDI))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIO_PA0_USER_BUTTON) |         \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA1_PWRMON_SLOW) |         \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA2_ACC_INT) |             \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA3_RGB_2_GREEN) |         \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA4_FLASH_CS) |            \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA5_RGB_1_GREEN) |         \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA6_KEYPAD_RIGHT) |        \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA7_RGB_2_BLUE) |          \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA8_RGB_1_RED) |           \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA9_GPRS_USART1_TX) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA10_GPRS_USART1_RX) |     \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA11_USB_DM) |             \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA12_USB_DP) |             \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA13_JTMS_SWDIO) |         \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA14_JTMS_SWCLK) |         \
                                     PIN_OTYPE_PUSHPULL(GPIO_PA15_JTDI))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIO_PA0_USER_BUTTON) |         \
                                     PIN_OSPEED_VERYLOW(GPIO_PA1_PWRMON_SLOW) |         \
                                     PIN_OSPEED_VERYLOW(GPIO_PA2_ACC_INT) |             \
                                     PIN_OSPEED_VERYLOW(GPIO_PA3_RGB_2_GREEN) |         \
                                     PIN_OSPEED_HIGH(GPIO_PA4_FLASH_CS) |            \
                                     PIN_OSPEED_VERYLOW(GPIO_PA5_RGB_1_GREEN) |         \
                                     PIN_OSPEED_VERYLOW(GPIO_PA6_KEYPAD_RIGHT) |        \
                                     PIN_OSPEED_VERYLOW(GPIO_PA7_RGB_2_BLUE) |          \
                                     PIN_OSPEED_VERYLOW(GPIO_PA8_RGB_1_RED) |           \
                                     PIN_OSPEED_HIGH(GPIO_PA9_GPRS_USART1_TX) |         \
                                     PIN_OSPEED_HIGH(GPIO_PA10_GPRS_USART1_RX) |        \
                                     PIN_OSPEED_HIGH(GPIO_PA11_USB_DM) |                \
                                     PIN_OSPEED_HIGH(GPIO_PA12_USB_DP) |                \
                                     PIN_OSPEED_HIGH(GPIO_PA13_JTMS_SWDIO) |            \
                                     PIN_OSPEED_HIGH(GPIO_PA14_JTMS_SWCLK) |            \
                                     PIN_OSPEED_VERYLOW(GPIO_PA15_JTDI))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLUP(GPIO_PA0_USER_BUTTON) |           \
                                     PIN_PUPDR_FLOATING(GPIO_PA1_PWRMON_SLOW) |         \
                                     PIN_PUPDR_PULLUP(GPIO_PA2_ACC_INT) |               \
                                     PIN_PUPDR_FLOATING(GPIO_PA3_RGB_2_GREEN) |         \
                                     PIN_PUPDR_PULLUP(GPIO_PA4_FLASH_CS) |            \
                                     PIN_PUPDR_FLOATING(GPIO_PA5_RGB_1_GREEN) |         \
                                     PIN_PUPDR_FLOATING(GPIO_PA6_KEYPAD_RIGHT) |        \
                                     PIN_PUPDR_FLOATING(GPIO_PA7_RGB_2_BLUE) |          \
                                     PIN_PUPDR_FLOATING(GPIO_PA8_RGB_1_RED) |           \
                                     PIN_PUPDR_FLOATING(GPIO_PA9_GPRS_USART1_TX) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PA10_GPRS_USART1_RX) |     \
                                     PIN_PUPDR_FLOATING(GPIO_PA11_USB_DM) |             \
                                     PIN_PUPDR_FLOATING(GPIO_PA12_USB_DP) |             \
                                     PIN_PUPDR_PULLDOWN(GPIO_PA13_JTMS_SWDIO) |         \
                                     PIN_PUPDR_PULLUP(GPIO_PA14_JTMS_SWCLK) |           \
                                     PIN_PUPDR_FLOATING(GPIO_PA15_JTDI))
#define VAL_GPIOA_ODR               (PIN_ODR_LOW(GPIO_PA0_USER_BUTTON) |                \
                                     PIN_ODR_LOW(GPIO_PA1_PWRMON_SLOW) |                \
                                     PIN_ODR_LOW(GPIO_PA2_ACC_INT) |                    \
                                     PIN_ODR_LOW(GPIO_PA3_RGB_2_GREEN) |                \
                                     PIN_ODR_HIGH(GPIO_PA4_FLASH_CS) |                   \
                                     PIN_ODR_HIGH(GPIO_PA5_RGB_1_GREEN) |               \
                                     PIN_ODR_LOW(GPIO_PA6_KEYPAD_RIGHT) |               \
                                     PIN_ODR_LOW(GPIO_PA7_RGB_2_BLUE) |                 \
                                     PIN_ODR_HIGH(GPIO_PA8_RGB_1_RED) |                 \
                                     PIN_ODR_LOW(GPIO_PA9_GPRS_USART1_TX) |             \
                                     PIN_ODR_LOW(GPIO_PA10_GPRS_USART1_RX) |            \
                                     PIN_ODR_LOW(GPIO_PA11_USB_DM) |                    \
                                     PIN_ODR_LOW(GPIO_PA12_USB_DP) |                    \
                                     PIN_ODR_LOW(GPIO_PA13_JTMS_SWDIO) |                \
                                     PIN_ODR_LOW(GPIO_PA14_JTMS_SWCLK) |                \
                                     PIN_ODR_LOW(GPIO_PA15_JTDI))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIO_PA0_USER_BUTTON, 0U) |            \
                                     PIN_AFIO_AF(GPIO_PA1_PWRMON_SLOW, 0U) |            \
                                     PIN_AFIO_AF(GPIO_PA2_ACC_INT, 0U) |                \
                                     PIN_AFIO_AF(GPIO_PA3_RGB_2_GREEN, 0U) |            \
                                     PIN_AFIO_AF(GPIO_PA4_FLASH_CS, 3U) |               \
                                     PIN_AFIO_AF(GPIO_PA5_RGB_1_GREEN, 0U) |            \
                                     PIN_AFIO_AF(GPIO_PA6_KEYPAD_RIGHT, 0U) |           \
                                     PIN_AFIO_AF(GPIO_PA7_RGB_2_BLUE, 0U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIO_PA8_RGB_1_RED, 0U) |              \
                                     PIN_AFIO_AF(GPIO_PA9_GPRS_USART1_TX, 7U) |         \
                                     PIN_AFIO_AF(GPIO_PA10_GPRS_USART1_RX, 7U) |        \
                                     PIN_AFIO_AF(GPIO_PA11_USB_DM, 10U) |               \
                                     PIN_AFIO_AF(GPIO_PA12_USB_DP, 10U) |               \
                                     PIN_AFIO_AF(GPIO_PA13_JTMS_SWDIO, 0U) |            \
                                     PIN_AFIO_AF(GPIO_PA14_JTMS_SWCLK, 0U) |            \
                                     PIN_AFIO_AF(GPIO_PA15_JTDI, 0U))
#define VAL_GPIOA_ASCR              (PIN_ASCR_DISABLED(GPIO_PA0_USER_BUTTON) |          \
                                     PIN_ASCR_DISABLED(GPIO_PA1_PWRMON_SLOW) |          \
                                     PIN_ASCR_DISABLED(GPIO_PA2_ACC_INT) |              \
                                     PIN_ASCR_DISABLED(GPIO_PA3_RGB_2_GREEN) |          \
                                     PIN_ASCR_DISABLED(GPIO_PA4_FLASH_CS) |             \
                                     PIN_ASCR_DISABLED(GPIO_PA5_RGB_1_GREEN) |          \
                                     PIN_ASCR_DISABLED(GPIO_PA6_KEYPAD_RIGHT) |         \
                                     PIN_ASCR_DISABLED(GPIO_PA7_RGB_2_BLUE) |           \
                                     PIN_ASCR_DISABLED(GPIO_PA8_RGB_1_RED) |            \
                                     PIN_ASCR_DISABLED(GPIO_PA9_GPRS_USART1_TX) |       \
                                     PIN_ASCR_DISABLED(GPIO_PA10_GPRS_USART1_RX) |      \
                                     PIN_ASCR_DISABLED(GPIO_PA11_USB_DM) |              \
                                     PIN_ASCR_DISABLED(GPIO_PA12_USB_DP) |              \
                                     PIN_ASCR_DISABLED(GPIO_PA13_JTMS_SWDIO) |          \
                                     PIN_ASCR_DISABLED(GPIO_PA14_JTMS_SWCLK) |          \
                                     PIN_ASCR_DISABLED(GPIO_PA15_JTDI))
#define VAL_GPIOA_LOCKR             (PIN_LOCKR_DISABLED(GPIO_PA0_USER_BUTTON) |         \
                                     PIN_LOCKR_DISABLED(GPIO_PA1_PWRMON_SLOW) |         \
                                     PIN_LOCKR_DISABLED(GPIO_PA2_ACC_INT) |             \
                                     PIN_LOCKR_DISABLED(GPIO_PA3_RGB_2_GREEN) |         \
                                     PIN_LOCKR_DISABLED(GPIO_PA4_FLASH_CS) |            \
                                     PIN_LOCKR_DISABLED(GPIO_PA5_RGB_1_GREEN) |         \
                                     PIN_LOCKR_DISABLED(GPIO_PA6_KEYPAD_RIGHT) |        \
                                     PIN_LOCKR_DISABLED(GPIO_PA7_RGB_2_BLUE) |          \
                                     PIN_LOCKR_DISABLED(GPIO_PA8_RGB_1_RED) |           \
                                     PIN_LOCKR_DISABLED(GPIO_PA9_GPRS_USART1_TX) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PA10_GPRS_USART1_RX) |     \
                                     PIN_LOCKR_DISABLED(GPIO_PA11_USB_DM) |             \
                                     PIN_LOCKR_DISABLED(GPIO_PA12_USB_DP) |             \
                                     PIN_LOCKR_DISABLED(GPIO_PA13_JTMS_SWDIO) |         \
                                     PIN_LOCKR_DISABLED(GPIO_PA14_JTMS_SWCLK) |         \
                                     PIN_LOCKR_DISABLED(GPIO_PA15_JTDI))

/*
 * GPIOB setup:
 *
 * PB0  - LCD Touch Reset           (Output High).
 * PB1  - LCD Power Enable          (Output Floating).
 * PB2  - LCD Backlight Enable      (Output Floating).
 * PB3  - JTDO/SWO                  (Alternate 0).
 * PB4  - JTAG RST                  (Alternate 0).
 * PB5  - eInk Busy                 (Input ).
 * PB6  - eInk D/C                  (Output ).
 * PB7  - eInk CS                   (Output ).
 * PB8  - Open                      ().
 * PB9  - Open                      ().
 * PB10 - GNSS Reset                (Output ).
 * PB11 - Barrel Switch             (Input ).
 * PB12 - SD Switch                 (Input ).
 * PB13 - 6V Reg Power Good         (Input ).
 * PB14 - eInk Power Enable         (Output High).
 * PB15 - Open                      ().
 */
#define VAL_GPIOB_MODER             (PIN_MODE_OUTPUT(GPIO_PB0_LCD_TOUCH_RST) |          \
                                     PIN_MODE_OUTPUT(GPIO_PB1_LCD_PWR_EN) |             \
                                     PIN_MODE_OUTPUT(GPIO_PB2_LCD_LIGHT_EN) |           \
                                     PIN_MODE_ALTERNATE(GPIO_PB3_JTDO_SWO) |            \
                                     PIN_MODE_ALTERNATE(GPIO_PB4_JTAG_RST) |            \
                                     PIN_MODE_ANALOG(GPIO_PB5_EINK_BUSY) |              \
                                     PIN_MODE_ANALOG(GPIO_PB6_EINK_DC) |          \
                                     PIN_MODE_ANALOG(GPIO_PB7_EINK_CS) |          \
                                     PIN_MODE_ANALOG(GPIO_PB8) |          \
                                     PIN_MODE_ANALOG(GPIO_PB9) |          \
                                     PIN_MODE_ANALOG(GPIO_PB10_GNSS_RST) |         \
                                     PIN_MODE_ANALOG(GPIO_PB11_DCPWR_SW) |         \
                                     PIN_MODE_ANALOG(GPIO_PB12_SDMMC_SW) |         \
                                     PIN_MODE_ANALOG(GPIO_PB13_6VREG_PG) |         \
                                     PIN_MODE_OUTPUT(GPIO_PB14_EINK_PWR_EN) |         \
                                     PIN_MODE_ANALOG(GPIO_PB15))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIO_PB0_LCD_TOUCH_RST) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB1_LCD_PWR_EN) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB2_LCD_LIGHT_EN) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB3_JTDO_SWO) |        \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB4_JTAG_RST) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB5_EINK_BUSY) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB6_EINK_DC) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB7_EINK_CS) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB10_GNSS_RST) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB11_DCPWR_SW) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB12_SDMMC_SW) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB13_6VREG_PG) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB14_EINK_PWR_EN) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PB15))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIO_PB0_LCD_TOUCH_RST) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PB1_LCD_PWR_EN) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PB2_LCD_LIGHT_EN) |       \
                                     PIN_OSPEED_HIGH(GPIO_PB3_JTDO_SWO) |           \
                                     PIN_OSPEED_VERYLOW(GPIO_PB4_JTAG_RST) |       \
                                     PIN_OSPEED_HIGH(GPIO_PB5_EINK_BUSY) |       \
                                     PIN_OSPEED_HIGH(GPIO_PB6_EINK_DC) |       \
                                     PIN_OSPEED_HIGH(GPIO_PB7_EINK_CS) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PB8) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PB9) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PB10_GNSS_RST) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PB11_DCPWR_SW) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PB12_SDMMC_SW) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PB13_6VREG_PG) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PB14_EINK_PWR_EN) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PB15))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_FLOATING(GPIO_PB0_LCD_TOUCH_RST) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PB1_LCD_PWR_EN) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PB2_LCD_LIGHT_EN) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PB3_JTDO_SWO) |        \
                                     PIN_PUPDR_FLOATING(GPIO_PB4_JTAG_RST) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PB5_EINK_BUSY) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PB6_EINK_DC) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PB7_EINK_CS) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PB8) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PB9) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PB10_GNSS_RST) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PB11_DCPWR_SW) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PB12_SDMMC_SW) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PB13_6VREG_PG) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PB14_EINK_PWR_EN) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PB15))
#define VAL_GPIOB_ODR               (PIN_ODR_LOW(GPIO_PB0_LCD_TOUCH_RST) |              \
                                     PIN_ODR_LOW(GPIO_PB1_LCD_PWR_EN) |              \
                                     PIN_ODR_LOW(GPIO_PB2_LCD_LIGHT_EN) |              \
                                     PIN_ODR_LOW(GPIO_PB3_JTDO_SWO) |               \
                                     PIN_ODR_LOW(GPIO_PB4_JTAG_RST) |              \
                                     PIN_ODR_LOW(GPIO_PB5_EINK_BUSY) |              \
                                     PIN_ODR_LOW(GPIO_PB6_EINK_DC) |              \
                                     PIN_ODR_LOW(GPIO_PB7_EINK_CS) |              \
                                     PIN_ODR_LOW(GPIO_PB8) |              \
                                     PIN_ODR_LOW(GPIO_PB9) |              \
                                     PIN_ODR_LOW(GPIO_PB10_GNSS_RST) |             \
                                     PIN_ODR_LOW(GPIO_PB11_DCPWR_SW) |             \
                                     PIN_ODR_LOW(GPIO_PB12_SDMMC_SW) |             \
                                     PIN_ODR_LOW(GPIO_PB13_6VREG_PG) |             \
                                     PIN_ODR_HIGH(GPIO_PB14_EINK_PWR_EN) |             \
                                     PIN_ODR_LOW(GPIO_PB15))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIO_PB0_LCD_TOUCH_RST, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PB1_LCD_PWR_EN, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PB2_LCD_LIGHT_EN, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PB3_JTDO_SWO, 0U) |           \
                                     PIN_AFIO_AF(GPIO_PB4_JTAG_RST, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PB5_EINK_BUSY, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PB6_EINK_DC, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PB7_EINK_CS, 0U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIO_PB8, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PB9, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PB10_GNSS_RST, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PB11_DCPWR_SW, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PB12_SDMMC_SW, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PB13_6VREG_PG, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PB14_EINK_PWR_EN, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PB15, 0U))
#define VAL_GPIOB_ASCR              (PIN_ASCR_DISABLED(GPIO_PB0_LCD_TOUCH_RST) |        \
                                     PIN_ASCR_DISABLED(GPIO_PB1_LCD_PWR_EN) |        \
                                     PIN_ASCR_DISABLED(GPIO_PB2_LCD_LIGHT_EN) |        \
                                     PIN_ASCR_DISABLED(GPIO_PB3_JTDO_SWO) |         \
                                     PIN_ASCR_DISABLED(GPIO_PB4_JTAG_RST) |        \
                                     PIN_ASCR_DISABLED(GPIO_PB5_EINK_BUSY) |        \
                                     PIN_ASCR_DISABLED(GPIO_PB6_EINK_DC) |        \
                                     PIN_ASCR_DISABLED(GPIO_PB7_EINK_CS) |        \
                                     PIN_ASCR_DISABLED(GPIO_PB8) |        \
                                     PIN_ASCR_DISABLED(GPIO_PB9) |        \
                                     PIN_ASCR_DISABLED(GPIO_PB10_GNSS_RST) |       \
                                     PIN_ASCR_DISABLED(GPIO_PB11_DCPWR_SW) |       \
                                     PIN_ASCR_DISABLED(GPIO_PB12_SDMMC_SW) |       \
                                     PIN_ASCR_DISABLED(GPIO_PB13_6VREG_PG) |       \
                                     PIN_ASCR_DISABLED(GPIO_PB14_EINK_PWR_EN) |       \
                                     PIN_ASCR_DISABLED(GPIO_PB15))
#define VAL_GPIOB_LOCKR             (PIN_LOCKR_DISABLED(GPIO_PB0_LCD_TOUCH_RST) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PB1_LCD_PWR_EN) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PB2_LCD_LIGHT_EN) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PB3_JTDO_SWO) |        \
                                     PIN_LOCKR_DISABLED(GPIO_PB4_JTAG_RST) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PB5_EINK_BUSY) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PB6_EINK_DC) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PB7_EINK_CS) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PB8) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PB9) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PB10_GNSS_RST) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PB11_DCPWR_SW) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PB12_SDMMC_SW) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PB13_6VREG_PG) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PB14_EINK_PWR_EN) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PB15))

/*
 * GPIOC setup:
 *
 * PC0  - Analyzer TX (LPUART 1 RX) (Alternate 8).
 * PC1  - Analyzer RX (LPUART 1 TX) (Alternate 8).
 * PC2  - Open                      ().
 * PC3  - Keypad Enter              (Input Pullup).
 * PC4  - LCD Reset                 (Output ).
 * PC5  - Keypad Escape INT         (Input Pullup).   (Wakeup)
 * PC6  - RGB 1 Blue                (Output High).
 * PC7  - Open                      ().
 * PC8  - SD DAT0                   (Alternate 12).
 * PC9  - SD DAT1                   (Alternate 12).
 * PC10 - SD DAT2                   (Alternate 12).
 * PC11 - SD DAT3                   (Alternate 12).
 * PC12 - SD CLK                    (Alternate 12).
 * PC13 - LCD Touch INT             (Input Pulldown). (Wakeup)
 * PC14 - OSC32 IN                  ().
 * PC15 - OSC32 Out                 ().
 */

// JAT: Changed pin modes for LED pins from ANALOG to OUTPUT
#define VAL_GPIOC_MODER             (PIN_MODE_ALTERNATE(GPIO_PC0_CONVERT_LPUART_RX) |   \
                                     PIN_MODE_ALTERNATE(GPIO_PC1_CONVERT_LPUART_TX) |   \
                                     PIN_MODE_ANALOG(GPIO_PC2) |                        \
                                     PIN_MODE_INPUT(GPIO_PC3_KEYPAD_ENTER) |            \
                                     PIN_MODE_ANALOG(GPIO_PC4_LCD_RST) |                \
                                     PIN_MODE_INPUT(GPIO_PC5_KEYPAD_ESCAPE) |           \
                                     PIN_MODE_OUTPUT(GPIO_PC6_RGB_1_BLUE) |             \
                                     PIN_MODE_ANALOG(GPIO_PC7) |                        \
                                     PIN_MODE_ALTERNATE(GPIO_PC8_SDMMC_D0) |            \
                                     PIN_MODE_ALTERNATE(GPIO_PC9_SDMMC_D1) |            \
                                     PIN_MODE_ALTERNATE(GPIO_PC10_SDMMC_D2) |           \
                                     PIN_MODE_ALTERNATE(GPIO_PC11_SDMMC_D3) |           \
                                     PIN_MODE_ALTERNATE(GPIO_PC12_SDMMC_CLK) |          \
                                     PIN_MODE_INPUT(GPIO_PC13_LCD_TOUCH_INT) |          \
                                     PIN_MODE_ANALOG(GPIO_PC14_OSC32_IN) |              \
                                     PIN_MODE_ANALOG(GPIO_PC15_OSC32_OUT))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIO_PC0_CONVERT_LPUART_RX) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC1_CONVERT_LPUART_TX) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC3_KEYPAD_ENTER) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC4_LCD_RST) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC5_KEYPAD_ESCAPE) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC6_RGB_1_BLUE) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC8_SDMMC_D0) | \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC9_SDMMC_D1) | \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC10_SDMMC_D2) | \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC11_SDMMC_D3) | \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC12_SDMMC_CLK) | \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC13_LCD_TOUCH_INT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC14_OSC32_IN) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PC15_OSC32_OUT))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_HIGH(GPIO_PC0_CONVERT_LPUART_RX) |       \
                                     PIN_OSPEED_HIGH(GPIO_PC1_CONVERT_LPUART_TX) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PC2) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PC3_KEYPAD_ENTER) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PC4_LCD_RST) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PC5_KEYPAD_ESCAPE) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PC6_RGB_1_BLUE) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PC7) |       \
                                     PIN_OSPEED_HIGH(GPIO_PC8_SDMMC_D0) |    \
                                     PIN_OSPEED_HIGH(GPIO_PC9_SDMMC_D1) |    \
                                     PIN_OSPEED_HIGH(GPIO_PC10_SDMMC_D2) |    \
                                     PIN_OSPEED_HIGH(GPIO_PC11_SDMMC_D3) |    \
                                     PIN_OSPEED_HIGH(GPIO_PC12_SDMMC_CLK) |    \
                                     PIN_OSPEED_VERYLOW(GPIO_PC13_LCD_TOUCH_INT) |    \
                                     PIN_OSPEED_VERYLOW(GPIO_PC14_OSC32_IN) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PC15_OSC32_OUT))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_FLOATING(GPIO_PC0_CONVERT_LPUART_RX) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PC1_CONVERT_LPUART_TX) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PC2) |       \
                                     PIN_PUPDR_PULLUP(GPIO_PC3_KEYPAD_ENTER) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PC4_LCD_RST) |       \
                                     PIN_PUPDR_PULLUP(GPIO_PC5_KEYPAD_ESCAPE) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PC6_RGB_1_BLUE) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PC7) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PC8_SDMMC_D0) | \
                                     PIN_PUPDR_FLOATING(GPIO_PC9_SDMMC_D1) | \
                                     PIN_PUPDR_FLOATING(GPIO_PC10_SDMMC_D2) | \
                                     PIN_PUPDR_FLOATING(GPIO_PC11_SDMMC_D3) | \
                                     PIN_PUPDR_FLOATING(GPIO_PC12_SDMMC_CLK) | \
                                     PIN_PUPDR_PULLDOWN(GPIO_PC13_LCD_TOUCH_INT) |    \
                                     PIN_PUPDR_FLOATING(GPIO_PC14_OSC32_IN) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PC15_OSC32_OUT))
#define VAL_GPIOC_ODR               (PIN_ODR_LOW(GPIO_PC0_CONVERT_LPUART_RX) |              \
                                     PIN_ODR_LOW(GPIO_PC1_CONVERT_LPUART_TX) |              \
                                     PIN_ODR_LOW(GPIO_PC2) |              \
                                     PIN_ODR_LOW(GPIO_PC3_KEYPAD_ENTER) |              \
                                     PIN_ODR_LOW(GPIO_PC4_LCD_RST) |              \
                                     PIN_ODR_LOW(GPIO_PC5_KEYPAD_ESCAPE) |              \
                                     PIN_ODR_HIGH(GPIO_PC6_RGB_1_BLUE) |              \
                                     PIN_ODR_LOW(GPIO_PC7) |              \
                                     PIN_ODR_LOW(GPIO_PC8_SDMMC_D0) |        \
                                     PIN_ODR_LOW(GPIO_PC9_SDMMC_D1) |        \
                                     PIN_ODR_LOW(GPIO_PC10_SDMMC_D2) |        \
                                     PIN_ODR_LOW(GPIO_PC11_SDMMC_D3) |        \
                                     PIN_ODR_LOW(GPIO_PC12_SDMMC_CLK) |        \
                                     PIN_ODR_LOW(GPIO_PC13_LCD_TOUCH_INT) |           \
                                     PIN_ODR_LOW(GPIO_PC14_OSC32_IN) |             \
                                     PIN_ODR_LOW(GPIO_PC15_OSC32_OUT))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIO_PC0_CONVERT_LPUART_RX, 8U) |          \
                                     PIN_AFIO_AF(GPIO_PC1_CONVERT_LPUART_TX, 8U) |          \
                                     PIN_AFIO_AF(GPIO_PC2, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PC3_KEYPAD_ENTER, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PC4_LCD_RST, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PC5_KEYPAD_ESCAPE, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PC6_RGB_1_BLUE, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PC7, 0U))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIO_PC8_SDMMC_D0, 12U) |   \
                                     PIN_AFIO_AF(GPIO_PC9_SDMMC_D1, 12U) |   \
                                     PIN_AFIO_AF(GPIO_PC10_SDMMC_D2, 12U) |   \
                                     PIN_AFIO_AF(GPIO_PC11_SDMMC_D3, 12U) |   \
                                     PIN_AFIO_AF(GPIO_PC12_SDMMC_CLK, 12U) |   \
                                     PIN_AFIO_AF(GPIO_PC13_LCD_TOUCH_INT, 0U) |       \
                                     PIN_AFIO_AF(GPIO_PC14_OSC32_IN, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PC15_OSC32_OUT, 0U))
#define VAL_GPIOC_ASCR              (PIN_ASCR_DISABLED(GPIO_PC0_CONVERT_LPUART_RX) |        \
                                     PIN_ASCR_DISABLED(GPIO_PC1_CONVERT_LPUART_TX) |        \
                                     PIN_ASCR_DISABLED(GPIO_PC2) |        \
                                     PIN_ASCR_DISABLED(GPIO_PC3_KEYPAD_ENTER) |        \
                                     PIN_ASCR_DISABLED(GPIO_PC4_LCD_RST) |        \
                                     PIN_ASCR_DISABLED(GPIO_PC5_KEYPAD_ESCAPE) |        \
                                     PIN_ASCR_DISABLED(GPIO_PC6_RGB_1_BLUE) |        \
                                     PIN_ASCR_DISABLED(GPIO_PC7) |        \
                                     PIN_ASCR_DISABLED(GPIO_PC8_SDMMC_D0) |  \
                                     PIN_ASCR_DISABLED(GPIO_PC9_SDMMC_D1) |  \
                                     PIN_ASCR_DISABLED(GPIO_PC10_SDMMC_D2) |  \
                                     PIN_ASCR_DISABLED(GPIO_PC11_SDMMC_D3) |  \
                                     PIN_ASCR_DISABLED(GPIO_PC12_SDMMC_CLK) |  \
                                     PIN_ASCR_DISABLED(GPIO_PC13_LCD_TOUCH_INT) |     \
                                     PIN_ASCR_DISABLED(GPIO_PC14_OSC32_IN) |       \
                                     PIN_ASCR_DISABLED(GPIO_PC15_OSC32_OUT))
#define VAL_GPIOC_LOCKR             (PIN_LOCKR_DISABLED(GPIO_PC0_CONVERT_LPUART_RX) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PC1_CONVERT_LPUART_TX) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PC2) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PC3_KEYPAD_ENTER) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PC4_LCD_RST) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PC5_KEYPAD_ESCAPE) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PC6_RGB_1_BLUE) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PC7) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PC8_SDMMC_D0) | \
                                     PIN_LOCKR_DISABLED(GPIO_PC9_SDMMC_D1) | \
                                     PIN_LOCKR_DISABLED(GPIO_PC10_SDMMC_D2) | \
                                     PIN_LOCKR_DISABLED(GPIO_PC11_SDMMC_D3) | \
                                     PIN_LOCKR_DISABLED(GPIO_PC12_SDMMC_CLK) | \
                                     PIN_LOCKR_DISABLED(GPIO_PC13_LCD_TOUCH_INT) |    \
                                     PIN_LOCKR_DISABLED(GPIO_PC14_OSC32_IN) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PC15_OSC32_OUT))

/*
 * GPIOD setup:
 *
 * PD0  - Open                      ().
 * PD1  - Open                      ().
 * PD2  - SD CMD                    (Alternate 12).
 * PD3  - Open                      ().
 * PD4  - Open                      ().
 * PD5  - STLINK TX (USART2 TX)     (Alternate 7).
 * PD6  - STLINK RX (USART2 RX)     (Alternate 7).
 * PD7  - Open                      ().
 * PD8  - RS485 TX (USART3 TX)      (Alternate 7).
 * PD9  - RS485 RX (USART3 RX)      (Alternate 7).
 * PD10 - RS485 3V DE               ().
 * PD11 - RS485 3V RE               ().
 * PD12 - RGB 2 Red                 (Output Low).
 * PD13 - Open                      ().
 * PD14 - RS485 5V DE               ().
 * PD15 - RS485 5V RE               ().
 */
#define VAL_GPIOD_MODER             (PIN_MODE_ANALOG(GPIO_PD0) |          \
                                     PIN_MODE_ANALOG(GPIO_PD1) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PD2_SDMMC_CMD) |\
                                     PIN_MODE_ANALOG(GPIO_PD3) |          \
                                     PIN_MODE_ANALOG(GPIO_PD4) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PD5_STLINK_USART2_TX) |\
                                     PIN_MODE_ALTERNATE(GPIO_PD6_STLINK_USART2_RX) |\
                                     PIN_MODE_ANALOG(GPIO_PD7) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PD8_RS485_USART3_TX) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PD9_RS485_USART3_RX) |          \
                                     PIN_MODE_ANALOG(GPIO_PD10_RS485_3V_DE) |         \
                                     PIN_MODE_ANALOG(GPIO_PD11_RS485_3V_RE) |         \
                                     PIN_MODE_OUTPUT(GPIO_PD12_RGB_2_RED) |         \
                                     PIN_MODE_ANALOG(GPIO_PD13) |         \
                                     PIN_MODE_ANALOG(GPIO_PD14_RS485_5V_DE) |         \
                                     PIN_MODE_ANALOG(GPIO_PD15_RS485_5V_RE))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIO_PD0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD2_SDMMC_CMD) |\
                                     PIN_OTYPE_PUSHPULL(GPIO_PD3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD5_STLINK_USART2_TX) |\
                                     PIN_OTYPE_PUSHPULL(GPIO_PD6_STLINK_USART2_RX) |\
                                     PIN_OTYPE_PUSHPULL(GPIO_PD7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD8_RS485_USART3_TX) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD9_RS485_USART3_RX) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD10_RS485_3V_DE) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD11_RS485_3V_RE) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD12_RGB_2_RED) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD14_RS485_5V_DE) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PD15_RS485_5V_RE))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIO_PD0) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PD1) |       \
                                     PIN_OSPEED_HIGH(GPIO_PD2_SDMMC_CMD) |   \
                                     PIN_OSPEED_VERYLOW(GPIO_PD3) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PD4) |       \
                                     PIN_OSPEED_HIGH(GPIO_PD5_STLINK_USART2_TX) |\
                                     PIN_OSPEED_HIGH(GPIO_PD6_STLINK_USART2_RX) |\
                                     PIN_OSPEED_VERYLOW(GPIO_PD7) |       \
                                     PIN_OSPEED_HIGH(GPIO_PD8_RS485_USART3_TX) |       \
                                     PIN_OSPEED_HIGH(GPIO_PD9_RS485_USART3_RX) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PD10_RS485_3V_DE) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PD11_RS485_3V_RE) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PD12_RGB_2_RED) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PD13) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PD14_RS485_5V_DE) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PD15_RS485_5V_RE))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_FLOATING(GPIO_PD0) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PD1) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PD2_SDMMC_CMD) |\
                                     PIN_PUPDR_FLOATING(GPIO_PD3) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PD4) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PD5_STLINK_USART2_TX) |\
                                     PIN_PUPDR_FLOATING(GPIO_PD6_STLINK_USART2_RX) |\
                                     PIN_PUPDR_FLOATING(GPIO_PD7) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PD8_RS485_USART3_TX) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PD9_RS485_USART3_RX) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PD10_RS485_3V_DE) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PD11_RS485_3V_RE) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PD12_RGB_2_RED) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PD13) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PD14_RS485_5V_DE) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PD15_RS485_5V_RE))
#define VAL_GPIOD_ODR               (PIN_ODR_LOW(GPIO_PD0) |              \
                                     PIN_ODR_LOW(GPIO_PD1) |              \
                                     PIN_ODR_LOW(GPIO_PD2_SDMMC_CMD) |       \
                                     PIN_ODR_LOW(GPIO_PD3) |              \
                                     PIN_ODR_LOW(GPIO_PD4) |              \
                                     PIN_ODR_LOW(GPIO_PD5_STLINK_USART2_TX) |  \
                                     PIN_ODR_LOW(GPIO_PD6_STLINK_USART2_RX) |  \
                                     PIN_ODR_LOW(GPIO_PD7) |              \
                                     PIN_ODR_LOW(GPIO_PD8_RS485_USART3_TX) |              \
                                     PIN_ODR_LOW(GPIO_PD9_RS485_USART3_RX) |              \
                                     PIN_ODR_LOW(GPIO_PD10_RS485_3V_DE) |             \
                                     PIN_ODR_LOW(GPIO_PD11_RS485_3V_RE) |             \
                                     PIN_ODR_LOW(GPIO_PD12_RGB_2_RED) |             \
                                     PIN_ODR_LOW(GPIO_PD13) |             \
                                     PIN_ODR_LOW(GPIO_PD14_RS485_5V_DE) |             \
                                     PIN_ODR_LOW(GPIO_PD15_RS485_5V_RE))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIO_PD0, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PD1, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PD2_SDMMC_CMD, 12U) |  \
                                     PIN_AFIO_AF(GPIO_PD3, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PD4, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PD5_STLINK_USART2_TX, 7U) |\
                                     PIN_AFIO_AF(GPIO_PD6_STLINK_USART2_RX, 7U) |\
                                     PIN_AFIO_AF(GPIO_PD7, 0U))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIO_PD8_RS485_USART3_TX, 7U) |          \
                                     PIN_AFIO_AF(GPIO_PD9_RS485_USART3_RX, 7U) |          \
                                     PIN_AFIO_AF(GPIO_PD10_RS485_3V_DE, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PD11_RS485_3V_RE, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PD12_RGB_2_RED, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PD13, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PD14_RS485_5V_DE, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PD15_RS485_5V_RE, 0U))
#define VAL_GPIOD_ASCR              (PIN_ASCR_DISABLED(GPIO_PD0) |        \
                                     PIN_ASCR_DISABLED(GPIO_PD1) |        \
                                     PIN_ASCR_DISABLED(GPIO_PD2_SDMMC_CMD) | \
                                     PIN_ASCR_DISABLED(GPIO_PD3) |        \
                                     PIN_ASCR_DISABLED(GPIO_PD4) |        \
                                     PIN_ASCR_DISABLED(GPIO_PD5_STLINK_USART2_TX) |\
                                     PIN_ASCR_DISABLED(GPIO_PD6_STLINK_USART2_RX) |\
                                     PIN_ASCR_DISABLED(GPIO_PD7) |        \
                                     PIN_ASCR_DISABLED(GPIO_PD8_RS485_USART3_TX) |        \
                                     PIN_ASCR_DISABLED(GPIO_PD9_RS485_USART3_RX) |        \
                                     PIN_ASCR_DISABLED(GPIO_PD10_RS485_3V_DE) |       \
                                     PIN_ASCR_DISABLED(GPIO_PD11_RS485_3V_RE) |       \
                                     PIN_ASCR_DISABLED(GPIO_PD12_RGB_2_RED) |       \
                                     PIN_ASCR_DISABLED(GPIO_PD13) |       \
                                     PIN_ASCR_DISABLED(GPIO_PD14_RS485_5V_DE) |       \
                                     PIN_ASCR_DISABLED(GPIO_PD15_RS485_5V_RE))
#define VAL_GPIOD_LOCKR             (PIN_LOCKR_DISABLED(GPIO_PD0) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PD1) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PD2_SDMMC_CMD) |\
                                     PIN_LOCKR_DISABLED(GPIO_PD3) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PD4) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PD5_STLINK_USART2_TX) |\
                                     PIN_LOCKR_DISABLED(GPIO_PD6_STLINK_USART2_RX) |\
                                     PIN_LOCKR_DISABLED(GPIO_PD7) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PD8_RS485_USART3_TX) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PD9_RS485_USART3_RX) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PD10_RS485_3V_DE) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PD11_RS485_3V_RE) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PD12_RGB_2_RED) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PD13) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PD14_RS485_5V_DE) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PD15_RS485_5V_RE))

/*
 * GPIOE setup:
 *
 * PE0  - Keypad Up                 (Input Pullup).
 * PE1  - Keypad Down               (Input Pullup).
 * PE2  - Container Enable          (Output Low).
 * PE3  - Container NO              (Input).
 * PE4  - Container NC              (Input).
 * PE5  - Open               ().
 * PE6  - Battery Control INT       (Input ).              (Wakeup)
 * PE7  - GPRS Reset                (Output ).
 * PE8  - LTE Power Enable          (Output Low).
 * PE9  - GNSS Geofence             (Input ).
 * PE10 - GNSS Power Enable         (Output Low).
 * PE11 - Keypad Left               (Input Pullup).
 * PE12 - GNSS V Backup Enable      (Output Low).
 * PE13 - SPI1 SCK                  (Alternate 5).
 * PE14 - SPI1 MISO                 (Alternate 5).
 * PE15 - SPI1 MOSI                 (Alternate 5).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_INPUT(GPIO_PE0_KEYPAD_UP) |          \
                                     PIN_MODE_INPUT(GPIO_PE1_KEYPAD_DOWN) |          \
                                     PIN_MODE_OUTPUT(GPIO_PE2_CONTAINER_EN) |          \
                                     PIN_MODE_ANALOG(GPIO_PE3_CONTAINER_NO) |          \
                                     PIN_MODE_ANALOG(GPIO_PE4_CONTAINER_NC) |          \
                                     PIN_MODE_ANALOG(GPIO_PE5) |          \
                                     PIN_MODE_ANALOG(GPIO_PE6_BATTERY_INT) |          \
                                     PIN_MODE_ANALOG(GPIO_PE7_GPRS_RST) |          \
                                     PIN_MODE_OUTPUT(GPIO_PE8_GPRS_PWR_EN) |          \
                                     PIN_MODE_ANALOG(GPIO_PE9_GNSS_GEOFENCE) |          \
                                     PIN_MODE_OUTPUT(GPIO_PE10_GNSS_PWR_EN) |         \
                                     PIN_MODE_INPUT(GPIO_PE11_KEYPAD_LEFT) |         \
                                     PIN_MODE_OUTPUT(GPIO_PE12_GNSS_VBCKP_EN) |         \
                                     PIN_MODE_ALTERNATE(GPIO_PE13_SPI1_SCK) |         \
                                     PIN_MODE_ALTERNATE(GPIO_PE14_SPI1_MISO) |         \
                                     PIN_MODE_ALTERNATE(GPIO_PE15_SPI1_MOSI))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIO_PE0_KEYPAD_UP) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE1_KEYPAD_DOWN) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE2_CONTAINER_EN) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE3_CONTAINER_NO) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE4_CONTAINER_NC) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE6_BATTERY_INT) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE7_GPRS_RST) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE8_GPRS_PWR_EN) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE9_GNSS_GEOFENCE) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE10_GNSS_PWR_EN) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE11_KEYPAD_LEFT) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE12_GNSS_VBCKP_EN) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE13_SPI1_SCK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE14_SPI1_MISO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PE15_SPI1_MOSI))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIO_PE0_KEYPAD_UP) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE1_KEYPAD_DOWN) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE2_CONTAINER_EN) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE3_CONTAINER_NO) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE4_CONTAINER_NC) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE5) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE6_BATTERY_INT) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE7_GPRS_RST) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE8_GPRS_PWR_EN) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE9_GNSS_GEOFENCE) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PE10_GNSS_PWR_EN) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PE11_KEYPAD_LEFT) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PE12_GNSS_VBCKP_EN) |      \
                                     PIN_OSPEED_HIGH(GPIO_PE13_SPI1_SCK) |      \
                                     PIN_OSPEED_HIGH(GPIO_PE14_SPI1_MISO) |      \
                                     PIN_OSPEED_HIGH(GPIO_PE15_SPI1_MOSI))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_PULLUP(GPIO_PE0_KEYPAD_UP) |       \
                                     PIN_PUPDR_PULLUP(GPIO_PE1_KEYPAD_DOWN) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PE2_CONTAINER_EN) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PE3_CONTAINER_NO) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PE4_CONTAINER_NC) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PE5) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PE6_BATTERY_INT) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PE7_GPRS_RST) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PE8_GPRS_PWR_EN) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PE9_GNSS_GEOFENCE) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PE10_GNSS_PWR_EN) |      \
                                     PIN_PUPDR_PULLUP(GPIO_PE11_KEYPAD_LEFT) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PE12_GNSS_VBCKP_EN) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PE13_SPI1_SCK) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PE14_SPI1_MISO) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PE15_SPI1_MOSI))
#define VAL_GPIOE_ODR               (PIN_ODR_LOW(GPIO_PE0_KEYPAD_UP) |              \
                                     PIN_ODR_LOW(GPIO_PE1_KEYPAD_DOWN) |              \
                                     PIN_ODR_LOW(GPIO_PE2_CONTAINER_EN) |              \
                                     PIN_ODR_LOW(GPIO_PE3_CONTAINER_NO) |              \
                                     PIN_ODR_LOW(GPIO_PE4_CONTAINER_NC) |              \
                                     PIN_ODR_LOW(GPIO_PE5) |              \
                                     PIN_ODR_LOW(GPIO_PE6_BATTERY_INT) |              \
                                     PIN_ODR_LOW(GPIO_PE7_GPRS_RST) |              \
                                     PIN_ODR_LOW(GPIO_PE8_GPRS_PWR_EN) |              \
                                     PIN_ODR_LOW(GPIO_PE9_GNSS_GEOFENCE) |              \
                                     PIN_ODR_LOW(GPIO_PE10_GNSS_PWR_EN) |             \
                                     PIN_ODR_LOW(GPIO_PE11_KEYPAD_LEFT) |             \
                                     PIN_ODR_LOW(GPIO_PE12_GNSS_VBCKP_EN) |             \
                                     PIN_ODR_LOW(GPIO_PE13_SPI1_SCK) |             \
                                     PIN_ODR_LOW(GPIO_PE14_SPI1_MISO) |             \
                                     PIN_ODR_LOW(GPIO_PE15_SPI1_MOSI))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIO_PE0_KEYPAD_UP, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PE1_KEYPAD_DOWN, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PE2_CONTAINER_EN, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PE3_CONTAINER_NO, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PE4_CONTAINER_NC, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PE5, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PE6_BATTERY_INT, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PE7_GPRS_RST, 0U))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIO_PE8_GPRS_PWR_EN, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PE9_GNSS_GEOFENCE, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PE10_GNSS_PWR_EN, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PE11_KEYPAD_LEFT, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PE12_GNSS_VBCKP_EN, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PE13_SPI1_SCK, 5U) |         \
                                     PIN_AFIO_AF(GPIO_PE14_SPI1_MISO, 5U) |         \
                                     PIN_AFIO_AF(GPIO_PE15_SPI1_MOSI, 5U))
#define VAL_GPIOE_ASCR              (PIN_ASCR_DISABLED(GPIO_PE0_KEYPAD_UP) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE1_KEYPAD_DOWN) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE2_CONTAINER_EN) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE3_CONTAINER_NO) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE4_CONTAINER_NC) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE5) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE6_BATTERY_INT) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE7_GPRS_RST) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE8_GPRS_PWR_EN) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE9_GNSS_GEOFENCE) |        \
                                     PIN_ASCR_DISABLED(GPIO_PE10_GNSS_PWR_EN) |       \
                                     PIN_ASCR_DISABLED(GPIO_PE11_KEYPAD_LEFT) |       \
                                     PIN_ASCR_DISABLED(GPIO_PE12_GNSS_VBCKP_EN) |       \
                                     PIN_ASCR_DISABLED(GPIO_PE13_SPI1_SCK) |       \
                                     PIN_ASCR_DISABLED(GPIO_PE14_SPI1_MISO) |       \
                                     PIN_ASCR_DISABLED(GPIO_PE15_SPI1_MOSI))
#define VAL_GPIOE_LOCKR             (PIN_LOCKR_DISABLED(GPIO_PE0_KEYPAD_UP) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE1_KEYPAD_DOWN) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE2_CONTAINER_EN) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE3_CONTAINER_NO) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE4_CONTAINER_NC) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE5) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE6_BATTERY_INT) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE7_GPRS_RST) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE8_GPRS_PWR_EN) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE9_GNSS_GEOFENCE) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PE10_GNSS_PWR_EN) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PE11_KEYPAD_LEFT) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PE12_GNSS_VBCKP_EN) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PE13_SPI1_SCK) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PE14_SPI1_MISO) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PE15_SPI1_MOSI))

/*
 * GPIOF setup:
 *
 * PF0  - SRAM SIO0                 (Alternate 5).
 * PF1  - SRAM SIO1                 (Alternate 5).
 * PF2  - SRAM SIO2                 (Alternate 5).
 * PF3  - SRAM SIO3                 (Alternate 5).
 * PF4  - SRAM CLK                  (Alternate 5).
 * PF5  - Battery Control Charge EN (Output ).
 * PF6  - Flash SIO3                (Alternate 10).
 * PF7  - Flash SIO2                (Alternate 10).
 * PF8  - Flash SIO0                (Alternate 10).
 * PF9  - Flash SIO1                (Alternate 10).
 * PF10 - Flash CLK                 (Alternate 3).
 * PF11 - LCD DC                    (Output ).
 * PF12 - LCD CS                    (Output ).
 * PF13 - GNSS 3D Fix               (Input ).
 * PF14 - i2c4 SCL                  (Alternate 4).
 * PF15 - i2c4 SDA                  (Alternate 4).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_ALTERNATE(GPIO_PF0_SRAM_SIO0) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PF1_SRAM_SIO1) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PF2_SRAM_SIO2) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PF3_SRAM_SIO3) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PF4_SRAM_CLK) |          \
                                     PIN_MODE_ANALOG(GPIO_PF5_BATTERY_CHRG_EN) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PF6_FLASH_SIO3) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PF7_FLASH_SIO2) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PF8_FLASH_SIO0) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PF9_FLASH_SIO1) |          \
                                     PIN_MODE_ALTERNATE(GPIO_PF10_FLASH_CLK) |         \
                                     PIN_MODE_ANALOG(GPIO_PF11_LCD_DC) |         \
                                     PIN_MODE_ANALOG(GPIO_PF12_LCD_CS) |         \
                                     PIN_MODE_ANALOG(GPIO_PF13_GNSS_3D_FIX) |         \
                                     PIN_MODE_ALTERNATE(GPIO_PF14_I2C4_SCL) |         \
                                     PIN_MODE_ALTERNATE(GPIO_PF15_I2C4_SDA))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIO_PF0_SRAM_SIO0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF1_SRAM_SIO1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF2_SRAM_SIO2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF3_SRAM_SIO3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF4_SRAM_CLK) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF5_BATTERY_CHRG_EN) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF6_FLASH_SIO3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF7_FLASH_SIO2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF8_FLASH_SIO0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF9_FLASH_SIO1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF10_FLASH_CLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF11_LCD_DC) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF12_LCD_CS) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF13_GNSS_3D_FIX) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF14_I2C4_SCL) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PF15_I2C4_SDA))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_HIGH(GPIO_PF0_SRAM_SIO0) |       \
                                     PIN_OSPEED_HIGH(GPIO_PF1_SRAM_SIO1) |       \
                                     PIN_OSPEED_HIGH(GPIO_PF2_SRAM_SIO2) |       \
                                     PIN_OSPEED_HIGH(GPIO_PF3_SRAM_SIO3) |       \
                                     PIN_OSPEED_HIGH(GPIO_PF4_SRAM_CLK) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PF5_BATTERY_CHRG_EN) |       \
                                     PIN_OSPEED_HIGH(GPIO_PF6_FLASH_SIO3) |       \
                                     PIN_OSPEED_HIGH(GPIO_PF7_FLASH_SIO2) |       \
                                     PIN_OSPEED_HIGH(GPIO_PF8_FLASH_SIO0) |       \
                                     PIN_OSPEED_HIGH(GPIO_PF9_FLASH_SIO1) |       \
                                     PIN_OSPEED_HIGH(GPIO_PF10_FLASH_CLK) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PF11_LCD_DC) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PF12_LCD_CS) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PF13_GNSS_3D_FIX) |      \
                                     PIN_OSPEED_HIGH(GPIO_PF14_I2C4_SCL) |      \
                                     PIN_OSPEED_HIGH(GPIO_PF15_I2C4_SDA))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_FLOATING(GPIO_PF0_SRAM_SIO0) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF1_SRAM_SIO1) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF2_SRAM_SIO2) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF3_SRAM_SIO3) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF4_SRAM_CLK) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF5_BATTERY_CHRG_EN) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF6_FLASH_SIO3) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF7_FLASH_SIO2) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF8_FLASH_SIO0) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF9_FLASH_SIO1) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PF10_FLASH_CLK) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PF11_LCD_DC) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PF12_LCD_CS) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PF13_GNSS_3D_FIX) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PF14_I2C4_SCL) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PF15_I2C4_SDA))
#define VAL_GPIOF_ODR               (PIN_ODR_LOW(GPIO_PF0_SRAM_SIO0) |              \
                                     PIN_ODR_LOW(GPIO_PF1_SRAM_SIO1) |              \
                                     PIN_ODR_LOW(GPIO_PF2_SRAM_SIO2) |              \
                                     PIN_ODR_LOW(GPIO_PF3_SRAM_SIO3) |              \
                                     PIN_ODR_LOW(GPIO_PF4_SRAM_CLK) |              \
                                     PIN_ODR_LOW(GPIO_PF5_BATTERY_CHRG_EN) |              \
                                     PIN_ODR_LOW(GPIO_PF6_FLASH_SIO3) |              \
                                     PIN_ODR_LOW(GPIO_PF7_FLASH_SIO2) |              \
                                     PIN_ODR_LOW(GPIO_PF8_FLASH_SIO0) |              \
                                     PIN_ODR_LOW(GPIO_PF9_FLASH_SIO1) |              \
                                     PIN_ODR_LOW(GPIO_PF10_FLASH_CLK) |             \
                                     PIN_ODR_LOW(GPIO_PF11_LCD_DC) |             \
                                     PIN_ODR_LOW(GPIO_PF12_LCD_CS) |             \
                                     PIN_ODR_LOW(GPIO_PF13_GNSS_3D_FIX) |             \
                                     PIN_ODR_LOW(GPIO_PF14_I2C4_SCL) |             \
                                     PIN_ODR_LOW(GPIO_PF15_I2C4_SDA))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIO_PF0_SRAM_SIO0, 5U) |          \
                                     PIN_AFIO_AF(GPIO_PF1_SRAM_SIO1, 5U) |          \
                                     PIN_AFIO_AF(GPIO_PF2_SRAM_SIO2, 5U) |          \
                                     PIN_AFIO_AF(GPIO_PF3_SRAM_SIO3, 5U) |          \
                                     PIN_AFIO_AF(GPIO_PF4_SRAM_CLK, 5U) |          \
                                     PIN_AFIO_AF(GPIO_PF5_BATTERY_CHRG_EN, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PF6_FLASH_SIO3, 10U) |          \
                                     PIN_AFIO_AF(GPIO_PF7_FLASH_SIO2, 10U))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIO_PF8_FLASH_SIO0, 10U) |          \
                                     PIN_AFIO_AF(GPIO_PF9_FLASH_SIO1, 10U) |          \
                                     PIN_AFIO_AF(GPIO_PF10_FLASH_CLK, 3U) |         \
                                     PIN_AFIO_AF(GPIO_PF11_LCD_DC, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PF12_LCD_CS, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PF13_GNSS_3D_FIX, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PF14_I2C4_SCL, 4U) |         \
                                     PIN_AFIO_AF(GPIO_PF15_I2C4_SDA, 4U))
#define VAL_GPIOF_ASCR              (PIN_ASCR_DISABLED(GPIO_PF0_SRAM_SIO0) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF1_SRAM_SIO1) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF2_SRAM_SIO2) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF3_SRAM_SIO3) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF4_SRAM_CLK) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF5_BATTERY_CHRG_EN) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF6_FLASH_SIO3) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF7_FLASH_SIO2) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF8_FLASH_SIO0) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF9_FLASH_SIO1) |        \
                                     PIN_ASCR_DISABLED(GPIO_PF10_FLASH_CLK) |       \
                                     PIN_ASCR_DISABLED(GPIO_PF11_LCD_DC) |       \
                                     PIN_ASCR_DISABLED(GPIO_PF12_LCD_CS) |       \
                                     PIN_ASCR_DISABLED(GPIO_PF13_GNSS_3D_FIX) |       \
                                     PIN_ASCR_DISABLED(GPIO_PF14_I2C4_SCL) |       \
                                     PIN_ASCR_DISABLED(GPIO_PF15_I2C4_SDA))
#define VAL_GPIOF_LOCKR             (PIN_LOCKR_DISABLED(GPIO_PF0_SRAM_SIO0) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF1_SRAM_SIO1) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF2_SRAM_SIO2) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF3_SRAM_SIO3) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF4_SRAM_CLK) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF5_BATTERY_CHRG_EN) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF6_FLASH_SIO3) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF7_FLASH_SIO2) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF8_FLASH_SIO0) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF9_FLASH_SIO1) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PF10_FLASH_CLK) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PF11_LCD_DC) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PF12_LCD_CS) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PF13_GNSS_3D_FIX) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PF14_I2C4_SCL) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PF15_I2C4_SDA))

/*
 * GPIOG setup:
 *
 * PG0  - CHAR LCD D0              (Output ).
 * PG1  - CHAR LCD D1              (Output ).
 * PG2  - CHAR LCD D2              (Output ).
 * PG3  - CHAR LCD D3              (Output ).
 * PG4  - CHAR LCD D4              (Output ).
 * PG5  - CHAR LCD D5              (Output ).
 * PG6  - CHAR LCD D6              (Output ).
 * PG7  - CHAR LCD D7              (Output ).
 * PG8  - LCD RS                   (Output ).
 * PG9  - LCD RW                   (Output ).
 * PG10 - LCD EN                   (Output ).
 * PG11 - GPRS PWRKEY              (Output ).
 * PG12 - SRAM CE                  (Alternate 5).
 * PG13 - i2c1 SDA                 (Alternate 4).
 * PG14 - i2c1 SCL                 (Alternate 4).
 * PG15 - eInk Reset               (Ouput).
 */
#define VAL_GPIOG_MODER             (PIN_MODE_ANALOG(GPIO_PG0_CHARLCD_D0) |          \
                                     PIN_MODE_ANALOG(GPIO_PG1_CHARLCD_D1) |          \
                                     PIN_MODE_ANALOG(GPIO_PG2_CHARLCD_D2) |          \
                                     PIN_MODE_ANALOG(GPIO_PG3_CHARLCD_D3) |          \
                                     PIN_MODE_ANALOG(GPIO_PG4_CHARLCD_D4) |          \
                                     PIN_MODE_ANALOG(GPIO_PG5_CHARLCD_D5) |          \
                                     PIN_MODE_ANALOG(GPIO_PG6_CHARLCD_D6) |          \
                                     PIN_MODE_ANALOG(GPIO_PG7_CHARLCD_D7) |          \
                                     PIN_MODE_ANALOG(GPIO_PG8_CHARLCD_RS) |          \
                                     PIN_MODE_ANALOG(GPIO_PG9_CHARLCD_RW) |\
                                     PIN_MODE_ANALOG(GPIO_PG10_CHARLCD_EN) |\
                                     PIN_MODE_ANALOG(GPIO_PG11_GPRS_PWRKEY) |         \
                                     PIN_MODE_ALTERNATE(GPIO_PG12_SRAM_CE) |\
                                     PIN_MODE_ALTERNATE(GPIO_PG13_I2C1_SDA) |         \
                                     PIN_MODE_ALTERNATE(GPIO_PG14_I2C1_SCL) |         \
                                     PIN_MODE_OUTPUT(GPIO_PG15_EINK_RST))
#define VAL_GPIOG_OTYPER            (PIN_OTYPE_PUSHPULL(GPIO_PG0_CHARLCD_D0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG1_CHARLCD_D1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG2_CHARLCD_D2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG3_CHARLCD_D3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG4_CHARLCD_D4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG5_CHARLCD_D5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG6_CHARLCD_D6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG7_CHARLCD_D7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG8_CHARLCD_RS) |       \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG9_CHARLCD_RW) |\
                                     PIN_OTYPE_PUSHPULL(GPIO_PG10_CHARLCD_EN) |\
                                     PIN_OTYPE_PUSHPULL(GPIO_PG11_GPRS_PWRKEY) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG12_SRAM_CE) |\
                                     PIN_OTYPE_PUSHPULL(GPIO_PG13_I2C1_SDA) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG14_I2C1_SCL) |      \
                                     PIN_OTYPE_PUSHPULL(GPIO_PG15_EINK_RST))
#define VAL_GPIOG_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIO_PG0_CHARLCD_D0) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PG1_CHARLCD_D1) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PG2_CHARLCD_D2) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PG3_CHARLCD_D3) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PG4_CHARLCD_D4) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PG5_CHARLCD_D5) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PG6_CHARLCD_D6) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PG7_CHARLCD_D7) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PG8_CHARLCD_RS) |       \
                                     PIN_OSPEED_VERYLOW(GPIO_PG9_CHARLCD_RW) |\
                                     PIN_OSPEED_VERYLOW(GPIO_PG10_CHARLCD_EN) |\
                                     PIN_OSPEED_VERYLOW(GPIO_PG11_GPRS_PWRKEY) |      \
                                     PIN_OSPEED_HIGH(GPIO_PG12_SRAM_CE) |\
                                     PIN_OSPEED_HIGH(GPIO_PG13_I2C1_SDA) |      \
                                     PIN_OSPEED_HIGH(GPIO_PG14_I2C1_SCL) |      \
                                     PIN_OSPEED_VERYLOW(GPIO_PG15_EINK_RST))
#define VAL_GPIOG_PUPDR             (PIN_PUPDR_FLOATING(GPIO_PG0_CHARLCD_D0) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PG1_CHARLCD_D1) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PG2_CHARLCD_D2) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PG3_CHARLCD_D3) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PG4_CHARLCD_D4) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PG5_CHARLCD_D5) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PG6_CHARLCD_D6) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PG7_CHARLCD_D7) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PG8_CHARLCD_RS) |       \
                                     PIN_PUPDR_FLOATING(GPIO_PG9_CHARLCD_RW) |\
                                     PIN_PUPDR_FLOATING(GPIO_PG10_CHARLCD_EN) |\
                                     PIN_PUPDR_FLOATING(GPIO_PG11_GPRS_PWRKEY) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PG12_SRAM_CE) |\
                                     PIN_PUPDR_FLOATING(GPIO_PG13_I2C1_SDA) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PG14_I2C1_SCL) |      \
                                     PIN_PUPDR_FLOATING(GPIO_PG15_EINK_RST))
#define VAL_GPIOG_ODR               (PIN_ODR_LOW(GPIO_PG0_CHARLCD_D0) |              \
                                     PIN_ODR_LOW(GPIO_PG1_CHARLCD_D1) |              \
                                     PIN_ODR_LOW(GPIO_PG2_CHARLCD_D2) |              \
                                     PIN_ODR_LOW(GPIO_PG3_CHARLCD_D3) |              \
                                     PIN_ODR_LOW(GPIO_PG4_CHARLCD_D4) |              \
                                     PIN_ODR_LOW(GPIO_PG5_CHARLCD_D5) |              \
                                     PIN_ODR_LOW(GPIO_PG6_CHARLCD_D6) |              \
                                     PIN_ODR_LOW(GPIO_PG7_CHARLCD_D7) |              \
                                     PIN_ODR_LOW(GPIO_PG8_CHARLCD_RS) |              \
                                     PIN_ODR_LOW(GPIO_PG9_CHARLCD_RW) |   \
                                     PIN_ODR_LOW(GPIO_PG10_CHARLCD_EN) |   \
                                     PIN_ODR_LOW(GPIO_PG11_GPRS_PWRKEY) |             \
                                     PIN_ODR_LOW(GPIO_PG12_SRAM_CE) |   \
                                     PIN_ODR_LOW(GPIO_PG13_I2C1_SDA) |             \
                                     PIN_ODR_LOW(GPIO_PG14_I2C1_SCL) |             \
                                     PIN_ODR_LOW(GPIO_PG15_EINK_RST))
#define VAL_GPIOG_AFRL              (PIN_AFIO_AF(GPIO_PG0_CHARLCD_D0, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PG1_CHARLCD_D1, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PG2_CHARLCD_D2, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PG3_CHARLCD_D3, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PG4_CHARLCD_D4, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PG5_CHARLCD_D5, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PG6_CHARLCD_D6, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PG7_CHARLCD_D7, 0U))
#define VAL_GPIOG_AFRH              (PIN_AFIO_AF(GPIO_PG8_CHARLCD_RS, 0U) |          \
                                     PIN_AFIO_AF(GPIO_PG9_CHARLCD_RW, 0U) |\
                                     PIN_AFIO_AF(GPIO_PG10_CHARLCD_EN, 0U) |\
                                     PIN_AFIO_AF(GPIO_PG11_GPRS_PWRKEY, 0U) |         \
                                     PIN_AFIO_AF(GPIO_PG12_SRAM_CE, 5U) |\
                                     PIN_AFIO_AF(GPIO_PG13_I2C1_SDA, 4U) |         \
                                     PIN_AFIO_AF(GPIO_PG14_I2C1_SCL, 4U) |         \
                                     PIN_AFIO_AF(GPIO_PG15_EINK_RST, 0U))
#define VAL_GPIOG_ASCR              (PIN_ASCR_DISABLED(GPIO_PG0_CHARLCD_D0) |        \
                                     PIN_ASCR_DISABLED(GPIO_PG1_CHARLCD_D1) |        \
                                     PIN_ASCR_DISABLED(GPIO_PG2_CHARLCD_D2) |        \
                                     PIN_ASCR_DISABLED(GPIO_PG3_CHARLCD_D3) |        \
                                     PIN_ASCR_DISABLED(GPIO_PG4_CHARLCD_D4) |        \
                                     PIN_ASCR_DISABLED(GPIO_PG5_CHARLCD_D5) |        \
                                     PIN_ASCR_DISABLED(GPIO_PG6_CHARLCD_D6) |        \
                                     PIN_ASCR_DISABLED(GPIO_PG7_CHARLCD_D7) |        \
                                     PIN_ASCR_DISABLED(GPIO_PG8_CHARLCD_RS) |        \
                                     PIN_ASCR_DISABLED(GPIO_PG9_CHARLCD_RW) |\
                                     PIN_ASCR_DISABLED(GPIO_PG10_CHARLCD_EN) |\
                                     PIN_ASCR_DISABLED(GPIO_PG11_GPRS_PWRKEY) |       \
                                     PIN_ASCR_DISABLED(GPIO_PG12_SRAM_CE) |\
                                     PIN_ASCR_DISABLED(GPIO_PG13_I2C1_SDA) |       \
                                     PIN_ASCR_DISABLED(GPIO_PG14_I2C1_SCL) |       \
                                     PIN_ASCR_DISABLED(GPIO_PG15_EINK_RST))
#define VAL_GPIOG_LOCKR             (PIN_LOCKR_DISABLED(GPIO_PG0_CHARLCD_D0) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PG1_CHARLCD_D1) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PG2_CHARLCD_D2) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PG3_CHARLCD_D3) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PG4_CHARLCD_D4) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PG5_CHARLCD_D5) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PG6_CHARLCD_D6) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PG7_CHARLCD_D7) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PG8_CHARLCD_RS) |       \
                                     PIN_LOCKR_DISABLED(GPIO_PG9_CHARLCD_RW) |\
                                     PIN_LOCKR_DISABLED(GPIO_PG10_CHARLCD_EN) |\
                                     PIN_LOCKR_DISABLED(GPIO_PG11_GPRS_PWRKEY) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PG12_SRAM_CE) |\
                                     PIN_LOCKR_DISABLED(GPIO_PG13_I2C1_SDA) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PG14_I2C1_SCL) |      \
                                     PIN_LOCKR_DISABLED(GPIO_PG15_EINK_RST))

/*
 * GPIOH setup:
 *
 * PH0  - OSC_IN                    (analog).
 * PH1  - OSC_OUT                   (analog).
 * PH2  - PIN2                      (N/A).
 * PH3  - BOOT0                     (input floating).
 * PH4  - PIN4                      (N/A).
 * PH5  - PIN5                      (N/A).
 * PH6  - PIN6                      (N/A).
 * PH7  - PIN7                      (N/A).
 * PH8  - PIN8                      (N/A).
 * PH9  - PIN9                      (N/A).
 * PH10 - PIN10                     (N/A).
 * PH11 - PIN11                     (N/A).
 * PH12 - PIN12                     (N/A).
 * PH13 - PIN13                     (N/A).
 * PH14 - PIN14                     (N/A).
 * PH15 - PIN15                     (N/A).
 */

#define VAL_GPIOH_MODER             (PIN_MODE_ANALOG(GPIOH_OSC_IN) |        \
                                     PIN_MODE_ANALOG(GPIOH_OSC_OUT) |       \
                                     PIN_MODE_ANALOG(GPIOH_PIN2) |          \
                                     PIN_MODE_INPUT(GPIOH_BOOT0) |          \
                                     PIN_MODE_ANALOG(GPIOH_PIN4) |           \
                                     PIN_MODE_ANALOG(GPIOH_PIN5) |          \
                                     PIN_MODE_ANALOG(GPIOH_PIN6) |          \
                                     PIN_MODE_ANALOG(GPIOH_PIN7) |          \
                                     PIN_MODE_ANALOG(GPIOH_PIN8) |\
                                     PIN_MODE_ANALOG(GPIOH_PIN9) |\
                                     PIN_MODE_ANALOG(GPIOH_PIN10) |\
                                     PIN_MODE_ANALOG(GPIOH_PIN11) |         \
                                     PIN_MODE_ANALOG(GPIOH_PIN12) |         \
                                     PIN_MODE_ANALOG(GPIOH_PIN13) |         \
                                     PIN_MODE_ANALOG(GPIOH_PIN14) |         \
                                     PIN_MODE_ANALOG(GPIOH_PIN15))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOH_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOH_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_BOOT0) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN4) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN8) |\
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN9) |\
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN10) |\
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN15))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOH_OSC_IN) |     \
                                     PIN_OSPEED_VERYLOW(GPIOH_OSC_OUT) |    \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_BOOT0) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN4) |           \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN8) |\
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN9) |\
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN10) |\
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN15))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_BOOT0) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN4) |        \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN8) |\
                                     PIN_PUPDR_FLOATING(GPIOH_PIN9) |\
                                     PIN_PUPDR_FLOATING(GPIOH_PIN10) |\
                                     PIN_PUPDR_FLOATING(GPIOH_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN15))
#define VAL_GPIOH_ODR               (PIN_ODR_LOW(GPIOH_OSC_IN) |            \
                                     PIN_ODR_LOW(GPIOH_OSC_OUT) |           \
                                     PIN_ODR_LOW(GPIOH_PIN2) |              \
                                     PIN_ODR_LOW(GPIOH_BOOT0) |             \
                                     PIN_ODR_LOW(GPIOH_PIN4) |              \
                                     PIN_ODR_LOW(GPIOH_PIN5) |              \
                                     PIN_ODR_LOW(GPIOH_PIN6) |              \
                                     PIN_ODR_LOW(GPIOH_PIN7) |              \
                                     PIN_ODR_LOW(GPIOH_PIN8) |   \
                                     PIN_ODR_LOW(GPIOH_PIN9) |   \
                                     PIN_ODR_LOW(GPIOH_PIN10) |   \
                                     PIN_ODR_LOW(GPIOH_PIN11) |             \
                                     PIN_ODR_LOW(GPIOH_PIN12) |             \
                                     PIN_ODR_LOW(GPIOH_PIN13) |             \
                                     PIN_ODR_LOW(GPIOH_PIN14) |             \
                                     PIN_ODR_LOW(GPIOH_PIN15))
#define VAL_GPIOH_AFRL              (PIN_AFIO_AF(GPIOH_OSC_IN, 0U) |        \
                                     PIN_AFIO_AF(GPIOH_OSC_OUT, 0U) |       \
                                     PIN_AFIO_AF(GPIOH_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_BOOT0, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN4, 0U) |           \
                                     PIN_AFIO_AF(GPIOH_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN7, 0U))
#define VAL_GPIOH_AFRH              (PIN_AFIO_AF(GPIOH_PIN8, 0U) |\
                                     PIN_AFIO_AF(GPIOH_PIN9, 0U) |\
                                     PIN_AFIO_AF(GPIOH_PIN10, 0U) |\
                                     PIN_AFIO_AF(GPIOH_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN15, 0U))
#define VAL_GPIOH_ASCR              (PIN_ASCR_DISABLED(GPIOH_OSC_IN) |      \
                                     PIN_ASCR_DISABLED(GPIOH_OSC_OUT) |     \
                                     PIN_ASCR_DISABLED(GPIOH_PIN2) |        \
                                     PIN_ASCR_DISABLED(GPIOH_BOOT0) |       \
                                     PIN_ASCR_DISABLED(GPIOH_PIN4) |         \
                                     PIN_ASCR_DISABLED(GPIOH_PIN5) |        \
                                     PIN_ASCR_DISABLED(GPIOH_PIN6) |        \
                                     PIN_ASCR_DISABLED(GPIOH_PIN7) |        \
                                     PIN_ASCR_DISABLED(GPIOH_PIN8) |\
                                     PIN_ASCR_DISABLED(GPIOH_PIN9) |\
                                     PIN_ASCR_DISABLED(GPIOH_PIN10) |\
                                     PIN_ASCR_DISABLED(GPIOH_PIN11) |       \
                                     PIN_ASCR_DISABLED(GPIOH_PIN12) |       \
                                     PIN_ASCR_DISABLED(GPIOH_PIN13) |       \
                                     PIN_ASCR_DISABLED(GPIOH_PIN14) |       \
                                     PIN_ASCR_DISABLED(GPIOH_PIN15))
#define VAL_GPIOH_LOCKR             (PIN_LOCKR_DISABLED(GPIOH_OSC_IN) |     \
                                     PIN_LOCKR_DISABLED(GPIOH_OSC_OUT) |    \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN2) |       \
                                     PIN_LOCKR_DISABLED(GPIOH_BOOT0) |      \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN4) |        \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN5) |       \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN6) |       \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN7) |       \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN8) |\
                                     PIN_LOCKR_DISABLED(GPIOH_PIN9) |\
                                     PIN_LOCKR_DISABLED(GPIOH_PIN10) |\
                                     PIN_LOCKR_DISABLED(GPIOH_PIN11) |      \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN12) |      \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN13) |      \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN14) |      \
                                     PIN_LOCKR_DISABLED(GPIOH_PIN15))

/*
 * GPIOI setup:
 *
 * PI0  - PIN0                      (N/A).
 * PI1  - PIN1                      (N/A).
 * PI2  - PIN2                      (N/A).
 * PI3  - PIN3                      (N/A).
 * PI4  - PIN4                      (N/A).
 * PI5  - PIN5                      (N/A).
 * PI6  - PIN6                      (N/A).
 * PI7  - PIN7                      (N/A).
 * PI8  - PIN8                      (N/A).
 * PI9  - PIN9                      (N/A).
 * PI10 - PIN10                     (N/A).
 * PI11 - PIN11                     (N/A).
 * PI12 - PIN12                     (N/A).
 * PI13 - PIN13                     (N/A).
 * PI14 - PIN14                     (N/A).
 * PI15 - PIN15                     (N/A).
 */
#define VAL_GPIOI_MODER             (PIN_MODE_ANALOG(GPIOI_PIN0) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN1) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN2) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN3) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN4) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN5) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN6) |\
                                     PIN_MODE_ANALOG(GPIOI_PIN7) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN8) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN9) |\
                                     PIN_MODE_ANALOG(GPIOI_PIN10) |\
                                     PIN_MODE_ANALOG(GPIOI_PIN11) |\
                                     PIN_MODE_ANALOG(GPIOI_PIN12) |         \
                                     PIN_MODE_ANALOG(GPIOI_PIN13) |         \
                                     PIN_MODE_ANALOG(GPIOI_PIN14) |         \
                                     PIN_MODE_ANALOG(GPIOI_PIN15))
#define VAL_GPIOI_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOI_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN6) |\
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN9) |\
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN10) |\
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN11) |\
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN15))
#define VAL_GPIOI_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOI_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN6) |\
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN9) |\
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN10) |\
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN11) |\
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN15))
#define VAL_GPIOI_PUPDR             (PIN_PUPDR_FLOATING(GPIOI_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN6) |\
                                     PIN_PUPDR_FLOATING(GPIOI_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN9) |\
                                     PIN_PUPDR_FLOATING(GPIOI_PIN10) |\
                                     PIN_PUPDR_FLOATING(GPIOI_PIN11) |\
                                     PIN_PUPDR_FLOATING(GPIOI_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN15))
#define VAL_GPIOI_ODR               (PIN_ODR_LOW(GPIOI_PIN0) |              \
                                     PIN_ODR_LOW(GPIOI_PIN1) |              \
                                     PIN_ODR_LOW(GPIOI_PIN2) |              \
                                     PIN_ODR_LOW(GPIOI_PIN3) |              \
                                     PIN_ODR_LOW(GPIOI_PIN4) |              \
                                     PIN_ODR_LOW(GPIOI_PIN5) |              \
                                     PIN_ODR_LOW(GPIOI_PIN6) |   \
                                     PIN_ODR_LOW(GPIOI_PIN7) |              \
                                     PIN_ODR_LOW(GPIOI_PIN8) |              \
                                     PIN_ODR_LOW(GPIOI_PIN9) |   \
                                     PIN_ODR_LOW(GPIOI_PIN10) |   \
                                     PIN_ODR_LOW(GPIOI_PIN11) |   \
                                     PIN_ODR_LOW(GPIOI_PIN12) |             \
                                     PIN_ODR_LOW(GPIOI_PIN13) |             \
                                     PIN_ODR_LOW(GPIOI_PIN14) |             \
                                     PIN_ODR_LOW(GPIOI_PIN15))
#define VAL_GPIOI_AFRL              (PIN_AFIO_AF(GPIOI_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN6, 0U) |\
                                     PIN_AFIO_AF(GPIOI_PIN7, 0U))
#define VAL_GPIOI_AFRH              (PIN_AFIO_AF(GPIOI_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN9, 0U) |\
                                     PIN_AFIO_AF(GPIOI_PIN10, 0U) |\
                                     PIN_AFIO_AF(GPIOI_PIN11, 0U) |\
                                     PIN_AFIO_AF(GPIOI_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN15, 0U))
#define VAL_GPIOI_ASCR              (PIN_ASCR_DISABLED(GPIOI_PIN0) |        \
                                     PIN_ASCR_DISABLED(GPIOI_PIN1) |        \
                                     PIN_ASCR_DISABLED(GPIOI_PIN2) |        \
                                     PIN_ASCR_DISABLED(GPIOI_PIN3) |        \
                                     PIN_ASCR_DISABLED(GPIOI_PIN4) |        \
                                     PIN_ASCR_DISABLED(GPIOI_PIN5) |        \
                                     PIN_ASCR_DISABLED(GPIOI_PIN6) |\
                                     PIN_ASCR_DISABLED(GPIOI_PIN7) |        \
                                     PIN_ASCR_DISABLED(GPIOI_PIN8) |        \
                                     PIN_ASCR_DISABLED(GPIOI_PIN9) |\
                                     PIN_ASCR_DISABLED(GPIOI_PIN10) |\
                                     PIN_ASCR_DISABLED(GPIOI_PIN11) |\
                                     PIN_ASCR_DISABLED(GPIOI_PIN12) |       \
                                     PIN_ASCR_DISABLED(GPIOI_PIN13) |       \
                                     PIN_ASCR_DISABLED(GPIOI_PIN14) |       \
                                     PIN_ASCR_DISABLED(GPIOI_PIN15))
#define VAL_GPIOI_LOCKR             (PIN_LOCKR_DISABLED(GPIOI_PIN0) |       \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN1) |       \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN2) |       \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN3) |       \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN4) |       \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN5) |       \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN6) |\
                                     PIN_LOCKR_DISABLED(GPIOI_PIN7) |       \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN8) |       \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN9) |\
                                     PIN_LOCKR_DISABLED(GPIOI_PIN10) |\
                                     PIN_LOCKR_DISABLED(GPIOI_PIN11) |\
                                     PIN_LOCKR_DISABLED(GPIOI_PIN12) |      \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN13) |      \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN14) |      \
                                     PIN_LOCKR_DISABLED(GPIOI_PIN15))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
