/* 
 * File:   ai.h
 * Author: martin
 *
 * Created on 26. prosinec 2012, 7:50
 */

#ifndef AI_H
	#define	AI_H

	#define MAT_VALUE 16000
	#define HIGH_VALUE 15000
	#define MAX_THINKING_DURATION 3
	#define BIG_ALPHA 100000


	Move get_move();

	int near_checkmate(int);

	int far_checkmate(int);

	int alphabeta(int, int, int, int);

#endif	/* AI_H */

