#pragma once
#ifndef RPSPLayer_H
#define RPSPlayer_H
#include <fstream>
#include<iostream>
enum Move { Rock, Paper, Scissors, StartMove };
enum GameResult	{ Win, Draw, Lose};
class RPSPlayer {
public:
	
	virtual Move nextMove() = 0;                   
	
};

#endif // !RPSPLayer