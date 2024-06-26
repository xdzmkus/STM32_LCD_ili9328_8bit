/**
  ******************************************************************************
  * @file    ili9328.h
  * @author  xdzmkus
  * @version V1.0
  * @date    2023
  * @brief   This file contains all the functions prototypes for the ili9328.c
  *          driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ILI9328_H
#define __ILI9328_H

#ifdef __cplusplus
 extern "C" {
#endif 

 /* Includes ------------------------------------------------------------------*/
#include "../lcd_drv.h"

#include <stdint.h>

/** 
  * @brief  ILI9328 ID  
  */  
#define  ILI9328_ID    0x9328
   
/** 
  * @brief  ILI9328 Size  
  */  
#define  ILI9328_LCD_PIXEL_WIDTH    ((uint16_t)240)
#define  ILI9328_LCD_PIXEL_HEIGHT   ((uint16_t)320)
   
/** 
  * @brief  ILI9328 Registers  
  */ 
#define LCD_REG_0             0x00
#define LCD_REG_1             0x01
#define LCD_REG_2             0x02
#define LCD_REG_3             0x03
#define LCD_REG_4             0x04
#define LCD_REG_7             0x07
#define LCD_REG_8             0x08
#define LCD_REG_9             0x09
#define LCD_REG_10            0x0A
#define LCD_REG_12            0x0C
#define LCD_REG_13            0x0D
#define LCD_REG_15            0x0F
#define LCD_REG_16            0x10
#define LCD_REG_17            0x11
#define LCD_REG_18            0x12
#define LCD_REG_19            0x13
#define LCD_REG_32            0x20
#define LCD_REG_33            0x21
#define LCD_REG_34            0x22
#define LCD_REG_41            0x29
#define LCD_REG_43            0x2B
#define LCD_REG_48            0x30
#define LCD_REG_49            0x31
#define LCD_REG_50            0x32
#define LCD_REG_53            0x35
#define LCD_REG_54            0x36
#define LCD_REG_55            0x37
#define LCD_REG_56            0x38
#define LCD_REG_57            0x39
#define LCD_REG_60            0x3C
#define LCD_REG_61            0x3D
#define LCD_REG_80            0x50
#define LCD_REG_81            0x51
#define LCD_REG_82            0x52
#define LCD_REG_83            0x53
#define LCD_REG_96            0x60
#define LCD_REG_97            0x61
#define LCD_REG_106           0x6A
#define LCD_REG_128           0x80
#define LCD_REG_129           0x81
#define LCD_REG_130           0x82
#define LCD_REG_131           0x83
#define LCD_REG_132           0x84
#define LCD_REG_133           0x85
#define LCD_REG_144           0x90
#define LCD_REG_146           0x92
#define LCD_REG_147           0x93
#define LCD_REG_149           0x95
#define LCD_REG_151           0x97
#define LCD_REG_152           0x98
#define LCD_REG_161           0xA1
#define LCD_REG_162           0xA2
#define LCD_REG_165           0xA5

uint16_t ili9328_GetLcdPixelWidth(void);
uint16_t ili9328_GetLcdPixelHeight(void);

void     ili9328_Init(void);

uint16_t ili9328_ReadID(void);

void     ili9328_Clear(uint16_t RGBCode);

void     ili9328_DisplayOn(void);
void     ili9328_DisplayOff(void);

void     ili9328_SetRotation(uint8_t rotation);

void     ili9328_SetCursor(uint16_t Xpos, uint16_t Ypos);

void     ili9328_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);

void     ili9328_WritePixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGBCode);
uint16_t ili9328_ReadPixel(uint16_t Xpos, uint16_t Ypos);

void     ili9328_DrawHLine(int16_t Xpos, int16_t Ypos, uint16_t Length, uint16_t RGBCode);
void     ili9328_DrawVLine(int16_t Xpos, int16_t Ypos, uint16_t Length, uint16_t RGBCode);

void     ili9328_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp);
void     ili9328_DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t *pdata, uint32_t Size);


/* LCD driver structure */
extern LCD_DrvTypeDef   ili9328_drv;

#ifdef __cplusplus
}
#endif

#endif /* __ILI9328_H */

