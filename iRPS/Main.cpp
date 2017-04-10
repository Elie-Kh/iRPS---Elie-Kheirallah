#include"RandomPlayer.h"
using namespace std;
int main() {
	RandomPlayer ana;
	int frq = 0, frq1 = 0, frq2 = 0;
	ofstream out;
		out.open("mytext.csv");
	for (int i = 0; i < 1000; i++) {
		
		
		out << ana.nextMove() << ",";
		
		
	}
	system("pause");
	return 0;
}