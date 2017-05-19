#pragma once
#include"RandomPlayer.h"
#include"PlayerManager.h"
#include"Human.h"
#include"Rock-Paper.cpp"
#include"RPSPlayer.h"
using namespace std;



int main() {
	int result = 0, player = 1, Hresult = 0, RPres = 0;;				//Result will increase and decrease whenever player wins and loses respectively. player is to define which player was picked.
	PlayerManager FirstPlayer;
	PlayerManager SecondPlayer;
	Move FirstPlayerMove = StartMove;
	Move SecondPlayerMove = StartMove;
	GameResult FirstPlayerResult = Draw;
	GameResult SecondPlayerResult = Draw;
	Move FirstPlayerPreviousMove = StartMove;
	Move SecondPlayerPreviousMove = StartMove;
	char * fname = "Result.csv";
	ofstream Result;
	Result.open(fname);
	PlayerManager ThirdPlayer;
	AHP Hello;

	if (!Result) {  // always check if a file was successfully opened
		cout << "file " << fname << " could not be opened " << endl;
		exit(1); // You can also return an exception
	}
	char * fname1 = "Scheme1.csv";
	ofstream Scheme1;
	Scheme1.open(fname1);

	if (!Scheme1) {  // always check if a file was successfully opened
		cout << "file " << fname1 << " could not be opened " << endl;
		exit(1); // You can also return an exception
	}
	char * fname2 = "Scheme2.csv";
	ofstream Scheme2;
	Scheme2.open(fname2);

	if (!Scheme2) {  // always check if a file was successfully opened
		cout << "file " << fname2 << " could not be opened " << endl;
		exit(1); // You can also return an exception
	}
	char * fname3 = "Scheme3.csv";
	ofstream Scheme3;
	Scheme3.open(fname3);

	if (!Scheme3) {  // always check if a file was successfully opened
		cout << "file " << fname3 << " could not be opened " << endl;
		exit(1); // You can also return an exception
	}
	char * fname4 = "HumanResults.csv";
	ofstream HumanResults;
	HumanResults.open(fname4);
	char * fname5 = "RPR.csv";
	ofstream RPR;
	RPR.open(fname5);

	if (!HumanResults) {  // always check if a file was successfully opened
		cout << "file " << fname4 << " could not be opened " << endl;
		exit(1); // You can also return an exception
	}
	
	for (int i = 0; i < 50; i++) {
		/*first 50 moves will be random to collect data*/
		FirstPlayerPreviousMove = FirstPlayerMove;					//move of last round will be saved at beginning
		SecondPlayerPreviousMove = SecondPlayerMove;
		FirstPlayerMove = FirstPlayer.nextMove();					//then, get new move
		player = FirstPlayer.CheckWhichPlayerPlayed();				//check which player played to save in csv file.
		if (player == 3) {
			Scheme3 << "1,";
			Scheme2 << ",";
			Scheme1 << ",";
		}
		else if(player == 2){
			Scheme2 << "1,";
			Scheme1 << ",";
			Scheme3 << ",";
		}
		else {
			Scheme1 << "1,";
			Scheme2 << ",";
			Scheme3 << ",";
		}
		SecondPlayerMove = SecondPlayer.nextMove();
		cout << "Result" << endl;
		FirstPlayerResult = FirstPlayer.result(FirstPlayerMove, SecondPlayerMove);				//get result of first player
		if (FirstPlayerResult == 0) {
			result++;
		}
		else if (FirstPlayerResult == 1) {}
		else {
			result--;
		}
		Result << result << ",";
		 
		if (FirstPlayerMove == 0) {
			cout << "Rock";
		}
		else if (FirstPlayerMove == 1) {
			cout << "Paper";
		}
		else { cout << "Scissors"; };
		cout << "\t\t\t\t"; 
		if (SecondPlayerMove == 0) {
			cout << "Rock";
		}
		else if (SecondPlayerMove == 1) {
			cout << "Paper";
		}
		else { cout << "Scissors"; };
		cout << "\t\t\t\t";
		if (FirstPlayerResult == 0) {
			cout << "win";
		}
		else if (FirstPlayerResult == 1) {
			cout << "Draw";
		}
		else {
			cout << "Lose";
		}
		cout << endl << endl;
		SecondPlayerResult = SecondPlayer.result(SecondPlayerMove, FirstPlayerMove);
		FirstPlayer.updateProb(SecondPlayerResult, SecondPlayerPreviousMove, SecondPlayerMove);		//update probability of manager
		SecondPlayer.updateProb(FirstPlayerResult, FirstPlayerPreviousMove, FirstPlayerMove);		//update probability of 2nd manager
		FirstPlayer.comparePlayers(SecondPlayerMove);			//update the past 5 game results of the players.
		SecondPlayer.comparePlayers(FirstPlayerMove);
		
		FirstPlayer.setGaS();				//set the result
		FirstPlayer.setGpS();
		FirstPlayer.setGrS();

		SecondPlayer.setGaS();				
		SecondPlayer.setGpS();
		SecondPlayer.setGrS(); 
		
		FirstPlayer.sumAs();				//calculate sum to see which player will play next.
		FirstPlayer.sumPs();
		FirstPlayer.sumRs();

		SecondPlayer.sumAs();
		SecondPlayer.sumPs();
		SecondPlayer.sumRs();
		
		
	}

	for (int i = 0; i < 950; i++) {	//all previous comments apply here.
		
		FirstPlayerPreviousMove = FirstPlayerMove;
		SecondPlayerPreviousMove = SecondPlayerMove;
		FirstPlayerMove = FirstPlayer.nextMove(SecondPlayerPreviousMove,FirstPlayerPreviousMove,SecondPlayerResult,FirstPlayerResult);
		player = FirstPlayer.CheckWhichPlayerPlayed();
		if (player == 3) {
			Scheme3 << "1,";
			Scheme2 << ",";
			Scheme1 << ",";
		}
		else if (player == 2) {
			Scheme2 << "1,";
			Scheme1 << ",";
			Scheme3 << ",";
		}
		else {
			Scheme1 << "1,";
			Scheme2 << ",";
			Scheme3 << ",";
		}

		SecondPlayerMove = SecondPlayer.nextMove(FirstPlayerPreviousMove,SecondPlayerPreviousMove,FirstPlayerResult,SecondPlayerResult);
		cout << "Result" << endl;
		FirstPlayerResult = FirstPlayer.result(FirstPlayerMove, SecondPlayerMove);
		if (FirstPlayerResult == 0) {
			result++;
		}
		else if (FirstPlayerResult == 1) {
		}
		else {
			result--;
		}
		Result << result << ",";
		if (FirstPlayerResult == 0) {
			result++;
		}
		else if (FirstPlayerResult == 1) {}
		else {
			result--;
		}
		Result << result << ",";

		if (FirstPlayerMove == 0) {
			cout << "Rock";
		}
		else if (FirstPlayerMove == 1) {
			cout << "Paper";
		}
		else { cout << "Scissors"; };
		cout << "\t\t\t\t";
		if (SecondPlayerMove == 0) {
			cout << "Rock";
		}
		else if (SecondPlayerMove == 1) {
			cout << "Paper";
		}
		else { cout << "Scissors"; };
		cout << "\t\t\t\t";
		if (FirstPlayerResult == 0) {
			cout << "win";
		}
		else if (FirstPlayerResult == 1) {
			cout << "Draw";
		}
		else {
			cout << "Lose";
		}
		cout << endl << endl;
		SecondPlayerResult = SecondPlayer.result(SecondPlayerMove, FirstPlayerMove);
		FirstPlayer.updateProb(SecondPlayerResult, SecondPlayerPreviousMove, SecondPlayerMove);
		SecondPlayer.updateProb(FirstPlayerResult, FirstPlayerPreviousMove, FirstPlayerMove);

		FirstPlayer.comparePlayers(SecondPlayerMove);
		SecondPlayer.comparePlayers(FirstPlayerMove);

		FirstPlayer.setGaS();
		FirstPlayer.setGpS();
		FirstPlayer.setGrS();

		SecondPlayer.setGaS();
		SecondPlayer.setGpS();
		SecondPlayer.setGrS();

		FirstPlayer.sumAs();
		FirstPlayer.sumPs();
		FirstPlayer.sumRs();

		SecondPlayer.sumAs();
		SecondPlayer.sumPs();
		SecondPlayer.sumRs();
	}
	Result.close();
	Scheme1.close();
	Scheme2.close();
	Scheme3.close();

	//Testing against human. Same as previously.
	Move ThirdMove = StartMove, HumanMove = StartMove;
	GameResult ThirdResult = Draw, HumanResult = Draw;
	Move HumanPrevious = StartMove,ThirdPrevious = StartMove;
	for (int i = 0; i < 1000; i++) {
		HumanPrevious = HumanMove;
		ThirdPrevious = ThirdMove;
		ThirdMove = ThirdPlayer.nextMove(HumanPrevious, ThirdPrevious, HumanResult, ThirdResult);
		cout << "Human\t";
		HumanMove = Hello.nextMove(HumanMove, HumanResult);
		cout << "Result" << endl;
		ThirdResult = ThirdPlayer.result(ThirdMove, HumanMove);
		if (ThirdResult == 0) {
			Hresult++;
		}
		else if (ThirdResult == 1) {
		}
		else {
			Hresult--;
		}
		HumanResults << Hresult << ",";
		if (FirstPlayerResult == 0) {
			result++;
		}
		else if (FirstPlayerResult == 1) {}
		else {
			result--;
		}
		HumanResults << result << ",";

		if (ThirdMove == 0) {
			cout << "Rock";
		}
		else if (ThirdMove == 1) {
			cout << "Scissors";
		}
		else { cout << "Paper"; };
		cout << "\t\t";
		if (HumanMove == 0) {
			cout << "Rock";
		}
		else if (HumanMove == 1) {
			cout << "Scissors";
		}
		else { cout << "Paper"; };
		cout << "\t\t";
		if (ThirdResult == 0) {
			cout << "win";
		}
		else if (ThirdResult == 1) {
			cout << "Draw";
		}
		else {
			cout << "Lose";
		}
		cout << endl << endl;
		if (ThirdResult == Win) {
			HumanResult = Lose;
		}
		else if (ThirdResult == Lose) {
			HumanResult = Win;
		}
		else {
			HumanResult = Draw;
		}
		ThirdPlayer.updateProb(HumanResult,HumanPrevious,HumanMove);
		ThirdPlayer.comparePlayers(HumanMove);
		ThirdPlayer.setGaS();
		ThirdPlayer.setGpS();
		ThirdPlayer.setGrS();
		ThirdPlayer.sumAs();
		ThirdPlayer.sumPs();
		ThirdPlayer.sumRs();
	}
	HumanResults.close();

	PlayerManager RockBreaker;
	RockPlayer Rocky;
	Move breakerMove = StartMove, rockMove = Rock, rockPrevious = StartMove, breakerPrevious = StartMove;
	GameResult breakerResult = Draw, rockResult = Draw;
	for (int i = 0; i < 20; i++) {
		rockPrevious = rockMove;
		breakerPrevious = breakerMove;
		rockMove = Rocky.nextMove();
		breakerMove = RockBreaker.nextMove(rockPrevious, breakerPrevious, rockResult, breakerResult);
		cout << "Rock\t\tResult" << endl;
		breakerResult = RockBreaker.result(breakerMove, rockMove);
		if (breakerMove == 0) {
			cout << "Rock";
		}
		else if (breakerMove == 1) {
			cout << "Paper";
		}
		else { cout << "Scissors"; };
		cout << "\t\t";
		if (rockMove == 0) {
			cout << "Rock";
		}
		else if (rockMove == 1) {
			cout << "Paper";
		}
		else { cout << "Scissors"; };
		cout << "\t\t";
		if (breakerResult == 0) {
			cout << "win";
		}
		else if (breakerResult == 1) {
			cout << "Draw";
		}
		else {
			cout << "Lose";
		}
		cout << endl << endl;
		if (breakerResult == Win) {
			rockResult = Lose;
		}
		else if (breakerResult == Lose) {
			rockResult = Win;
		}
		else {
			rockResult = Draw;
		}
		RockBreaker.updateProb(rockResult, rockPrevious, rockMove);
		RockBreaker.comparePlayers(rockMove);
		RockBreaker.setGaS();
		RockBreaker.setGpS();
		RockBreaker.setGrS();
		RockBreaker.sumAs();
		RockBreaker.sumPs();
		RockBreaker.sumRs();
	}
	PlayerManager RPBreaker;
	RockPaperPlayer RP;
	Move rpBMove = StartMove, rpMove = Rock, rpPrevious = Paper, rpBPrevious = StartMove;
	GameResult rpBResult = Draw, rpResult = Draw;
	for (int i = 0; i < 20; i++) {
		rpPrevious = rpMove;
		rpBPrevious = rpBMove;
		rpMove = RP.nextMove();
		rpBMove = RPBreaker.nextMove(rpPrevious, rpBPrevious, rpResult, rpBResult);
		cout << "Rock-Paper\t\tResult" << endl;
		rpBResult = RPBreaker.result(rpBMove, rpMove);
		if (rpBMove == 0) {
			cout << "Rock";
		}
		else if (rpBMove == 1) {
			cout << "Paper";
		}
		else { cout << "Scissors"; };
		cout << "\t\t\t";
		if (rpMove == 0) {
			cout << "Rock";
		}
		else if (rpMove == 1) {
			cout << "Paper";
		}
		else { cout << "Scissors"; };
		cout << "\t\t\t";
		if (rpBResult == 0) {
			cout << "win";
		}
		else if (rpBResult == 1) {
			cout << "Draw";
		}
		else {
			cout << "Lose";
		}
		cout << endl << endl;
		if (rpBResult == Win) {
			rpResult = Lose;
		}
		else if (rpBResult == Lose) {
			rpResult = Win;
		}
		else {
			rpResult = Draw;
		}
		if (rpBResult == 0) {
			RPres++;
		}
		else if (rpBResult == 1) {}
		else {
			RPres--;
		}
		RPR << RPres << ",";
		RPBreaker.updateProb(rpResult, rpPrevious, rpMove);
		RPBreaker.comparePlayers(rpMove);
		RPBreaker.setGaS();
		RPBreaker.setGpS();
		RPBreaker.setGrS();
		RPBreaker.sumAs();
		RPBreaker.sumPs();
		RPBreaker.sumRs();
	}
	system("pause");
	return 0;
}