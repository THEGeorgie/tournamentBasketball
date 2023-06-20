#include <stdio.h>
#include<stdlib.h>
#include"tournament.h"
#include "sqlite3.h"

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main() {
	
	char input;

	printf("------------------------------------");
	printf("\n-    MINI BASCKETBALL TOURNAMENT   -");
	printf("\n------------------------------------");
	
	printf("\n Create team, Chose team, Edit Team (a,b,c)");
	scanf_s("%c", &input, 1);

	switch (input)
	{
	case 'a':
		system("cls");
	default:
		break;
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

