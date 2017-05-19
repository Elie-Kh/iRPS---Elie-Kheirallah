#pragma once
#ifndef RandomPlayer_H
#define RandomPlayer_H

#include"RNGeezus.h"
#include"RPSPlayer.h"

using namespace std;
class RandomPlayer: public RPSPlayer {								//generates random number
private:
	RNG randomNum;													//calls random number generator
public:
	Move nextMove() {
		return static_cast <Move> (randomNum.getRandom(0, 2)) ;		//casts integer to move for random.
	}
	
	
};

#endif // !RandomPlayer