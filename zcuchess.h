
#ifndef ZCUCHESS_H
	#define	ZCUCHESS_H

	#define BLACK_ROW 7
	#define WHITE_ROW 0

	#define BLACK 1
	#define WHITE -1
	#define ANYONE 0

	#define EMPTY 0
	#define PAWN 1
	#define ROOK 2
	#define KNIGHT 3
	#define BISHOP 4
	#define QUEEN 5
	#define KING 6

	#define PAWN_VALUE 100
	#define ROOK_VALUE 400
	#define KNIGHT_VALUE 300
	#define BISHOP_VALUE 350
	#define QUEEN_VALUE 750

	#define SHORT_WHITE 0
	#define LONG_WHITE 1
	#define SHORT_BLACK 2
	#define LONG_BLACK 3

	#define ROW 1
	#define COL 0

	#define RIGHT 1
	#define LEFT -1

	int chessboard[8][8];
	bool castlings[4];
	int en_passant[2];
	bool human_move;
	int position_bonus[8][8];
	
	Move parse_move(char*);
	
	Position save_position();

	void load_position(Position);

	void add_move(Moves*, Move);

	void free_moves(Moves);
	
#endif

