#include "tournament.h"



float overAllCalculatorPlayer(struct player p) {
	float cal = p.accuracy + p.dribling + p.speed;
	float over = cal / 3;

	return over;
}

float overAllCalculatorTeam(struct team t, struct manager m) {
	float cal = t.losts + t.wins + m.overallScore;
	float over = cal / 3;

	return over;
}

float overAllCalculatorManager(struct manager m) {
	if (m.losts == 0 || m.wins == 0) {
		return 0.0;
	}

	float cal = m.losts + m.wins;
	float over = cal / 2;

	return over;
}

int LeugeDisider(struct team t) {
	
	if (t.overallScore <= 50) {
		return THIRD;
	}
	else if (t.overallScore <= 70){
		return SECOND;
	}
	else if (t.overallScore <= 100) {
		return FIRST;
	}

}

int matchDisider(struct tournament l1, 
	struct tournament l2, struct tournament l3) {
	//Takes only the actual memory used not allocated
	for (int i = 0; i < (int*) malloc(l1.teams); i++) {

	}

}
