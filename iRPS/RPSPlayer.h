#ifndef RPSPLayer_H
#define RPSPlayer_H
#include <fstream>

#include<iostream>

class RPSPlayer {
public:
	enum Move { Rock, Paper, Scissors };
	virtual Move nextMove() = 0;                   
	enum GameResult	{ Win, Draw, Lose};
};

#endif // !RPSPLayer