#pragma once
#ifndef Human_H
#define Human_H
#include"RPSPlayer.h"
#include"RandomPlayer.h"

/* Human player. 
The human player is static.
It plays the winning move always. If the human wins, it plays the same thing.
If the human loses, it will play what just beat it.*/

class Human : public RPSPlayer {   
public:
	Move nextMove() {
		return da.nextMove();
	}
	Move nextMove(Move myMove, GameResult myResult) {
		if (myResult == 1) {
			return da.nextMove();
		}
		else if (myResult == 0) {
			if (myMove == 0) {
				return Rock;
			}
			else if (myMove == 1) {
				return Paper;
			}
			else {
				return Scissors;
			}
		}
		else {
			if (myMove == 0) {
				return Paper;
			}
			else if (myMove == 1) {
				return Scissors;
			}
			else {
				return Rock;
			}
		}
	}
private:
	RandomPlayer da;
};

#endif // !AHP*/