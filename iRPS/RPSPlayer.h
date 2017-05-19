#pragma once
#ifndef RPSPLayer_H
#define RPSPlayer_H
#include <fstream>
#include<iostream>

/*RPS player: Abstract class. Contains nextMove which every other player requires.*/
enum Move { Rock, Paper, Scissors, StartMove }; //StartMove is there in order to start randomly
enum GameResult	{ Win, Draw, Lose};
class RPSPlayer {
public:
	
	virtual Move nextMove() = 0;                   
	
};

#endif // !RPSPLayer