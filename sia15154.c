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

// Function Declarations
int rollDice();
int movePlayerPosition(int initialPlayerPosition, int rollDice);

int main()
{
  int start;
  int gameDifficulty, playerPosition ;

  playerPosition = 1;


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
	printf("	*                          *\n");

  // dice rolling works
  
  printf("Initial Player Position: %d", playerPosition);
  playerPosition = movePlayerPosition(playerPosition, rollDice());
  printf("New Player Position: %d", playerPosition);

  
}

/*
<Description of the Function>
Precondition: <precondition / assumption>
@param <name> <purpose>
@return <Randomized Number between 1 and 6, to simulate the rolling of a dice>
*/

int rollDice(){
  int num;
  srand(time(NULL));
  // sets num to a number randomly between 1 and 6.
  num = rand() % (6 + 1 - 1) + 1;
  return num;
}

int movePlayerPosition(int initialPlayerPosition, int rollDice)
{
  int newPosition;
  newPosition = initialPlayerPosition + rollDice;
  return newPosition;
}

