
/*
 *	ZČU Chess
 *	Jednoduchý šachový program.
 *	
 * Modul ai.c
 * Tento modul obsahuje umělou inteligenci pro šachovou hru.
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
#include <strings.h>
#include <time.h>

#include "types.h"
#include "io.h"
#include "zcuchess.h"
#include "chess.h"
#include "ai.h"


/**
 * Vrací nejlepší tah počítače.
 */
Move get_move()
{
	Moves moves;
	Move move;
	int value;
	int alpha;
	Position position;
	double time = 0;
	int depth = 0;
	clock_t start;
	clock_t end;

	start = clock();
	moves = get_all_moves(BLACK);
	position = save_position();
	while(time < TWO_SEC)
	{
		alpha = BIG_ALPHA;
		depth++;
		for(int i=0; i<moves.count; i++)
		{
			show_thinking();
			play_move(moves.move[i], true);
			if(is_check(BLACK) == 0)
			{
				value = far_checkmate(alphabeta(WHITE, depth, -BIG_ALPHA, near_checkmate(alpha)));
				if(value < alpha)
				{
					alpha = value;
					move = moves.move[i];
				}
			}
			load_position(position);
		}
		end = clock();
		time = (double)(end - start);
	}
	if(moves.count > 0)free(moves.move);
	return move;
}


/**
 * Vrací hodnotu pozice.
 */
int get_position_value()
{
	int value = 0;
	int side = 0;
	int figure;
	for(int col=0; col<8; col++)
	{
		for(int row=0; row<8; row++)
		{
			figure = abs(chessboard[col][row]);
			side = get_side_coeficient(col, row);
			if(figure == PAWN)value = value - PAWN_VALUE*side;
			if(figure == ROOK)value = value - ROOK_VALUE*side;
			if(figure == KNIGHT)value = value - KNIGHT_VALUE*side;
			if(figure == BISHOP)value = value - BISHOP_VALUE*side;
			if(figure == QUEEN)value = value - QUEEN_VALUE*side;
			value = value - position_bonus[col][row]*side;
		}
	}
	return value;
}

/**
 * Úprava hodnoty pozice v blízkosti matu - počítač upřednostní mat dřívějším tahem
 * 
 * @param value Hodnota pozice
 */
int near_checkmate(int value)
{
	if(value > HIGH_VALUE)value++;
	if(value < -HIGH_VALUE)value--;
	return value;
}


/**
 * Úprava hodnoty pozice dále od matu - počítač upřednostní mat dřívějším tahem
 * 
 * @param value Hodnota pozice
 */
int far_checkmate(int value)
{
	if(value > HIGH_VALUE)value--;
	if(value < -HIGH_VALUE)value++;
	return value;
}


/**
 * Vrací nejlepší hodnotu pozice s ohledem na zahrané tahy do hlobky depth.
 * Implementováno alfabeta algoritmem.
 * 
 * @param side Strana, která je na tahu (BLACK, WHITE)
 * @param depth Hloubka propočtu
 * @param alpha Mez alfa - cokoliv horšího se nepočítá
 * @param beta Mez beta - nejlepší hodnota z minulé iterace
 */
int alphabeta(int side, int depth, int alpha, int beta)
{
	Moves moves;
	Position position;
	int value;

	if(is_checkmate())return side*MAT_VALUE;
	if(depth <= 0)return get_position_value();

	moves = get_all_moves(side);
	position = save_position();
	for(int i=0; i<moves.count; i++)
	{
		play_move(moves.move[i], true);
		if(is_check(side) != 0)
		{
			load_position(position);
			continue;
		}
		value = far_checkmate(alphabeta(side*(-1), depth-1, near_checkmate(beta), near_checkmate(alpha)));
		load_position(position);
		if((side == BLACK && value < alpha) || (side == WHITE && value > alpha))
		{
			alpha = value;
			if((side == BLACK && value <= beta) || (side == WHITE && value >= beta))
			{
				free_moves(moves);
				return beta;
			}
		}
	}
	free_moves(moves);
	return alpha;
}


