#ifndef RandomPlayer_H
#define RandomPlayer_H

#include"RNGeezus.h"
#include"RPSPlayer.h"
#include<sstream>
#include<ios>
using namespace std;
class RandomPlayer: public RPSPlayer {
private:
	RNG randomNum;
public:
	Move nextMove() {
		return static_cast <Move> (randomNum.getRandom(0, 2)) ;
	}
	
	
};

#endif // !RandomPlayer