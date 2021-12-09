/*
 *******************************************************************************
 * Copyright (c) 2020-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#pragma once

/*----------------------------------------------------------------------------
 *        STM32 pins number
 *----------------------------------------------------------------------------*/


  //J22 Connector
#define PA0         0
#define PA1         1
#define PA2         2
#define PA3         3
#define PA4         4
#define PA5         5
#define PA6         6 
#define PA8         7
#define PA9         8
#define PA10        9
#define PA11        10
#define PA12        11
#define PA13        12

  //J23 Connector 
#define PD0        13
#define PD1        14
#define PD2        15
#define PD8        16
#define PD9        17
#define PD10       18
#define PD11       19
#define PD12       20
  //J24 Connector
#define PB0        21
#define PB1        22
#define PB2        23
#define PB5        24
#define PB6        25
#define PB7        26
#define PB8        27
#define PB9        28
#define PB12       29
#define PB13       30
  //J25 Connector
#define PE1        31
#define PE2        32
#define PE3        33
#define PE4        34
#define PE5        35
#define PE6        36
#define PE7        37
#define PE8        38
#define PE9        39
#define PE10       40
#define PE11       41
#define PE12       42
#define PE13       43
#define PE14       44
#define PE15       45
  //J26 Connector
#define PC0        46
#define PC1        47
#define PC2        48
#define PC3        49
#define PC4        50
#define PC5        51
#define PC6        52
#define PC7        53
#define PC8        54
#define PC9        55
#define PC10       56
#define PC11       57
#define PC12       58
#define PC13       59



#define NUM_DIGITAL_PINS        59
#define NUM_ANALOG_INPUTS       6

// On-board LED pin number
#define LED_BLUE1               PD_15 //ok
#define LED_BLUE2               PD_14 //ok
#ifndef LED_BUILTIN
  #define LED_BUILTIN           LED_BLUE1 //ok
#endif

// On-board user button
#ifndef USER_BTN
  #define USER_BTN              PD_13 //ok
#endif

// SPI Definitions
#ifndef PIN_SPI_SS
  #define PIN_SPI_SS            PB12 //ok
#endif
#ifndef PIN_SPI_SS1
  #define PIN_SPI_SS1           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS2
  #define PIN_SPI_SS2           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS3
  #define PIN_SPI_SS3           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_MOSI
  #define PIN_SPI_MOSI          PC3 //ok
#endif
#ifndef PIN_SPI_MISO
  #define PIN_SPI_MISO          PC2 //ok
#endif
#ifndef PIN_SPI_SCK
  #define PIN_SPI_SCK           PB13 //ok
#endif

// I2C Definitions
#ifndef PIN_WIRE_SDA
  #define PIN_WIRE_SDA          PB9 //ok
#endif
#ifndef PIN_WIRE_SCL
  #define PIN_WIRE_SCL          PB8 //ok
#endif

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM6 //ok
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM7 //ok
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
  #define SERIAL_UART_INSTANCE  1 //Connected to ST-Link //ok
#endif

// Default pin used for 'Serial' instance (ex: ST-Link)
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
  #define PIN_SERIAL_RX         PA10 //ok
#endif
#ifndef PIN_SERIAL_TX
  #define PIN_SERIAL_TX         PA9 //ok
#endif

/* Extra HAL modules */
#if !defined(HAL_DAC_MODULE_DISABLED)
  #define HAL_DAC_MODULE_ENABLED
#endif
#if !defined(HAL_SD_MODULE_DISABLED)
  #define HAL_SD_MODULE_ENABLED
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial
  #endif
#endif
