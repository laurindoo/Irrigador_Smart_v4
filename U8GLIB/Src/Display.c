#include "Display.h"
#include "main.h"

#include "u8g_com_arm_stm32.h" 	//---INCLUDES DISPLAY
#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include "fonts.h"							//---INCLUDES DISPLAY

extern char 		Buff_Display	[128]		;	//---- BUFF PARA IMPRESS�O 1
extern u8g_t 	u8g; 			// INSTANCIA PARA DISPLAY
const unsigned char bluetooth_8x14[] U8G_PROGMEM = {
		0x00, 0x10, 0x18, 0x14, 0x12, 0x54, 0x38, 0x18, 0x34, 0x52, 0x14, 0x18, 0x10, 0x00,
};

#define largura_display 128
#define altura_display 64


#define MENU_BMPWIDTH  5
#define MENU_BMPHEIGHT 5
const unsigned char Menu_cheio[] PROGMEM = {
		0x70, // ▐█··
		0xF8, // ██▌·
		0xF8, // ██▌·
		0xF8, // ██▌·
		0x70  // ▐█··
};

const unsigned char Menu_vazio[] PROGMEM = {
		0x70, // ▐█··
		0xD8, // █▐▌·
		0x88, // ▌·▌·
		0xD8, // █▐▌·
		0x70  // ▐█··
};

//--FUNÇÃO DE INICIALIZAÇÃO DE DISPLAY ------------------------
uint8_t Inicia_display(void)//INICIALIZACAO DO DISPLAY OLED
{
	uint8_t retorno;
	retorno = u8g_InitComFn(&u8g, &u8g_dev_ssd1306_128x64_i2c, u8g_com_arm_stm32_ssd_i2c_fn); //INICIA O DISPLAY EM I2C
	HAL_Delay(50);
	u8g_SetRot180(&u8g);					//INVERTE 180
	u8g_DisableCursor(&u8g);           		//DESABILITA O CURSOR
	u8g_SetColorIndex(&u8g,1);				//SETA O PIXEL COMO POSITIVO
	u8g_SetDefaultForegroundColor(&u8g);	//FUNDO PRETO   -   LETRA BRANCA

	return retorno;
}//																																																											//

//--DRAW CAIXA DIALOGO AVISO ----------------------------------
void Draw_principal(Hibrido_StateDef_t *carro)
{
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);

	static int Hect=0;

	Hect = carro->Delta_Area / 10000;

	u8g_DrawLine(&u8g,64, 0, 64, 32);	//LINHA VERTICAL MEIO SUPERIOR
	u8g_DrawLine(&u8g,42, 32, 42, 64);	//LINHA VERTICAL INFERIOR ESQ
	u8g_DrawBox(&u8g, 0, 0, 127, 13);  	//BACKGROUND LINHA 1
	u8g_DrawBox(&u8g, 0, 32, 127, 13);  //BACKGROUND LINHA 2

	sprintf(Buff_Display,"%2.1d,",(int)(carro->Delta_Area)/10000);
	u8g_DrawStr(&u8g, 0, 16, Buff_Display);

	sprintf(Buff_Display,"%4.4d",(int)carro->Delta_Area % ((int)Hect*10000));
	u8g_DrawStr(&u8g, 26, 16, Buff_Display);

	sprintf(Buff_Display,"%3.0dkm/h",(int)carro->Velocidade_kmh);
	u8g_DrawStr(&u8g, 68, 16, Buff_Display);

	sprintf(Buff_Display,"%3.0d C",(int)carro->TEMPERATURA);
	u8g_DrawStr(&u8g, 0, 48, Buff_Display);


	//pelo menos um dos dois deve estar selecionado
	if(carro->Switch_bomba_2)
	{

		if(carro->MODO)
		{
			u8g_DrawStr(&u8g, 50, 48,	"MANUAL");	//LINHA 1
		}

		//Abaixo do nivel minimo
		else if(carro->Nivel)
		{
			u8g_DrawStr(&u8g, 50, 48,	"liq.Baixo");	//LINHA 1
		}

		//velocidade abaixo da minima
		else if(carro->Velocidade_kmh < carro->Velocidade_troca)
		{
			u8g_DrawStr(&u8g, 50, 48,	"Vel.Baixa");	//LINHA 1
		}

		else if(carro->Velocidade_kmh < carro->Velocidade_troca)
		{
			u8g_DrawStr(&u8g, 50, 48,	"Vel.Baixa");	//LINHA 1
		}

		//funcionamento normal
		else
		{
			u8g_DrawStr(&u8g, 50, 48,	" Ativo");		//LINHA 1
		}
	}
	else
	{
		u8g_DrawStr(&u8g, 50, 48,  "Desligado");	//LINHA 1
	}


	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 0, 0,	" Hect     Veloc");	//LINHA 1
	u8g_DrawStr(&u8g, 3, 32,"Temp	   STATUS");	//LINHA 1
	u8g_SetDefaultForegroundColor(&u8g);


}

//--DRAW CAIXA DIALOGO AVISO ----------------------------------
void Draw_caixa_dialogo_aviso(char *string1, char *string2, char *string3)
{
	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;

	u8g_DrawBox(&u8g, 0, 51, 127, 64);  	//BACKGROUND BARRA INFERIOR
	u8g_DrawLine(&u8g,0, 0, 127, 0);		//LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);			//LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);		//LINHA VERTICAL DIREITA
	u8g_DrawStr(&u8g, 5, 0*h+7,string1);	//LINHA 1
	u8g_DrawStr(&u8g, 5, 1*h+7,string2);	//LINHA 2
	u8g_DrawStr(&u8g, 5, 2*h+7,string3);	//LINHA 3
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 5, 51, "OK");			//LADO ESQUERDO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);
}//

//---------- IMPRESSAO TELA MENU_MODO ----------------------------------
void Tela_Menu_Raio(uint32_t Raio)
{
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	u8g_DrawBox(&u8g, 0, 0, 127, 13);  	//BACKGROUND LINHA 1

	u8g_DrawRFrame(&u8g, 0, 25, 21, 21, 3); // frame para bota de sinal de subtraçao
	u8g_DrawBox(&u8g, 4, 34, 13, 3); // sinal de menos


	u8g_DrawRFrame(&u8g, 103, 25, 21, 21, 3); // frame para bota de sinal de subtraçao
	u8g_DrawBox(&u8g, 107, 34, 13, 3); // sinal de mais horizontal
	u8g_DrawBox(&u8g, 112, 29, 3, 13); // sinal de mais vertical


	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 0, 0,	" DIAMETRO PNEU ");	//LINHA
	u8g_SetDefaultForegroundColor(&u8g);

	sprintf(Buff_Display,"%3.0d cm",(int)Raio);
	u8g_DrawStr(&u8g, 32, 30, Buff_Display);

	//DESENHANDO CIRCULO
	Menu_bolas_display(4, 1);
}

//---------- IMPRESSAO TELA LARGURA BRACO ----------------------------------
void Tela_Menu_braco(uint32_t Braco)
{
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	u8g_DrawBox(&u8g, 0, 0, 127, 13);  	//BACKGROUND LINHA 1

	u8g_DrawRFrame(&u8g, 0, 25, 21, 21, 3); // frame para bota de sinal de subtraçao
	u8g_DrawBox(&u8g, 4, 34, 13, 3); // sinal de menos


	u8g_DrawRFrame(&u8g, 103, 25, 21, 21, 3); // frame para bota de sinal de subtraçao
	u8g_DrawBox(&u8g, 107, 34, 13, 3); // sinal de mais horizontal
	u8g_DrawBox(&u8g, 112, 29, 3, 13); // sinal de mais vertical


	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 0, 0,	"  COMPRIMENTO L");	//LINHA
	u8g_SetDefaultForegroundColor(&u8g);

	sprintf(Buff_Display,"%3.0d cm",(int)Braco);
	u8g_DrawStr(&u8g, 32, 30, Buff_Display);

	//DESENHANDO CIRCULO
	Menu_bolas_display(4, 2);
}

//---------- IMPRESSAO TELA LARGURA BRACO ----------------------------------
void Tela_Menu_Vel_troca(uint32_t Velocidade)
{
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	u8g_DrawBox(&u8g, 0, 0, 127, 13);  	//BACKGROUND LINHA 1

	u8g_DrawRFrame(&u8g, 0, 25, 21, 21, 3); // frame para bota de sinal de subtraçao
	u8g_DrawBox(&u8g, 4, 34, 13, 3); // sinal de menos


	u8g_DrawRFrame(&u8g, 103, 25, 21, 21, 3); // frame para bota de sinal de subtraçao
	u8g_DrawBox(&u8g, 107, 34, 13, 3); // sinal de mais horizontal
	u8g_DrawBox(&u8g, 112, 29, 3, 13); // sinal de mais vertical


	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 0, 0,	"  VEL. MIN");	//LINHA
	u8g_SetDefaultForegroundColor(&u8g);

	sprintf(Buff_Display,"%3.0d km/h",(int)Velocidade);
	u8g_DrawStr(&u8g, 32, 30, Buff_Display);

	//DESENHANDO CIRCULO
	Menu_bolas_display(4, 3);
}


//---------- IMPRESSAO TELA SELECAO MODO ----------------------------------
void Tela_Menu_Modo(uint8_t Modo)
{
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	u8g_DrawBox(&u8g, 0, 0, 127, 13);  	//BACKGROUND LINHA 1

	u8g_DrawRFrame(&u8g, 0, 25, 21, 21, 3); // frame para bota de sinal de subtraçao
	u8g_DrawBox(&u8g, 4, 34, 13, 3); // sinal de menos


	u8g_DrawRFrame(&u8g, 103, 25, 21, 21, 3); // frame para bota de sinal de subtraçao
	u8g_DrawBox(&u8g, 107, 34, 13, 3); // sinal de mais horizontal
	u8g_DrawBox(&u8g, 112, 29, 3, 13); // sinal de mais vertical


	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 0, 0,	"  MODO OPERACAO");	//LINHA
	u8g_SetDefaultForegroundColor(&u8g);


	if(Modo == 1)
	{
		u8g_DrawStr(&u8g, 32, 30,	" MANUAL");	//LINHA
	}
	else
	{
		u8g_DrawStr(&u8g, 32, 30,	"  AUTO");	//LINHA
	}
	//
	//	sprintf(Buff_Display,"%3.0d km/h",(int)Velocidade);
	//	u8g_DrawStr(&u8g, 32, 30, Buff_Display);

	//DESENHANDO CIRCULO
	Menu_bolas_display(4, 4);
}

//---------- FUNÇÃO IMPRESSÃO INDICAÇÃO MENU ---------------------------
void Menu_bolas_display(uint8_t quantidade, uint8_t indice)
{

#define ALTURA_BOLA_INDICACAO 56
#define LARGURA_BOLA_INDICACAO 45
	for (int i = 1; i <= quantidade; ++i) {
		if(i != indice)
			u8g_DrawBitmap(&u8g,LARGURA_BOLA_INDICACAO+8*(i-1),ALTURA_BOLA_INDICACAO,1,MENU_BMPWIDTH,Menu_vazio);
		else
			u8g_DrawBitmap(&u8g,LARGURA_BOLA_INDICACAO+8*(i-1),ALTURA_BOLA_INDICACAO,1,MENU_BMPWIDTH,Menu_cheio);
	}
}

//--SETA FONTE ------------------------------------------
void u8g_My_SetaFonte(const u8g_fntpgm_uint8_t  *font)
{
	u8g_SetFont(&u8g, font);
	u8g_SetFontRefHeightText(&u8g);
	u8g_SetFontPosTop(&u8g);
}//
