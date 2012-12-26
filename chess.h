/* 
 * File:   chess.h
 * Author: martin
 *
 * Created on 26. prosinec 2012, 7:37
 */

#ifndef CHESS_H
	#define	CHESS_H

	bool is_checkmate_or_stalemate();
	
	void play_move(Move, bool);

	bool is_castling(Move);

	bool can_do_castling(Move);

	void do_castling(Move);

	bool is_en_passant(Move);

	void do_en_passant(Move);

	void do_simple_move(Move);

	void upgrade_pawn();

	void check_castling();

	void check_en_passant(Move);

	Moves get_all_moves(int);

	bool is_checkmate();

	int is_check(int);

	int get_side_with_check();

	void init_chessboard();

	void set_empty_chessboard();

	void set_figures();

	bool check_move(Move);

	Moves get_possible_moves_for_pawn(int, int);

	bool is_pawn_diagonally_move_possible(int, int, int);

	Moves get_possible_moves_for_rook(int, int);

	Moves get_possible_moves_for_knight(int, int);

	Moves get_possible_moves_for_bishop(int, int);

	Moves get_possible_moves_for_queen(int, int);

	Moves get_possible_moves_for_king(int, int);

	void add_castling_moves(Moves*, int, int);

	bool add_move_and_break(Moves*, int, int, int, int, int );

	bool is_check_after_move(Move);

	int get_side_coeficient(int, int);

	bool is_move_possible(Move);

	Moves get_possible_moves(int, int);

	int get_position_value();

	int get_figure();
	
#endif	/* CHESS_H */

