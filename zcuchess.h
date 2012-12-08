
#ifndef ZCUCHESS_H
	#define	ZCUCHESS_H
#endif

#define ASCII_VALUE_OF_A 97

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

#define SHORT_WHITE 0
#define LONG_WHITE 1
#define SHORT_BLACK 2
#define LONG_BLACK 3

#define ROW 1
#define COL 0

#define RIGHT 1
#define LEFT -1

typedef struct {
	int from[2];
	int to[2];
	bool status;
} Move;

typedef struct {
	int count;
	Move *move;
} Moves;

int chessboard[8][8];

bool is_checkmate_or_stalemate();

bool is_exit(char*);

Move parse_move(char*);

Move get_move();

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

int translate_row(char);

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

void add_move(Moves*, Move);

bool is_move_possible(Move);

Moves get_possible_moves(int, int);

void show_chessboard();

void print_move(Move move);

