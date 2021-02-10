#include "Global.h"

//MANAGER
void managerStart()
{
	//Player A
		//6er Ship
		do
		{
			setMessage("Bitte die Koordinaten vom 6er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 6));
		clearMessage();

		//4er Ships
		do
		{
			setMessage("Bitte die Koordinaten vom ersten 4er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 4));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom zweiten 4er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 4));
		clearMessage();


		//3er Ships
		do
		{
			setMessage("Bitte die Koordinaten vom ersten 3er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 3));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom zweiten 3er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 3));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom dritten 3er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 3));
		clearMessage();

		//2er Ships
		do
		{
			setMessage("Bitte die Koordinaten vom ersten 2er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 2));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom zweiten 2er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 2));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom dritten 2er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 2));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom vierten 2er Schiff eingeben.\n");
			grafikStart(playerA, PLAYER_A);
		} while (setShip(PLAYER_A, 2));
		clearMessage();
	//Player B
		//6er Ship
		do
		{
			setMessage("Bitte die Koordinaten vom 6er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 6));
		clearMessage();

		//4er Ships
		do
		{
			setMessage("Bitte die Koordinaten vom ersten 4er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 4));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom zweiten 4er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 4));
		clearMessage();


		//3er Ships
		do
		{
			setMessage("Bitte die Koordinaten vom ersten 3er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 3));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom zweiten 3er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 3));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom dritten 3er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 3));
		clearMessage();

		//2er Ships
		do
		{
			setMessage("Bitte die Koordinaten vom ersten 2er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 2));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom zweiten 2er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 2));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom dritten 2er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 2));
		clearMessage();

		do
		{
			setMessage("Bitte die Koordinaten vom vierten 2er Schiff eingeben.\n");
			grafikStart(playerB, PLAYER_B);
		} while (setShip(PLAYER_B, 2));
		clearMessage();
}

//Asks for Koordinates
int setShip(int player, int shiplength)
{
	int xStart, yStart, xEnd, yEnd;

	do
	{
		printf("Bitte Startkoordinate eingeben zB. A1\n");
	} while (scanKoordinate(&xStart, &yStart));

	do
	{
		printf("Bitte Endkoordinate eingeben zB. B1\n");
	} while (scanKoordinate(&xEnd, &yEnd));

	clearMessage();

	if (logikStart( xStart, yStart, xEnd, yEnd, player, shiplength) == EXIT_SUCCESS)
	{
		strcat_s(message, MESSAGE_LENGTH, "Schiff wurde platziert.\n");
		return EXIT_SUCCESS;
	}
	else
	{
		setMessage( "Schiff darf nicht plaziert werden. Bitte nur von Links nach Rechts und Oben nach Unten.\nAusserdem beim Schiffeplatzieren die Plazierregeln beachten!\n");
		return EXIT_FAILURE;
	}
}

//Gets User input
int scanKoordinate(int* x, int *y)
{
	char cX;
	

	scanf_s(" %c", &cX);
	scanf_s(" %d", y);
	switch (cX)
	{
	case 'A':
		*x = A;
		break;
	case 'B':
		*x = B;
		break;
	case 'C':
		*x = C;
		break;
	case 'D':
		*x = D;
		break;
	case 'E':
		*x = E;
		break;
	case 'F':
		*x = F;
		break;
	case 'G':
		*x = G;
		break;
	case 'H':
		*x = H;
		break;
	case 'I':
		*x = I;
		break;
	case 'J':
		*x = J;
		break;
	case 'K':
		*x = K;
		break;
	case 'L':
		*x = L;
		break;
	default:
		return EXIT_FAILURE;
		break;
	}
	
	
	if (*y > 12 || *y < 1)
	{
		return EXIT_FAILURE;
	}

	*y = *y - 1;

	return EXIT_SUCCESS;
}


//GRAFIK
void grafikStart(int player[ARRAYSIZE][ARRAYSIZE], int actualPlayer)
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

	printf(" %s\n", message);

}



//LOGIK
int logikStart(int xStart, int yStart, int xEnd, int yEnd, int player, int shiplength)
{
	//Vertikal
	if (xStart == xEnd)
	{
		if (yEnd - yStart == shiplength - 1)
		{
			for (int y = yStart; y <= yEnd; y++)
			{
				if (!boarderCheck(xStart, yStart, xEnd, yEnd, 0, y, 0, player))
				{
					//Do nothing
				}
				else
				{
					return EXIT_FAILURE;
				}
			}


			if (player == PLAYER_A)
			{
				for (int y = yStart; y <= yEnd; y++)
				{
					playerA[y][xStart] = ship;
				}
			}
			else if (player == PLAYER_B)
			{
				for (int y = yStart; y <= yEnd; y++)
				{
					playerB[y][xStart] = ship;
				}
			}
			else
			{
				return EXIT_FAILURE;
			}
			
			return EXIT_SUCCESS;
		}
		else
		{
			return EXIT_FAILURE;
		}
	}
	//Horizontal
	else if (yStart == yEnd)
	{
		if (xEnd - xStart == shiplength - 1)
		{
			for (int x = xStart; x <= xEnd; x++)
			{
				if (!boarderCheck(xStart, yStart, xEnd, yEnd, x, 0, 1, player))
				{
					//Do nothing
				}
				else
				{
					return EXIT_FAILURE;
				}
			}

			if (player == PLAYER_A)
			{
				for (int x = xStart; x <= xEnd; x++)
				{
					playerA[yStart][x] = ship;
				}
			}
			else if (player == PLAYER_B)
			{
				for (int x = xStart; x <= xEnd; x++)
				{
					playerB[yStart][x] = ship;
				}
			}
			else
			{
				return EXIT_FAILURE;
			}
			
			return EXIT_SUCCESS;
		}
		else
		{
			return EXIT_FAILURE;
		}
	}
	//Default
	else
	{
		return EXIT_FAILURE;
	}

}

//Ceck
int boarderCheck(int xStart, int yStart, int xEnd, int yEnd, int x, int y, int vertikal, int player)
{
	if (player == PLAYER_A)
	{
		//Vertikal
		if (vertikal == 0)
		{
			//left side
			if (xStart - 1 < 0)
			{
				//under
				if (yStart - 1 < 0)
				{
					if (/*actual*/playerA[y][xStart] != ship &&/*right*/ playerA[y][xStart + 1] != ship && /*above*/playerA[yEnd + 1][xStart] != ship &&/*Corners*/playerA[yEnd + 1][xStart + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//above
				else if (yEnd + 1 > 11)
				{
					if (/*actual*/playerA[y][xStart] != ship &&/*right*/ playerA[y][xStart + 1] != ship && /*under*/playerA[yStart - 1][xStart] != ship &&/*Corners*/ playerA[yStart - 1][xStart + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//Default
				else
				{
					if (/*actual*/playerA[y][xStart] != ship &&/*right*/ playerA[y][xStart + 1] != ship && /*under*/playerA[yStart - 1][xStart] != ship && /*above*/playerA[yEnd + 1][xStart] != ship &&/*Corners*/ playerA[yStart - 1][xStart + 1] != ship && playerA[yEnd + 1][xStart + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
			}
			//rigth side
			else if (xStart + 1 > 11)
			{
				//under
				if (yStart - 1 < 0)
				{
					if (/*actual*/playerA[y][xStart] != ship &&/*left*/ playerA[y][xStart - 1] != ship && /*under*/playerA[yStart - 1][xStart] != ship && /*above*/playerA[yEnd + 1][xStart] != ship &&/*Corners*/playerA[yEnd + 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}

				}
				//above
				else if (yEnd + 1 > 11)
				{
					if (/*actual*/playerA[y][xStart] != ship &&/*left*/ playerA[y][xStart - 1] != ship && /*under*/playerA[yStart - 1][xStart] != ship && /*Corners*/ playerA[yStart - 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//Default
				else
				{
					if (/*actual*/playerA[y][xStart] != ship &&/*left*/ playerA[y][xStart - 1] != ship && /*under*/playerA[yStart - 1][xStart] != ship && /*above*/playerA[yEnd + 1][xStart] != ship &&/*Corners*/ playerA[yStart - 1][xStart - 1] != ship && playerA[yEnd + 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
			}
			//under
			else if (yStart - 1 < 0)
			{
				if (/*actual*/playerA[y][xStart] != ship &&/*left*/ playerA[y][xStart - 1] != ship &&/*right*/ playerA[y][xStart + 1] != ship && /*above*/playerA[yEnd + 1][xStart] != ship &&/*Corners*/  playerA[yEnd + 1][xStart - 1] != ship && playerA[yEnd + 1][xStart + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
			//above
			else if (yEnd + 1 > 11)
			{
				if (/*actual*/playerA[y][xStart] != ship &&/*left*/ playerA[y][xStart - 1] != ship &&/*right*/ playerA[y][xStart + 1] != ship && /*under*/playerA[yStart - 1][xStart] != ship &&/*Corners*/ playerA[yStart - 1][xStart - 1] != ship && playerA[yStart - 1][xStart + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
			//default
			else
			{
				if (/*actual*/playerA[y][xStart] != ship &&/*left*/ playerA[y][xStart - 1] != ship &&/*right*/ playerA[y][xStart + 1] != ship && /*under*/playerA[yStart - 1][xStart] != ship && /*above*/playerA[yEnd + 1][xStart] != ship &&/*Corners*/ playerA[yStart - 1][xStart - 1] != ship && playerA[yStart - 1][xStart + 1] != ship && playerA[yEnd + 1][xStart - 1] != ship && playerA[yEnd + 1][xStart + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
		}
		//Horizontal
		else if (vertikal == 1)
		{
			//upper
			if (yStart - 1 < 0)
			{
				//left
				if (xStart - 1 < 0)
				{
					if (/*actual*/playerA[yStart][x] != ship &&/*right*/ playerA[yStart][xEnd + 1] != ship && /*under*/playerA[yStart + 1][x] != ship && /*Corners*/ playerA[yStart + 1][xEnd + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//right
				else if (xEnd + 1 > 11)
				{
					if (/*actual*/playerA[yStart][x] != ship  && /*left*/playerA[yStart][xStart - 1] != ship && /*under*/playerA[yStart + 1][x] != ship && /*Corners*/ playerA[yStart + 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//Default
				else
				{
					if (/*actual*/playerA[yStart][x] != ship &&/*right*/ playerA[yStart][xEnd + 1] != ship && /*left*/playerA[yStart][xStart - 1] != ship && /*under*/playerA[yStart + 1][x] != ship && /*Corners*/ playerA[yStart + 1][xStart - 1] != ship && playerA[yStart + 1][xEnd + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
			}
			//lower
			else if (yStart + 1 > 11)
			{
				//left
				if (xStart - 1 < 0)
				{
					if (/*actual*/playerA[yStart][x] != ship &&/*right*/ playerA[yStart][xEnd + 1] != ship &&  /*above*/playerA[yStart - 1][x] != ship &&/*Corners*/  playerA[yStart - 1][xEnd + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}

				}
				//right
				else if (xEnd + 1 > 11)
				{
					if (/*actual*/playerA[yStart][x] != ship  && /*left*/playerA[yStart][xStart - 1] != ship && /*above*/playerA[yStart - 1][x] != ship &&/*Corners*/ playerA[yStart - 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//Default
				else
				{
					if (/*actual*/playerA[yStart][x] != ship &&/*right*/ playerA[yStart][xEnd + 1] != ship && /*left*/playerA[yStart][xStart - 1] != ship && /*above*/playerA[yStart - 1][x] != ship &&/*Corners*/ playerA[yStart - 1][xStart - 1] != ship  && playerA[yStart - 1][xEnd + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
			}
			//left
			else if (xStart - 1 < 0)
			{
				if (/*actual*/playerA[yStart][x] != ship &&/*right*/ playerA[yStart][xEnd + 1] != ship  && /*under*/playerA[yStart + 1][x] != ship && /*above*/playerA[yStart - 1][x] != ship &&/*Corners*/   playerA[yStart + 1][xEnd + 1] != ship && playerA[yStart - 1][xEnd + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
			//right
			else if (xEnd + 1 > 11)
			{
				if (/*actual*/playerA[yStart][x] != ship  && /*left*/playerA[yStart][xStart - 1] != ship && /*under*/playerA[yStart + 1][x] != ship && /*above*/playerA[yStart - 1][x] != ship &&/*Corners*/ playerA[yStart + 1][xStart - 1] != ship && playerA[yStart - 1][xStart - 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
			//default
			else
			{
				if (/*actual*/playerA[yStart][x] != ship &&/*right*/ playerA[yStart][xEnd + 1] != ship && /*left*/playerA[yStart][xStart - 1] != ship && /*under*/playerA[yStart + 1][x] != ship && /*above*/playerA[yStart - 1][x] != ship &&/*Corners*/ playerA[yStart + 1][xStart - 1] != ship && playerA[yStart - 1][xStart - 1] != ship && playerA[yStart + 1][xEnd + 1] != ship && playerA[yStart - 1][xEnd + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
		}
		//Default
		else
		{
			return EXIT_FAILURE;
		}
	}
	else if (player == PLAYER_B)
	{
		//Vertikal
		if (vertikal == 0)
		{
			//left side
			if (xStart - 1 < 0)
			{
				//under
				if (yStart - 1 < 0)
				{
					if (/*actual*/playerB[y][xStart] != ship &&/*right*/ playerB[y][xStart + 1] != ship && /*above*/playerB[yEnd + 1][xStart] != ship &&/*Corners*/playerB[yEnd + 1][xStart + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//above
				else if (yEnd + 1 > 11)
				{
					if (/*actual*/playerB[y][xStart] != ship &&/*right*/ playerB[y][xStart + 1] != ship && /*under*/playerB[yStart - 1][xStart] != ship &&/*Corners*/ playerB[yStart - 1][xStart + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//Default
				else
				{
					if (/*actual*/playerB[y][xStart] != ship &&/*right*/ playerB[y][xStart + 1] != ship && /*under*/playerB[yStart - 1][xStart] != ship && /*above*/playerB[yEnd + 1][xStart] != ship &&/*Corners*/ playerB[yStart - 1][xStart + 1] != ship && playerB[yEnd + 1][xStart + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
			}
			//rigth side
			else if (xStart + 1 > 11)
			{
				//under
				if (yStart - 1 < 0)
				{
					if (/*actual*/playerB[y][xStart] != ship &&/*left*/ playerB[y][xStart - 1] != ship && /*under*/playerB[yStart - 1][xStart] != ship && /*above*/playerB[yEnd + 1][xStart] != ship &&/*Corners*/playerB[yEnd + 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}

				}
				//above
				else if (yEnd + 1 > 11)
				{
					if (/*actual*/playerB[y][xStart] != ship &&/*left*/ playerB[y][xStart - 1] != ship && /*under*/playerB[yStart - 1][xStart] != ship && /*Corners*/ playerB[yStart - 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//Default
				else
				{
					if (/*actual*/playerB[y][xStart] != ship &&/*left*/ playerB[y][xStart - 1] != ship && /*under*/playerB[yStart - 1][xStart] != ship && /*above*/playerB[yEnd + 1][xStart] != ship &&/*Corners*/ playerB[yStart - 1][xStart - 1] != ship && playerB[yEnd + 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
			}
			//under
			else if (yStart - 1 < 0)
			{
				if (/*actual*/playerB[y][xStart] != ship &&/*left*/ playerB[y][xStart - 1] != ship &&/*right*/ playerB[y][xStart + 1] != ship && /*above*/playerB[yEnd + 1][xStart] != ship &&/*Corners*/  playerB[yEnd + 1][xStart - 1] != ship && playerB[yEnd + 1][xStart + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
			//above
			else if (yEnd + 1 > 11)
			{
				if (/*actual*/playerB[y][xStart] != ship &&/*left*/ playerB[y][xStart - 1] != ship &&/*right*/ playerB[y][xStart + 1] != ship && /*under*/playerB[yStart - 1][xStart] != ship &&/*Corners*/ playerB[yStart - 1][xStart - 1] != ship && playerB[yStart - 1][xStart + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
			//default
			else
			{
				if (/*actual*/playerB[y][xStart] != ship &&/*left*/ playerB[y][xStart - 1] != ship &&/*right*/ playerB[y][xStart + 1] != ship && /*under*/playerB[yStart - 1][xStart] != ship && /*above*/playerB[yEnd + 1][xStart] != ship &&/*Corners*/ playerB[yStart - 1][xStart - 1] != ship && playerB[yStart - 1][xStart + 1] != ship && playerB[yEnd + 1][xStart - 1] != ship && playerB[yEnd + 1][xStart + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
		}
		//Horizontal
		else if (vertikal == 1)
		{
			//upper
			if (yStart - 1 < 0)
			{
				//left
				if (xStart - 1 < 0)
				{
					if (/*actual*/playerB[yStart][x] != ship &&/*right*/ playerB[yStart][xEnd + 1] != ship && /*under*/playerB[yStart + 1][x] != ship && /*Corners*/ playerB[yStart + 1][xEnd + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//right
				else if (xEnd + 1 > 11)
				{
					if (/*actual*/playerB[yStart][x] != ship && /*left*/playerB[yStart][xStart - 1] != ship && /*under*/playerB[yStart + 1][x] != ship && /*Corners*/ playerB[yStart + 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//Default
				else
				{
					if (/*actual*/playerB[yStart][x] != ship &&/*right*/ playerB[yStart][xEnd + 1] != ship && /*left*/playerB[yStart][xStart - 1] != ship && /*under*/playerB[yStart + 1][x] != ship && /*Corners*/ playerB[yStart + 1][xStart - 1] != ship && playerB[yStart + 1][xEnd + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
			}
			//lower
			else if (yStart + 1 > 11)
			{
				//left
				if (xStart - 1 < 0)
				{
					if (/*actual*/playerB[yStart][x] != ship &&/*right*/ playerB[yStart][xEnd + 1] != ship &&  /*above*/playerB[yStart - 1][x] != ship &&/*Corners*/  playerB[yStart - 1][xEnd + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}

				}
				//right
				else if (xEnd + 1 > 11)
				{
					if (/*actual*/playerB[yStart][x] != ship && /*left*/playerB[yStart][xStart - 1] != ship && /*above*/playerB[yStart - 1][x] != ship &&/*Corners*/ playerB[yStart - 1][xStart - 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
				//Default
				else
				{
					if (/*actual*/playerB[yStart][x] != ship &&/*right*/ playerB[yStart][xEnd + 1] != ship && /*left*/playerB[yStart][xStart - 1] != ship && /*above*/playerB[yStart - 1][x] != ship &&/*Corners*/ playerB[yStart - 1][xStart - 1] != ship && playerB[yStart - 1][xEnd + 1] != ship)
					{
						return EXIT_SUCCESS;
					}
					else
					{
						return EXIT_FAILURE;//exits
					}
				}
			}
			//left
			else if (xStart - 1 < 0)
			{
				if (/*actual*/playerB[yStart][x] != ship &&/*right*/ playerB[yStart][xEnd + 1] != ship && /*under*/playerB[yStart + 1][x] != ship && /*above*/playerB[yStart - 1][x] != ship &&/*Corners*/   playerB[yStart + 1][xEnd + 1] != ship && playerB[yStart - 1][xEnd + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
			//right
			else if (xEnd + 1 > 11)
			{
				if (/*actual*/playerB[yStart][x] != ship && /*left*/playerB[yStart][xStart - 1] != ship && /*under*/playerB[yStart + 1][x] != ship && /*above*/playerB[yStart - 1][x] != ship &&/*Corners*/ playerB[yStart + 1][xStart - 1] != ship && playerB[yStart - 1][xStart - 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
			//default
			else
			{
				if (/*actual*/playerB[yStart][x] != ship &&/*right*/ playerB[yStart][xEnd + 1] != ship && /*left*/playerB[yStart][xStart - 1] != ship && /*under*/playerB[yStart + 1][x] != ship && /*above*/playerB[yStart - 1][x] != ship &&/*Corners*/ playerB[yStart + 1][xStart - 1] != ship && playerB[yStart - 1][xStart - 1] != ship && playerB[yStart + 1][xEnd + 1] != ship && playerB[yStart - 1][xEnd + 1] != ship)
				{
					return EXIT_SUCCESS;
				}
				else
				{
					return EXIT_FAILURE;//exits
				}
			}
		}
		//Default
		else
		{
			return EXIT_FAILURE;
		}
	}
	
}

//Delete Message
void clearMessage()
{
	strcpy_s(message, MESSAGE_LENGTH, "\n");
}

//set Message
void setMessage(char input[MESSAGE_LENGTH])
{
	strcat_s(message, MESSAGE_LENGTH, input);
}