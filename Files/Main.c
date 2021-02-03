#include "Global.h"

int main()
{
	//Arrays
	for (size_t i = 0; i < ARRAYSIZE; i++)
	{
		for (size_t j = 0; j < ARRAYSIZE; j++)
		{
			playerA[i][j] = neutral;
			playerB[i][j] = neutral;
		}
	}

	strcpy_s(message, MESSAGE_LENGTH, "");

	managerStart();
}