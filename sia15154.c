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

// TODO: What happens when player rolls a 6
int movePlayerPosition(int initialPlayerPosition, int rollDice)
{
  int newPosition;
  
  printf("Outcome: %d\n\n", rollDice);
  newPosition = initialPlayerPosition + rollDice;
  
  if (newPosition > 20 )
  {
    // if you need 3 to win, and you roll a 5. You move 3 spaces forward, then 2 backwards.
    printf("Roll makes position Larger than 20\n");
    int greaterPos = newPosition - 20;
    newPosition = 20 - greaterPos;
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
  
  
  // Operator Generator
  // randomized number between 1 and 4;
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
        printf("-------------------------------\n");
        printf("Correct!\n");
        printf("-------------------------------\n\n");
        return 0;
    } else {
        printf("-------------------------------\n");
        printf("Incorrect. The correct answer is %d.\n", ans);
        printf("-------------------------------\n");
        return 1;
    }
  
}

int main()
{
  int gameDifficulty;
  int questionStatus; // What the math equation returns: 0 = question correct, 1 question wrong
  int numMin, numMax; // range numbers can go from for math questions
  int roundNumber = 1; // shows round number.
  int playerPosition = 1; // set initial player position
  int numPlayers; 
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
  printf("This Game can have up to 4 Players. Choose the number of players: (1) (2) (3) (4) \n");
  printf("________________________________________________________________________________________\n\n");

  // TODO Ask for number of Players - Implement Functionality Later.
  printf("Choose Number of Players [(1) (2) (3) (4)]: ");
  scanf("%d", &numPlayers);
  while(numPlayers != 1 || numPlayers != 2 || numPlayers != 3 || numPlayers != 4)
  {
    if (numPlayers == 1 || numPlayers == 2 ||  numPlayers == 3 || numPlayers == 4)
    {
        printf("Number of Players: (%d) Selected\n", numPlayers);
        // TODO can we even use break?
        break;
    }
    else
    {
        printf("Pick one of the Available Choices, Try Again.\n");
        printf("Choose Number of Players [(1) (2) (3) (4)]: ");
        scanf("%d", &numPlayers);
    }
  } 

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
        // TODO can we even use break?
        break;
    }
    else
    {
        printf("Pick one of the Available Choices, Try Again.\n");
        printf("Choose Your Difficulty [(1) (2) (3)]: ");
        scanf("%d", &gameDifficulty);
    }
  } 

// Sets the Game Difficulty, by setting minimum and max values for the math problems.
  if (gameDifficulty == 1){
    numMin = -10;
    numMax = 10;
  } else if (gameDifficulty == 2)
  {
    numMin = -100;
    numMax = 100;
  } else if (gameDifficulty == 3)
  {
    numMin = -1000;
    numMax = 1000;
  }

  /*START THE GAME*/
	printf("\n");

	printf("	*     Are you ready to     *\n");
	printf("	*           start          *\n");
	printf("	* A Walk in The Math Park? *\n");
	printf("	*                          *\n");
	printf("	*  Difficulty: (%i)         *\n", gameDifficulty);
	printf("	*                          *\n");
	printf("	*                          *\n\n\n");

  /*This is the actual Game Flow part, utilizes if the question was right or wrong, and its return statuses.*/
  // TODO: IMPLEMENT A CHECKER THAT IMPLEMENTS THIS RULE: If the die roll is too large, the token goes off the finalsquare and back again. 
  //(For example, if a player requiring a 4 to win rolls a 5, the token moves forward three spaces, then back two spaces.)
  while (playerPosition < 20)
  {

    // Round Number Display: Aesthetic Purpose only
    printf("-----------------\n");
    printf("Round Number: %d \nScore: \nPlayer turn: \n", roundNumber);
    printf("-----------------\n\n");
    // player positioning Test
    printf("Initial Player Position: %d\n", playerPosition);
    // Rolls the Dice, and calculates player Position from it.
    // sets the value to movePlayerPosition which returns a number, rather than the function setting it itself.
    playerPosition = movePlayerPosition(playerPosition, rollDice());
    printf("New Player Position: %d\n", playerPosition);

    // Generate Math Problem to Solve
    questionStatus = generateMathProblem(numMin,numMax);

    // Check if question is Correct, questionStatus of 0 = Correct
    if (questionStatus == 0) {
      printf("***Player Stays in same Tile***\n");
      printf("Player position is: %d \n\n", playerPosition);
    } else if (questionStatus == 1)
    {
      // TODO Functionality to send players back 
      // sends player back a random amount between 1 and 3
      int randNum = rand() % (3 - 1 + 1) + 1;
      playerPosition = playerPosition - randNum;
      printf("***Player sent back %d tile/s***\n", randNum);
      printf("New Player position is: %d \n\n", playerPosition);
    }

    roundNumber++;
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
}
