/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


extern USBD_HandleTypeDef hUsbDeviceFS;

typedef struct
{
	uint8_t button;
	int8_t mouse_x;
	int8_t mouse_y;
	int8_t wheel;
} mouseHID;

mouseHID mousehid = {0,0,0,0};

int colrow0 = 0;
int colrow1 = 0;
int colrow2 = 0;
int colrow3 = 0;
int colrow4 = 0;
int colrow5 = 0;
int colrow6 = 0;
int colrow7 = 0;
int colrow8 = 0;
int colrow9 = 0;
int colrow10 = 0;
int colrow11 = 0;
int colrow12 = 0;
int colrow13 = 0;
int colrow14 = 0;
int rot_sw = 0;
int rot_A = 0;
int rot_B = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)){
			colrow0 = 1;
		} else {
			colrow0 = 0;
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)){
			colrow1 = 1;
		} else {
			colrow1 = 0;
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2)){
			colrow2 = 1;
		} else {
			colrow2 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)){
			colrow3 = 1;
		} else {
			colrow3 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)){
			colrow4 = 1;
		} else {
			colrow4 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)){
			colrow5 = 1;
		} else {
			colrow5 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)){
			colrow6 = 1;
		} else {
			colrow6 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)){
			colrow7 = 1;
		} else {
			colrow7 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)){
			colrow8 = 1;
		} else {
			colrow8 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9)){
			colrow9 = 1;
		} else {
			colrow9 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)){
			colrow10 = 1;
		} else {
			colrow10 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)){
			colrow11 = 1;
		} else {
			colrow11 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)){
			colrow12 = 1;
		} else {
			colrow12 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15)){
			colrow13 = 1;
		} else {
			colrow13 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15)){
			colrow14 = 1;
		} else {
			colrow14 = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13)){
			rot_sw = 1;
		} else {
			rot_sw = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7)){
			rot_A = 1;
		} else {
			rot_A = 0;
		}
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)){
			rot_B = 1;
		} else {
			rot_B = 0;
		}

	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA7
                           PA8 PA9 PA10 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 PB13 PB15
                           PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_15
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
