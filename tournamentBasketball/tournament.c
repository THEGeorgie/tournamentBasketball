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
	float cal = m.losts + m.wins;
	float over = cal / 2;

	return over;
}

int LeugeDisder(struct team t) {
	
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

int matchDisder(struct tournament l1, 
	struct tournament l2, struct tournament l3) {
	
	for (int i = 0; i < (int*) malloc(l1.teams); i++) {

	}

}

void init() {
	struct manager Rick;
	 Rick.id = 1;
	printf("Initialized");
}