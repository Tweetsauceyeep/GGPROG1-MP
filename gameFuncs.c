#include <stdio.h>

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
  printf("There are 2 Difficulties to Choose from, (1) Easy (2) Normal (3) Hard\n");
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