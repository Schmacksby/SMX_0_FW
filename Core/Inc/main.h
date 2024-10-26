/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
/*
typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} GPIO_Pin;

extern GPIO_Pin rowsToIterate[];
extern GPIO_Pin colsToIterate[];

extern const size_t rowsToIterateSize;
extern const size_t colsToIterateSize;

extern volatile uint8_t matrix_current[rowsToIterateSize][colsToIterateSize];
extern volatile uint8_t matrix_previous[rowsToIterateSize][colsToIterateSize];
*/
void check_matrix(void);


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */
/*
#define ROWS 5
#define COLS 15
//ROW Pin Definitions
#define ROW0_PIN GPIO_PIN_3
#define ROW0_PORT GPIOB
#define ROW1_PIN GPIO_PIN_4
#define ROW1_PORT GPIOB
#define ROW2_PIN GPIO_PIN_5
#define ROW2_PORT GPIOB
#define ROW3_PIN GPIO_PIN_8
#define ROW3_PORT GPIOB
#define ROW4_PIN GPIO_PIN_9
#define ROW4_PORT GPIOB
//COL Pin Definitions
#define COL0_PIN GPIO_PIN_0
#define COL0_PORT GPIOA
#define COL1_PIN GPIO_PIN_1
#define COL1_PORT GPIOA
#define COL2_PIN GPIO_PIN_2
#define COL2_PORT GPIOA
#define COL3_PIN GPIO_PIN_3
#define COL3_PORT GPIOA
#define COL4_PIN GPIO_PIN_4
#define COL4_PORT GPIOA
#define COL5_PIN GPIO_PIN_5
#define COL5_PORT GPIOA
#define COL6_PIN GPIO_PIN_6
#define COL6_PORT GPIOA
#define COL7_PIN GPIO_PIN_7
#define COL7_PORT GPIOA
#define COL8_PIN GPIO_PIN_8
#define COL8_PORT GPIOA
#define COL9_PIN GPIO_PIN_9
#define COL9_PORT GPIOA
#define COL10_PIN GPIO_PIN_10
#define COL10_PORT GPIOA
#define COL11_PIN GPIO_PIN_10
#define COL11_PORT GPIOB
#define COL12_PIN GPIO_PIN_11
#define COL12_PORT GPIOB
#define COL13_PIN GPIO_PIN_15
#define COL13_PORT GPIOA
#define COL14_PIN GPIO_PIN_15
#define COL14_PORT GPIOB
//Rotary Switch Defines
#define ROT_A_PIN GPIO_PIN_7
#define ROT_A_PORT GPIOB
#define ROT_B_PIN GPIO_PIN_6
#define ROT_B_PORT GPIOB
#define ROT_SW_PIN GPIO_PIN_13
#define ROT_SW_PORT GPIOB
*/
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
