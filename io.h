/*
 * File:   io.h
 * Author: martin
 *
 * Created on 26. prosinec 2012, 7:01
 */
#ifndef IO_H
	#define	IO_H

	#define ASCII_VALUE_OF_A 97

	#define HEADER "ZCU Chess\n\nJednoduche sachy, vytvorene pod licenci GNU/GPL jako semestralni prace do predmetu KIV/PC\nAutor: Martin Zadrazil <zadram1@gmail.com> v roce 2012\nZdrojovy kod: https://github.com/ClaryAldringen/ZCUChess\n\n"
	#define HELP "Zadani tahu: <odkud> <kam> (napr.: e2 e3)\nMala rosada: e1 h1\nVelka rosada: e1 a1\nKonec programu: exit\nNapoveda: help\n"

	bool is_exit(char*);

	void show_chessboard();

	void print_move(Move move);

	int translate_col(char);

	bool is_help(char*);

	void show_help();

	void show_header();

	void show_check();

	void show_thinking();

#endif	/* IO_H */

