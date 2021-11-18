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
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Init.h"
#include "lcd_init.h"
#include "lcd.h"
#include "pic.h"
#include "p3.h"
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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void) {
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
    u8 i,j;
    float t=0;
    HAL_Delay(168);
    LCD_Init();//LCD初始化
    LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        LCD_ShowPicture(0,0,240,240,p3);
        HAL_Delay(5000);
        LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
        LCD_ShowChinese(0,0,"中景园电子",RED,WHITE,32,0);
        LCD_ShowString(0,40,"LCD_W:",RED,WHITE,16,0);
        LCD_ShowIntNum(48,40,LCD_W,3,RED,WHITE,16);
        LCD_ShowString(80,40,"LCD_H:",RED,WHITE,16,0);
        LCD_ShowIntNum(128,40,LCD_H,3,RED,WHITE,16);
        LCD_ShowString(80,40,"LCD_H:",RED,WHITE,16,0);
        LCD_ShowString(0,70,"Increaseing Nun:",RED,WHITE,16,0);
        LCD_ShowFloatNum1(128,70,t,4,RED,WHITE,16);
        t+=0.11;
        for(j=0;j<3;j++)
        {
            for(i=0;i<6;i++)
            {
                LCD_ShowPicture(40*i,120+j*40,40,40,gImage_1);
            }
        }
        HAL_Delay(1000);
        LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
        Display_Asc_String(0,15,7, "ASCII_5x7",RED,WHITE);      //ASC 5X7点阵
        Display_Asc_String(0,25,8, "ASCII_7x8",RED,WHITE);      //ASC 7X8点阵
        Display_Asc_String(0,35,12, "ASCII_6x12",RED,WHITE);	  //ASC 6X12点阵
        Display_Asc_String(0,50,16, "ASCII_8x16",RED,WHITE);	  //ASC 8X16点阵
        Display_Asc_String(0,70,24, "ASCII_12x24",RED,WHITE);   //ASC 12X24点阵
        Display_Asc_String(0,100,32, "ASCII_16x32",RED,WHITE);	//ASC 16X32点阵
        Display_GB2312_String(0,145,12, "中景园１２ｘ１２",RED,WHITE); //12x12汉字
        Display_GB2312_String(0,160,16, "中景园１６ｘ１６",RED,WHITE); //15x16汉字
        Display_GB2312_String(0,179,24, "中景园２４ｘ２４",RED,WHITE); //24x24汉字
        Display_GB2312_String(0,204,32, "中景园３２ｘ３",RED,WHITE);   //32x32汉字
        HAL_Delay(1000);
        LCD_Fill(0,0,LCD_W,LCD_H,WHITE);

        Display_TimesNewRoman_String(0,15,12, "ASCII_8x12",RED,WHITE);   //ASC 8x12点阵(TimesNewRoman类型)
        Display_TimesNewRoman_String(0,30,16, "ASCII_12x16",RED,WHITE);  //ASC 12x16点阵(TimesNewRoman类型)
        Display_TimesNewRoman_String(0,50,24, "ASCII_16x24",RED,WHITE);	//ASC 16x24点阵(TimesNewRoman类型)
        Display_TimesNewRoman_String(0,80,32, "ASCII_24x",RED,WHITE);	  //ASC 24x32点阵(TimesNewRoman类型)
        Display_Arial_String(0,120,12, "ASCII_8x12",RED,WHITE);    //ASC 8x12点阵(Arial类型)
        Display_Arial_String(0,140,16, "ASCII_12x16",RED,WHITE);   //ASC 12x16点阵(Arial类型)
        Display_Arial_String(0,160,24, "ASCII_16x24",RED,WHITE);	 //ASC 16x24点阵(Arial类型)
        Display_Arial_String(0,190,32, "ASCII_24x",RED,WHITE);	   //ASC 24x32点阵(Arial类型)
        HAL_Delay(1000);
        LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
    }
    /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void) {
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
    RCC_OscInitStruct.PLL.PLLM = 15;
    RCC_OscInitStruct.PLL.PLLN = 216;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 4;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }
    /** Activate the Over-Drive mode
    */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
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
