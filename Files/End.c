#include "Global.h"

//GRAFIK
void grafikEnd()
{
	system("cls");

	printf("                              PLAYER A                                               \t\t\t                              PLAYER B\n");
	printf("-----------------------------------------------------------------------------\t\t\t-----------------------------------------------------------------------------\n\n\n");

	printf("     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |  I  |  J  |  K  |  L  |\t\t\t     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |  I  |  J  |  K  |  L  |\n");
	printf("-----------------------------------------------------------------------------\t\t\t-----------------------------------------------------------------------------\n");

	for (int i = 0; i < ARRAYSIZE - 2; i++)
	{
		printf(" %02d  |", i + 1);
		for (int j = 0; j < ARRAYSIZE - 2; j++)
		{
			if (playerB[i + 1][j + 1] == neutral)
			{
				printf("     |");
			}
			else if (playerB[i + 1][j + 1] == fail)
			{
				printf("  O  |");
			}
			else if (playerB[i + 1][j + 1] == hit)
			{
				printf("  X  |");
			}
			else if (playerB[i + 1][j + 1] == ship)
			{
				printf("  S  |");
			}
			else if (playerB[i + 1][j + 1] == destroyed)
			{
				printf("  #  |");
			}


		}
		printf("\t\t\t");
		printf(" %02d  |", i + 1);
		for (int j = 0; j < ARRAYSIZE - 2; j++)
		{
			if (playerA[i + 1][j + 1] == neutral)
			{
				printf("     |");
			}
			else if (playerA[i + 1][j + 1] == fail)
			{
				printf("  O  |");
			}
			else if (playerA[i + 1][j + 1] == hit)
			{
				printf("  X  |");
			}
			else if (playerA[i + 1][j + 1] == ship)
			{
				printf("  S  |");
			}
			else if (playerA[i + 1][j + 1] == destroyed)
			{
				printf("  #  |");
			}
		}
		printf("\n-----------------------------------------------------------------------------\t\t\t-----------------------------------------------------------------------------\n");
	}

	printf(" %s\n", message);
}