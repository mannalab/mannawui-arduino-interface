/*
 *******************************************************************************
 * Copyright (c) 2019, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif


#define PA0
#define PA1
#define PA3
#define PA4
#define PA5
#define PA6
#define PA7
#define PA8
#define PA9
#define PA10
#define PA11
#define PA12
#define PA15

#define PB0
#define PB1
#define PB2
#define PB5
#define PB6
#define PB7
#define PB8
#define PB9
#define PB12
#define PB13

#define PC0
#define PC1
#define PC3
#define PC4
#define PC5
#define PC6
#define PC7
#define PC8
#define PC9
#define PC10
#define PC11
#define PC12
#define PC13

#define PD0
#define PD1
#define PD2
#define PD8
#define PD9
#define PD10
#define PD11
#define PD12

#define PE1
#define PE2
#define PE3
#define PE4
#define PE5
#define PE6
#define PE7
#define PE8
#define PE9
#define PE10
#define PE11
#define PE12
#define PE13
#define PE14
#define PE15 
  



// Digital PinName array
// This array allows to wrap Arduino pin number(Dx or x)
// to STM32 PinName (PX_n)
const PinName digitalPin[] = {
  //PX_n, //Dx
  PA_0,   // Digital pin 0
  PA_1,   // Digital pin 1
  PA_2,   // Digital pin 2
  PA_3,   // Digital pin 3
  PA_4,   // Digital pin 4
  PA_5,   // Digital pin 5
  PA_6,   // Digital pin 6
  PA_8,   // Digital pin 7
  PA_9,   // Digital pin 8
  PA_10,  // Digital pin 9
  PA_11,  // Digital pin 10
  PA_12,  // Digital pin 11
  PA_15,  // Digital pin 12

  PB_0,   // Digital pin 13
  PB_1,   // Digital pin 14
  PB_2,   // Digital pin 15
  PB_5,   // Digital pin 16
  PB_6,   // Digital pin 17
  PB_7,   // Digital pin 18
  PB_8,   // Digital pin 19
  PB_9,   // Digital pin 20
  PB_12,  // Digital pin 21
  PB_13,  // Digital pin 22

  PC_0,   // Digital pin 23
  PC_1,   // Digital pin 24
  PC_2,   // Digital pin 25
  PC_3,   // Digital pin 26
  PC_4,   // Digital pin 27
  PC_5,   // Digital pin 28
  PC_6,   // Digital pin 29
  PC_7,   // Digital pin 30
  PC_8,   // Digital pin 31
  PC_9,   // Digital pin 32
  PC_10,  // Digital pin 33
  PC_11,  // Digital pin 34
  PC_12,  // Digital pin 35
  PC_13,  // Digital pin 36

  PD_0,   // Digital pin 37
  PD_1,   // Digital pin 38
  PD_2,   // Digital pin 39
  PD_8,   // Digital pin 40
  PD_9,   // Digital pin 41
  PD_10,  // Digital pin 42
  PD_11,  // Digital pin 43
  PD_12,  // Digital pin 44

  PE_1,   // Digital pin 45
  PE_2,   // Digital pin 46
  PE_3,   // Digital pin 47
  PE_4,   // Digital pin 48
  PE_5,   // Digital pin 49
  PE_6,   // Digital pin 50
  PE_7,   // Digital pin 51
  PE_8,   // Digital pin 52
  PE_9,   // Digital pin 53
  PE_10,  // Digital pin 54
  PE_11,  // Digital pin 55
  PE_12,  // Digital pin 56
  PE_13,  // Digital pin 57
  PE_14,  // Digital pin 58
  PE_15   // Digital pin 59
};

// If analog pins are not contiguous in the digitalPin array:
// Add the analogInputPin array without defining NUM_ANALOG_FIRST
// Analog (Ax) pin number array
// where x is the index to retrieve the digital pin number
const uint32_t analogInputPin[] = {
  //PXn, //Ax = Dx
  0,  //PA0 
  1,  //PA1 
  2,  //PA2
  3,  //PA3
  4,  //PA5
  13  //PB0
}

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    while(1)
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    while(1)
  }
}

#ifdef __cplusplus
}






#endif
