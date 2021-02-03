#include "Global.h"


void grafikStart(char message[MESSAGE_LENGTH], int player[ARRAYSIZE][ARRAYSIZE], int actualPlayer)
{
	system("cls");

	if (actualPlayer == PLAYER_A)
	{
		printf("Spieler A setzt nun seine Figuren.\n");
	}
	else if (actualPlayer == PLAYER_B)
	{
		printf("Spieler B setzt nun seine Figuren.\n");
	}

	printf(" %s\n", message);
	printf("-----------------------------------------------------------------------------\n\n\n");

	printf("     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |  I  |  J  |  K  |  L  |\n");
	printf("-----------------------------------------------------------------------------\n");

	for (int i = 0; i < ARRAYSIZE ; i++)
	{
		printf(" %02d  |", i + 1);
		for (int j = 0; j < ARRAYSIZE; j++)
		{
			if (player[i][j] == neutral)
			{
				printf("     |");
			}
			else if (player[i][j] == ship)
			{
				printf("  S  |");
			}
		}
		printf("\n-----------------------------------------------------------------------------\n");
	}
}