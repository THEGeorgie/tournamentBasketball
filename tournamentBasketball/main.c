#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include"tournament.h"
#include "sqlite3.h"
#include <string.h>
 struct Team {
	char id;
	char name[30];
	char m_id;
	char wins;
	char losts;
	char overallScore;
} team1;
 static char buffer[5][20];

static int callback(void* unused, int count, char** data, char** columns) {	
	for (int idx = 0; idx < count; idx++) {
		printf("|%s: %s\n", columns[idx], data[idx]);
	}
	printf("\n");

	return 0;
}

static int callbackSetTeam(void* unused, int count, char** data, char** columns) {
	for (size_t i = 0; i < count; i++) {
		for (size_t k = 0; k < strlen(data); k++)
		{
			buffer[i][k] = data[i];
		}
		
		printf("%s \n", buffer[i]);
	}

	return 0;
}

void title() {
	printf("\n------------------------------------");
	printf("\n-    MINI BASCKETBALL TOURNAMENT   -");
	printf("\n------------------------------------\n");
}
void commandExe(char name[]) {
	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	//printf("The name is %s", name);
	rc = sqlite3_open("database.db", &db);
		char sql = "SELECT * FROM TEAM where name=";
		rc = sqlite3_exec(db, sql, callbackSetTeam, NULL, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			printf("%c team selected", team1.id);
		}
			
	sqlite3_close(db);
}
void commandReader(char input[]) {
	int word, index;
	char extracted[10][10];
	char buffer[] = "select";
	word = 0; index = 0;
	for (int i = 0; i <= strlen(input); i++) {
		if (input[i] == '-' || input[i] == "\0" || input[i] == ' ') {
			extracted[word][index] = "\0";
			word++;
			index = 0;
		}
		else {
			extracted[word][index] = input[i];
			if (extracted[word][index] == buffer[i]) {
				commandExe(extracted[word][index + 1]);
				printf("YEssir");
			}
			else
			{
				printf("\nShit aint it");
			}
			index++;
		}
		
	}
}

int main() {

	char* zErrMsg = 0;
	int rc;
	char input;
	char command[30 + 1];
	sqlite3* db;

	title();
	
	printf("\n Create team, Chose team, Edit Team (a,b,c)");
	scanf_s("%c", &input, 1);

	switch (input)
	{
	case 'a':
		system("cls");
	case 'b':
		system("cls");
		title();
		rc = sqlite3_open("database.db", &db);
		rc = sqlite3_exec(db, "SELECT name,wins,losts,overall_score from TEAM", callback, NULL, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		sqlite3_close(db);
		scanf_s("%29s", command, (unsigned)_countof(command));
		commandReader(command);

		
	default:
		break;
	}


	return 0;
}

/*
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
*/
