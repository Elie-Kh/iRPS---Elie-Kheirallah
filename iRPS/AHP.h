#pragma once
#ifndef AHP_H
#define AHP_H
#include"RPSPlayer.h"
#include"RandomPlayer.h"


class AHP : public RPSPlayer {
public:
	/*AHP will counter the human strategy. It will always play the thing that beats the thing that won.
	Unless it draws. Then it plays random. Under normal conditions, 
	it will win and keep on winning because it is 1 step ahead. */
	Move nextMove() {
		return da.nextMove();
	}
	Move nextMove(Move myMove, GameResult myResult) {
		if (myResult == 1) {
			return da.nextMove();
		}
		else if (myResult == 0) {
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
		else {
			if (myMove == 0) {
				return Scissors;
			}
			else if (myMove == 1) {
				return Rock;
			}
			else {
				return Paper;
			}
		}
	}
private:
	RandomPlayer da;
};
#include"RPSPlayer.h"

#endif // !AHP*/