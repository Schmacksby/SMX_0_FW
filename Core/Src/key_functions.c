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
		//FIRST ROW
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
		{11, 0x2D}, // ß but coded as Key_Minus
		{12, 0x27}, // ´` but coded as Key_Equal
		{13, 0x2A}, //Backspace
		{14, 0x00}, //BLANK FOR NOW
		//SECOND ROW
		{15, 0x2B}, //Tab
		{16, 0x14}, //Q
		{17, 0x1A}, //W
		{18, 0x08}, //E
		{19, 0x15}, //R
		{20, 0x17}, //T
		{21, 0x1C}, //Z but coded as Y
		{22, 0x18}, //U
		{23, 0x0C}, //I
		{24, 0x12}, //O
		{25, 0x13}, //P
		{26, 0x2F}, //Ü but coded as {[ LEFT_BRACE
		{27, 0x30}, //+~* but coded as }] RIGHT_BRACE
		{28, 0x4A}, //Pos1 coded as Home
		{29, 0x00}, //BLANK FOR NOW
		//THIRD ROW
		{30, 0x64}, //|<> coded as KEY_102ND according to USB-IF labeled Keyboard Non-US \ and |
		{31, 0x04}, //A
		{32, 0x16}, //S
		{33, 0x07}, //D
		{34, 0x09}, //F
		{35, 0x0A}, //G
		{36, 0x0B}, //H
		{37, 0x0D}, //J
		{38, 0x0E}, //K
		{39, 0x0F}, //L
		{40, 0x33}, //Ö but coded as ;: Key_Semicolon
		{41, 0x34}, //Ä but coded as '" Key_Apostrophe
		{42, 0x28}, //Enter
		{43, 0x4D}, //End
		{44, 0x00}, //BLANK FOR NOW
		//FOURTH ROW
		{45, 0xE1}, //LEFT SHIFT MODIFIER

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
