/*
 * File:   main.c
 * Author: clary
 *
 * Created on 1. prosinec 2012, 13:47
 */

#include <stdlib.h>
#include <stdbool.h>

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


int main(int argc, char** argv)
{
	char input[6];
	Move move;
	init_chessboard();
	while(!is_checkmate_or_stalemate())
	{
		human_move = true;
		gets(input);
		if(is_exit(input))break;
		move = parse_move(input);
		if(move.status == false)
		{
			printf("Špatně zadaný tah.\n");
			continue;
		}
		play_move(move, true);
		if(is_checkmate_or_stalemate())break;
		human_move = false;
		move = get_move();
		play_move(move, true);
		print_move(move);
		if(is_check(WHITE))printf("Šach bílý\n");
		if(is_check(BLACK))printf("Šach černý\n");
		show_chessboard();
	}
	return (EXIT_SUCCESS);
}

Move parse_move(char* input)
{
	Move move;
	move.from[COL] = translate_row(input[0]);
	move.from[ROW] = atoi(&input[1]) - 1;
	move.to[COL] = translate_row(input[3]);
	move.to[ROW] = atoi(&input[4]) - 1;
	move.status = check_move(move);
	return move;
}


Position save_position()
{
	Position position;
	memcpy(position.chessboard, chessboard, sizeof(chessboard));
	memcpy(position.castlings, castlings, sizeof(castlings));
	memcpy(position.en_passant, en_passant, sizeof(en_passant));
	return position;
}


void load_position(Position position)
{
	memcpy(chessboard, position.chessboard, sizeof(chessboard));
	memcpy(castlings, position.castlings, sizeof(castlings));
	memcpy(en_passant, position.en_passant, sizeof(en_passant));
}


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
