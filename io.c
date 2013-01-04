
/*
 *	ZČU Chess
 *	Jednoduchý šachový program.
 *	
 * Modul io.c
 * Tento modul obsahuje vstupní a výstupní operace.
 * 
 * Dialekt: C99
 * Kompiler: Jakýkoliv kompatibilní s C99
 * 
 * Autor: Martin Zadražil, 2012
 * Licence: GNU/GPL
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "types.h"
#include "io.h"
#include "zcuchess.h"
#include "chess.h"

int status = 0;

/**
 * Vrátí true, je-li vstupním parametrem řetězec "exit"
 * 
 * @param input
 */
bool is_exit(char* input)
{
	if(strcmp(input, "exit") == 0)
	{
		printf("Nashledanou\n");
		return true;
	}
	return false;
}


/**
 * Vypíše nápovědu a vrátí true, je-li vstupním parametrem řetězec "help"
 * 
 * @param input
 */
bool is_help(char* input)
{
	if(strcmp(input, "help") == 0)
	{
		show_help();
		return true;
	}
	return false;
}


/**
 * Přeloží sloupcovou souřadnici zadanou písmenem a-h na číslo.
 * 
 * @param character
 */
int translate_col(char character)
{
	int number = (int)(character - ASCII_VALUE_OF_A);
	if(number > 7 || number < 0)number = -1;
	return number;
}


/**
 * Zobrazí zjednodušenou podobu šachovnice.
 */
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


/**
 * Vypíše tah.
 * 
 * @param move Tah
 */
void print_move(Move move)
{
	printf("%c%d %c%d         \n", move.from[COL]+ASCII_VALUE_OF_A, move.from[ROW]+1, move.to[COL]+ASCII_VALUE_OF_A, move.to[ROW]+1);
}


/**
 * Vypíše hlavičku.
 */
void show_header()
{
	printf(HEADER);
	show_help();
}


/**
 * Zobrazí nápovědu.
 */
void show_help()
{
	printf(HELP);
}


/**
 * Zobrazí šach.
 */
void show_check()
{
	if(is_check(WHITE))printf("Sach bily\n");
	if(is_check(BLACK))printf("Sach cerny\n");
}


/**
 * Zobrazí přemýšlení :-)
 */
void show_thinking()
{
	printf("Premyslim...\r");
}

