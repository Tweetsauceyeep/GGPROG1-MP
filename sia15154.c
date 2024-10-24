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
#include <math.h>
#include <time.h>
#include "gameFuncs.c"



/*
<Generates a random number between a specified range (1, 6) then returning that number to be used in main>
Precondition: <No Preconditions/Assumptions.>
@param <name> <purpose>
@return <Randomized Number between 1 and 6>
*/
int diceRoll(){
  int num;
  num = rand() % 6 + 1;
  return num;
}

// TODO: What happens when player rolls a 6
int movePlayerPosition(int initialPlayerPosition, int diceRoll, int winningPosition)
{
  int newPosition;
  
  printf("Dice Roll: %d\n", diceRoll);
  newPosition = initialPlayerPosition + diceRoll;
  
  if (newPosition > winningPosition )
  {
    // if you need 3 to win, and you roll a 5. You move 3 spaces forward, then 2 backwards.
    printf("Roll makes position Larger than %d\n", winningPosition);
    int  overshoot = newPosition - winningPosition;
    newPosition = winningPosition - overshoot;
    return newPosition;
  } else 
  {
    return newPosition;
  }

}

/* Helper Functions for the Equation Generation Function*/
// could probably extract it into one function

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// TODO catch division by 0 
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

void playTurn(int *gameStatus, int currentPlayer, int *playerPosition, int winningPosition, int numMin, int numMax)
{
  printf("Current Player: %d  Initial Player Position: %d \n", currentPlayer, *playerPosition);
  *playerPosition = movePlayerPosition(*playerPosition, diceRoll(), winningPosition);
  printf("New Player Position: %d\n", *playerPosition);

  // Generate Math Problem to Solve
  int questionStatus = generateMathProblem(numMin,numMax);// What the math equation returns: 0 = question correct, 1 question wrong

  // Check if question is Correct, questionStatus of 0 = Correct
  if (questionStatus == 1) {
    printf("***Player (%d) Stays in same Tile: New Position is: (%d)***\n\n", currentPlayer, *playerPosition);
  } else if (questionStatus == 0) // 0 is false 1 is true
  {
    // TODO Functionality to send players back 
    // sends player back a random amount between 1 and 3
    int randNum = rand() % (3 - 1 + 1) + 1;
    *playerPosition = *playerPosition - randNum;
    printf("***Player (%d) sent back %d tile/s: New Position is: (%d)***\n\n", currentPlayer, randNum, *playerPosition);
    if (*playerPosition < 0) {
      *playerPosition = -1;
      printf("Player (%d)is ejected from the Game", currentPlayer);
    }
  }

  // player win checker.
  if (*playerPosition == winningPosition) *gameStatus = 1;

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
  int gameStatus = 0;


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
   if (*currentPosition >= 0)
   {
    playTurn(&gameStatus, currentPlayer, currentPosition, winningPosition, numMin, numMax);
    currentPlayer = (currentPlayer % numPlayers) + 1;
   } else 
   {
    // skips player ? if current position = -1
    currentPlayer = (currentPlayer % numPlayers) + 1;
   }
  }

  // rn it works until player gets a question wrong.
  // Ending Screen
  printf("\n");
	printf("	****************************\n");
	printf("	*   Thank you for Playing  *\n");
	printf("	*                          *\n");
	printf("	* A Walk in The Math Park! *\n");
	printf("	*                          *\n");
	printf("	****************************\n");
  return 0;
}
