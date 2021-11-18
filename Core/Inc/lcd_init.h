#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#include "Init.h"
#include "main.h"

#define USE_HORIZONTAL 0  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����

#define LCD_W 240
#define LCD_H 240

//-----------------LCD�˿ڶ���---------------- 

#define LCD_SCLK_Clr() HAL_GPIO_WritePin(GPIOA,SCL_Pin,GPIO_PIN_RESET)//SCL=SCLK
#define LCD_SCLK_Set() HAL_GPIO_WritePin(GPIOA,SCL_Pin,GPIO_PIN_SET)

#define LCD_MOSI_Clr() HAL_GPIO_WritePin(GPIOA,SDA_Pin,GPIO_PIN_RESET)//SDA=MOSI
#define LCD_MOSI_Set() HAL_GPIO_WritePin(GPIOA,SDA_Pin,GPIO_PIN_SET)

#define LCD_RES_Clr()  HAL_GPIO_WritePin(GPIOC,RES_Pin,GPIO_PIN_RESET)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(GPIOC,RES_Pin,GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(GPIOG,DC_Pin,GPIO_PIN_RESET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(GPIOG,DC_Pin,GPIO_PIN_SET)

#define LCD_CS_Clr()   HAL_GPIO_WritePin(GPIOC,CS1_Pin,GPIO_PIN_RESET)//CS1
#define LCD_CS_Set()   HAL_GPIO_WritePin(GPIOC,CS1_Pin,GPIO_PIN_SET)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(GPIOA,BLK_Pin,GPIO_PIN_RESET)//BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(GPIOA,BLK_Pin,GPIO_PIN_SET)

#define ZK_MISO        HAL_GPIO_ReadPin(GPIOB,FSO_Pin)//MISO  ��ȡ�ֿ���������

#define ZK_CS_Clr()    HAL_GPIO_WritePin(GPIOG,CS2_Pin,GPIO_PIN_RESET)//CS2 �ֿ�Ƭѡ
#define ZK_CS_Set()    HAL_GPIO_WritePin(GPIOG,CS2_Pin,GPIO_PIN_SET)


void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(u8 dat);//ģ��SPIʱ��
void LCD_WR_DATA8(u8 dat);//д��һ���ֽ�
void LCD_WR_DATA(u16 dat);//д�������ֽ�
void LCD_WR_REG(u8 dat);//д��һ��ָ��
void LCD_Address_Set(u16 x1, u16 y1, u16 x2, u16 y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��
#endif




