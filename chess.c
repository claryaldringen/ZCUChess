#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include "types.h"
#include "io.h"
#include "zcuchess.h"
#include "chess.h"


void init_chessboard()
{
	set_empty_chessboard();
	set_figures(WHITE_ROW);
	set_figures(BLACK_ROW);
}


bool is_checkmate_or_stalemate()
{
	bool checkmate = is_checkmate();
	if(checkmate)printf("Mat\n");
	return checkmate;
}


bool is_checkmate()
{
	Moves moves;
	int check;
	int temp_chessboard[8][8];
	int check_side = get_side_with_check();

	if(check_side != 0)
	{
		moves = get_all_moves(check_side);
		memcpy(temp_chessboard, chessboard, sizeof(chessboard));
		for(int i=0; i<moves.count; i++)
		{
			//printf("Hledani matu: \n");
			//print_move(moves.move[i]);
			play_move(moves.move[i], false);
			check = is_check(check_side);
			memcpy(chessboard, temp_chessboard, sizeof(chessboard));
			if(!check)
			{
				if(moves.count > 0)free(moves.move);
				return false;
			}
		}
		if(moves.count > 0)free(moves.move);
		return true;
	}
	return false;
}


int is_check(int side)
{
	Moves moves;
	int start = 0;
	int end = 2;
	int sides[3] = {BLACK, WHITE, BLACK};

	moves.count = 0;
	if(side == WHITE)end = 1;
	if(side == BLACK)start = 1;

	for(int s=start; s<end; s++)
	{
		moves = get_all_moves(sides[s]);
		for(int i=0; i<moves.count; i++)
		{
			if(chessboard[moves.move[i].to[COL]][moves.move[i].to[ROW]] == (sides[s]*KING))
			{
				if(moves.count > 0)free(moves.move);
				return 1;
			}
		}
		if(moves.count > 0)free(moves.move);
	}
	return 0;
}


int get_side_with_check()
{
	Moves moves;
	int start = 0;
	int end = 2;
	int sides[3] = {BLACK, WHITE, BLACK};

	moves.count = 0;
	for(int s=start; s<end; s++)
	{
		moves = get_all_moves(sides[s]);
		for(int i=0; i<moves.count; i++)
		{
			if(chessboard[moves.move[i].to[COL]][moves.move[i].to[ROW]] == (sides[s]*KING))
			{
				if(moves.count > 0)free(moves.move);
				return sides[s+1];
			}
		}
		if(moves.count > 0)free(moves.move);
	}
	return 0;	
}


Moves get_all_moves(int side)
{
	Moves all_moves;
	Moves moves;

	moves.count = 0;
	all_moves.count = 0;
	for(int col=0; col<8; col++)
	{
		for(int row=0; row<8; row++)
		{
			if((chessboard[col][row] > 0 && side == WHITE) || (chessboard[col][row] < 0 && side == BLACK))
			{
				moves = get_possible_moves(col, row);
				for(int i = 0; i<moves.count; i++)
				{
					moves.move[i].from[COL] = col;
					moves.move[i].from[ROW] = row;
					add_move(&all_moves, moves.move[i]);
				}
				if(moves.count > 0)free(moves.move);
				moves.count = 0;
			}
		}
	}
	return all_moves;
}


void play_move(Move move, bool real)
{
	if(is_castling(move) && can_do_castling(move))
	{
		do_castling(move);
	}
	else if(is_en_passant(move))
	{
		do_en_passant(move);
	}
	else
	{
		check_en_passant(move);
		do_simple_move(move);
	}

	if(real)check_castling(move);
}


void check_castling(Move move)
{
	if(move.from[COL] == 0 && move.from[ROW] == 0)castlings[LONG_WHITE] = false;
	if(move.from[COL] == 7 && move.from[ROW] == 0)castlings[SHORT_WHITE] = false;
	if(move.from[COL] == 4 && move.from[ROW] == 0)
	{
		castlings[LONG_WHITE] = false;
		castlings[SHORT_WHITE] = false;
	}

	if(move.from[COL] == 0 && move.from[ROW] == 7)castlings[LONG_BLACK] = false;
	if(move.from[COL] == 7 && move.from[ROW] == 7)castlings[SHORT_BLACK] = false;
	if(move.from[COL] == 4 && move.from[ROW] == 7)
	{
		castlings[LONG_BLACK] = false;
		castlings[SHORT_BLACK] = false;
	}
}


bool is_castling(Move move)
{
	int side = get_side_coeficient(move.from[COL], move.from[ROW]);
	if(side == WHITE && move.from[COL] == 4 && move.from[ROW] == 0 && (move.to[COL] == 0 || move.to[COL] == 7) && move.to[ROW] == 0)return true;
	if(side == BLACK && move.from[COL] == 4 && move.from[ROW] == 7 && (move.to[COL] == 0 || move.to[COL] == 7) && move.to[ROW] == 7)return true;
	return false;
}


bool can_do_castling(Move move)
{
	int row = 0;
	int temp_chessboard[8][8];
	int side = get_side_coeficient(move.from[COL], move.from[ROW]);
	if(is_check(side))return false;

	if(side == BLACK)row = 7;

	int castling_target[3] = {7,0,0};
	int start_col[3] = {4,4,3};
	int end_col[3] = {5,3,2};

	memcpy(temp_chessboard, chessboard, sizeof(chessboard));
	for(int i=0; i<3; i++)
	{
		if(move.to[COL] == castling_target[i])
		{
			chessboard[start_col[i]][row] = EMPTY;
			chessboard[end_col[i]][row] = -1*side*KING;
			if(is_check(side))
			{
				memcpy(chessboard, temp_chessboard, sizeof(chessboard));
				return false;
			}
		}
	}
	memcpy(chessboard, temp_chessboard, sizeof(chessboard));
	return true;
}


void do_castling(Move move)
{
	int side = get_side_coeficient(move.from[COL], move.from[ROW]);
	if(side == WHITE && move.to[COL] == 0)
	{
		chessboard[2][0] = KING;
		chessboard[3][0] = ROOK;
		chessboard[0][0] = EMPTY;
		chessboard[4][0] = EMPTY;
	}
	if(side == WHITE && move.to[COL] == 7)
	{
		chessboard[6][0] = KING;
		chessboard[5][0] = ROOK;
		chessboard[7][0] = EMPTY;
		chessboard[4][0] = EMPTY;
	}
	if(side == BLACK && move.to[COL] == 0)
	{
		chessboard[2][7] = -KING;
		chessboard[3][7] = -ROOK;
		chessboard[0][7] = EMPTY;
		chessboard[4][7] = EMPTY;
	}
	if(side == BLACK && move.to[COL] == 7)
	{
		chessboard[6][7] = -KING;
		chessboard[5][7] = -ROOK;
		chessboard[7][7] = EMPTY;
		chessboard[4][7] = EMPTY;
	}
}


bool is_en_passant(Move move)
{
	int figure = abs(chessboard[move.from[COL]][move.from[ROW]]);
	if(figure == PAWN && chessboard[move.to[COL]][move.to[ROW]] == 0 && move.from[COL] != move.to[COL])return true;
	return false;
}


void do_en_passant(Move move)
{
	do_simple_move(move);
	chessboard[move.to[COL]][move.from[ROW]] = 0;
}


void do_simple_move(Move move)
{
	if(chessboard[move.from[COL]][move.from[ROW]] == PAWN && move.to[ROW] == BLACK_ROW)
	{
		chessboard[move.to[COL]][move.to[ROW]] = get_figure();
	}
	else if(chessboard[move.from[COL]][move.from[ROW]] == -PAWN && move.to[ROW] == WHITE_ROW)
	{
		chessboard[move.to[COL]][move.to[ROW]] = -QUEEN;
	}
	else chessboard[move.to[COL]][move.to[ROW]] = chessboard[move.from[COL]][move.from[ROW]];
	chessboard[move.from[COL]][move.from[ROW]] = 0;

}


int get_figure()
{
	char input;
	int figure = 0;
	if(!human_move)return QUEEN;
	while(figure == EMPTY)
	{
		printf("Jakou chcete figuru? (D - dáma, V - věž, S - střelec, K - kůň): ");
		gets(&input);
		if(input == 'd' || input == 'D')figure = QUEEN;
		if(input == 'v' || input == 'V')figure = ROOK;
		if(input == 'k' || input == 'K')figure = KNIGHT;
		if(input == 's' || input == 'S')figure = BISHOP;
	}
	return figure;
}


void check_en_passant(Move move)
{
	int side = get_side_coeficient(move.from[COL], move.from[ROW]);
	int figure = chessboard[move.from[COL]][move.from[ROW]];
	if(move.from[COL] == move.to[COL] && abs(figure) == PAWN && ((move.to[ROW] == 3 && side == WHITE) || (move.to[ROW] == 4 && side == BLACK)))
	{
		en_passant[COL] = move.to[COL];
		en_passant[ROW] = move.to[ROW];
	}
	else
	{
		en_passant[COL] = -1;
		en_passant[ROW] = -1;
	}
}


void set_empty_chessboard()
{
	for(int col=0; col<9; col++)
	{
		for(int row=2; row<6; row++ )
		{
			chessboard[col][row] = 0;
		}
	}
}


void set_figures(int type)
{
	int koeficient;
	if(type == WHITE_ROW)koeficient = 1;
	if(type == BLACK_ROW)koeficient = -1;
	for(int col=0; col < 8; col++)
	{
		chessboard[col][type+koeficient] = koeficient * PAWN;
	}
	chessboard[0][type] = koeficient * ROOK;
	chessboard[7][type] = koeficient * ROOK;
	chessboard[1][type] = koeficient * KNIGHT;
	chessboard[6][type] = koeficient * KNIGHT;
	chessboard[2][type] = koeficient * BISHOP;
	chessboard[5][type] = koeficient * BISHOP;
	chessboard[3][type] = koeficient * QUEEN;
	chessboard[4][type] = koeficient * KING;
}


bool check_move(Move move)
{
	if(move.from[COL] == -1 || move.from[ROW] == -1 || move.to[COL] == -1 || move.to[ROW] == -1)return false;
	if(move.from[ROW] > 7 || move.to[ROW] > 7)return false;
	return is_move_possible(move);
}


bool is_move_possible(Move move)
{
	Moves moves = get_possible_moves(move.from[COL], move.from[ROW]);
	for(int i=0; i<moves.count; i++)
	{
		if(move.to[COL] == moves.move[i].to[COL] && move.to[ROW] == moves.move[i].to[ROW] && !is_check_after_move(move))
		{
			if(moves.count > 0)free(moves.move);
			return true;
		}
	}
	if(moves.count > 0)free(moves.move);
	return false;
}


Moves get_possible_moves(int col, int row)
{
	Moves moves;
	moves.count = 0;
	int figure = chessboard[col][row];
	if(abs(figure) == PAWN)return get_possible_moves_for_pawn(col, row);
	if(abs(figure) == ROOK)return get_possible_moves_for_rook(col, row);
	if(abs(figure) == KNIGHT)return get_possible_moves_for_knight(col, row);
	if(abs(figure) == BISHOP)return get_possible_moves_for_bishop(col, row);
	if(abs(figure) == QUEEN)return get_possible_moves_for_queen(col, row);
	if(abs(figure) == KING)return get_possible_moves_for_king(col, row);
	return moves;
}


Moves get_possible_moves_for_pawn(int col, int row)
{
	int koeficient = get_side_coeficient(col, row);
	Move move;
	Moves moves;

	move.from[COL] = col;
	move.from[ROW] = row;
	moves.count = 0;

	if(chessboard[col][row] != 0)
	{
		if(chessboard[col][row-1*koeficient] == 0)
		{
			move.to[COL] = col;
			move.to[ROW] = row-1*koeficient;
			add_move(&moves, move);
		}
		if(chessboard[col][row-2*koeficient] == 0 && chessboard[col][row-1*koeficient] == 0)
		{
			if((koeficient == -1 && row == 1) || (koeficient == 1 && row == 6))
			{
				move.to[COL] = col;
				move.to[ROW] = row-2*koeficient;
				add_move(&moves, move);
			}
		}
		if(is_pawn_diagonally_move_possible(col, row, RIGHT))
		{
			move.to[COL] = col+1;
			move.to[ROW] = row-1*koeficient;
			add_move(&moves, move);
		}
		if(is_pawn_diagonally_move_possible(col, row, LEFT))
		{
			move.to[COL] = col-1;
			move.to[ROW] = row-1*koeficient;
			add_move(&moves, move);
		}
	}
	return moves;
}


bool is_pawn_diagonally_move_possible(int col, int row, int order)
{
	int coeficient_of_from = get_side_coeficient(col, row);
	int coeficient_of_to = get_side_coeficient(col+order, row-1*coeficient_of_from);
	if(coeficient_of_to == EMPTY && en_passant[COL] == col+order && en_passant[ROW] == row)return true;
	if(coeficient_of_to != EMPTY && coeficient_of_from != coeficient_of_to)return true;
	return false;
}


Moves get_possible_moves_for_rook(int col, int row)
{
	int koeficient = get_side_coeficient(col, row);
	Moves moves;
	moves.count = 0;

	int order[2] = {-1, 1};
	int limit[2] = {-1, 8};

	for(int i = 0; i<2; i++)
	{
		for(int r = row+order[i]; r != limit[i]; r = r + order[i])
		{
			if(add_move_and_break(&moves, col, row, col, r, koeficient))break;
		}
		for(int c = col+order[i]; c != limit[i]; c = c + order[i])
		{
			if(add_move_and_break(&moves, col, row, c, row, koeficient))break;
		}
	}

	return moves;
}


Moves get_possible_moves_for_knight(int col, int row)
{
	int rows[8] = {-1, -2, -1, -2, 1, 2, 1, 2};
	int cols[8] = {-2, -1, 2, 1, -2, -1, 2, 1};
	Moves moves;
	Move move;

	moves.count = 0;
	move.from[COL] = col;
	move.from[ROW] = row;
	for(int i=0; i<8; i++)
	{
		if(((col + cols[i]) > -1) && ((col + cols[i]) < 8) && ((row + rows[i]) > -1) && ((row + rows[i]) < 8) && (chessboard[col + cols[i]][row + rows[i]] == 0 || get_side_coeficient(col, row) != get_side_coeficient(col + cols[i], row + rows[i])))
		{
			move.to[COL] = col + cols[i];
			move.to[ROW] = row + rows[i];
			add_move(&moves, move);
		}
	}
	return moves;
}


Moves get_possible_moves_for_bishop(int col, int row)
{
	int koeficient = get_side_coeficient(col, row);
	int order[2] = {-1, 1};
	int limit[2] = {-1, 8};
	Moves moves;
	moves.count = 0;

	int c;
	for(int i=0; i<2; i++)
	{
		c = col + order[i];
		for(int r = row+1; r < 8 && c != limit[i]; r++)
		{
			if(add_move_and_break(&moves, col, row, c, r, koeficient))break;
			c = c + order[i];
		}
		c = col + order[i];
		for(int r = row-1; r > -1 && c != limit[i]; r--)
		{
			if(add_move_and_break(&moves, col, row, c, r, koeficient))break;
			c = c + order[i];
		}
	}

	return moves;
}


Moves get_possible_moves_for_queen(int col, int row)
{
	Moves moves = get_possible_moves_for_rook(col, row);
	Moves bishop_moves = get_possible_moves_for_bishop(col, row);
	for(int i=0; i< bishop_moves.count; i++)
	{
		add_move(&moves, bishop_moves.move[i]);
	}
	if(bishop_moves.count > 0)free(bishop_moves.move);
	return moves;
}


Moves get_possible_moves_for_king(int col, int row)
{
	Moves moves;
	moves.count = 0;

	Move move;
	move.from[COL] = col;
	move.from[ROW] = row;

	for(int c = col-1; c < col+2; c++)
	{
		for(int r = row-1; r < row+2; r++)
		{
			if(r > -1 && r < 8 && c > -1 && c < 8 && (chessboard[c][r] == 0 || get_side_coeficient(col, row) != get_side_coeficient(c, r)))
			{
				move.to[COL] = c;
				move.to[ROW] = r;
				add_move(&moves, move);
			}
		}
	}
	add_castling_moves(&moves, col, row);

	return moves;
}


void add_castling_moves(Moves *moves, int col, int row)
{
	Move move;
	move.from[COL] = col;
	move.from[ROW] = row;

	if(get_side_coeficient(col, row) == WHITE)
	{
		if(castlings[LONG_WHITE] && chessboard[1][0] == 0 && chessboard[2][0] == 0 && chessboard[3][0] == 0)
		{
			move.to[COL] = 0;
			move.to[ROW] = 0;
			add_move(moves, move);
		}

		if(castlings[SHORT_WHITE] && chessboard[5][0] == 0 && chessboard[6][0] == 0)
		{
			move.to[COL] = 7;
			move.to[ROW] = 0;
			add_move(moves, move);
		}
	}
	else
	{
		if(castlings[LONG_BLACK] && chessboard[1][7] == 0 && chessboard[2][7] == 0 && chessboard[3][7] == 0)
		{
			move.to[COL] = 0;
			move.to[ROW] = 7;
			add_move(moves, move);
		}

		if(castlings[SHORT_BLACK] && chessboard[5][7] == 0 && chessboard[6][7] == 0)
		{
			move.to[COL] = 7;
			move.to[ROW] = 7;
			add_move(moves, move);
		}
	}
}


bool add_move_and_break(Moves *moves, int from_col, int from_row, int to_col, int to_row, int coeficient)
{
	Move move;
	move.from[COL] = from_col;
	move.from[ROW] = from_row;
	if(chessboard[to_col][to_row] == 0)
	{
		move.to[COL] = to_col;
		move.to[ROW] = to_row;
		add_move(moves, move);
	}
	else
	{
		if(coeficient == get_side_coeficient(to_col, to_row))return true;
		else
		{
			move.to[COL] = to_col;
			move.to[ROW] = to_row;
			add_move(moves, move);
			return true;
		}
	}
	return false;
}


bool is_check_after_move(Move move)
{
	int side = get_side_coeficient(move.from[COL], move.from[ROW]);
	int check;
	int temp_chessboard[8][8];
	memcpy(temp_chessboard, chessboard, sizeof(chessboard));
	play_move(move, false);
	check = is_check(side);
	memcpy(chessboard, temp_chessboard, sizeof(chessboard));
	if(check)return true;
	return false;
}


int get_side_coeficient(int col, int row)
{
	if(chessboard[col][row] < 0)return BLACK;
	if(chessboard[col][row] > 0)return WHITE;
	return EMPTY;
}

