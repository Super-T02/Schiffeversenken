//Bibs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants
#define ARRAYSIZE 14
#define SHIPTYPES 4
#define MESSAGE_LENGTH 10000
#define INPUT_LENGTH 10
#define NUMBER_OF_SHIPS 1

//Enums
enum FELDNUMBER { A = 1, B, C, D, E, F, G, H, I, J, K, L };
enum SCHIFFSTATUS {neutral = 0, ship, fail, hit, destroyed, alreadyTyped};
enum PLAYER {PLAYER_A = 1, PLAYER_B};
enum DIRECTION {leftNUM = 0, underNUM, rightNUM, aboveNUM};

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