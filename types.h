/* 
 * File:   types.h
 * Author: martin
 *
 * Created on 26. prosinec 2012, 7:25
 */

#ifndef TYPES_H
	#define	TYPES_H

	typedef struct {
		int from[2];
		int to[2];
		bool status;
	} Move;

	typedef struct {
		int count;
		Move *move;
	} Moves;


	typedef struct {
		int chessboard[8][8];
		int castlings[4];
		int en_passant[2];
	} Position;
	
#endif	/* TYPES_H */

