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
#include "board.c"

//#include "gameFuncs.c"


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
  int playerChoice;
  // start screen
  // TODO: CHANGE THIS TO USE EQUALS
  printf("\n");
	printf("****************************\n");
	printf("*        Welcome to        *\n");
	printf("*                          *\n");
	printf("* A Walk in The Math Park! *\n");
	printf("*                          *\n");
	printf("****************************\n");


  do 
  {
    printf("\tMAIN MENU\t\n\n");
    printf("Start game (0)\n");
    printf("Read Rules (1)\n\n");
    printf("Pick an Option (0) (1): ");
    scanf("%d", &playerChoice);

    if (playerChoice != 0) {
      printf("________________________________________________________________________________________\n\n");
      printf("### How to Play the Game ###\n");
      printf("1. Players: The game can be played by 1 to 4 players.\n\n");
      printf("2. Game Level Selection:\n");
      printf("   - Before starting, players will decide on a game level:\n");
      printf("     - Level 1: Range of numbers from -10 to 10.\n");
      printf("     - Level 2: Range of numbers from -100 to 100.\n");
      printf("     - Level 3: Range of numbers from -1000 to 1000.\n\n");
      printf("3. Rolling the Die and Movement:\n");
      printf("   - Players take turns rolling a single die to move their token by the number of squares indicated by the die roll.\n\n");
      printf("5. Token Movement:\n");
      printf("   - Tokens follow a fixed boustrophedon track on the gameboard, passing through every square once.\n");
      printf("   - For each tile a player lands on, the program randomly generates an equation (e.g., 5 * 3, 2 - 8, 7 %% 2) that the player must solve mentally.\n\n");
      printf("6. Correct Answers:\n");
      printf("   - If the player answers correctly, they stay on the current tile.\n");
      printf("   - If the answer is incorrect, the player moves back 1 to 3 tiles as a penalty (penalty is randomly generated).\n");
      printf("     - If the penalty exceeds the player's current position, they are ejected from the game.\n\n");
      printf("7. Rolling Again:\n");
      printf("   - If a player rolls a 6, they move and immediately roll again. Otherwise, play passes to the next player.\n\n");
      printf("8. Winning the Game:\n");
      printf("   - The winner is declared under one of the following conditions:\n");
      printf("     - The first player to bring their token to the last square of the track wins.\n");
      printf("       - If the die roll exceeds the necessary spaces, the token moves forward the required number of spaces and then back the difference (e.g., if requiring a 3 to win but rolling a 5, the token moves forward 3 spaces, then back 2).\n");
      printf("     - All other players are ejected from the game (i.e., their current position is a negative number).\n");
      printf("________________________________________________________________________________________\n\n");
    }
  } while(playerChoice != 0);

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

  printf("\n\nNumber of Players: (%d) Selected\n\n", *numPlayers);

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
  printf("\n\nGame Difficulty (%d) Selected\n\n", *gameDifficulty);
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
	printf("\n\n\n");
	printf("=======================================\n");
	printf("	    Are you ready to      \n");
	printf("	          start           \n");
	printf("	A Walk in The Math Park?  \n");
	printf("	                            \n");
	printf("	  Difficulty: (%i)         \n", *gameDifficulty);
	printf("	                            \n");
	printf("=======================================\n\n\n");
}

void displayTurnSeparator(int currentPlayer){
printf("\n\n\n");
printf("---------------------------------------\n");
printf("           Player (%d)'s Turn           \n",currentPlayer);
printf("---------------------------------------\n");
printf("\n\n");

}

/*
Description: <Displays the round number at the start of every round. Serves as a separator>
Precondition: <N/A>
@param <N/A> 
@return <N/A>
*/
void displayRoundSeparator(int round) {
    printf("\n\n\n");
    printf("=======================================\n");
    printf("           START OF ROUND %d           \n", round);
    printf("=======================================\n");
    printf("\n\n");
}

/*
Description: <Displays a scoreboard of player positions.>
Precondition: <>
@param <name> <purpose> 
  <player1Pos> <Stores position of player 1>
  <player2Pos> <Stores position of player 2>
  <player3Pos> <Stores position of player 3>
  <player4Pos> <Stores position of player 4>
  <roundNumber> <Stores value of current round number>
  <currentPlayer> <current player>
  <numPlayers> <Number of players playing in the game>
  <winningPosition> <Winning Position is both the number of tiles, and the last tile in the game board.>
  <tilesPerRow> <Number of tiles per row on the game board.>
@return <N/A>
*/
void displayScoreboard(int player1Pos, int player2Pos , int player3Pos , int player4Pos, int roundNumber, int currentPlayer, int numPlayers, int winningPosition, int tilesPerRow)
{

  printf("\n\tSCOREBOARD\t\n");
  printf("\nPlayer Standings:\n");
  printf("Round Number: [%d]    Current Player: [%d]\n", roundNumber, currentPlayer);
  printf("___________________________________________________\n\n");
  // the code after the && makes sure to not show the player position if theyre ejected
  if (numPlayers >= 1 && player1Pos != -1)
  {
  printf("Player 1 Position (A): %d \n", player1Pos);
  }
  if (numPlayers >=2 && player2Pos != -1)
  {
  printf("Player 2 Position (B): %d \n", player2Pos);
  }
  if (numPlayers >=3 && player3Pos != -1)
  {
  printf("Player 3 Position (C): %d \n", player3Pos);
  }
  if (numPlayers >=4 && player4Pos != -1)
  {
  printf("Player 4 Position (D): %d \n", player4Pos);
  }
  printf("___________________________________________________\n\n");

  // displays visual representation of the Game board.
  displayGameBoard(winningPosition, tilesPerRow, player1Pos, player2Pos, player3Pos, player4Pos, numPlayers);
  printf("\n");
}

/*
Description: <Displays a scoreboard of player positions.>
Precondition: <>
@param <initialPlayerPosition> <Players previous position before moving>
@param <diceRoll> <simulated dice roll, which is the amount of tiles the player will move>
@param <winningPosition> <The last tile on the board.>
@return <newPosition: variable that holds the new position of the player after moving.>
*/
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

/*
<Generates a random number within the specified range.>
Precondition: <N/A>
@param min <Minimum range value>
@param max <Maximum range value>
@return <Random number within the range of [min, max]>
*/
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/*
<Generates and displays a random math problem based on specified range and evaluates the player's answer.>
Precondition: <N/A>
@param min <Minimum range value for math problem numbers>
@param max <Maximum range value for math problem numbers>
@return <1 if the answer is correct, 0 if incorrect>
*/
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
  // TODO: Could probably use case statements.
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
        printf("_______________________________\n");
        printf("\nCorrect!\n");
        printf("_______________________________\n\n");
        return 1;
    } else {
        printf("_______________________________\n");
        printf("\nIncorrect. The correct answer is %d.\n", ans);
        printf("_______________________________\n");
        return 0; // 0 is false
    }
  
}

/*
<Generates a random number between a specified range (1, 6)>
Precondition: <No Preconditions/Assumptions.>
@param <N/A>
@return <Random Number between 1 and 6>
*/
int diceRoll(){
  int num;
  //num = rand() % 6 + 1;
  num = rand() % (6 - 1 + 1) + 1;
  return num;
}

/*
<Simulates a player's dice roll, moves the player's position, and displays their new position.>
Precondition: <playerPosition points to a valid player position>
@param currentPlayer <The current player rolling the dice>
@param playerPosition <The player's position to update after the roll>
@param winningPosition <The last tile on the board>
@return <The dice roll value>
*/
int rollDiceAndMove(int currentPlayer, int *playerPosition, int winningPosition)
{
  int dice = diceRoll();
  //printf("Current Player: %d  Initial Player Position: %d \n", currentPlayer, *playerPosition);
  printf("Player (%d) Rolled a %d and moved from [%d] ", currentPlayer, dice, *playerPosition);
  *playerPosition = movePlayerPosition(*playerPosition, dice, winningPosition);
  printf("to new position [%d] \n", *playerPosition);
  return dice;
}

/*
<Generates a math problem and checks if the player's answer is correct.>
Precondition: <N/A>
@param numMin <Minimum range value for the math problem>
@param numMax <Maximum range value for the math problem>
@return <1 if the answer is correct, 0 if incorrect>
*/
int generateAndCheckMathProblem(int numMin, int numMax)
{
  return generateMathProblem(numMin,numMax);// What the math equation returns: 0 = question correct, 1 question wrong
}

/*
<Handles the case when the player answers correctly, Displays that player is on the same tile.>
Precondition: <N/A>
@param currentPlayer <The current player>
@param playerPosition <The player's current position>
@return <N/A>
*/
void handleCorrectAnswer(int currentPlayer, int playerPosition) 
{
  printf("***Player (%d) Stays in same Tile: New Position is: (%d)***\n\n", currentPlayer, playerPosition);
}

/*
<Ejects a player from the game if their position is less than 0.>
Precondition: <>
@param playerPosition <The player's position to check>
@param numPlayers <The number of players in the game>
@param currentPlayer <The player being checked>
@return <N/A>
*/
void handlePlayerEjection(int *playerPosition, int *numPlayers, int currentPlayer)
{
  if (*playerPosition < 1) {
    printf("***Player (%d) is ejected from the Game***", currentPlayer);
    // subtracts from total number of players
    *numPlayers = *numPlayers - 1;
    *playerPosition = -1;
  }
}

/*
<Handles the case when the player answers incorrectly, moving them back a random number of tiles.>
Precondition: <playerPosition points to a valid player position>
@param currentPlayer <The current player>
@param playerPosition <The player's position to update>
@param numPlayers <The number of players remaining>
@return <N/A>
*/
void handleIncorrectAnswer(int currentPlayer, int *playerPosition, int *numPlayers)
{
  int randNum = rand() % (3 - 1 + 1) + 1;
  *playerPosition -= randNum;
  printf("***Player (%d) sent back %d tile/s: New Position is: (%d)***\n\n", currentPlayer, randNum, *playerPosition);
  // checks if player should be ejected.
  handlePlayerEjection(playerPosition, numPlayers, currentPlayer);
}
/*
<Plays a single turn for the current player, handling dice roll, movement, and math problem interaction.>
Precondition: <gameStatus != 1>
@param gameStatus <Tracks if the game is ongoing or completed>
@param currentPlayer <The current player taking their turn>
@param playerPosition <The player's position to update during the turn>
@param winningPosition <The last tile on the board>
@param numMin <Minimum value for numbers in math problem>
@param numMax <Maximum value for numbers in math problem>
@param numPlayers <The number of players remaining>
@param winningPlayer <Stores the player who won the game>
@return <N/A: Sets values through pointers.>
*/
// better to separate printing from the logic. Old playTurn function was WAY too long
void playTurn(int *gameStatus, int currentPlayer, int *playerPosition, int winningPosition, int numMin, int numMax, int *numPlayers, int *winningPlayer)
{
  int rolledSix = 0;
  do
  {

    if (rolledSix) 
    {
      printf("***Player Rolled a 6!: Extra turn for Player [%d]***\n\n", currentPlayer);
    }
    // initially it was *playerPosition, but i got errors.
    int dice = rollDiceAndMove(currentPlayer, playerPosition, winningPosition);
    int answerCorrect = generateAndCheckMathProblem(numMin, numMax);

    if (answerCorrect == 1) {
      handleCorrectAnswer(currentPlayer, *playerPosition);
    } 
    // TODO was an else if
    if (answerCorrect == 0) // 0 is false 1 is true
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
  // GAMEBOARD size initialization
  // SUPPOSED TO BE 50
  int winningPosition = 20; 
  int tilesPerRow = 10;

  int gameDifficulty; // Value of Game difficulty (1-3) 
  int numMin, numMax; // range of numbers for math questions
  int roundNumber = 1; // shows round number.
  int player1Pos = 1, player2Pos = 1, player3Pos = 1, player4Pos = 1; // Player Positions
  int currentPlayer = 1; // Current player of the game, starts at 1.
  int numPlayers;  // number of players
  int winningPlayer; // Used to display the winner of the game.
  int gameStatus = 0; // 0 if game ongoing 1 if win


  // seed the random number generation
  srand(time(NULL));

  // game setup function
  setupGame(&numPlayers, &gameDifficulty, &numMin, &numMax);

  // Game Logic
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

    if (*currentPosition >= 1)
    {
      // Displays the scoreboard before every round
      displayTurnSeparator(currentPlayer);
      displayScoreboard(player1Pos,player2Pos,player3Pos,player4Pos,roundNumber, currentPlayer, numPlayers, winningPosition, tilesPerRow);

      playTurn(&gameStatus, currentPlayer, currentPosition, winningPosition, numMin, numMax, &numPlayers, &winningPlayer);

      // gets the modulo of current player then +1. ex. (4%4 = 0) then + 1 (player 1 turn)
      currentPlayer = (currentPlayer % numPlayers) + 1;

    } else if (*currentPosition < 0 && numPlayers > 0) 
    {
     // skips player ? if current position = -1
      currentPlayer = (currentPlayer % numPlayers) + 1;
    }

     // added gameStatus != 1
    if (currentPlayer == 1 && gameStatus != 1) {
      roundNumber++;
      displayRoundSeparator(roundNumber);
    }

  }

  //  Probably just put this in a function.
  // Ending Screen
  displayScoreboard(player1Pos,player2Pos,player3Pos,player4Pos,roundNumber, currentPlayer, numPlayers, winningPosition, tilesPerRow);
  printf("\n");
	printf("=======================================\n");
	printf("\t   Thank you for Playing  \n");
	printf("\t                          \n");
	printf("\tA Walk in The Math Park! \n");
	printf("\t  Winner: Player [%d]    \n", winningPlayer);
	printf("\t  Game Finished in\n");
	printf("\t  Round Number [%d]\n", roundNumber);
	printf("=======================================\n");
  return 0;
}
