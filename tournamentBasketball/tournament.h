#pragma once
#ifndef TOR_H_
#define TOR_H_
enum Leuges {
	FIRST = 1,
	SECOND = 2,
	THIRD = 3
}leuges;

struct player {
	int id;
	char name[50];
	char surname[50];
	float overallScore;
	int speed;
	int dribling;
	int accuracy;
};

struct team {
	int id;
	char name[50];
	int players[3];
	float overallScore;
	int leuge;
	int manager;
	int wins;
	int losts;
};

struct manager {
	int id;
	char name[50];
	char surnname[50];
	int wins;
	int losts;
	float overallScore;
};

struct tournament {
	int leuge;
	int teams[12];
	int matches[6];
	int winner;
	int losers[];
};


float overAllCalculatorPlayer(struct player p);
float overAllCalculatorTeam(struct team t, struct manager m);
float overAllCalculatorManager(struct manager m);
int matchDisder();
int LeugeDisder(struct team t);
void init();


#endif // !TOR_H_
