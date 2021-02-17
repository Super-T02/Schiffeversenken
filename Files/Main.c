#include "Global.h"
int main()
{
	int winner;
	char input;

	printf("Bitte Enter Druecken um zu starten....");
	getc(stdin);

	do
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

		//Ships
		numberOfShips_A = NUMBER_OF_SHIPS;
		numberOfShips_B = NUMBER_OF_SHIPS;

		clearMessage();

#if DEBUG == 1
        playerA[1][1] = ship;
        playerA[1][2] = ship;

        playerA[4][1] = ship;
        playerA[5][1] = ship;
        playerA[6][1] = ship;
        numberOfShips_A = 2;

        playerB[1][1] = ship;
        playerB[1][2] = ship;

        playerB[4][1] = ship;
        playerB[5][1] = ship;
        playerB[6][1] = ship;
        numberOfShips_B = 2;
#endif

#if DEBUG != 1
		managerStart();
#endif
		winner = managerPlay();
		
		if (winner == PLAYER_A)
		{
			clearMessage();
			setMessage("Die Flotte von SPIELER B ist UNTERGEGANGEN!\nSPIELER A war SIEGREICH.\nWollen Sie Spieler B wiederbeleben und die Schlacht von Neuem starten lassen?\nWenn ja bitte 'j' eingeben:");
			grafikEnd();
		}
		else
		{
			clearMessage();
			setMessage("Die Flotte von SPIELER A ist UNTERGEGANGEN!\nSPIELER B war SIEGREICH.\nWollen Sie Spieler A wiederbeleben und die Schlacht von Neuem starten lassen?\nWenn ja bitte 'j' eingeben:");
			grafikEnd();
		}

        scanf_s(" %c", &input);

	} while (input == 'j' || input == 'J');
	
	exit(0);
}