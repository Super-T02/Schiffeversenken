#include "Global.h"
//MANAGER
int managerPlay()
{
	int x, y, status;

	clearMessage();
	//What's happening
	do
	{
		
		//Player A
		setMessage("Spieler A ist am Zug.\nBitte gebe ein Feld ein auf welches du schiessen willst:\n");
		grafikPlay(PLAYER_A);

		//Get koordinates
		if (scanKoordinate(&x, &y))
		{
			clearMessage();
			setMessage("Bitte eine gueltige Koordinate eingeben.\n");
			continue;//new iritation
		}

		//set Status
		status = logikPlay(PLAYER_A, x, y);

		if (status == allreadyTyped)
		{
			clearMessage();
			setMessage("Auf dieses Feld wurde bereits geschossen.\n");
			continue;//new iritation
		}

		//replace in array
		if (replace(PLAYER_A, status, x, y))
		{
			clearMessage();
			setMessage("Schuss konnte nicht abgefeurt werden.\n");
			continue;//new iritation
		}

		clearMessage();

		//Player B
		setMessage("Spieler B ist am Zug.\nBitte gebe ein Feld ein auf welches du schiessen willst:\n");
		grafikPlay(PLAYER_B);

		//Get koordinates
		if (scanKoordinate(&x, &y))
		{
			clearMessage();
			setMessage("Bitte eine gueltige Koordinate eingeben.\n");
			continue;//new iritation
		}

		//set Status
		status = logikPlay(PLAYER_B, x, y);

		if (status == allreadyTyped)
		{
			clearMessage();
			setMessage("Auf dieses Feld wurde bereits geschossen.\n");
			continue;//new iritation
		}

		//replace in array
		if (replace(PLAYER_B, status, x, y))
		{
			clearMessage();
			setMessage("Schuss konnte nicht abgefeurt werden.\n");
			continue;//new iritation
		}
		
		clearMessage();
	} while (numberOfShips_A != 0 && numberOfShips_B != 0);

	//End
	if (numberOfShips_A == 0)
	{
		return PLAYER_A;
	}
	else if(numberOfShips_B == 0)
	{
		return PLAYER_B;
	}
}

//replace
int replace(int actualPlayer, int status, int x, int y)
{
	if (actualPlayer == PLAYER_A)
	{
		playerA[y][x] = status;
	}
	else if (actualPlayer == PLAYER_B)
	{
		playerB[y][x] = status;
	}
	else
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


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


//LOGIK
int logikPlay(int actualPlayer, int x, int y)
{
	int actualStatus;

	//Player A
	if (actualPlayer == PLAYER_A)
	{
		actualStatus = playerB[y][x];
		if (actualStatus == neutral)
		{
			return fail;
		}
		else if (actualStatus == ship)
		{
			//check destroy			
		}
		else
		{
			return allreadyTyped;
		}
	}
	else if(actualPlayer == PLAYER_B)
	{

	}
	
}