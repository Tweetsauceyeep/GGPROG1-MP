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


/*
<Generates a random number between a specified range (1, 6) then returning that number to be used in main>
Precondition: <No Preconditions/Assumptions.>
@param <name> <purpose>
@return <Randomized Number between 1 and 6>
*/
int rollDice(){
  int num;
  
  num = rand() % (6 + 1 - 1) + 1;
  return num;
}

int movePlayerPosition(int initialPlayerPosition, int rollDice)
{
  int newPosition;
  // TODO Move printing outside the function.
  printf("Rolled Dice... \n");
  printf("Outcome: %d\n", rollDice);
  newPosition = initialPlayerPosition + rollDice;
  return newPosition;
}

/* Helper Functions for the Equation Generation Function*/
// could probably extract it into one function

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int generateMathProblem(int min, int max){
  int num1, num2, ans;
  char operator;
  num1 = getRandomNumber(min, max);
  num2 = getRandomNumber(min, max);
  
  
  int randInt = rand() % 4;
  if (randInt == 0) {
    operator = '+';
    ans = num1 + num2;
  } else if (randInt == 1) {
    operator = '-';
    ans = num1 - num2;
  } else if (randInt == 2) {
    operator = '*';
    ans = num1 * num2;
  } else if (randInt == 3) {
    operator = '/';
    ans = num1 / num2;
  } else {
    operator = '%';
    ans = num1 % num2;
  }

    printf("Solve: %d %c %d = ?\n", num1, operator, num2);

    int userAns;
    printf("Your answer: ");
    scanf("%d", &userAns);

    if (userAns == ans) {
        printf("Correct!\n");
        return 0;
    } else {
        printf("Incorrect. The correct answer is %d.\n", ans);
        return 1;
    }
  
}

int main()
{
  int start;
  int gameDifficulty, playerPosition;
  int questionStatus;

  playerPosition = 1;
  // seed the random number generation
  srand(time(NULL));

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
  printf("There are 3 Difficulties to Choose from, (1) Easy (2) Normal (3) Hard\n");
  printf("________________________________________________________________________________________\n\n");
  
  // Difficulty Selection:
  printf("Choose Your Difficulty [(1) (2) (3)]: ");
  scanf("%d", &gameDifficulty);

  while(gameDifficulty != 1 || gameDifficulty != 2 || gameDifficulty != 3)
  {
    if (gameDifficulty == 1 || gameDifficulty == 2 || gameDifficulty == 3)
    {
        printf("Game Difficulty (%d) Selected\n", gameDifficulty);
        // can we even use break?
        break;
    }
    else
    {
        printf("Pick one of the Available Choices, Try Again.\n");
        printf("Choose Your Difficulty [(1) (2) (3)]: ");
        scanf("%d", &gameDifficulty);
    }
  } 

  /*START THE GAME*/
	printf("\n");

	printf("	*     Are you ready to     *\n");
	printf("	*           start          *\n");
	printf("	* A Walk in The Math Park? *\n");
	printf("	*                          *\n");
	printf("	*  Difficulty: (%i)         *\n", gameDifficulty);
	printf("	*                          *\n");
	printf("	*  (type 'start' to begin) *\n");
	printf("	*                          *\n\n\n");

  

  /*This is the actual Game Flow part, utilizes if the question was right or wrong, and its return statuses.*/
  // TODO 10, 10 -> min and max set by difficulty of the game. Implement that system before this.  
  while (playerPosition != 20)
  {
    // player positioning Test
    printf("Initial Player Position: %d\n", playerPosition);
    playerPosition = movePlayerPosition(playerPosition, rollDice());
    printf("New Player Position: %d\n", playerPosition);
    questionStatus = generateMathProblem(-10,10);
    if (questionStatus == 0) {
      printf("Player Stays in same Tile\n");
      printf("Player position is: %d \n", playerPosition);
    } else if (questionStatus == 1)
    {
      // Functionality to send players back TODO
      // sends player back a random amount between 1 and 3
      int randNum = rand() % (3 - 1 + 1) + 1;
      playerPosition = playerPosition - randNum;
      printf("Player sent back %d tile/s\n", randNum);
      printf("New Player position is: %d \n", playerPosition);
    }
  }
  printf("game Over fr position: %d\n", playerPosition);
  

  
}

