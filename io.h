/*
 * File:   io.h
 * Author: martin
 *
 * Created on 26. prosinec 2012, 7:01
 */

#ifndef IO_H
	#define	IO_H

	#define ASCII_VALUE_OF_A 97

	#define HEADER "ZČU Chess\n\nJednoduché šachy, vytvořené pod licencí GNU/GPL jako semestrální práce do předmětu KIV/PC\nAutor: Martin Zadražil <zadram1@gmail.com> v roce 2012\nZdrojový kód: https://github.com/ClaryAldringen/ZCUChess\n\n"
	#define HELP "Zadání tahu: <odkud> <kam> (např.: e2 e3)\nMalá rošáda: e1 h1\nVelká rošáda: e1 a1\nKonec programu: exit\nNápověda: help\n"

	bool is_exit(char*);

	void show_chessboard();

	void print_move(Move move);

	int translate_row(char);

	bool is_help(char*);

	void show_help();

	void show_header();

#endif	/* IO_H */

