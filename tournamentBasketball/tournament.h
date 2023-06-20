#pragma once
#ifndef TOR_H_
#define TOR_H_
enum Leuges {
	FIRST = 1,
	SECOND = 2,
	THIRD = 3
};



struct tournament {
	int leuge;
	int teams[12];
	int matches[6];
	int winner;
	int losers[];
};


float overAllCalculatorPlayer();
float overAllCalculatorTeam();
float overAllCalculatorManager();
int matchDisider();
int LeugeDisider();


#endif // !TOR_H_
