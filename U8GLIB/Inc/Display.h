#ifndef DISPLAY_H
#define DISPLAY_H

#include "main.h"

uint8_t Inicia_display(void);
void Menu_bolas_display(uint8_t quantidade, uint8_t indice);
void 	u8g_My_SetaFonte(const uint8_t  *font);
void Draw_principal(Hibrido_StateDef_t *carro);
void Tela_Menu_Raio(uint32_t Raio);
void Tela_Menu_braco(uint32_t Braco);
void Tela_Menu_Vel_troca(uint32_t Velocidade);
void Tela_Menu_Modo(uint8_t Modo);
void Draw_caixa_dialogo_aviso(char *string1, char *string2, char *string3);
#endif /* __DISPLAY_H__ */

/************************ (C) COPYRIGHT MRrider *****END OF FILE****/
