#pragma once
#include"RandomPlayer.h"
#include"PlayerManager.h"
#include"Human.h"

#include"RPSPlayer.h"
using namespace std;
int main() {
	/*PlayerManager ana;											//HUMAN DESTRUCTION
	AHP AHD;
	Human Proba;
	Move ProbaMe = StartMove;
	Move AvHum = StartMove;
	GameResult ProbaResult = Draw;
	GameResult AHPResult = Draw;
	for (int i = 0; i < 1000; i++) {
		ProbaMe = AHD.nextMove(ProbaMe,ProbaResult);
		AvHum = Proba.nextMove(AvHum, AHPResult);
		ProbaResult = ana.result(ProbaMe,AvHum);
		if (ProbaResult == Win) {
			AHPResult = Lose;
		}
		else if (ProbaResult == Lose) {
			AHPResult = Win;
		}
		else{
			AHPResult = Draw;
		}
		cout << ProbaResult;

	}*/
	PlayerManager ana;
	ProbPlayer Proba;
	Human AHD;
	//RandomPlayer ran;
	Move ProbaMe = StartMove;
	Move AvHum = StartMove;
	GameResult ProbaResult = Draw;
	GameResult AHPResult = Draw;
	Move AvHumPrev = Scissors;
	for (int j = 0; j < 500; j++) {
		AvHumPrev = AvHum;
		ProbaMe = AHD.nextMove();
		AvHum = Proba.nextMove();
		ProbaResult = ana.result(ProbaMe, AvHum);
		if (ProbaResult == Win) {
			AHPResult = Lose;
		}
		else if (ProbaResult == Lose) {
			AHPResult = Win;
		}
		else {
			AHPResult = Draw;
		}
		Proba.Prob(AHPResult, AvHumPrev, AvHum);
		//cout << ProbaMe << endl;
		//cout << AvHum << endl;
		cout << ProbaResult << endl;
	}
	cout << "end prob\n";
	for (int i = 0; i < 1000; i++) {
		
		ProbaMe = Proba.nextMove(AHPResult, AvHumPrev);
		AvHum = AHD.nextMove(AvHum, AHPResult);
		//AvHum = ran.nextMove();
		Proba.Prob(AHPResult, AvHumPrev, AvHum);
		ProbaResult = ana.result(ProbaMe, AvHum);

		if (ProbaResult == Win) {
			AHPResult = Lose;
		}
		else if (ProbaResult == Lose) {
			AHPResult = Win;
		}
		else {
			AHPResult = Draw;
		}
		
        AvHumPrev = AvHum;
		
		//cout << ProbaMe << endl;
		//cout << AvHum << endl;
		cout << ProbaResult << endl;
	}

	

	system("pause");
	return 0;
}