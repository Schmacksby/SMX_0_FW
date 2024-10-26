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
