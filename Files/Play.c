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

		if (status == alreadyTyped)
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

		if (status == alreadyTyped)
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

	grafikPlay(PLAYER_B);

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
		playerB[y][x] = status;
	}
	else if (actualPlayer == PLAYER_B)
	{
		playerA[y][x] = status;
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
				printf("     |");
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
				printf("     |");
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
			replace(actualPlayer, hit, x, y);
			if (checkDestroy(actualPlayer, x, y) == EXIT_FAILURE)
			{
				return hit;
			}
			else
			{
				numberOfShips_B--;
				return destroyed;
			}
		}
		else
		{
			return alreadyTyped;
		}
	}
	
	//Player B
	else if(actualPlayer == PLAYER_B)
	{
		actualStatus = playerA[y][x];
		if (actualStatus == neutral)
		{
			return fail;
		}
		else if (actualStatus == ship)
		{
			replace(actualPlayer, hit, x, y);
			if (checkDestroy(actualPlayer, x, y) == EXIT_FAILURE)
			{
				return hit;
			}
			else
			{
				numberOfShips_A--;
				return destroyed;
			}
		}
		else
		{
			return alreadyTyped;
		}
	}
	
}

int checkDestroy(int actualPlayer, int x, int y)
{
	int startX, startY;
	//PLAYER B
	if (actualPlayer == PLAYER_B)
	{
		while (playerA[y - 1][x] == hit || playerA[y - 1][x] == ship)
		{
			y --;
		}
		
		while (playerA[y][x - 1] == hit || playerA[y][x - 1] == ship)
		{
			x--;
		}
		startX = x;
		startY = y;
		/*Actual position is the top-left of the ship*/
		

		if (playerA[y][x] == ship)
		{
			return EXIT_FAILURE;
		}
		//vertikal
		else if ( playerA[y + 1][x] == hit)
		{
			//Runs to the rigth end of the ship. If it the next koordinate is a ship it returns failure.
			while (playerA[y + 1][x] == hit|| playerA[y + 1][x] == ship)
			{
				y++;
				if (playerA[y][x] == ship)
				{
					return EXIT_FAILURE;
				}
			}

			while (playerA[y + 1][x] == hit || playerA[y + 1][x] == ship)
			{
				y++;
				if (playerA[y][x] == ship)
				{
					return EXIT_FAILURE;
				}
			}

			//replace hit with destroyed
			while (playerA[startY][startX] == hit || playerA[y + 1][x] == ship)
			{
				playerA[startY][startX] = destroyed;
				startY++;
			}

			return EXIT_SUCCESS;
		}
		//Case for a ship of the legth 2
		else if (playerA[y + 1][x] == ship)
		{
			return EXIT_FAILURE;
		}
		//Horizontal
		else if (playerA[y][x + 1] == hit)
		{
			//Runs to the bottom end of the ship. If it the next koordinate is a ship it returns failure.
			while (playerA[y][x + 1] == hit || playerA[y][x + 1] == ship)
			{
				x++;
				if (playerA[y][x] == ship)
				{
					return EXIT_FAILURE;
				}
			}

			//replace hit with destroyed
			while (playerA[startY][startX] == hit || playerA[y + 1][x] == ship)
			{
				playerA[startY][startX] = destroyed;
				startX++;
			}

			return EXIT_SUCCESS;
		}
		//Case for a ship of the legth 2
		else if (playerA[y][x + 1] == ship)
		{
			return EXIT_FAILURE;
		}
	}




	//PLAYER A
	else if (actualPlayer == PLAYER_A)
	{
		while (playerB[y - 1][x] == hit || playerB[y - 1][x] == ship)
		{
			y--;
		}

		while (playerB[y][x - 1] == hit || playerB[y][x - 1] == ship)
		{
			x--;
		}
		startX = x;
		startY = y;
		/*Actual position is the top-left of the ship*/

		if (playerB[y][x] == ship)
		{
			return EXIT_FAILURE;
		}
		//vertikal
		else if (playerB[y + 1][x] == hit)
		{
			//Runs to the rigth end of the ship. If it the next koordinate is a ship it returns failure.
			while (playerB[y + 1][x] == hit || playerB[y + 1][x] == ship)
			{
				y++;
				if (playerB[y][x] == ship)
				{
					return EXIT_FAILURE;
				}
			}

			//replace hit with destroyed
			while (playerB[startY][startX] == hit || playerB[y + 1][x] == ship)
			{
				playerB[startY][startX] = destroyed;
				startY++;
			}

			return EXIT_SUCCESS;
		}
		//Case for a ship of the length 2
		else if (playerB[y + 1][x] == ship)
		{
			return EXIT_FAILURE;
		}
		//Horizontal
		else if (playerB[y][x + 1] == hit)
		{
			//Runs to the bottom end of the ship. If it the next koordinate is a ship it returns failure.
			while (playerB[y][x + 1] == hit || playerB[y][x + 1] == ship)
			{
				x++;
				if (playerB[y][x] == ship)
				{
					return EXIT_FAILURE;
				}
			}

			//replace hit with destroyed
			while (playerB[startY][startX] == hit || playerB[y + 1][x] == ship)
			{
				playerB[startY][startX] = destroyed;
				startX++;
			}

			return EXIT_SUCCESS;
		}
		//Case for a ship of the length 2
		else if (playerB[y][x + 1] == ship)
		{
			return EXIT_FAILURE;
		}
	}
}