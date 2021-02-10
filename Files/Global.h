//Bibs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants
#define ARRAYSIZE 12
#define SHIPTYPES 4
#define MESSAGE_LENGTH 10000
#define INPUT_LENGTH 10
#define NUMBER_OF_SHIPS 10

//Enums
enum FELDNUMBER { A = 0, B, C, D, E, F, G, H, I, J, K, L };
enum SCHIFFSTATUS {neutral = 0, ship, fail, hit, destroyed, allreadyTyped};
enum PLAYER {PLAYER_A = 1, PLAYER_B};

//Array defenition
	//Player A
	int playerA[ARRAYSIZE][ARRAYSIZE];
	int numberOfShips_A;

	//Player B
	int playerB[ARRAYSIZE][ARRAYSIZE];
	int numberOfShips_B;

//global Variables
	char message[MESSAGE_LENGTH];


//Header
#include "End.h"
#include "Play.h"
#include "Start.h"