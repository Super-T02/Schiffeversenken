#include "Global.h"

int main()
{
	int winner;

	//Arrays
	for (size_t i = 0; i < ARRAYSIZE; i++)
	{
		for (size_t j = 0; j < ARRAYSIZE; j++)
		{
			playerA[i][j] = neutral;
			playerB[i][j] = neutral;
		}
	}

	//Ships
	numberOfShips_A = NUMBER_OF_SHIPS;
	numberOfShips_B = NUMBER_OF_SHIPS;

	strcpy_s(message, MESSAGE_LENGTH, "");

	

	managerStart();
	winner = managerPlay();
	printf("%d", winner);
}