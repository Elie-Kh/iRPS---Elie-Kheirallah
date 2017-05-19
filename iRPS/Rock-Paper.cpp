#include "RPSPlayer.h"
class RockPlayer : public RPSPlayer {
	public:
	Move nextMove() {
		return Rock;
	};
};

class RockPaperPlayer : public RPSPlayer {
private:
	bool playedRock = false;
public:
	Move nextMove() {
			if (playedRock)
			{
				playedRock = false;
				return Paper;
			}
			else
			{
				playedRock = true;
				return Rock;
			}
		}
};
