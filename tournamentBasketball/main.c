#include <stdio.h>
#include<stdlib.h>
#include"tournament.h"


int main() {
	char tempName[50];
	char tempSurname[50];

	char* tempNameP = tempName;
	char* tempSurnameP = tempSurname;

	
	

	struct manager Boby;
	struct manager Tod;
	struct manager Williams;
	struct manager George;
	struct manager Wayne;
	struct manager Martin;
	struct manager Luka;
	struct manager Adam;
	struct manager Logan;
	struct manager Jake;
	struct manager Mark;
	struct manager Tory;

	

	*tempNameP = "Boby";
	//for (int i = 0; i < sizeof(*tempNameP); i++) {
		//Boby.name[i] = *tempNameP[i];
	// }
	Boby.surnname[49] = "Shmurda";
	Boby.wins = 0;
	Boby.losts = 0;
	Boby.overallScore = overAllCalculatorManager(Boby);


	struct team lakers;
	struct team celtics;
	struct team knicks;
	struct team Suns;
	struct team Bulls;
	struct team Seven6ers;
	struct team Heat;
	struct team Nuggets;
	struct team Pistons;
	struct team Kings;
	struct team Bucks;
	struct team Hornets;

	lakers.id = 1;
	lakers.name[49] = "Lakers";


	
	printf("------------------------------------");
	printf("\n-    MINI BASCKETBALL TOURNAMENT   -");
	printf("\n------------------------------------");

	//printf("\n Over for managager %s is %f", Boby.name, Boby.overallScore);
	
	for (int i = 0; i < 4; i++) {
		printf("\n %c", *(tempNameP + i));
	}
	return 0;
}


void testinfStuff() {
	int m[12] = { 1,4,5,3 };
	int size = (int*)malloc(m);
	for (int i = 0; i < size; i++) {

	}
	for (int i = 0; i < 10; i++)
	{
		printf("\n %2d", 1 + (rand() % 3));
	}
}