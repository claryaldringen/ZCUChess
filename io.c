#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "types.h"
#include "io.h"
#include "zcuchess.h"

bool is_exit(char* input)
{
	if(strcmp(input, "exit") == 0)
	{
		printf("Nashledanou\n");
		return true;
	}
	return false;
}


bool is_help(char* input)
{
	if(strcmp(input, "help") == 0)
	{
		show_help();
		return true;
	}
	return false;
}


int translate_row(char character)
{
	int number = (int)(character - ASCII_VALUE_OF_A);
	if(number > 7 || number < 0)number = -1;
	return number;
}


void show_chessboard()
{
	for(int col = 0; col < 8; col++)
	{
		for(int row = 0; row < 8; row++)
		{
			printf("%d ", chessboard[col][row]);
		}
		printf("\n");
	}
}


void print_move(Move move)
{
	printf("%c%d %c%d\n", move.from[COL]+ASCII_VALUE_OF_A, move.from[ROW]+1, move.to[COL]+ASCII_VALUE_OF_A, move.to[ROW]+1);
}


void show_header()
{
	printf(HEADER);
	show_help();
}


void show_help()
{
	printf(HELP);
}
