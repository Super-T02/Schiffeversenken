
//Funkctions
void managerStart();
int setShip(int player, int shiplength);
int scanKoordinate(int* x, int* y);
void grafikStart(int player[ARRAYSIZE][ARRAYSIZE], int actualPlayer);
int logikStart(int xStart, int yStart, int xEnd, int yEnd, int player, int shiplength);
int boarderCheck(int xStart, int yStart, int xEnd, int yEnd, int x, int y, int vertikal, int player);
void clearMessage();
void setMessage(char input[MESSAGE_LENGTH]);