/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define ADDR_FLASH_PAGE_0     ((uint32_t)0x08000000) /* Base @ of Page 0, 1 Kbyte */
#define ADDR_FLASH_PAGE_1     ((uint32_t)0x08000400) /* Base @ of Page 1, 1 Kbyte */
#define ADDR_FLASH_PAGE_2     ((uint32_t)0x08000800) /* Base @ of Page 2, 1 Kbyte */
#define ADDR_FLASH_PAGE_3     ((uint32_t)0x08000C00) /* Base @ of Page 3, 1 Kbyte */
#define ADDR_FLASH_PAGE_4     ((uint32_t)0x08001000) /* Base @ of Page 4, 1 Kbyte */
#define ADDR_FLASH_PAGE_5     ((uint32_t)0x08001400) /* Base @ of Page 5, 1 Kbyte */
#define ADDR_FLASH_PAGE_6     ((uint32_t)0x08001800) /* Base @ of Page 6, 1 Kbyte */
#define ADDR_FLASH_PAGE_7     ((uint32_t)0x08001C00) /* Base @ of Page 7, 1 Kbyte */
#define ADDR_FLASH_PAGE_8     ((uint32_t)0x08002000) /* Base @ of Page 8, 1 Kbyte */
#define ADDR_FLASH_PAGE_9     ((uint32_t)0x08002400) /* Base @ of Page 9, 1 Kbyte */
#define ADDR_FLASH_PAGE_10    ((uint32_t)0x08002800) /* Base @ of Page 10, 1 Kbyte */
#define ADDR_FLASH_PAGE_11    ((uint32_t)0x08002C00) /* Base @ of Page 11, 1 Kbyte */
#define ADDR_FLASH_PAGE_12    ((uint32_t)0x08003000) /* Base @ of Page 12, 1 Kbyte */
#define ADDR_FLASH_PAGE_13    ((uint32_t)0x08003400) /* Base @ of Page 13, 1 Kbyte */
#define ADDR_FLASH_PAGE_14    ((uint32_t)0x08003800) /* Base @ of Page 14, 1 Kbyte */
#define ADDR_FLASH_PAGE_15    ((uint32_t)0x08003C00) /* Base @ of Page 15, 1 Kbyte */
#define ADDR_FLASH_PAGE_16    ((uint32_t)0x08004000) /* Base @ of Page 16, 1 Kbyte */
#define ADDR_FLASH_PAGE_17    ((uint32_t)0x08004400) /* Base @ of Page 17, 1 Kbyte */
#define ADDR_FLASH_PAGE_18    ((uint32_t)0x08004800) /* Base @ of Page 18, 1 Kbyte */
#define ADDR_FLASH_PAGE_19    ((uint32_t)0x08004C00) /* Base @ of Page 19, 1 Kbyte */
#define ADDR_FLASH_PAGE_20    ((uint32_t)0x08005000) /* Base @ of Page 20, 1 Kbyte */
#define ADDR_FLASH_PAGE_21    ((uint32_t)0x08005400) /* Base @ of Page 21, 1 Kbyte */
#define ADDR_FLASH_PAGE_22    ((uint32_t)0x08005800) /* Base @ of Page 22, 1 Kbyte */
#define ADDR_FLASH_PAGE_23    ((uint32_t)0x08005C00) /* Base @ of Page 23, 1 Kbyte */
#define ADDR_FLASH_PAGE_24    ((uint32_t)0x08006000) /* Base @ of Page 24, 1 Kbyte */
#define ADDR_FLASH_PAGE_25    ((uint32_t)0x08006400) /* Base @ of Page 25, 1 Kbyte */
#define ADDR_FLASH_PAGE_26    ((uint32_t)0x08006800) /* Base @ of Page 26, 1 Kbyte */
#define ADDR_FLASH_PAGE_27    ((uint32_t)0x08006C00) /* Base @ of Page 27, 1 Kbyte */
#define ADDR_FLASH_PAGE_28    ((uint32_t)0x08007000) /* Base @ of Page 28, 1 Kbyte */
#define ADDR_FLASH_PAGE_29    ((uint32_t)0x08007400) /* Base @ of Page 29, 1 Kbyte */
#define ADDR_FLASH_PAGE_30    ((uint32_t)0x08007800) /* Base @ of Page 30, 1 Kbyte */
#define ADDR_FLASH_PAGE_31    ((uint32_t)0x08007C00) /* Base @ of Page 31, 1 Kbyte */
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/*_________STRUCT INPUT_CAPTURE_____________________________________*/
struct InputCapture_StateDef_t{
	__IO uint32_t 	Value1; 			//tempo do primeiro pulso
	__IO uint32_t 	Value2;	 			//tempo do segundo pulso
	__IO uint32_t 	Difference; 		//diferenca entre pulsos
	__IO uint32_t 	Frequency; 			//frequencia já calculada
	__IO uint16_t  	Is_First_Captured; 	//data capture	- 0- not captured, 1- captured
	__IO uint16_t  	IC_compare_cont; 	//Compara leitura de RPM para nao travamento da lógica
	__IO uint16_t  	IC_compare1; 		//evita frequencia confusa
	uint32_t		Media_calculada;
	uint32_t 		Media[10];
};




/*_________STRUCT CARRO_____________________________________________*/
typedef struct {
	uint8_t			MODO;					//MODO DE OPERACAO, PODENDO SER MANUAL OU AUTOMATICO

	uint32_t 		MARCHA_LENTA;		// MARCHA LENTA PARA CALIBRAÇÃO RODA FONICA
	uint32_t 		RPM_TROCA;			// RPM_TROCA DEFINE A ROTAÇÃO DE COMUTAR
	uint32_t 		TEMPERATURA;			// Temperatura lida
	uint16_t			Incidencia_apagou;	//conta quantos ciclos ficou com rotação abaixo do definido

	__IO uint32_t 	RPM_CORRECAO;		//rpm capturado na hora da conversao
	__IO uint16_t 	Clock_rpm;			//rotação do motor já convertida em RPM
	__IO uint32_t 	Clock_rpm_Conv;	//rotacao ja convertida com a correcao
	__IO float 		Velocidade_kmh;	//rotacao ja convertida com a correcao
	__IO float 		Velocidade_ms;		//rotacao ja convertida com a correcao
	__IO float	 	Correcao_rpm;		//MULTIPLICADOR PONTO FLUTUANTE

	uint32_t 		Delta_D_metros;	//Distancia percorrida
	float				Delta_Area;			//Area em metros quadrados irrigada desde que ligou
	__IO float		Delta_Hect;			//Area em hectares irrigada desde que ligou

	uint8_t			Nivel;				//flag que indica nivel
	uint8_t			Switch_bomba_1;	//flag para acionar bomba esquerda
	uint8_t			Switch_bomba_2;	//flag para acionar bomba direita
	uint8_t			FLAG_bomba_1;	//flag para acionar bomba esquerda
	uint8_t			FLAG_bomba_2;	//flag para acionar bomba direita

	uint32_t			Diametro_pneu;		//valor em centimentros do diametro externo do pneu
	uint32_t			Comprimento_braco;//valor em metros do comprimento do braco pulverizador
	uint32_t			Velocidade_troca;	//valor em metros do comprimento do braco pulverizador

	uint32_t		VerificaMEM;		//variavel para verificar memoria

	struct InputCapture_StateDef_t IC;  // STRUCT INPUT_CAPTURE

}Hibrido_StateDef_t;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

//TEMPOS DE CLIQUE DE BOTAO
#define DEF_CLICK_CURTO				4		// multiplicado por 10ms    -> ex 2 	== 20 ms
#define DEF_CLICK_LONGO				50		// multiplicado por 10ms    -> ex 100 	== 1 s
#define DEF_TEMPO_MAX_MENU			5 		// 10 SEGUNDOS	- tempo máximo no menu
#define DEF_TEMPO_BURST				10 		// multiplicado por 10ms    -> ex 20 	== 200 ms
#define DEF_TEMPO_INCREMENTO		50 		// multiplicado por 10ms    -> ex 20 	== 200 ms

#define DEF_LIMITE_DIAMETRO_MAX	500 		//
#define DEF_LIMITE_DIAMETRO_STD	100 		//
#define DEF_LIMITE_DIAMETRO_MIN	40 		//

#define DEF_LIMITE_LARGURA_MAX	400 		//
#define DEF_LIMITE_LARGURA_STD	200 		//
#define DEF_LIMITE_LARGURA_MIN	40 		//

#define DEF_VELOCIDADE_MAX			30 		//
#define DEF_VELOCIDADE_STD			10 		//
#define DEF_VELOCIDADE_MIN			2 			//

#define DEF_NUM_DENTES			3

//DEFINES TELA
/*telas importantes tem numero maior que 30*/
#define TELA_PRINCIPAL  			1
#define TELA_DIAMETRO_PNEU  		8
#define TELA_LARGURA_BRACO			9
#define TELA_VELOCIDADE_TROCA		10
#define TELA_MENU  					11
#define TELA_MODO  					12

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

//___________MACRO LE BOTAO ___________________________________________
#define READ_ESQ		HAL_GPIO_ReadPin 	(BTN_ESQ_GPIO_Port,		BTN_ESQ_Pin)
#define READ_DIR		HAL_GPIO_ReadPin 	(BTN_DIR_GPIO_Port,		BTN_DIR_Pin)
#define READ_MENU		HAL_GPIO_ReadPin 	(BTN_MENU_GPIO_Port,		BTN_MENU_Pin)
#define READ_NIVEL	HAL_GPIO_ReadPin 	(NIVEL_GPIO_Port,			NIVEL_Pin)


#define LEITURA_FL 5.9844*ADC_buff[0]

#define M_LED_2_ON 		HAL_GPIO_WritePin		(LED_2_GPIO_Port,	LED_2_Pin	,GPIO_PIN_SET);
#define M_LED_2_OFF		HAL_GPIO_WritePin		(LED_2_GPIO_Port,	LED_2_Pin	,GPIO_PIN_RESET);

#define M_LED_1_ON 		HAL_GPIO_WritePin		(LED_1_GPIO_Port,	LED_1_Pin	,GPIO_PIN_SET);
#define M_LED_1_OFF		HAL_GPIO_WritePin		(LED_1_GPIO_Port,	LED_1_Pin	,GPIO_PIN_RESET);

#define M_BOMBA_1_ON 		HAL_GPIO_WritePin		(BOMBA_1_GPIO_Port,	BOMBA_1_Pin	,GPIO_PIN_SET);
#define M_BOMBA_1_OFF		HAL_GPIO_WritePin		(BOMBA_1_GPIO_Port,	BOMBA_1_Pin	,GPIO_PIN_RESET);

#define M_BOMBA_2_ON 		HAL_GPIO_WritePin		(BOMBA_2_GPIO_Port,	BOMBA_2_Pin	,GPIO_PIN_SET);
#define M_BOMBA_2_OFF		HAL_GPIO_WritePin		(BOMBA_2_GPIO_Port,	BOMBA_2_Pin	,GPIO_PIN_RESET);
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define AD_PRESSURE_1_Pin GPIO_PIN_0
#define AD_PRESSURE_1_GPIO_Port GPIOA
#define AD_PRESSURE_2_Pin GPIO_PIN_1
#define AD_PRESSURE_2_GPIO_Port GPIOA
#define AD_TEMP_Pin GPIO_PIN_2
#define AD_TEMP_GPIO_Port GPIOA
#define NIVEL_Pin GPIO_PIN_3
#define NIVEL_GPIO_Port GPIOA
#define BOMBA_1_Pin GPIO_PIN_6
#define BOMBA_1_GPIO_Port GPIOA
#define BOMBA_2_Pin GPIO_PIN_7
#define BOMBA_2_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_0
#define LED_1_GPIO_Port GPIOB
#define LED_2_Pin GPIO_PIN_1
#define LED_2_GPIO_Port GPIOB
#define POS_CHAVE_Pin GPIO_PIN_11
#define POS_CHAVE_GPIO_Port GPIOA
#define BTN_ESQ_Pin GPIO_PIN_5
#define BTN_ESQ_GPIO_Port GPIOB
#define BTN_ESQ_EXTI_IRQn EXTI4_15_IRQn
#define BTN_MENU_Pin GPIO_PIN_6
#define BTN_MENU_GPIO_Port GPIOB
#define BTN_MENU_EXTI_IRQn EXTI4_15_IRQn
#define BTN_DIR_Pin GPIO_PIN_7
#define BTN_DIR_GPIO_Port GPIOB
#define BTN_DIR_EXTI_IRQn EXTI4_15_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
