#include "Global.h"

//GRAFIK
void grafikPlay(int actualPlayer)
{
	system("cls");

	printf("                              PLAYER A                                               \t\t\t                              PLAYER B\n");
	printf("-----------------------------------------------------------------------------\t\t\t-----------------------------------------------------------------------------\n\n\n");

	printf("     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |  I  |  J  |  K  |  L  |\t\t\t     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |  I  |  J  |  K  |  L  |\n");
	printf("-----------------------------------------------------------------------------\t\t\t-----------------------------------------------------------------------------\n");

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		printf(" %02d  |", i + 1);
		for (int j = 0; j < ARRAYSIZE; j++)
		{
			if (playerB[i][j] == neutral)
			{
				printf("     |");
			}
			else if (playerB[i][j] == fail)
			{
				printf("  O  |");
			}
			else if (playerB[i][j] == hit)
			{
				printf("  X  |");
			}
			else if (playerB[i][j] == ship)
			{
				printf("     |");
			}
			else if (playerB[i][j] == destroyed)
			{
				printf("  #  |");
			}

		}
		printf("\t\t\t");
		printf(" %02d  |", i + 1);
		for (int j = 0; j < ARRAYSIZE; j++)
		{
			if (playerA[i][j] == neutral)
			{
				printf("     |");
			}
			else if (playerA[i][j] == fail)
			{
				printf("  O  |");
			}
			else if (playerA[i][j] == hit)
			{
				printf("  X  |");
			}
			else if (playerA[i][j] == ship)
			{
				printf("     |");
			}
			else if (playerA[i][j] == destroyed)
			{
				printf("  #  |");
			}
		}
		printf("\n-----------------------------------------------------------------------------\t\t\t-----------------------------------------------------------------------------\n");
	}

	printf(" %s\n", message);
}