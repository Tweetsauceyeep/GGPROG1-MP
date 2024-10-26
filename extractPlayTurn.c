int rollDiceAndMove(int currentPlayer, int *playerPosition, int winningPosition)
{
  int dice = diceRoll();
  //printf("Current Player: %d  Initial Player Position: %d \n", currentPlayer, *playerPosition);
  printf("Player (%d) Rolled a %d and moved from [%d] ", currentPlayer, dice, *playerPosition);
  *playerPosition = movePlayerPosition(*playerPosition, dice, winningPosition);
  printf("to new position [%d] \n", *playerPosition);
  return dice;

}

int generateAndCheckMathProblem(int numMin, int numMax)
{
  return generateMathProblem(numMin,numMax);// What the math equation returns: 0 = question correct, 1 question wrong
}

void stayOnSameTile(int currentPlayer, int playerPosition) 
{
  printf("***Player (%d) Stays in same Tile: New Position is: (%d)***\n\n", currentPlayer, *playerPosition);
}

void handleIncorrectAnswer(int currentPlayer, int *playerPosition, int *numPlayers)
{
  int randNum = rand() % (3 - 1 + 1) + 1;
  *playerPosition = *playerPosition - randNum;
  printf("***Player (%d) sent back %d tile/s: New Position is: (%d)***\n\n", currentPlayer, randNum, *playerPosition);
  if (*playerPosition < 0) {
    *playerPosition = -1;
    // subtracts from total number of players
    *numPlayers = *numPlayers - 1;
    printf("Player (%d)is ejected from the Game", currentPlayer);
  }
}

void playTurn(int *gameStatus, int currentPlayer, int *playerPosition, int winningPosition, int numMin, int numMax, int *numPlayers, int *winningPlayer)
{
  rollDiceAndMove(currentPlayer, *playerPosition, winningPosition);
  int questionStatus = generateAndCheckMathProblem(numMin, numMax);
  if (questionStatus == 1) {
    stayOnSameTile(currentPlayer, *playerPosition);
  } else if (questionStatus == 0) // 0 is false 1 is true
  {
    handleIncorrectAnswer(currentPlayer, playerPosition, numPlayers);
  }
}