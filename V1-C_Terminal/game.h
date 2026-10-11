void startGame(int mode, char board[3][3]);

int playerMove();

int validMoveInput(char board[3][3], int index);

void puttingInput(char board[3][3], int index, char token);

void gameOverText(int number);

int gameOver(char board[3][3], char token1, char token2);

void playerVsPlayer(char board[3][3]);

void playerVsAI1(char board[3][3]);

void playerVsAI2(char board[3][3]);

void playerVsAI3(char board[3][3]);
