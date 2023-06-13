#include <stdio.h>
#include<stdlib.h>
#include"tournament.h"



int main() {
	init();
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