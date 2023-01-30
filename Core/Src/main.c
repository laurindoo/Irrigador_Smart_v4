/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "u8g_com_arm_stm32.h" 	//---INCLUDES DISPLAY
#include "Display.h"
#include <stdio.h>
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

int tabela_temp[22] = {98,460,821,1136,1427,1675,1898,2084,2246,2382,2481,2581,2655,2730,2779,2829,2866,2903,2928,2953,2965,2990};
int i = 1;


/*VARIAVEIS FUNCIONAMENTO DA EEPROM EMULADA*/
#define FLASH_USER_START_ADDR		ADDR_FLASH_PAGE_31   							/* Start @ of user Flash area */
#define FLASH_USER_DIAMETRO		(FLASH_USER_START_ADDR + (0x400-0x024)) 	/* endereço da variavel de DIAMETRO DE PNEU*/
#define FLASH_USER_LARGURA 		(FLASH_USER_START_ADDR + (0x400-0x01C)) 	/* endereço da variavel LARGURA BRACO PULVERIZADOR*/
#define FLASH_USER_VEL_MIN			(FLASH_USER_START_ADDR + (0x400-0x004)) 	/* endereço da variavel VELOCIADDE MINIMA*/
#define FLASH_USER_END_ADDR     	ADDR_FLASH_PAGE_31 + FLASH_PAGE_SIZE   	/* End @ of user Flash area */
//uint32_t Address 						= 0;
uint32_t PAGEError 						= 0;
//__IO uint32_t MemoryProgramStatus 		= 0;
static FLASH_EraseInitTypeDef EraseInitStruct;

//REVISAR
__IO float Pot_var;

/*_________CONTADORES_______________________________________________*/
__IO uint8_t  Cont_100ms		= 0;
__IO uint16_t Cont_500ms		= 0;
__IO uint16_t Cont_1000ms		= 0;
__IO uint16_t Cont_sem_click	= 0;

///*_________STRUCT INPUT_CAPTURE_____________________________________*/
//struct InputCapture_StateDef_t;

/*_________STRUCT CARRO_____________________________________________*/
Hibrido_StateDef_t Carro;

/*--VARIAVEL DE DISPLAY E ERRO I2C -----------------------------------------------------------------------------------*/
__IO uint32_t FLAG_ERRO_I2C 		= 0	;
__IO int Erro_display 				= 0	;
char		FLAG_TELA_ABERTURA		= 1	; // FLAG PARA ACIONAMENTO DE TELA DE ABERTURA
char		FLAG_ATUALIZA_TELA		= 1	; // FLAG LIBERA IMPRESSÃO EM DISPLAY
char		FLAG_TELA_BUSY				= 0	; // FLAG INDICA DISPLAY OCUPADO
char		FLAG_REFRESH				= 0	; // FLAG QUE SOLICITA ATUALIZAÇÃO DE TELA
char		Buff_Display[128]			= ""; // BUFF PARA IMPRESSÃO 1
u8g_t 		u8g				   			; // Instancia para uso do display
uint8_t 	Selecao_Tela_next			= TELA_PRINCIPAL	; // Próxima tela em fila
uint8_t 	Selecao_Tela				= 0	; // Tela atual utilizada para ser impressa

/*_________VARIAVEIS TEMPERATURA, PRESSAO 1 E PRESSAO 2_________________*/
__IO uint32_t	ADC_buff_1[3]		;	// BUFFER DE ARMAZENAMENTO DOS VALORES AD (valores de AD)/**/;

struct AD_read {
		__IO uint32_t	ADC_buff[3]	;	// BUFFER DE ARMAZENAMENTO DOS VALORES AD (valores de AD)/**/
		uint32_t 	Temperatura		;	// Valor de TEMPERATURA lido pelo AD (valor em Celsius)
		uint32_t 	Pressure_1		;	// Valor de PRESSAO 1 (valor em BAR)
		uint32_t 	Pressure_2		;	// Valor de PRESSAO 2 (valor em BAR)

}AD_read;

/*--VARIAVEIS BOTAO -------------------------------------------------------------------------------------------------*/
struct Type_Botao //64bytes
{
		uint16_t 	FLAG;
		uint16_t 	LAST_FLAG;
		uint16_t 	ContPress;
		uint16_t 	Cont_N_Press;
}Botao;
struct Type_Botao BTN_ESQ;
struct Type_Botao BTN_DIR;
struct Type_Botao BTN_MENU;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Callback_100ms(void);
void Callback_500ms(void);
void Callback_1000ms(void);
void Callback_CURTO_PB_ESQ(void);
void Callback_LONGO_PB_ESQ(void);
void Callback_CURTO_PB_DIR(void);
void Callback_LONGO_PB_DIR(void);
void Callback_CURTO_PB_MENU(void);
void Callback_LONGO_PB_MENU(void);
void Controle_De_Telas(void);
void Grava_memoria(void);
void Atualiza_Variaveis (void);
void Write_in_flash_HIBRIDO(uint32_t Address_Var, uint32_t Value_Var );
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
  MX_DMA_Init();
  MX_ADC_Init();
  MX_I2C1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT	(&htim2) ;									// TIMER DE 10 MICRO segundos
	HAL_ADC_Start_DMA		(&hadc	,(uint32_t*)&ADC_buff_1, 3);		// ADC_DMA
	HAL_TIM_IC_Start_IT	(&htim3	,TIM_CHANNEL_1	);				// LEITURA RPM
	Atualiza_Variaveis();


	HAL_Delay(200);
	//INICIA O DISPLAY
	Inicia_display();

	//Carro.TEMPERATURA  = 1.15*(double)ADC_buff_1[0];

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		Controle_De_Telas();

		if(i < 22)
		{//tabela_temp
			if(ADC_buff_1[2] > tabela_temp[(i-1)] && ADC_buff_1[2] < tabela_temp[i])
			{
				Carro.TEMPERATURA = i*5;
				i = 1;
			}
			else
			{
				i++;
			}
		}
		else
		{
			i = 1;
		}

		if(Carro.FLAG_bomba_2)
		{
			__NOP();
			M_BOMBA_2_ON
		}
		else
		{
			__NOP();
			M_BOMBA_2_OFF
		}

		if(Carro.Switch_bomba_1)
		{
			__NOP();
			M_BOMBA_1_ON
		}
		else
		{
			__NOP();
			M_BOMBA_1_OFF
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

//--CALLBACK TIMERS -------------------------------------------------
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	/*----------------------- TIM 2   PASSO DE 10 MILISEGUNDOS---------------------*/
	if (htim == &htim2 ){// 10 milisegundos

		//	identifica se O MOTOR APAGOU
		(Carro.Clock_rpm <2 ) ? (Carro.Incidencia_apagou++) : (Carro.Incidencia_apagou = 0);


		/*---ROTINA ANTI-TRAVAMENTO DE AQUISIÇÃO DE RPM VINDO DO SENSOR HALL---------*/
		if(Carro.IC.IC_compare1 == 0){
			if(Carro.IC.IC_compare_cont	<	10000)
				Carro.IC.IC_compare_cont++;
			if(Carro.IC.IC_compare_cont>200){
				Carro.IC.Frequency	 = 0;
				Carro.Clock_rpm 	 = 0;
				Carro.Clock_rpm_Conv = 0;
			}
		}
		else{
			Carro.IC.IC_compare_cont = 	0;
			Carro.IC.IC_compare1	 =	0;
		}




		/*PRESSIONAMENTO BTN_ESQ*/
		if(READ_ESQ){

			BTN_ESQ.Cont_N_Press =0;
			(BTN_ESQ.ContPress <= DEF_CLICK_LONGO) ? (BTN_ESQ.ContPress++) : 0;

			/*	PRESSIONAMENTO LENTO	*/
			if(BTN_ESQ.ContPress > DEF_CLICK_LONGO)
			{
				BTN_ESQ.ContPress 	= 80; // revisar teste
				BTN_ESQ.FLAG 		= 1;//PRESSIONAMENTO ESPECIFICO CANCELADO A BAIXO  //revisar teste
				Callback_CURTO_PB_ESQ();
			}

		}else
		{
			BTN_ESQ.FLAG 		= 0;
			BTN_ESQ.ContPress 	= 0;
		}

		/*PRESSIONAMENTO BTN_MENU*/
		if(READ_MENU){

			BTN_MENU.Cont_N_Press =0;
			(BTN_MENU.ContPress <= DEF_CLICK_LONGO) ? (BTN_MENU.ContPress++) : 0;

			/*	PRESSIONAMENTO LENTO	*/
			if(BTN_MENU.ContPress > DEF_CLICK_LONGO)
			{
				HAL_GPIO_EXTI_Callback(BTN_MENU_Pin);
			}

		}else
		{
			BTN_MENU.FLAG 		= 0;
			BTN_MENU.ContPress 	= 0;
		}

		/*PRESSIONAMENTO BTN_DIR*/
		if(READ_DIR){

			BTN_DIR.Cont_N_Press =0;
			(BTN_DIR.ContPress <= DEF_CLICK_LONGO) ? (BTN_DIR.ContPress++) : 0;

			//			/*	PRESSIONAMENTO LENTO	*/
			//			if(BTN_DIR.ContPress > DEF_CLICK_LONGO)
			//			{
			//				HAL_GPIO_EXTI_Callback(BTN_DIR_Pin);
			//			}
			/*	PRESSIONAMENTO LENTO	*/
			if(BTN_DIR.ContPress > DEF_CLICK_LONGO)
			{
				BTN_DIR.ContPress 	= 80; // revisar teste
				BTN_DIR.FLAG 		= 1;//PRESSIONAMENTO ESPECIFICO CANCELADO A BAIXO  //revisar teste
				Callback_CURTO_PB_DIR();
			}


		}else
		{
			BTN_DIR.FLAG 		= 0;
			BTN_DIR.ContPress 	= 0;
		}
	}
	/*----------------------- TIM 2   PASSO DE 100 MILISEGUNDOS---------------------*/
	if (htim == &htim2 ){// 100 milisegundos
		if(Cont_100ms<10)
		{
			Cont_100ms++;
		}
		else
		{
			Cont_100ms=0;

			Callback_100ms();
		}
	}
	/*----------------------- TIM 2   PASSO DE 500 MILISEGUNDOS---------------------*/
	if (htim == &htim2 ){// 500 milisegundos
		if(Cont_500ms<50)
		{
			Cont_500ms++;
		}
		else
		{
			Cont_500ms=0;
			Callback_500ms();
		}
	}
	/*----------------------- TIM 2   PASSO DE 1000 MILISEGUNDOS---------------------*/
	if (htim == &htim2 ){// 1000 milisegundos
		if(Cont_1000ms<100)
		{
			Cont_1000ms++;
		}
		else
		{
			Cont_1000ms=0;
			Callback_1000ms();
		}
	}
}

//--PASSO DE TEMPO DE 0.1 SEGUNDO------------------------------------
void Callback_100ms(void)
{

}//

//--PASSO DE TEMPO DE 0.5 SEGUNDO------------------------------------
void Callback_500ms(void)
{

}//

//--PASSO DE TEMPO DE 1 SEGUNDO--------------------------------------
void Callback_1000ms(void)
{

	//Coleta status do nivel
	Carro.Nivel = READ_NIVEL;

	//coleta da velocidade e conversao
	Carro.Velocidade_ms = ((float)Carro.Clock_rpm/DEF_NUM_DENTES) * ((float)Carro.Diametro_pneu/100)* 3.6 * 3.14 * 1/10;
	Carro.Velocidade_kmh = Carro.Velocidade_ms* 3.6;

	//BOMBA 1
	if(Carro.Switch_bomba_1 == 1)
	{
		Carro.FLAG_bomba_1 = 1;
		Carro.Delta_D_metros = Carro.Delta_D_metros +  Carro.Velocidade_ms;
		Carro.Delta_Area 		= Carro.Delta_Area + (Carro.Velocidade_ms * ( Carro.Comprimento_braco/100));
	}
	else
	{
		Carro.FLAG_bomba_1 = 0;
	}

	//liberacao de funcionamento das bombas
	if(Carro.Velocidade_kmh >= Carro.Velocidade_troca || Carro.MODO == 1)
	{

		//BOMBA DIREITA
		if(Carro.Switch_bomba_2 == 1)
		{
			Carro.FLAG_bomba_2 = 1;
			Carro.Delta_D_metros = Carro.Delta_D_metros +  Carro.Velocidade_ms;
			Carro.Delta_Area 		= Carro.Delta_Area + (Carro.Velocidade_ms * ( Carro.Comprimento_braco/100));
		}
		else
		{
			Carro.FLAG_bomba_2 = 0;
		}
	}
	else
	{
		//Carro.FLAG_bomba_1 = 0;
		Carro.FLAG_bomba_2 = 0;
	}


	Carro.Delta_Hect = Carro.Delta_Area / 10000;
	FLAG_REFRESH 		= 	1;
}//

//--CALLBACK INTERRUPÇÃO DO BOTÃO ----------------------rising-------
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	switch (GPIO_Pin) {
		case BTN_ESQ_Pin:
			Cont_sem_click = 0;

			BTN_ESQ.Cont_N_Press = 0; //zera a contagem que é feita no timer de contagem

			/*	PRESSIONAMENTO CURTO	*/
			if(		BTN_ESQ.ContPress >= DEF_CLICK_CURTO 		&&
					BTN_ESQ.ContPress < DEF_CLICK_LONGO)//tempo de bounce a ser calculado ainda para evitar clique ruidoso
			{
				Callback_CURTO_PB_ESQ();
			}
			/*	PRESSIONAMENTO LENTO	*/
			else if(BTN_ESQ.ContPress >= DEF_CLICK_LONGO)//tempo de bounce a ser calculado ainda para evitar clique ruidoso
			{
				Callback_LONGO_PB_ESQ();
			}
			BTN_ESQ.ContPress	= 0;
			break;

		case BTN_MENU_Pin:
			Cont_sem_click = 0;

			BTN_MENU.Cont_N_Press = 0; //zera a contagem que é feita no timer de contagem

			/*	PRESSIONAMENTO CURTO	*/
			if(		BTN_MENU.ContPress >= DEF_CLICK_CURTO 		&&
					BTN_MENU.ContPress < DEF_CLICK_LONGO)//tempo de bounce a ser calculado ainda para evitar clique ruidoso
			{
				Callback_CURTO_PB_MENU();
			}
			/*	PRESSIONAMENTO LENTO	*/
			else if(BTN_MENU.ContPress >= DEF_CLICK_LONGO)//tempo de bounce a ser calculado ainda para evitar clique ruidoso
			{
				Callback_LONGO_PB_MENU();
			}
			BTN_MENU.ContPress	= 0;
			break;

		case BTN_DIR_Pin:
			Cont_sem_click = 0;

			BTN_DIR.Cont_N_Press = 0; //zera a contagem que é feita no timer de contagem

			/*	PRESSIONAMENTO CURTO	*/
			if(		BTN_DIR.ContPress >= DEF_CLICK_CURTO 		&&
					BTN_DIR.ContPress < DEF_CLICK_LONGO)//tempo de bounce a ser calculado ainda para evitar clique ruidoso
			{
				Callback_CURTO_PB_DIR();
			}
			/*	PRESSIONAMENTO LENTO	*/
			else if(BTN_DIR.ContPress >= DEF_CLICK_LONGO)//tempo de bounce a ser calculado ainda para evitar clique ruidoso
			{
				Callback_LONGO_PB_DIR();
			}
			BTN_DIR.ContPress	= 0;
			break;
	}
}

//--PRESSIONAMENTO_CURTO_PB_ESQ--------------------------------------
void Callback_CURTO_PB_ESQ(void)
{
	BTN_ESQ.ContPress	= 0;
	__NOP();
	switch (Selecao_Tela) {

		case TELA_PRINCIPAL:
			FLAG_REFRESH = 1;
			/*-DESATIVA BOMBA ESQUERDA-*/
			if(Carro.Switch_bomba_1==1)
			{
				Carro.Switch_bomba_1 = 0;
				M_LED_1_OFF
			}
			/*-  ATIVA BOMBA ESQUERDA-*/
			else
			{
				Carro.Switch_bomba_1 = 1;
				M_LED_1_ON
			}
			break;

		case TELA_DIAMETRO_PNEU:
			if(Carro.Diametro_pneu > DEF_LIMITE_DIAMETRO_MIN)
			{
				Carro.Diametro_pneu--;
			}
			else
			{
				Carro.Diametro_pneu=DEF_LIMITE_DIAMETRO_MAX;
			}

			FLAG_REFRESH = 1;
			break;

		case TELA_LARGURA_BRACO:
			if(Carro.Comprimento_braco > DEF_LIMITE_LARGURA_MIN)
			{
				Carro.Comprimento_braco--;
			}
			else
			{
				Carro.Comprimento_braco=DEF_LIMITE_LARGURA_MAX;
			}


			FLAG_REFRESH = 1;
			break;

		case TELA_VELOCIDADE_TROCA:
			if(Carro.Velocidade_troca > DEF_VELOCIDADE_MIN)
			{
				Carro.Velocidade_troca--;
			}
			else
			{
				Carro.Velocidade_troca=DEF_VELOCIDADE_MAX;
			}


			FLAG_REFRESH = 1;
			break;

		case TELA_MODO:
			Carro.MODO = !Carro.MODO;

			FLAG_REFRESH = 1;
			break;

		default:
			break;
	}
}//

//--PRESSIONAMENTO_LONGO_PB_ESQ--------------------------------------
void Callback_LONGO_PB_ESQ(void)
{
	BTN_ESQ.ContPress	= 0;
	__NOP();
}

//--PRESSIONAMENTO_CURTO_PB_DIR--------------------------------------
void Callback_CURTO_PB_DIR(void)
{
	BTN_DIR.ContPress	= 0;
	__NOP();
	switch (Selecao_Tela) {

		case TELA_PRINCIPAL:
			FLAG_REFRESH = 1;
			/*-DESATIVA BOMBA DIREITA-*/
			if(Carro.Switch_bomba_2==1)
			{
				Carro.Switch_bomba_2 = 0;
				M_LED_2_OFF
			}
			/*-  ATIVA BOMBA DIREITA-*/
			else
			{
				Carro.Switch_bomba_2 = 1;
				M_LED_2_ON
			}
			break;

		case TELA_DIAMETRO_PNEU:
			if(Carro.Diametro_pneu < DEF_LIMITE_DIAMETRO_MAX)
			{
				Carro.Diametro_pneu++;
			}
			else
			{
				Carro.Diametro_pneu = DEF_LIMITE_DIAMETRO_MIN;
			}
			FLAG_REFRESH = 1;
			break;

		case TELA_LARGURA_BRACO:
			if(Carro.Comprimento_braco < DEF_LIMITE_LARGURA_MAX)
			{
				Carro.Comprimento_braco+=10;
			}
			else
			{
				Carro.Comprimento_braco=DEF_LIMITE_LARGURA_MIN;
			}
			FLAG_REFRESH = 1;
			break;

		case TELA_VELOCIDADE_TROCA:
			if(Carro.Velocidade_troca < DEF_VELOCIDADE_MAX)
			{
				Carro.Velocidade_troca++;
			}
			else
			{
				Carro.Velocidade_troca=DEF_VELOCIDADE_MIN;
			}

			FLAG_REFRESH = 1;
			break;

		case TELA_MODO:
			Carro.MODO = !Carro.MODO;

			FLAG_REFRESH = 1;
			break;

			//Carro.Comprimento_braco

		default:
			break;
	}
}//

//--PRESSIONAMENTO_LONGO_PB_DIR--------------------------------------
void Callback_LONGO_PB_DIR(void)
{
	BTN_DIR.ContPress	= 0;
	__NOP();
}//

//--PRESSIONAMENTO_CURTO_PB_MENU-------------------------------------
void Callback_CURTO_PB_MENU(void)
{
	BTN_MENU.ContPress	= 0;
	__NOP();
	switch (Selecao_Tela) {

		case TELA_PRINCIPAL:
			Selecao_Tela_next = TELA_DIAMETRO_PNEU;
			break;
		case TELA_DIAMETRO_PNEU:
			Selecao_Tela_next = TELA_LARGURA_BRACO;
			Grava_memoria();//ATUALIZA MEMORIA QUANDO TROCADA A TELA
			break;
		case TELA_LARGURA_BRACO:
			Selecao_Tela_next = TELA_VELOCIDADE_TROCA;
			Grava_memoria();//ATUALIZA MEMORIA QUANDO TROCADA A TELA
			break;
		case TELA_VELOCIDADE_TROCA:
			Selecao_Tela_next = TELA_MODO;
			Grava_memoria();//ATUALIZA MEMORIA QUANDO TROCADA A TELA
			break;
		case TELA_MODO:
			Selecao_Tela_next = TELA_PRINCIPAL;
			Grava_memoria();//ATUALIZA MEMORIA QUANDO TROCADA A TELA
			break;
	}
	//Selecao_Tela_next
}//

//--PRESSIONAMENTO_LONGO_PB_MENU-------------------------------------
void Callback_LONGO_PB_MENU(void)
{
	BTN_MENU.ContPress	= 0;
	__NOP();
}//

//--CALLBACK PARA LEITURA DE FREQUENCIA -----------------------------
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){

	if (htim == &htim3 && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1){

		if (Carro.IC.Is_First_Captured==0) {// is the first value captured ?
			Carro.IC.Value1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // capture the first value
			Carro.IC.Is_First_Captured =1;  	// set the first value captured as true
		}

		else if (Carro.IC.Is_First_Captured) {// if the first is captured

			Carro.IC.Value2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // capture second value

			if (Carro.IC.Value2 > Carro.IC.Value1)
				Carro.IC.Difference = Carro.IC.Value2-Carro.IC.Value1;   // calculate the difference

			else if (Carro.IC.Value2 < Carro.IC.Value1)
				Carro.IC.Difference = ((0xffff-Carro.IC.Value1)+Carro.IC.Value2);
			//			else
			//				Error_Handler();

			Carro.IC.Frequency = HAL_RCC_GetPCLK1Freq()/Carro.IC.Difference/100;  // calculate frequency


			if(Carro.IC.Frequency > 3 && Carro.IC.Frequency < 100)//RANGE DE LEITURA ROTAÇÃO INDUTIVO
			{
//				for(int i=0 ; i<9 ; i++)
//				{
//					Carro.IC.Media[i] = Carro.IC.Media[i+1];
//				}
//				Carro.IC.Media[9] = Carro.IC.Frequency;
//				Carro.IC.Media_calculada=0;
//
//				for (int j = 0; j < 10; ++j) {
//					Carro.IC.Media_calculada = Carro.IC.Media[j]+Carro.IC.Media_calculada;
//				}
//				Carro.Clock_rpm = Carro.IC.Media_calculada/10; // SETA A VARIAVEL COM A MÉDIA FIFO

				Carro.Clock_rpm = Carro.IC.Frequency; // SETA A VARIAVEL COM A MÉDIA FIFO

				Carro.Clock_rpm_Conv = (float)Carro.Clock_rpm*(float)Carro.Correcao_rpm;
			}
			else
				Carro.Clock_rpm = 0;

			Carro.IC.Is_First_Captured 		= 0;  					// reset the first captured
			Carro.IC.IC_compare1			= 1;//controle de perca de rotação
		}
	}
}

//--CONTROLA ATUALIZAÇÃO DE TELA ------------------------------------
void Controle_De_Telas(void){

	/*------- CONTROLE DE TELAS---------------------------------------------------*/
	if(Selecao_Tela_next != Selecao_Tela){
		Selecao_Tela = Selecao_Tela_next;	//ATUALIZA PARA PRÓXIMA TELA
		FLAG_REFRESH = 1;					//SOLICITA ATUALIZAÇÃO DE TELA
	}

	/*	Se o display estiver ocupado, monta-se um sistema de "pilha" com as telas
	 *  Fazendo assim, uma impressão sem travamentos
	 *  Estrutura de funcionamento dada em 2 verificações
	 *  */
	// Primeira verificação de display
	if(FLAG_TELA_BUSY == 0 && FLAG_REFRESH){
		FLAG_REFRESH 		= 	0;			//RESETA FLAG DE LIBERAÇÃO DE TELA
		FLAG_ATUALIZA_TELA	=	1;			//LIBERA IMPRESSÃO EM DISPLAY
	}
	// Segunda verificação de display
	if(FLAG_ATUALIZA_TELA==1){

		FLAG_TELA_BUSY = 1;		//SETA DISPLAY COMO OCUPADO
		u8g_FirstPage(&u8g);
		do {

			switch (Selecao_Tela) {

				case TELA_PRINCIPAL:
					Draw_principal(&Carro);
					break;

				case TELA_DIAMETRO_PNEU:
					Tela_Menu_Raio(Carro.Diametro_pneu);
					break;

				case TELA_LARGURA_BRACO:
					Tela_Menu_braco(Carro.Comprimento_braco);
					break;

				case TELA_VELOCIDADE_TROCA:
					Tela_Menu_Vel_troca(Carro.Velocidade_troca);
					break;

				case TELA_MODO:
					Tela_Menu_Modo(Carro.MODO);
					break;
			}

		} while( u8g_NextPage(&u8g));

		FLAG_ATUALIZA_TELA = 0;		//RESETA LIBERAÇÃO DE IMPRESSÃO EM DISPLAY
		FLAG_TELA_BUSY = 0;			//DESOCUPA DISPLAY
	}


}//

//----------- FUNÇÃO DE GRAVAÇÃO NA MEMÓRIA -------------------------------------------
void Grava_memoria(void){
	/* Unlock the Flash to enable the flash control register access *************/
	HAL_FLASH_Unlock();

	/* Erase the user Flash area
		(area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

	/* Fill EraseInit structure*/
	EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.PageAddress = FLASH_USER_START_ADDR;
	EraseInitStruct.NbPages     = (FLASH_USER_END_ADDR - FLASH_USER_START_ADDR) / FLASH_PAGE_SIZE;

	/* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
		 you have to make sure that these data are rewritten before they are accessed during code
		 execution. If this cannot be done safely, it is recommended to flush the caches by setting the
		 DCRST and ICRST bits in the FLASH_CR register. */
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK){
		/*
			Error occurred while page erase.
			User can add here some code to deal with this error.
			PAGEError will contain the faulty page and then to know the code error on this page,
			user can call function 'HAL_FLASH_GetError()'
		 */
		/* Infinite loop */
		while (1){

			/* Make LED3 blink (100ms on, 2s off) to indicate error in Erase operation */
			//MACRO_LED_ON
			HAL_Delay(100);
			//MACRO_LED_OFF
			HAL_Delay(2000);
		}
	}

	/* Program the user Flash area word by word
		(area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

	Write_in_flash_HIBRIDO(FLASH_USER_DIAMETRO	,Carro.Diametro_pneu);
	Write_in_flash_HIBRIDO(FLASH_USER_LARGURA		,Carro.Comprimento_braco);
	Write_in_flash_HIBRIDO(FLASH_USER_VEL_MIN		,Carro.Velocidade_troca);

	/* Lock the Flash to disable the flash control register access (recommended
		 to protect the FLASH memory against possible unwanted operation) *********/
	HAL_FLASH_Lock();

}

//----------- VERIFICA E ATUALIZA MEMORIAS PARA INICIO DO PROGRAMA---------------------
void Atualiza_Variaveis (void){

	__IO uint32_t VerificaMEM[3];

	VerificaMEM[0] = *(__IO uint32_t *)FLASH_USER_DIAMETRO;
	VerificaMEM[1] = *(__IO uint32_t *)FLASH_USER_LARGURA;
	VerificaMEM[2] = *(__IO uint32_t *)FLASH_USER_VEL_MIN;

	if( 	VerificaMEM[0] 	< DEF_LIMITE_DIAMETRO_MIN 	||		VerificaMEM[0]		> DEF_LIMITE_DIAMETRO_MAX 	||
			VerificaMEM[1] 	< DEF_LIMITE_LARGURA_MIN 	|| 	VerificaMEM[1] 	> DEF_LIMITE_LARGURA_MAX	||
			VerificaMEM[2] 	< DEF_VELOCIDADE_MIN			|| 	VerificaMEM[2]		> DEF_VELOCIDADE_MAX		  ){// reseta memoria

		/*DEFINIÇÕES DE FABRICA OU PÓS FORMAT*/

		Carro.Diametro_pneu  		= DEF_LIMITE_DIAMETRO_STD;
		Carro.Comprimento_braco 	= DEF_LIMITE_LARGURA_STD;
		Carro.Velocidade_troca	   = DEF_VELOCIDADE_STD;

		Grava_memoria();

	}
	else{//tudo certo

		Carro.Diametro_pneu 			= *(__IO uint32_t *)FLASH_USER_DIAMETRO;
		Carro.Comprimento_braco		= *(__IO uint32_t *)FLASH_USER_LARGURA;
		Carro.Velocidade_troca		= *(__IO uint32_t *)FLASH_USER_VEL_MIN;
	}
}

//----------- FUNÇÃO AUXILIAR MEMÓRIA -------------------------------------------------
void Write_in_flash_HIBRIDO(uint32_t Address_Var, uint32_t Value_Var ){
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address_Var, Value_Var) != HAL_OK){// trocar pelo valor atribuido na IHM

		while (1){

			/* Make LED3 blink (100ms on, 2s off) to indicate error in Write operation */
			//	MACRO_LED_ON
			HAL_Delay(100);
			//	MACRO_LED_OFF
			HAL_Delay(2000);
		}
	}
}

//
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
