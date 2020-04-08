/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include <list>
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "math.h"
#include "stdlib.h"
#include "Double_screen.h"
#include "Snake_game.h"
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
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

/* USER CODE BEGIN PV */
#undef RAND_MAX
#define RAND_MAX 0x02

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
/* USER CODE BEGIN PFP */
void SystemClock_Config(void);
void testdrawline(void);
void testdrawrect(void);
void testfillrect(void);
void testdrawcircle(void);
void testdrawroundrect(void);
void testfillroundrect(void);
void testdrawtriangle(void);
void testfilltriangle(void);
void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h);

#define OLED_RESET 0

//Adafruit_SSD1306 display_top(&hi2c1, OLED_RESET);
//Adafruit_SSD1306 display_bottom(&hi2c2, OLED_RESET);
Double_screen mydoubleScreen;
//Snake_game mygame; 
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char logo16_glcd_bmp[] =
{ 
0x00,0x00,0x00,0x20,0x00,0x60,0x00,0xE0,0x00,0xE0,0xEE,0xCC,0x7E,0xCE,0x7F,0xDE,
0x7F,0xFF,0x3F,0xFB,0x3B,0x33,0x11,0x27,0x00,0x0E,0x00,0x0E,0x00,0x0C,0x00,0x00
};
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
  MX_I2C1_Init();
	MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
	
	/*if ( mygame.getSize() == 7) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	}*/
	//mygame.start();
	/*for (int i=0; i<10; i++) {
		mygame.drawCurrentSnake();
		mygame.right();
	}
	for (int i=0; i<5; i++) {
		mygame.drawCurrentSnake();
		mygame.up();
	}
	for (int i=0; i<6; i++) {
		mygame.drawCurrentSnake();
		mygame.left();
	}
	for (int i=0; i<10; i++) {
		mygame.drawCurrentSnake();
		mygame.up();
	}*/
		
		/*______________________________________________________________________________________*/
		//display_top.switch_screen(TOP_SCREEN);
		//display_top.begin(SSD1306_SWITCHCAPVCC, 0x78);
		//display_top.switch_screen(BOTTOM_SCREEN);
		//display_bottom.begin(SSD1306_SWITCHCAPVCC, 0x78);
		mydoubleScreen.begin(SSD1306_SWITCHCAPVCC, 0x78);
		//display_top.display();
		//display_bottom.display();
		mydoubleScreen.display();
		HAL_Delay(1000);
		//display_top.clearDisplay();
		//display_bottom.clearDisplay();
		
		mydoubleScreen.clearDisplay();
		//display_top.drawPixel(10, 10, WHITE);
		//display_top.display();
		//display_bottom.clearDisplay();
		//display_bottom.drawPixel(100, 10, WHITE);
		//mydoubleScreen.drawPixel(40, 66, WHITE);
		mydoubleScreen.write('h');
		mydoubleScreen.write('a');
		//display_top.display();
		//display_bottom.display();
		mydoubleScreen.display();
		HAL_Delay(5000);
		/*
	//  display_top.clearDisplay();
		display_top.display();
		display_bottom.display();
		HAL_Delay(5000);
	//  while(1);
		display_top.clearDisplay();
		display_top.display();
		display_bottom.clearDisplay();
		display_bottom.display();
		//Display text
		display_top.setTextSize(2);
		display_top.setTextColor(WHITE);
		display_top.setCursor(28,8);
		display_top.printf("Ayoub");
		display_top.display();
		
		display_bottom.setTextSize(2);
		display_bottom.setTextColor(WHITE);
		display_bottom.setCursor(28,8);
		display_bottom.printf("Soussi");
		display_bottom.display();
		HAL_Delay(2000);
		display_top.clearDisplay();
		display_top.display();
		
		display_bottom.clearDisplay();
		display_bottom.display();
		*/
		// draw many lines
		testdrawline();
		mydoubleScreen.display();
		HAL_Delay(2000);
		mydoubleScreen.clearDisplay();

		// draw rectangles
		testdrawrect();
		mydoubleScreen.display();
		HAL_Delay(2000);
		mydoubleScreen.clearDisplay();
		
		// draw multiple rectangles
		testfillrect();
		mydoubleScreen.display();
		HAL_Delay(2000);
		mydoubleScreen.clearDisplay();
		
		// draw mulitple circles
		testdrawcircle();
		mydoubleScreen.display();
		HAL_Delay(2000);
		mydoubleScreen.clearDisplay();
		
		// draw a white circle, 10 pixel radius
		mydoubleScreen.fillCircle(mydoubleScreen.width()/2, mydoubleScreen.height()/2, 10, WHITE);
		mydoubleScreen.display();
		HAL_Delay(2000);
		mydoubleScreen.clearDisplay();
		
		testdrawroundrect();
		HAL_Delay(2000);
		mydoubleScreen.clearDisplay();

		testfillroundrect();
		HAL_Delay(2000);
		mydoubleScreen.clearDisplay();
		
		testdrawtriangle();
		HAL_Delay(2000);
		mydoubleScreen.clearDisplay();
		 
		testfilltriangle();
		HAL_Delay(2000);
		mydoubleScreen.clearDisplay();
		
		// miniature bitmap mydoubleScreen
		mydoubleScreen.clearDisplay();
		mydoubleScreen.drawBitmap(30, 16,  logo16_glcd_bmp, 16, 16, 1);
		mydoubleScreen.display();
		HAL_Delay(500);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
		HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		// invert the display_top
    mydoubleScreen.invertDisplay(true);
    HAL_Delay(1000); 
    mydoubleScreen.invertDisplay(false);
    HAL_Delay(1000); 
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

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD9 PD10 PD11 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
	__disable_irq();
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	/*switch(GPIO_Pin) {
		case START_BUTTON :
			mygame.start();
			break;
		case RIGHT_BUTTON :
			mygame.right();
			break;
		case LEFT_BUTTON :
			mygame.left();
			break;
		case UP_BUTTON :
			mygame.up();
			break;
		case DOWN_BUTTON :
			mygame.down();
			break;
		default :
			break;
	}*/
	//for (int i=0; i<10000; i++);
	__enable_irq();
}

void testdrawline(void) {  
  for (int16_t i=0; i<mydoubleScreen.width(); i+=4) {
    mydoubleScreen.drawLine(0, 0, i, mydoubleScreen.height()-1, WHITE);
    mydoubleScreen.display();
  }
  for (int16_t i=0; i<mydoubleScreen.height(); i+=4) {
    mydoubleScreen.drawLine(0, 0, mydoubleScreen.width()-1, i, WHITE);
    mydoubleScreen.display();
  }
  HAL_Delay(250);
  
  mydoubleScreen.clearDisplay();
  for (int16_t i=0; i<mydoubleScreen.width(); i+=4) {
    mydoubleScreen.drawLine(0, mydoubleScreen.height()-1, i, 0, WHITE);
    mydoubleScreen.display();
  }
  for (int16_t i=mydoubleScreen.height()-1; i>=0; i-=4) {
    mydoubleScreen.drawLine(0, mydoubleScreen.height()-1, mydoubleScreen.width()-1, i, WHITE);
    mydoubleScreen.display();
  }
  HAL_Delay(250);
  
  mydoubleScreen.clearDisplay();
  for (int16_t i=mydoubleScreen.width()-1; i>=0; i-=4) {
    mydoubleScreen.drawLine(mydoubleScreen.width()-1, mydoubleScreen.height()-1, i, 0, WHITE);
    mydoubleScreen.display();
  }
  for (int16_t i=mydoubleScreen.height()-1; i>=0; i-=4) {
    mydoubleScreen.drawLine(mydoubleScreen.width()-1, mydoubleScreen.height()-1, 0, i, WHITE);
    mydoubleScreen.display();
  }
  HAL_Delay(250);

  mydoubleScreen.clearDisplay();
  for (int16_t i=0; i<mydoubleScreen.height(); i+=4) {
    mydoubleScreen.drawLine(mydoubleScreen.width()-1, 0, 0, i, WHITE);
    mydoubleScreen.display();
  }
  for (int16_t i=0; i<mydoubleScreen.width(); i+=4) {
    mydoubleScreen.drawLine(mydoubleScreen.width()-1, 0, i, mydoubleScreen.height()-1, WHITE); 
    mydoubleScreen.display();
  }
  HAL_Delay(250);
}

void testdrawrect(void) {
  for (int16_t i=0; i<mydoubleScreen.height()/2; i+=2) {
    mydoubleScreen.drawRect(i, i, mydoubleScreen.width()-2*i, mydoubleScreen.height()-2*i, WHITE);
    mydoubleScreen.display();
    HAL_Delay(1);
  }
}

void testfillrect(void) {
  uint8_t color = 1;
  for (int16_t i=0; i<mydoubleScreen.height()/2; i+=3) {
    // alternate colors
    mydoubleScreen.fillRect(i, i, mydoubleScreen.width()-i*2, mydoubleScreen.height()-i*2, color%2);
    mydoubleScreen.display();
    HAL_Delay(1);
    color++;
  }
}

void testdrawcircle(void) {
  for (int16_t i=0; i<mydoubleScreen.height(); i+=2) {
    mydoubleScreen.drawCircle(mydoubleScreen.width()/2, mydoubleScreen.height()/2, i, WHITE);
    mydoubleScreen.display();
    HAL_Delay(1);
  }
}

void testdrawroundrect(void) {
  for (int16_t i=0; i<mydoubleScreen.height()/2-2; i+=2) {
    mydoubleScreen.drawRoundRect(i, i, mydoubleScreen.width()-2*i, mydoubleScreen.height()-2*i, mydoubleScreen.height()/4, WHITE);
    mydoubleScreen.display();
    HAL_Delay(1);
  }
}

void testfillroundrect(void) {
  uint8_t color = WHITE;
  for (int16_t i=0; i<mydoubleScreen.height()/2-2; i+=2) {
    mydoubleScreen.fillRoundRect(i, i, mydoubleScreen.width()-2*i, mydoubleScreen.height()-2*i, mydoubleScreen.height()/4, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    mydoubleScreen.display();
    HAL_Delay(1);
  }
}

void testdrawtriangle(void) {
  for (int16_t i=0; i<min(mydoubleScreen.width(),mydoubleScreen.height())/2; i+=5) {
    mydoubleScreen.drawTriangle(mydoubleScreen.width()/2, mydoubleScreen.height()/2-i,
                     mydoubleScreen.width()/2-i, mydoubleScreen.height()/2+i,
                     mydoubleScreen.width()/2+i, mydoubleScreen.height()/2+i, WHITE);
    mydoubleScreen.display();
    HAL_Delay(1);
  }
}

void testfilltriangle(void) {
  uint8_t color = WHITE;
  for (int16_t i=min(mydoubleScreen.width(),mydoubleScreen.height())/2; i>0; i-=5) {
    mydoubleScreen.fillTriangle(mydoubleScreen.width()/2, mydoubleScreen.height()/2-i,
                     mydoubleScreen.width()/2-i, mydoubleScreen.height()/2+i,
                     mydoubleScreen.width()/2+i, mydoubleScreen.height()/2+i, WHITE);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    mydoubleScreen.display();
    HAL_Delay(1);
  }
}

void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h) {
  uint8_t icons[NUMFLAKES][3];
 
  // initialize
  for (uint8_t f=0; f< NUMFLAKES; f++) {
    icons[f][XPOS] = rand();
    icons[f][YPOS] = 0;
    icons[f][DELTAY] = rand() + 1;

  }

  while (1) {
    // draw each icon
    for (uint8_t f=0; f< NUMFLAKES; f++) {
      mydoubleScreen.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo16_glcd_bmp, w, h, WHITE);
    }
    mydoubleScreen.display();
    HAL_Delay(200);
    
    // then erase it + move it
    for (uint8_t f=0; f< NUMFLAKES; f++) {
      mydoubleScreen.drawBitmap(icons[f][XPOS], icons[f][YPOS],  logo16_glcd_bmp, w, h, BLACK);
      // move it
      icons[f][YPOS] += icons[f][DELTAY];
      // if its gone, reinit
      if (icons[f][YPOS] > mydoubleScreen.height()) {
	icons[f][XPOS] = rand();
	icons[f][YPOS] = 0;
	icons[f][DELTAY] = rand() ;
      }
    }
   }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
