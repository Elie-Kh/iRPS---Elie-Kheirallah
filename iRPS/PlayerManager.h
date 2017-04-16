#pragma once
#ifndef PlayerManager_H
#define PlayerManager_H
#include"RPSPlayer.h"
#include"RandomPlayer.h"
#include"ProbabilityPlayer.h"
#include"AHP.h"
using namespace std;
class PlayerManager: public RPSPlayer {
private:

	RandomPlayer r1;
	
	
public:
	Move nextMove() {return r1.nextMove(); };
	GameResult result(Move mine, Move his) {
		if (mine == Rock && his == Paper) {
			return Lose;
		}
		else if (mine == Rock && his == Scissors) {
			return Win;
		}
		else if (mine == Paper && his == Rock) {
			return Win;
		}
		else if (mine == Paper && his == Scissors) {
			return Lose;
		}
		else if (mine == Scissors && his == Paper) {
			return Win;
		}
		else if (mine == Scissors && his == Rock) {
			return Lose;
		}
		else {
			return Draw;
		}
	}
};
#endif // !PlayerManager_H