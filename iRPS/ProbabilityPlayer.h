#pragma once
#include"RPSPlayer.h"
#include"RNGeezus.h"
#include"RandomPlayer.h"
#include<iostream>
#include"RandomPlayer.h"
class ProbPlayer : public RPSPlayer {
public:
	Move nextMove() {			//initializing nextMove to overload and be able to create objects. (not abstract anymore)
		return rand.nextMove();
	}
	/*The following 200 lines are to update probability. 
	Example for 1st if: WRR == Win Rock Rock
	If user won playing Rock, and then plays Rock again,
	His probability for playing Rock after winning with
	a rock increases, while playing paper and scissors
	After winning with rock decreases.*/
	void Prob(GameResult hisPrevStatus, Move Previous, Move presentMove) {
		if (Previous == 0) {
			if (hisPrevStatus == 0) {
				if (presentMove == 0) {
					temp = WRR;
					WRR = WRR*(1 - Factor) + Factor;
					WRS = WRS + (temp - WRR) / 2;
					WRP = WRP + (temp - WRR) / 2;
					
				}
				else if (presentMove == 1) {
					temp = WRP;
					WRP = WRP*(1 - Factor) + Factor;
					WRR = WRR + (temp - WRP) / 2;
					WRS = WRS + (temp - WRP) / 2;
				}
				else {
					temp = WRS;
					WRS = WRS*(1 - Factor) + Factor;
					WRR = WRR +(temp - WRS) / 2;
					WRP = WRP + (temp - WRS) / 2;
				}
			}
			else if (hisPrevStatus == 1) {
				if (presentMove == 0) {
					temp = DRR;
					DRR = DRR*(1 - Factor) + Factor;
					DRS = DRS + (temp - DRR) / 2;
					DRP = DRP + (temp - DRR) / 2;
				}
				else if (presentMove == 1) {
					temp = DRP;
					DRP = DRP*(1 - Factor) + Factor;
					DRR = DRR + (temp - DRP) / 2;
					DRS = DRS + (temp - DRP) / 2;
				}
				else {
					temp = DRS;
					DRS = DRS*(1 - Factor) + Factor;
					DRR = DRR + (temp - DRS) / 2;
					DRP = DRP + (temp - DRS) / 2;
				}
			}
			else {
				if (presentMove == 0) {
					temp = LRR;
					LRR = LRR*(1 - Factor) + Factor;
					LRS = LRS + (temp - LRR) / 2;
					LRP = LRP + (temp - LRR) / 2;
				}
				else if (presentMove == 1) {
					temp = LRP;
					LRP = LRP*(1 - Factor) + Factor;
					LRR = LRR + (temp - LRP) / 2;
					LRS = LRS + (temp - LRP) / 2;
				}
				else {
					temp = LRS;
					LRS = LRS*(1 - Factor) + Factor;
					LRR = LRR + (temp - LRS) / 2;
					LRP = LRP + (temp - LRS) / 2;
				}
			}
		}
	
		else if (Previous == 2) {
			if (hisPrevStatus == 0) {
				if (presentMove == 0) {
					temp = WSR;
					WSR = WSR*(1 - Factor) + Factor;
					WSS = WSS + (temp - WSR) / 2;
					WSP = WSP + (temp - WSR) / 2;
				}
				else if (presentMove == 1) {
					temp = WSP;
					WSP = WSP*(1 - Factor) + Factor;
					WSR = WSR + (temp - WSP) / 2;
					WSS = WSS + (temp - WSP) / 2;
				}
				else {
					temp = WSS;
					WSS = WSS*(1 - Factor) + Factor;
					WSR = WSR + (temp - WSS) / 2;
					WSP = WSP + (temp - WSS) / 2;
				}
			}
			else if (hisPrevStatus == 1) {
				if (presentMove == 0) {
					temp = DSR;
					DSR = DSR*(1 - Factor) + Factor;
					DSS = DSS + (temp - DSR) / 2;
					DSP = DSP + (temp - DSR) / 2;
				}
				else if (presentMove == 1) {
					temp = DSP;
					DSP = DSP*(1 - Factor) + Factor;
					DSR = DSR + (temp - DSP) / 2;
					DSS = DSS + (temp - DSP) / 2;
				}
				else {
					temp = DSS;
					DSS = DSS*(1 - Factor) + Factor;
					DSR = DSR + (temp - DSS) / 2;
					DSP = DSP + (temp - DSS) / 2;
				}
			}
			else {
				if (presentMove == 0) {
					temp = LSR;
					LSR = LSR*(1 - Factor) + Factor;
					LSS = LSS + (temp - LSR) / 2;
					LSP = LSP + (temp - LSR) / 2;
				}
				else if (presentMove == 1) {
					temp = LSP;
					LSP = LSP*(1 - Factor) + Factor;
					LSR = LSR + (temp - LSP) / 2;
					LSS = LSS + (temp - LSP) / 2;
				}
				else {
					temp = LSS;
					LSS = LSS*(1 - Factor) + Factor;
					LSR = LSR + (temp - LSS) / 2;
					LSP = LSP + (temp - LSS) / 2;

				}
			}
		}
		else {
			if (hisPrevStatus == 0) {
				if (presentMove == 0) {
					temp = WPR;
					WPR = WPR*(1 - Factor) + Factor;
					WPS = WPS + (temp - WPR) / 2;
					WPP = WPP + (temp - WPR) / 2;
				}
				else if (presentMove == 1) {
					temp = WPP;
					WPP = WPP*(1 - Factor) + Factor;
					WPR = WPR + (temp - WPP) / 2;
					WPS = WPS + (temp - WPP) / 2;
				}
				else {
					temp = WPS;
					WPS = WPS*(1 - Factor) + Factor;
					WPR = WPR + (temp - WPS) / 2;
					WPP = WPP + (temp - WPS) / 2;
				}
			}
			else if (hisPrevStatus == 1) {
				if (presentMove == 0) {
					temp = DPR;
					DPR = DPR*(1 - Factor) + Factor;
					DPS = DPS + (temp - DPR) / 2;
					DPP = DPP + (temp - DPR) / 2;
				}
				else if (presentMove == 1) {
					temp = DPP;
					DPP = DPP*(1 - Factor) + Factor;
					DPR = DPR + (temp - DPP) / 2;
					DPS = DPS + (temp - DPP) / 2;
				}
				else {
					temp = DPS;
					DPS = DPS*(1 - Factor) + Factor;
					DPR = DPR + (temp - DPS) / 2;
					DPP = DPP + (temp - DPS) / 2;
				}
			}
			else {
				if (presentMove == 0) {
					temp = LPR;
					LPR = LPR*(1 - Factor) + Factor;
					LPS = LPS + (temp - LPR) / 2;
					LPP = LPP + (temp - LPR) / 2;
				}
				else if (presentMove == 1) {
					temp = LPP;
					LPP = LPP*(1 - Factor) + Factor;
					LPR = LPR + (temp - LPP) / 2;
					LPS = LPS + (temp - LPP) / 2;
				}
				else {
					temp = LPS;
					LPS = LPS*(1 - Factor) + Factor;
					LPR = LPR + (temp - LPS) / 2;
					LPP = LPP + (temp - LPS) / 2;

				}
			}
		}

		/*nextMove will take previous move and result.
		Base on that, the next move will be picked.
		Example: nextMove(Win,Rock)
		Means last round, the opponent won with Rock.
		If WRR > WRP and WRS, then his chance of playing
		Rock next is higher, and the probability player will
		Play paper to counter his move.
		This applies to the next 160 lines.
		Starts with W = Win, D = Draw, L = Lose.*/
	}
	Move nextMove(GameResult hisPrev,Move Previous) {
		if (hisPrev == 0) {
			if (Previous == 0) {
				if (WRR > WRP && WRR > WRS) {
					return Paper;
				}
				else if (WRP > WRR && WRP > WRS) {
					return Scissors;
				}
				else if (WRS > WRR && WRS > WRP) {
					return Rock;
				}
				else {
			
					return rand.nextMove();
				}
			}
			else if (Previous == 2) {
				if (WSR > WSP && WSR > WSS) {
					return Paper;
				}
				else if (WSP > WSR && WSP > WSS) {
					return Scissors;
				}
				else if (WSS > WSR && WSS > WSP) {
					return Rock;
				}
				else {
					
					return rand.nextMove();
				}
			}
			else if (Previous == 1) {
				if (WPR > WPP && WPR > WPS) {
					return Paper;
				}
				else if (WPP > WPR && WPP > WPS) {
					return Scissors;
				}
				else if (WPS > WPR && WPS > WPP) {
					return Rock;
				}
				else {
				
					return rand.nextMove();
				}
			}
			else {
				
				return rand.nextMove();
			}
		}
		else if (hisPrev == 1) {
			if (Previous == 0) {
				if (DRR > DRS && DRR > DRP) {
					return Paper;
				}
				else if (DRP > DRR && DRP > DRS) {
					return Scissors;
				}
				else if (DRS > DRR && DRS > DRP) {
					return Rock;
				}
				else {
					
					return rand.nextMove();
				}
			}
			else if (Previous== 2) {
				if (DSR > DSP && DSR > DSS) {
					return Paper;
				}
				else if (DSP > DSR && DSP > DSS) {
					return Scissors;
				}
				else if (DSS > DSR && DSS > DSP) {
					return Rock;
				}
				else {
				
					return rand.nextMove();
				}
			}
			else if (Previous == 1) {
				if (DPR > DPP && DPR > DPS) {
					return Paper;
				}
				else if (DPP > DPR && DPP > DPS) {
					return Scissors;
				}
				else if (DPS > DPR && DPS > DPP) {
					return Rock;
				}
				else {
				
					return rand.nextMove();
				}
			}
			else {
			
				return rand.nextMove();
			}
		}
		else if (hisPrev == 2){
			if (Previous == 0) {
				if (LRR > LRP && LRR > LRS) {
					return Paper;
				}
				else if (LRP > LRR && LRP > LRS) {
					return Scissors;
				}
				else if (LRS > LRR && LRS > LRP) {
					return Rock;
				}
				else {
			
					return rand.nextMove();
				}
			}
			else if (Previous == 2) {
				if (LSR > LSP && LSR > LSS) {
					return Paper;
				}
				else if (LSP > LSR && LSP > LSS) {
					return Scissors;
				}
				else if (LSS > LSR && LSS > LSP) {
					return Rock;
				}
				else {
				
					return rand.nextMove();
				}
			}
			else if (Previous == 1) {
				if (LPR > LPP && LPR > LPS) {
					return Paper;
				}
				else if (LPP > LPR && LPP > LPS) {
					return Scissors;
				}
				else if (LPS > LPR && LPS > LPP) {
					return Rock;
				}
				else {
		
					return rand.nextMove();
				}
			}
			else {
		
				return rand.nextMove();
			}
		}
		else {
	
			return rand.nextMove();
		}

	}
private:
	//Move Previous = StartMove;
	RandomPlayer rand;
	double temp;
	double Factor = 0.5;
	double WRR = 1 / 3, WRP = 1 / 3, WRS = 1 / 3, DRR = 1 / 3, DRP = 1 / 3, DRS = 1/3, LRR = 1 / 3, LRP = 1 / 3, LRS = 1 / 3, WSR = 1 / 3, WSP = 1 / 3, WSS = 1 / 3, DSR = 1 / 3, DSP = 1 / 3, DSS = 1 / 3, LSR = 1 / 3, LSP = 1 / 3, LSS = 1 / 3, WPR = 1 / 3, WPP = 1 / 3, WPS = 1 / 3, DPR = 1 / 3, DPP = 1 / 3, DPS = 1 / 3, LPR = 1 / 3, LPP = 1 / 3, LPS = 1 / 3;
};