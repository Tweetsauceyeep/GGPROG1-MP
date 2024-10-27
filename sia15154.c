/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
<Sia, Ethan James D.> - <12415154> - <S11>
******************************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include "gameFuncs.c"


/*
Description: <Function displays starting screen, as well as allows players to pick number of players and set the difficulty.>
Precondition: <N/A>
@param <name> <purpose> 
  <numPlayers> <Stores Value of number of players>
  <gameDifficulty> <Stores Value of Game Difficulty Level>
  <numMin> <Minimum value for numbers in math problem>
  <numMax> <Maximum value for numbers in math problem>
@return <N/A: sets values through pointers.>
*/
void setupGame(int *numPlayers, int *gameDifficulty, int *numMin, int *numMax)
{
  // start screen
  printf("\n");
	printf("	****************************\n");
	printf("	*        Welcome to        *\n");
	printf("	*                          *\n");
	printf("	* A Walk in The Math Park! *\n");
	printf("	*                          *\n");
	printf("	****************************\n");

  printf("________________________________________________________________________________________\n\n");
  printf("PRINT RULES HERE\n");
  printf("________________________________________________________________________________________\n\n");

  printf("________________________________________________________________________________________\n\n");
  printf("This Game can have up to 4 players. Choose the number of players: (1) (2) (3) (4) \n");
  printf("________________________________________________________________________________________\n\n");


  printf("Choose Number of Players [(1) (2) (3) (4)]: ");
  scanf("%d", numPlayers);

  while (*numPlayers < 1 || *numPlayers > 4) {
    printf("Pick one of the Available Choices, Try Again.\n");
    printf("Choose Number of Players [(1) (2) (3) (4)]: ");
    scanf("%d", numPlayers);
  }

  printf("Number of Players: (%d) Selected\n", *numPlayers);

  printf("________________________________________________________________________________________\n\n");
  printf("There are 3 Difficulties to Choose from, (1) Easy (2) Normal (3) Hard\n");
  printf("________________________________________________________________________________________\n\n");

  // Difficulty Selection:
  printf("Choose Your Difficulty [(1) (2) (3)]: ");
  scanf("%d", gameDifficulty);

  while (*gameDifficulty < 1 || *gameDifficulty > 3) {
    printf("Pick one of the Available Choices, Try Again.\n");
    printf("Choose Your Difficulty [(1) (2) (3)]: ");
    scanf("%d", gameDifficulty);
  }
  printf("Game Difficulty (%d) Selected\n", *gameDifficulty);
  // Sets the Game Difficulty, by setting minimum and max values for the math problems.
  if (*gameDifficulty == 1){
    *numMin = -10;
    *numMax = 10;
  } else if (*gameDifficulty == 2)
  {
    *numMin = -100;
    *numMax = 100;
  } else if (*gameDifficulty == 3)
  {
    *numMin = -1000;
    *numMax = 1000;
  }
  /*START THE GAME*/
	printf("\n");
	printf("	*     Are you ready to     *\n");
	printf("	*           start          *\n");
	printf("	* A Walk in The Math Park? *\n");
	printf("	*                          *\n");
	printf("	*  Difficulty: (%i)         *\n", *gameDifficulty);
	printf("	*                          *\n");
	printf("	*                          *\n\n\n");
}


// TODO: What happens when player rolls a 6
int movePlayerPosition(int initialPlayerPosition, int diceRoll, int winningPosition)
{
  int newPosition;
  newPosition = initialPlayerPosition + diceRoll;
  if (newPosition > winningPosition )
  {
    printf("(Roll makes position Larger than %d) ", winningPosition);
    int  overshoot = newPosition - winningPosition;
    newPosition = winningPosition - overshoot;
    return newPosition;
  } else 
  {
    return newPosition;
  }

}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int generateMathProblem(int min, int max){
  int num1, num2, ans;
  char operator;
  num1 = getRandomNumber(min, max);
  num2 = getRandomNumber(min, max);

  int operatorInt = rand() % 5;
  
  // avoid division by 0
  if (operatorInt == 3 && num2 == 0) num2 = 1;
  
  // Operator Generator
  // randomized number between 1 and 4;
  if (operatorInt== 0) {
    operator = '+';
    ans = num1 + num2;
  } else if (operatorInt== 1) {
    operator = '-';
    ans = num1 - num2;
  } else if (operatorInt== 2) {
    operator = '*';
    ans = num1 * num2;
  } else if (operatorInt== 3) {
    operator = '/';
    ans = num1 / num2;
  } else if (operatorInt == 4) {
    operator = '%';
    ans = num1 % num2;
  }

    printf("Solve: %d %c %d = ?\n", num1, operator, num2);
    int userAns;
    printf("Your answer: ");
    scanf("%d", &userAns);
    if (userAns == ans) {
        printf("-------------------------------\n");
        printf("Correct!\n");
        printf("-------------------------------\n\n");
        return 1;
    } else {
        printf("-------------------------------\n");
        printf("Incorrect. The correct answer is %d.\n", ans);
        printf("-------------------------------\n");
        return 0; // 0 is false
    }
  
}

/*
Description: <Displays a scoreboard of player positions.>
Precondition: <>
@param <name> <purpose> 
  <player1Pos> <Stores position of player 1>
  <player2Pos> <Stores position of player 2>
  <player3Pos> <Stores position of player 3>
  <player4Pos> <Stores position of player 4>
@return <N/A>
*/
void displayScoreboard(int player1Pos, int player2Pos , int player3Pos , int player4Pos, int roundNumber, int currentPlayer, int numPlayers)
{
  printf("\nPlayer Standings:\n");
  printf("Round Number: [%d]    Current Player: [%d]\n", roundNumber, currentPlayer);
  printf("________________________________________________________________________________________\n\n");
  if (numPlayers >= 1)
  {
  printf("Player 1 Position: %d \n", player1Pos);
  }
  if (numPlayers >=2)
  {
  printf("Player 2 Position: %d \n", player2Pos);
  }
  if (numPlayers >=3)
  {
  printf("Player 3 Position: %d \n", player3Pos);
  }
  if (numPlayers >=4)
  {
  printf("Player 4 Position: %d \n", player4Pos);
  }
  printf("________________________________________________________________________________________\n\n");
}

/*
<Generates a random number between a specified range (1, 6) then returning that number to be used in main>
Precondition: <No Preconditions/Assumptions.>
@param <name> <purpose> <N/A>
@return <Randomized Number between 1 and 6>
*/
int diceRoll(){
  int num;
  num = rand() % 6 + 1;
  return num;
}

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

void handleCorrectAnswer(int currentPlayer, int playerPosition) 
{
  printf("***Player (%d) Stays in same Tile: New Position is: (%d)***\n\n", currentPlayer, playerPosition);
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

// better to separate printing from the logic. Old playTurn function was WAY too long
void playTurn(int *gameStatus, int currentPlayer, int *playerPosition, int winningPosition, int numMin, int numMax, int *numPlayers, int *winningPlayer)
{
  int rolledSix = 0;
  do
  {
    if (rolledSix) 
    {
      printf("Player Rolled a 6!: Extra turn for Player [%d]", currentPlayer);
    }
    // initially it was *playerPosition, but i got errors.
    int dice = rollDiceAndMove(currentPlayer, playerPosition, winningPosition);
    int answerCorrect = generateAndCheckMathProblem(numMin, numMax);

    if (answerCorrect == 1) {
      handleCorrectAnswer(currentPlayer, *playerPosition);
    } else if (answerCorrect == 0) // 0 is false 1 is true
    {
      handleIncorrectAnswer(currentPlayer, playerPosition, numPlayers);
    }

    if (*playerPosition == winningPosition) 
    {
      *gameStatus = 1;
      *winningPlayer = currentPlayer;
    }
    rolledSix = (dice == 6);
  } while (rolledSix && *gameStatus != 1);
}

int main()
{
  // variable definition
  int gameDifficulty;
  int numMin, numMax; // range numbers can go from for math questions
  int roundNumber = 1; // shows round number.
  // Individual Player Positions;
  int player1Pos = 0, player2Pos = 0, player3Pos = 0, player4Pos = 0;
  int currentPlayer = 1;
  int numPlayers;  // number of players
  int winningPosition = 10; // SUPPOSED TO BE 50
  int winningPlayer;
  int gameStatus = 0; // 0 if game ongoing 1 if win


  // seed the random number generation
  srand(time(NULL));
  // game setup func
  setupGame(&numPlayers, &gameDifficulty, &numMin, &numMax);

  /*This is the actual Game Flow part, utilizes if the question was right or wrong, and its return statuses.*/
  // Preferably make a gameActive Variable.
  while (gameStatus != 1)
  {
    int *currentPosition;
    switch (currentPlayer)
    {
      case 1: currentPosition = &player1Pos; break;
      case 2: currentPosition = &player2Pos; break;
      case 3: currentPosition = &player3Pos; break;
      case 4: currentPosition = &player4Pos; break;
    } 

   // have a conditional that switches between the players. then pass in the function

  displayScoreboard(player1Pos,player2Pos,player3Pos,player4Pos,roundNumber, currentPlayer, numPlayers);
   if (*currentPosition >= 0)
   {
    playTurn(&gameStatus, currentPlayer, currentPosition, winningPosition, numMin, numMax, &numPlayers, &winningPlayer);
    // gets the modulo of current player then +1. ex. (4%4 = 0) then + 1 (player 1 turn)
    currentPlayer = (currentPlayer % numPlayers) + 1;
   } else if (*currentPosition < 0 && numPlayers > 0) 
   {
    // skips player ? if current position = -1
    currentPlayer = (currentPlayer % numPlayers) + 1;
   }

   if (currentPlayer == 1) {
      roundNumber++;
    }
  }

  // rn it works until player gets a question wrong.
  // Ending Screen
  printf("\n");
	printf("	****************************\n");
	printf("	*   Thank you for Playing  *\n");
	printf("	*                          *\n");
	printf("	* A Walk in The Math Park! *\n");
	printf("	*   [Winner: Player %d]     *\n", winningPlayer);
	printf("	*   Game Finished in       *\n");
	printf("	*   Round Number [%d]       *\n", roundNumber);
	printf("	*                          *\n");
	printf("	****************************\n");
  return 0;
}
