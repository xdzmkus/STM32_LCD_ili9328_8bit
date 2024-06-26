/*
 * appMain.cpp
 *
 *  Author: xdzmkus
 */

#include "appMain.h"

#include "main.h"

#include "lcd.h"

#include <stdio.h>
#include <algorithm>

extern uint8_t stm32_mini_map[];

uint16_t lcd_colors[] =
{
LCD_COLOR_BLUE,
LCD_COLOR_GREEN,
LCD_COLOR_RED,
LCD_COLOR_CYAN,
LCD_COLOR_MAGENTA,
LCD_COLOR_YELLOW,
LCD_COLOR_LIGHTBLUE,
LCD_COLOR_LIGHTGREEN,
LCD_COLOR_LIGHTRED,
LCD_COLOR_LIGHTCYAN,
LCD_COLOR_LIGHTMAGENTA,
LCD_COLOR_LIGHTYELLOW,
LCD_COLOR_DARKBLUE,
LCD_COLOR_DARKGREEN,
LCD_COLOR_DARKRED,
LCD_COLOR_DARKCYAN,
LCD_COLOR_DARKMAGENTA,
LCD_COLOR_DARKYELLOW,
LCD_COLOR_WHITE,
LCD_COLOR_LIGHTGRAY,
LCD_COLOR_GRAY,
LCD_COLOR_DARKGRAY,
LCD_COLOR_BLACK,
LCD_COLOR_BROWN,
LCD_COLOR_ORANGE };

void demoClear()
{
	for (uint8_t r = 0; r < 25; r++)
	{
		HAL_Delay(1000);

		LCD_SetRotation(r);

		LCD_Clear(lcd_colors[r]);
	}
}

void demoPixels()
{
	static uint16_t color = -1;

	for (uint8_t r = 0; r < 4; r++)
	{
		LCD_SetRotation(r);

		for (uint16_t y = 0; y < LCD_GetHeight(); ++y)
		{
			for (uint16_t x = 0; x < LCD_GetWidth(); ++x)
			{
				LCD_DrawPixel(x, y, color--);
			}
		}

		HAL_Delay(1000);
	}
}

void demoLines()
{
	LCD_SetTextColor(LCD_COLOR_WHITE);

	for (uint8_t r = 0; r < 4; r++)
	{
		LCD_SetRotation(r);

		LCD_Clear(LCD_COLOR_BLACK);

		for (uint16_t x = 0; x < LCD_GetWidth(); x += 6)
		{
			LCD_DrawLine(0, 0, x, LCD_GetHeight() - 1);
		}
		for (uint16_t y = 0; y < LCD_GetHeight(); y += 6)
		{
			LCD_DrawLine(0, 0, LCD_GetWidth() - 1, y);
		}

		LCD_Clear(LCD_COLOR_BLUE);

		int16_t startX = LCD_GetWidth() / 2 - LCD_GetWidth();
		int16_t endX = LCD_GetWidth() / 2 + LCD_GetWidth();

		int16_t startY = LCD_GetHeight() / 2 - LCD_GetHeight();
		int16_t endY = LCD_GetHeight() / 2 + LCD_GetHeight();

		for (int16_t y = startY; y < endY; y += 6)
		{
			LCD_DrawLine(startX, y, endX, LCD_GetHeight() - y);
		}

		for (int16_t x = startX; x < endX; x += 6)
		{
			LCD_DrawLine(x, endY, LCD_GetWidth() - x, startY);
		}

		HAL_Delay(1000);
	}
}

void demoFastLines()
{
	for (uint8_t r = 0; r < 4; r++)
	{
		LCD_SetRotation(r);

		LCD_Clear(LCD_COLOR_WHITE);

		LCD_SetTextColor(LCD_COLOR_RED);

		for (int16_t y = -10; y < LCD_GetHeight(); y += 10)
		{
			LCD_DrawHLine(0, y, LCD_GetWidth());
		}

		LCD_SetTextColor(LCD_COLOR_GREEN);

		for (int16_t x = -10; x < LCD_GetWidth(); x += 10)
		{
			LCD_DrawVLine(x, 0, LCD_GetHeight());
		}

		HAL_Delay(1000);
	}
}

void demoRects()
{
	for (uint8_t r = 0; r < 4; r++)
	{
		LCD_SetRotation(r);

		LCD_Clear(LCD_COLOR_WHITE);

		LCD_SetTextColor(lcd_colors[r]);

		uint16_t cx = LCD_GetWidth() / 2;
		uint16_t cy = LCD_GetHeight() / 2;

		uint16_t n = std::min(LCD_GetWidth(), LCD_GetHeight());

		for (uint16_t i = 2; i < n; i += 6)
		{
			uint16_t i2 = i / 2;
			LCD_DrawRect(cx - i2, cy - i2, i, i);
		}

		HAL_Delay(1000);
	}
}

void demoFilledRects()
{
	for (uint8_t r = 0; r < 4; r++)
	{
		LCD_SetRotation(r);

		LCD_Clear(LCD_COLOR_WHITE);

		LCD_SetTextColor(lcd_colors[r]);

		uint16_t cx = LCD_GetWidth() / 2;
		uint16_t cy = LCD_GetHeight() / 2;

		uint16_t n = std::min(LCD_GetWidth(), LCD_GetHeight());

		for (uint16_t i = 2; i < n; i += 6)
		{
			uint16_t i2 = i / 2;
			LCD_FillRect(cx - i2, cy - i2, i, i);
		}

		HAL_Delay(1000);
	}
}

void demoCircles()
{
	for (uint8_t r = 0; r < 4; r++)
	{
		LCD_SetRotation(r);

		LCD_Clear(LCD_COLOR_WHITE);

		LCD_SetTextColor(lcd_colors[r]);

		uint16_t r1 = 10;
		uint16_t r2 = 20;

		uint16_t w = LCD_GetWidth() + r1;
		uint16_t h = LCD_GetHeight() + r1;

		for (uint16_t x = r1; x < w; x += r2)
		{
			for (uint16_t y = r1; y < h; y += r2)
			{
				LCD_DrawCircle(x, y, r1);
			}
		}

		HAL_Delay(1000);
	}
}

void demoFilledCircles()
{
	for (uint8_t r = 0; r < 4; r++)
	{
		LCD_SetRotation(r);

		LCD_Clear(LCD_COLOR_WHITE);

		LCD_SetTextColor(lcd_colors[r]);

		uint16_t r1 = 10;
		uint16_t r2 = 20;

		uint16_t w = LCD_GetWidth();
		uint16_t h = LCD_GetHeight();

		for (uint16_t x = 0; x <= w; x += r2)
		{
			for (uint16_t y = 0; y <= h; y += r2)
			{
				LCD_FillCircle(x, y, r1);
			}
		}

		HAL_Delay(1000);
	}
}

void demoChar()
{
	LCD_Clear(LCD_COLOR_WHITE);

	LCD_SetTextColor(LCD_COLOR_RED);

	LCD_SetFont(&Font24);

	for (uint8_t r = 0; r < 4; r++)
	{
		LCD_SetRotation(r);

		LCD_DisplayChar(10, 10, 'F');

		LCD_DisplayStringAt(10, 35, (uint8_t*) "ILI9325", CENTER_MODE);

		HAL_Delay(1000);
	}
}

void demoImage()
{
	for (uint8_t r = 0; r < 4; r++)
	{
		LCD_SetRotation(r);

		LCD_DrawRGBImage(0, 0, 240, 180, (uint16_t*)stm32_mini_map);

		HAL_Delay(1000);
	}
}

void demoArc()
{
	LCD_Clear(LCD_COLOR_WHITE);

	const uint8_t SECTORS = 20;

	/** The ANGLE sector. */
	const float ANGLE_SECTOR = 360.0 / SECTORS;

	/** The ANGLE start. */
	const float ANGLE_START = 0 - ANGLE_SECTOR / 2;

	// ============================<
	// Define sizes of board's figures
	// ================================>
	const uint16_t centerX = 120;
	const uint16_t centerY = 120;

	const float widthNarrowZone = 240 / SECTORS;
	const float widthWideZone = widthNarrowZone * 2;

	// ==============<
	// Make MISS-sectors
	// ==================>
	float angleStartZone = ANGLE_START;
	float angleEndZone = ANGLE_START + ANGLE_SECTOR;
	float outerRadiusZone = 3 * widthWideZone + 4 * widthNarrowZone;
	float innerRadiusZone = outerRadiusZone - widthWideZone;

	LCD_SetTextColor(LCD_COLOR_BLACK);

	for (uint8_t i = 0; i < SECTORS; i++)
	{
		LCD_FillArc(centerX, centerY, outerRadiusZone, innerRadiusZone, angleStartZone, angleEndZone);

		angleStartZone = angleEndZone;
		angleEndZone += ANGLE_SECTOR;
	}
	//=================<
	// Make DOUBLE-sectors
	// ====================>
	angleStartZone = ANGLE_START;
	angleEndZone = ANGLE_START + ANGLE_SECTOR;
	innerRadiusZone -= widthNarrowZone;
	outerRadiusZone -= widthWideZone;

	for (uint8_t i = 0; i < SECTORS; i++)
	{
		LCD_SetTextColor((i % 2 == 0) ? LCD_COLOR_GREEN : LCD_COLOR_RED);

		LCD_FillArc(centerX, centerY, outerRadiusZone, innerRadiusZone, angleStartZone, angleEndZone);

		angleStartZone = angleEndZone;
		angleEndZone += ANGLE_SECTOR;
	}

	// ====================<
	// Make top SINGLE-sectors
	// ========================>
	angleStartZone = ANGLE_START;
	angleEndZone = ANGLE_START + ANGLE_SECTOR;
	innerRadiusZone -= widthWideZone;
	outerRadiusZone -= widthNarrowZone;

	for (uint8_t i = 0; i < SECTORS; i++)
	{
		LCD_SetTextColor((i % 2 == 0) ? LCD_COLOR_BLACK : LCD_COLOR_WHITE);

		LCD_FillArc(centerX, centerY, outerRadiusZone, innerRadiusZone, angleStartZone, angleEndZone);

		angleStartZone = angleEndZone;
		angleEndZone += ANGLE_SECTOR;
	}
	// ================<
	// Make TRIPLE-sectors
	// ====================>
	angleStartZone = ANGLE_START;
	angleEndZone = ANGLE_START + ANGLE_SECTOR;
	innerRadiusZone -= widthNarrowZone;
	outerRadiusZone -= widthWideZone;

	for (uint8_t i = 0; i < SECTORS; i++)
	{
		LCD_SetTextColor((i % 2 == 0) ? LCD_COLOR_GREEN : LCD_COLOR_RED);

		LCD_FillArc(centerX, centerY, outerRadiusZone, innerRadiusZone, angleStartZone, angleEndZone);

		angleStartZone = angleEndZone;
		angleEndZone += ANGLE_SECTOR;
	}
	// =======================<
	// Make bottom SINGLE-sectors
	// ===========================>
	angleStartZone = ANGLE_START;
	angleEndZone = ANGLE_START + ANGLE_SECTOR;
	innerRadiusZone -= widthWideZone;
	outerRadiusZone -= widthNarrowZone;

	for (uint8_t i = 0; i < SECTORS; i++)
	{
		LCD_SetTextColor((i % 2 == 0) ? LCD_COLOR_BLACK : LCD_COLOR_WHITE);

		LCD_FillArc(centerX, centerY, outerRadiusZone, innerRadiusZone, angleStartZone, angleEndZone);

		angleStartZone = angleEndZone;
		angleEndZone += ANGLE_SECTOR;
	}
	// ===============<
	// Make RING and BULL
	// ===================>
	innerRadiusZone -= widthNarrowZone;
	outerRadiusZone -= widthWideZone;

	LCD_SetTextColor(LCD_COLOR_GREEN);

	LCD_FillArc(centerX, centerY, outerRadiusZone, innerRadiusZone, 0, 360);

	innerRadiusZone = 0;
	outerRadiusZone -= widthNarrowZone;

	LCD_SetTextColor(LCD_COLOR_RED);

	LCD_FillArc(centerX, centerY, outerRadiusZone, innerRadiusZone, 0, 360);

}

void appMain()
{
	if (LCD_Init() == LCD_ERROR)
	{
		/* Initialization Error */
		Error_Handler();
	}

	LCD_Clear(LCD_COLOR_BLACK);

	/* Infinite loop */
	while (1)
	{
		demoClear();

		demoPixels();

		demoLines();

		demoFastLines();

		demoRects();

		demoFilledRects();

		demoCircles();

		demoFilledCircles();

		demoChar();

		demoImage();

		demoArc();
	}
}
