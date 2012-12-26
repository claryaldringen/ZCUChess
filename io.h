/* 
 * File:   io.h
 * Author: martin
 *
 * Created on 26. prosinec 2012, 7:01
 */

#ifndef IO_H
	#define	IO_H

	#define ASCII_VALUE_OF_A 97

	bool is_exit(char*);
	
	void show_chessboard();

	void print_move(Move move);
	
	int translate_row(char);
	
#endif	/* IO_H */

