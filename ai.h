/* 
 * File:   ai.h
 * Author: martin
 *
 * Created on 26. prosinec 2012, 7:50
 */

#ifndef AI_H
	#define	AI_H

	Move get_move();

	int near_checkmate(int);

	int far_checkmate(int);

	int alphabeta(int, int, int, int);

#endif	/* AI_H */

