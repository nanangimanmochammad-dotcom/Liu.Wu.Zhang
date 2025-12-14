/*
 * lcd1602.c
 *
 *  Created on: Dec 12, 2025
 *      Author: admin
 */

#include "lcd1602.h"

// Internal microsecond delay (rough)
static void delay_us(uint32_t us) {
    us *= 10;
    while(us--);
}

//Trigger the enable signal
static void LCD_Enable(void) {
    HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);
    delay_us(20);
    HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);
    delay_us(20);
}

// Send 4-bit data
static void LCD_Send4Bits(uint8_t data) {
    HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (data >> 0) & 0x01);
    HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (data >> 1) & 0x01);
    HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (data >> 2) & 0x01);
    HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (data >> 3) & 0x01);
    LCD_Enable();
}

// Send instruction (0) or data (1)
static void LCD_Send(uint8_t value, uint8_t is_data) {
    HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, is_data ? GPIO_PIN_SET : GPIO_PIN_RESET);
    LCD_Send4Bits(value >> 4);
    LCD_Send4Bits(value & 0x0F);
    delay_us(50);
}

// --- external interface ---

void LCD_Init(void) {
    HAL_Delay(50);
    HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);

    // 4-bit mode initialization sequence
    LCD_Send4Bits(0x03); HAL_Delay(5);
    LCD_Send4Bits(0x03); HAL_Delay(1);
    LCD_Send4Bits(0x03); HAL_Delay(1);
    LCD_Send4Bits(0x02); HAL_Delay(1);

    LCD_Send(0x28, 0); // function set
    LCD_Send(0x0C, 0); // Turn on display and turn off cursor
    LCD_Send(0x06, 0); // Move the cursor to the right after inputting the text
    LCD_Clear();
}

void LCD_Clear(void) {
    LCD_Send(0x01, 0);
    HAL_Delay(2);
}

void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t address = (row == 0) ? 0x80 : 0xC0;
    address += col;
    LCD_Send(address, 0);
}

void LCD_Print(char *str) {
    while (*str) LCD_Send(*str++, 1);
}

void LCD_WriteChar(uint8_t data) {
    LCD_Send(data, 1);
}

void LCD_CreateCustomChar(uint8_t location, uint8_t *charmap) {
    location &= 0x07;
    LCD_Send(0x40 | (location << 3), 0);
    for (int i = 0; i < 8; i++) LCD_Send(charmap[i], 1);
}


