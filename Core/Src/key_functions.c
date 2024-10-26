/*
 * key_functions.c
 *
 *  Created on: Oct 26, 2024
 *      Author: schmacks
 */

#include "main.h"

typedef struct {
	GPIO_TypeDef *port;
	uint16_t pin;
} GPIO_Pin;

typedef struct {
	uint8_t decValue;
	uint8_t hexValue;
} Key_Mapping;

GPIO_Pin rowsToIterate[] = {
		{GPIOB, GPIO_PIN_3},
		{GPIOB, GPIO_PIN_4},
		{GPIOB, GPIO_PIN_5},
		{GPIOB, GPIO_PIN_8},
		{GPIOB, GPIO_PIN_9}
};

GPIO_Pin colsToIterate[] = {
		{GPIOA, GPIO_PIN_0},
		{GPIOA, GPIO_PIN_1},
		{GPIOA, GPIO_PIN_2},
		{GPIOA, GPIO_PIN_3},
		{GPIOA, GPIO_PIN_4},
		{GPIOA, GPIO_PIN_5},
		{GPIOA, GPIO_PIN_6},
		{GPIOA, GPIO_PIN_7},
		{GPIOA, GPIO_PIN_8},
		{GPIOA, GPIO_PIN_9},
		{GPIOA, GPIO_PIN_10},
		{GPIOB, GPIO_PIN_10},
		{GPIOB, GPIO_PIN_11},
		{GPIOA, GPIO_PIN_15},
		{GPIOB, GPIO_PIN_15}
};

Key_Mapping keyMapping[] = {
		{0, 0x29}, //Escape
		{1, 0x1E}, //Keyboard 1
		{2, 0x1F}, //Keyboard 2
		{3, 0x20}, //Keyboard 3
		{4, 0x21}, //Keyboard 4
		{5, 0x22}, //Keyboard 5
		{6, 0x23}, //Keyboard 6
		{7, 0x24}, //Keyboard 7
		{8, 0x25}, //Keyboard 8
		{9, 0x26}, //Keyboard 9
		{10, 0x27}, //Keyboard 0
		{11, 0x27}, // ß
		{12, 0x27}, // ´
		{13, 0x2A}, //Backspace
		//{14, 0x27}, //Keyboard 0
		{15, 0x27}, //Keyboard 0
};


#define ROWS_TO_ITERATE_SIZE sizeof(rowsToIterate)/sizeof(rowsToIterate[0])
#define COLS_TO_ITERATE_SIZE sizeof(colsToIterate)/sizeof(colsToIterate[0])

volatile uint8_t matrix_current[ROWS_TO_ITERATE_SIZE][COLS_TO_ITERATE_SIZE] = {{0}};
volatile uint8_t matrix_previous[ROWS_TO_ITERATE_SIZE][COLS_TO_ITERATE_SIZE] = {{0}};

void check_matrix(void){

	uint8_t row, col;
	//reset all rows to known state
	for (row = 0; row < ROWS_TO_ITERATE_SIZE; row++){
		HAL_GPIO_WritePin(rowsToIterate[row].port, rowsToIterate[row].pin, GPIO_PIN_RESET);
	}

	//check each key and save status to matrix_current
	for (row = 0; row < ROWS_TO_ITERATE_SIZE; row++){
		HAL_GPIO_WritePin(rowsToIterate[row].port, rowsToIterate[row].pin, GPIO_PIN_SET);
		for(col = 0; col < COLS_TO_ITERATE_SIZE; col++){
			if(HAL_GPIO_ReadPin(colsToIterate[col].port, colsToIterate[col].pin)){
				matrix_current[row][col] = 1;
			} else {
				matrix_current[row][col] = 0;
			}
		}
		HAL_GPIO_WritePin(rowsToIterate[row].port, rowsToIterate[row].pin, GPIO_PIN_RESET);
	}
	//HAL_Delay(200);

}
