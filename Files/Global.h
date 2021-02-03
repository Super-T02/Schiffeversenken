//Bibs
#include <stdio.h>
#include <stdlib.h>

//Constants
#define ARRAYSIZE 12
#define MESSAGE_LENGTH 100

//Enums
enum FELDNUMBER { A = 0, B, C, D, E, F, G, H, I, J, K, L };
enum SCHIFFSTATUS {neutral = 0, ship, fail, hit, destroyed};
enum PLAYER {PLAYER_A = 1, PLAYER_B};

//Array defenition
	//Player A
	int playerA[ARRAYSIZE][ARRAYSIZE];

	//Player B
	int playerB[ARRAYSIZE][ARRAYSIZE];

	

//Header
#include "End.h"
#include "Play.h"
#include "Start.h"