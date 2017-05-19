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

	RandomPlayer Randomonium;
	ProbPlayer Probium;
	AHP AHPonium;
	
	Move probHimPast = StartMove, ahpMePast = StartMove, randMePast = StartMove;
	int sumR=0, sumP=0, sumA=0;
	int gr5 = 0, gr4 = 0, gr3 = 0, gr2 = 0, gr1 = 0, ga1 = 0, ga2 = 0, ga3 = 0, ga4 = 0, ga5 = 0,gp1=0,gp2=0,gp3=0,gp4=0,gp5=0,Palt=0,Ralt=0,Aalt=0;
public: 
	/*The next 20 lines simply set each variable to the previous. 
	This is to be able to "save" 5 moves.
	If the player loses, its set to -1
	If draw, its 0 and win is 1. Further explanation follows in Sums.*/
	void setGrS() {
		gr5 = gr4;
		gr4 = gr3;
		gr3 = gr2;	
		gr2 = gr1;
		gr1 = Ralt;
	}
	void setGpS() {
		gp5 = gp4;
		gp4 = gp3;
		gp3 = gp2;
		gp2 = gp1;
		gp1 = Palt;
	}
	void setGaS() {
		ga5 = ga4;
		ga4 = ga3;
		ga3 = ga2;
		ga2 = ga1;
		ga1 = Aalt;
	}
	/*The 3 sums below are to check "history" of results of previous games.
	This will be for a later funciton. Look for ComparePlayers, line 78*/
	void sumPs() {
		sumP = gp5 + gp4 + gp3 + gp2 + gp1;
		
	}
	void sumRs() {
		sumR = gr5 + gr4 + gr3 + gr2 + gr1;
	}
	void sumAs() {
		sumA = ga5 + ga4 + ga3 + ga2 + ga1;
	}
	/*This function is for outputs to check which has been played. Look at main.*/
	int CheckWhichPlayerPlayed()
	{
		if (sumP >= sumR && sumP >= sumA) {
			return 1;
			
		}
		else if (sumA > sumR) {
			return 2;
			
		}
		else {
			return 3;

		}
	}
	/*Compare players will be to see if the manager lost or won against
	The opponent. It is used to set ProbabilityAlt
	AHPAlt and RandomAlt at each round.
	That way they will each be updated with their respective
	played moves and will have their own history.
	The one with most wins will be picked in nextMove*/
	void comparePlayers(Move opponent) {
		if (probHimPast == Rock && opponent == Paper) {
			Palt = -1;
			
		}
		else if (probHimPast == Rock && opponent == Scissors) {
			Palt = 1;
			
		}
		else if (probHimPast == Paper && opponent == Rock) {
			Palt = 1;
		
		}
		else if (probHimPast == Paper && opponent == Scissors) {
			Palt = -1;
			
		}
		else if (probHimPast == Scissors && opponent == Paper) {
			Palt = 1;
			
		}
		else if (probHimPast == Scissors && opponent == Rock) {
			Palt = -1;
		
		}
		else {
			Palt = 0;
		
		}
		if (ahpMePast == Rock && opponent == Paper) {
			Aalt = -1;
	
		}
		else if (ahpMePast == Rock && opponent == Scissors) {
			Aalt = 1;
		
		}
		else if (ahpMePast == Paper && opponent == Rock) {
			Aalt = 1;
		
		}
		else if (ahpMePast == Paper && opponent == Scissors) {
			Aalt = -1;
		
		}
		else if (ahpMePast == Scissors && opponent == Paper) {
			Aalt = 1;
		
		}
		else if (ahpMePast == Scissors && opponent == Rock) {
			Aalt = -1;
		
		}
		else {
			Aalt = 0;
		
		}
		if (randMePast == Rock && opponent == Paper) {
			Ralt = -1;

		}
		else if (randMePast == Rock && opponent == Scissors) {
			Ralt = 1;
		
		}
		else if (randMePast == Paper && opponent == Rock) {
			Ralt = 1;
	
		}
		else if (randMePast == Paper && opponent == Scissors) {
			Ralt = -1;
	
		}
		else if (randMePast == Scissors && opponent == Paper) {
			Ralt = 1;
	
		}
		else if (randMePast == Scissors && opponent == Rock) {
			Ralt = -1;

		}
		else {
			Ralt = 0;


		}
		return;
	}

	//Define function to be able to create objects of that class.
	Move nextMove() {
		cout << "Random Player picked\t";
		return Randomonium.nextMove();
	}
	/*nextMove will take both players's moves and results.
	nextMove will run the nextMove of every player, and based on the 
	win history of them will pick 1.
	Probability is on top of hierarchy, because if probability has highest wins, it most
	probably detected a sequence. After that, AHP comes in the hierarchy.
	Random comes last as a last resort.*/
	Move nextMove(Move SecondPlayerPrev,Move FirstPlayerPrev, GameResult SecondPlayerPast, GameResult FirstPlayerResult) {
		probHimPast = Probium.nextMove(SecondPlayerPast,SecondPlayerPrev);
		ahpMePast = AHPonium.nextMove(FirstPlayerPrev, FirstPlayerResult);
		randMePast = Randomonium.nextMove();
		
		if (sumP >= sumR && sumP >= sumA) {
			
			cout << "Probability Player picked\t";
			return probHimPast;
	}
		else if (sumA > sumR) {
			
			cout << "Anti Human Player picked\t";
			return ahpMePast;
		}
		else {
			cout << "Random Player picked\t";
			return randMePast;

		}
	};
	//UpdateProb will update probability, see probabilityplayer.h, updatemove
	void updateProb(GameResult hisPrevStatus, Move Previous, Move presentMove) {
		Probium.Prob(hisPrevStatus, Previous, presentMove);
	}
	/*Result checks who won and returns it. normally its the manager that calls it for himself.*/
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