/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ECHO_Pin GPIO_PIN_4
#define ECHO_GPIO_Port GPIOA
#define ECHO_EXTI_IRQn EXTI4_IRQn
#define GPIO_PIN_3_Pin GPIO_PIN_6
#define GPIO_PIN_3_GPIO_Port GPIOA
#define GPIO_PIN_4_Pin GPIO_PIN_7
#define GPIO_PIN_4_GPIO_Port GPIOA
#define ECHOB10_Pin GPIO_PIN_10
#define ECHOB10_GPIO_Port GPIOB
#define GPIO_PIN_1_Pin GPIO_PIN_14
#define GPIO_PIN_1_GPIO_Port GPIOD
#define GPIO_PIN_2_Pin GPIO_PIN_15
#define GPIO_PIN_2_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
