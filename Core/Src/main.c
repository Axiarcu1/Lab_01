/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void clearAllClock(){
	HAL_GPIO_WritePin(C12_GPIO_Port, C12_Pin, RESET);
	HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, RESET);
	HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, RESET);
	HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, RESET);
	HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, RESET);
	HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, RESET);
	HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, RESET);
	HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, RESET);
	HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, RESET);
	HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, RESET);
	HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, RESET);
	HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, RESET);
}

void setNumberOnClock(int n){
	if (n == 0){
		HAL_GPIO_WritePin(C12_GPIO_Port, C12_Pin, RESET);
	}
	else if (n == 1){
		HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, RESET);
	}
	else if (n == 2){
		HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, RESET);
	}
	else if (n == 3){
		HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, RESET);
	}
	else if (n == 4){
		HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, RESET);
	}
	else if (n == 5){
		HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, RESET);
	}
	else if (n == 6){
		HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, RESET);
	}
	else if (n == 7){
		HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, RESET);
	}
	else if (n == 8){
		HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, RESET);
	}
	else if (n == 9){
		HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, RESET);
	}
	else if (n == 10){
		HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, RESET);
	}
	else if (n == 11){
		HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, RESET);
	}
}

void clearNumberOnClock(int n){
	if (n == 0){
		HAL_GPIO_WritePin(C12_GPIO_Port, C12_Pin, SET);
	}
	else if (n == 1){
		HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
	}
	else if (n == 2){
		HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
	}
	else if (n == 3){
		HAL_GPIO_WritePin(C3_GPIO_Port, C3_Pin, SET);
	}
	else if (n == 4){
		HAL_GPIO_WritePin(C4_GPIO_Port, C4_Pin, SET);
	}
	else if (n == 5){
		HAL_GPIO_WritePin(C5_GPIO_Port, C5_Pin, SET);
	}
	else if (n == 6){
		HAL_GPIO_WritePin(C6_GPIO_Port, C6_Pin, SET);
	}
	else if (n == 7){
		HAL_GPIO_WritePin(C7_GPIO_Port, C7_Pin, SET);
	}
	else if (n == 8){
		HAL_GPIO_WritePin(C8_GPIO_Port, C8_Pin, SET);
	}
	else if (n == 9){
		HAL_GPIO_WritePin(C9_GPIO_Port, C9_Pin, SET);
	}
	else if (n == 10){
		HAL_GPIO_WritePin(C10_GPIO_Port, C10_Pin, SET);
	}
	else if (n == 11){
		HAL_GPIO_WritePin(C11_GPIO_Port, C11_Pin, SET);
	}
}

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
  /* USER CODE BEGIN 2 */
  int h_num = 6;
  int m_num = 20;
  int s_num = 0;

  int s_counter = 2;
  int m_blink_counter = 10;
  int m_state = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  clearAllClock();

	  if (s_num >= 60){
		  s_num = 0;
		  m_num++;
		  if (m_num >= 60){
			  m_num = 0;
			  clearNumberOnClock(h_num);
			  h_num++;
			  if (h_num >=12){
				  h_num = 0;
			  }
		  }
	  }

	  if (s_counter <= 0){
		  s_num++;
		  s_counter = 2;
	  }

	  if (s_num % 5 == 0){
		  if (s_num / 5 == 0){
			  clearNumberOnClock(11);
		  }
		  else{
			  clearNumberOnClock(s_num / 5 - 1);
		  }
		  setNumberOnClock(s_num / 5);
	  }

	  setNumberOnClock(h_num);

	  if (m_blink_counter <= 0){
		  if (m_state == 0){
			  setNumberOnClock(m_num/5);
			  m_blink_counter = 1;
		  }
		  else{
			  clearNumberOnClock(m_num/5);
			  m_blink_counter = 0;
		  }
		  m_blink_counter = 10;
	  }

	  m_blink_counter--;
	  s_counter--;
	  HAL_Delay(10);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, C1_Pin|C2_Pin|C3_Pin|C4_Pin
                          |C5_Pin|C6_Pin|C7_Pin|C8_Pin
                          |C9_Pin|C10_Pin|C11_Pin|C12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : C1_Pin C2_Pin C3_Pin C4_Pin
                           C5_Pin C6_Pin C7_Pin C8_Pin
                           C9_Pin C10_Pin C11_Pin C12_Pin */
  GPIO_InitStruct.Pin = C1_Pin|C2_Pin|C3_Pin|C4_Pin
                          |C5_Pin|C6_Pin|C7_Pin|C8_Pin
                          |C9_Pin|C10_Pin|C11_Pin|C12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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