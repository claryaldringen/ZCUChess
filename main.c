
/*
 *	ZČU Chess
 *	Jednoduchý šachový program.
 *	
 * Modul main.c
 * Hlavní modul aplikace, obsahuje funkci main, funkce pro práci s pamětí a pomocné funkce.
 * 
 * Dialekt: C99
 * Kompiler: Jakýkoliv kompatibilní s C99
 * 
 * Autor: Martin Zadražil, 2012
 * Licence: GNU/GPL
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "types.h"
#include "zcuchess.h"
#include "io.h"
#include "chess.h"
#include "ai.h"

int chessboard[8][8];
bool castlings[4] = {true, true, true, true};
int en_passant[2];
bool human_move;
int position_bonus[8][8] = {
		{0, 1, 2, 3, 3, 2, 1, 0},
		{1, 2, 3, 4, 4, 3, 2, 1},
		{2, 3, 4, 5, 5, 4, 3, 2},
		{3, 4, 5, 6, 6, 5, 4, 3},
		{3, 4, 5, 6, 6, 5, 4, 3},
		{2, 3, 4, 5, 5, 4, 3, 2},
		{1, 2, 3, 4, 4, 3, 2, 1},
		{0, 1, 2, 3, 3, 2, 1, 0}
	};


/**
 * Hlavní funkce programu.
 * 
 * @param argc Počet parametrů
 * @param argv Pole parametrů
 */
int main(int argc, char** argv)
{
	char input[6];
	Move move;

	show_header();
	init_chessboard();
	while(!is_checkmate_or_stalemate())
	{
		human_move = true;
		gets(input);
		if(is_exit(input))break;
		if(is_help(input))continue;
		move = parse_move(input);
		if(move.status == false)continue;
		play_move(move, true);
		if(is_checkmate_or_stalemate())break;
		human_move = false;
		move = get_move();
		play_move(move, true);
		print_move(move);
		show_check();
		if(is_check(WHITE))printf("Šach bílý\n");
		if(is_check(BLACK))printf("Šach černý\n");
	}
	return (EXIT_SUCCESS);
}


/**
 * Zparsuje tah zadaný z klávesnice.
 * 
 * @param input
 */
Move parse_move(char* input)
{
	Move move;
	move.from[COL] = translate_col(input[0]);
	move.from[ROW] = atoi(&input[1]) - 1;
	move.to[COL] = translate_col(input[3]);
	move.to[ROW] = atoi(&input[4]) - 1;
	if(move.from[ROW] == -1 || move.to[COL] == -1)
	{
		printf("Chyba vstupu: pravděpodobně jste udělali překlep na české klávesnici. Opakujte prosím zadání.\n");
		move.status = false;
		return move;
	}
	move.status = check_move(move);
	if(move.status == false)printf("Špatně zadaný tah.\n");
	return move;
}


/**
 * Vrátí aktuální stav hry.
 */
Position save_position()
{
	Position position;
	memcpy(position.chessboard, chessboard, sizeof(chessboard));
	memcpy(position.castlings, castlings, sizeof(castlings));
	memcpy(position.en_passant, en_passant, sizeof(en_passant));
	return position;
}


/**
 * Nastaví hru do daného stavu.
 * 
 * @param position Aktuální stav hry
 */
void load_position(Position position)
{
	memcpy(chessboard, position.chessboard, sizeof(chessboard));
	memcpy(castlings, position.castlings, sizeof(castlings));
	memcpy(en_passant, position.en_passant, sizeof(en_passant));
}


/**
 * Přidá tah do množiny tahů.
 * 
 * @param moves Množina tahů
 * @param move Tah
 */
void add_move(Moves *moves, Move move)
{
	int size = 0;
	if(moves->count > 0)
	{
		size = (moves->count+1)*sizeof(move);
		moves->move = (Move*) realloc(moves->move, size);
	}
	else
	{
		moves->move = malloc(sizeof(move));
	}
	moves->move[moves->count] = move;
	moves->count++;
}


/**
 * Uvolní paměť, kterou zabírá množina tahů.
 * 
 * @param moves Množina tahů
 */
void free_moves(Moves moves)
{
	if(moves.count > 0)free(moves.move);
}
