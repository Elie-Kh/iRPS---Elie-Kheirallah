#pragma once
#ifndef AHP_H
#define AHP_H
#include"RPSPlayer.h"
#include"RandomPlayer.h"


class AHP : public RPSPlayer {
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