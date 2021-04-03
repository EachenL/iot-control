/* USER CODE BEGIN Header */
/**
	******************************************************************************
	* @file           : main.c
	* @brief          : Main program body
	******************************************************************************
	* @attention
	*
	* <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
	* All rights reserved.</center></h2>
	*
	* This software component is licensed by ST under BSD 3-Clause license,
	* the "License"; You may not use this file except in compliance with the
	* License. You may obtain a copy of the License at:
	*                        opensource.org/licenses/BSD-3-Clause
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
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
uint8_t connect[47] = {0x10, 0x22, 0x00, 0x04, 0x4D, 0x51, 0x54, 0x54, 0x04, 0xC2, 0x00, 0x78, 0x00, 0x09, 0x36, 0x39, 0x38, 0x39, 0x34, 0x30, 0x30, 0x37, 0x34, 0x00, 0x06, 0x34, 0x31, 0x30, 0x39, 0x38, 0x37, 0x00, 0x03, 0x61, 0x61, 0x61};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void); 
static void MX_USART1_UART_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */
void init8266(){
    uint8_t transmit[] = "AT+CWMODE=3\r\n";
	uint8_t recev[100] = {0};
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
	HAL_Delay(2000);
	HAL_UART_Transmit(&huart3, transmit, sizeof(transmit)-1, 100);
	HAL_UART_Receive(&huart3, recev, 100, 1000);
	//if(recev[0] == 'O' && recev[1] == 'K')
	HAL_UART_Transmit(&huart1, recev, 100, 200);
	memset(recev, 0, 100);
	HAL_UART_Transmit(&huart1, transmit, 13, 100);
	HAL_Delay(5000);
	uint8_t transmit1[] = "AT+CWJAP=\"CMCC-G9Ay\",\"75294z1z\"\r\n";
	HAL_UART_Transmit(&huart3, transmit1, sizeof(transmit1)-1, 50);
	HAL_UART_Receive(&huart3, recev, 100, 1000);

	HAL_UART_Transmit(&huart1, recev, 100, 200);
	memset(recev, 0, 100);
	HAL_UART_Transmit(&huart1, transmit1, 33, 100);
	HAL_Delay(10000);
	uint8_t transmit2[] = "AT+CIPSTART=\"TCP\",\"183.230.40.39\",6002\r\n";
	HAL_UART_Transmit(&huart3, transmit2, sizeof(transmit2)-1, 50);
	HAL_UART_Receive(&huart3, recev, 100, 1000);
	HAL_UART_Transmit(&huart1, recev, 100, 200);
	memset(recev, 0, 100);
	HAL_UART_Transmit(&huart1, transmit2, 38, 100);
	HAL_Delay(5000);
	uint8_t transmit3[] = "AT+CIPMODE=1\r\n";
	HAL_UART_Transmit(&huart3, transmit3, sizeof(transmit3)-1, 50);
	HAL_UART_Receive(&huart3, recev, 100, 1000);
	HAL_UART_Transmit(&huart1, recev, 100, 200);
	memset(recev, 0, 100);
	HAL_UART_Transmit(&huart1, transmit3, 14, 100);
	HAL_Delay(5000);
	uint8_t transmit4[] = "AT+CIPSEND\r\n";
	HAL_UART_Transmit(&huart3, transmit4, sizeof(transmit4)-1, 50);
	HAL_UART_Receive(&huart3, recev, 100, 1000);
	HAL_UART_Transmit(&huart1, recev, 100, 200);
	memset(recev, 0, 100);
	HAL_UART_Transmit(&huart1, transmit4, 12, 100);
	HAL_Delay(5000);  
	HAL_UART_Transmit(&huart3, connect, 36, 100);
	HAL_UART_Receive(&huart3, recev, 100, 3000);
	HAL_UART_Transmit(&huart1, recev, 100, 200);
	memset(recev, 0, 100);
	HAL_UART_Transmit(&huart1, connect, 36, 100);
	//if(HAL_UART_Transmit(&huart3, recev, 2, 2000)==HAL_OK);
}
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
	uint8_t p[47];
	uint8_t t[] = "i have receive";
	uint8_t nt[] = "i didn't receive";
	//nt = "i didn't receive";
	//t = "i have receive";
	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_USART1_UART_Init();
	MX_USART3_UART_Init();
	/* USER CODE BEGIN 2 */
	//__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
	init8266();
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
		//HAL_UART_Transmit(&huart1, nt, 17, 2);
		HAL_UART_Receive(&huart3, p, 47, 100);
		if(p[46] == 0x30){

			HAL_UART_Transmit(&huart1, t, 15, 2);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
			memset(p, 0, 47);
		}
		if(p[46] == 0x31){

			HAL_UART_Transmit(&huart1, t, 15, 100);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
			memset(p, 0, 47);
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

	/** Initializes the RCC Oscillators according to the specified parameters
	* in the RCC_OscInitTypeDef structure.
	*/
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
	* @brief USART1 Initialization Function
	* @param None
	* @retval None
	*/
static void MX_USART1_UART_Init(void)
{

	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}

/**
	* @brief USART3 Initialization Function
	* @param None
	* @retval None
	*/
static void MX_USART3_UART_Init(void)
{

	/* USER CODE BEGIN USART3_Init 0 */

	/* USER CODE END USART3_Init 0 */

	/* USER CODE BEGIN USART3_Init 1 */

	/* USER CODE END USART3_Init 1 */
	huart3.Instance = USART3;
	huart3.Init.BaudRate = 115200;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart3) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN USART3_Init 2 */

	/* USER CODE END USART3_Init 2 */

}

/**
	* @brief GPIO Initialization Function
	* @param None
	* @retval None
	*/
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(led0_GPIO_Port, led0_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : PA4 */
	GPIO_InitStruct.Pin = GPIO_PIN_4;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin : led0_Pin */
	GPIO_InitStruct.Pin = led0_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(led0_GPIO_Port, &GPIO_InitStruct);

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
