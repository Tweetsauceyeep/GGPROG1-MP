#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int generateHarderMathProblem(int min, int max){
  int num1, num2, num3, ans;
  char operator1, operator2;
  num1 = getRandomNumber(min, max);
  num2 = getRandomNumber(min, max);
  num3 = getRandomNumber(min, max);

  int firstOperatorInt = rand() % 5;
  int secondOperatorInt = rand() % 5;

  
  // Operator Generator
  // randomized number between 1 and 4;
  // TODO: Could probably use case statements.
  if (firstOperatorInt == 0) {
    operator1 = '+';
  } else if (firstOperatorInt == 1) {
    operator1 = '-';
  } else if (firstOperatorInt == 2) {
    operator1 = '*';
  } else if (firstOperatorInt == 3) {
    operator1 = '/';
  } else if (firstOperatorInt == 4) {
    operator1 = '%';
  }

  if (secondOperatorInt == 0) {
    operator2 = '+';
  } else if (secondOperatorInt == 1) {
    operator2 = '-';
  } else if (secondOperatorInt == 2) {
    operator2 = '*';
  } else if (secondOperatorInt == 3) {
    operator1 = '/';
  } else if (secondOperatorInt == 4) {
    operator2 = '%';
  }

  if ((operator1 == '*' || operator1 == '/' || operator1 == '%') ||
        (operator2 == '+' || operator2 == '-')) {
        // First calculate num1 and num2 if operator1 has higher precedence
        int intermediate;
        switch (operator1) {
            case '+': intermediate = num1 + num2; break;
            case '-': intermediate = num1 - num2; break;
            case '*': intermediate = num1 * num2; break;
            case '/': intermediate = num1 / num2; break;
            case '%': intermediate = num1 % num2; break;
        }
        switch (operator2) {
            case '+': ans = intermediate + num3; break;
            case '-': ans = intermediate - num3; break;
            case '*': ans = intermediate * num3; break;
            case '/': ans = intermediate / num3; break;
            case '%': ans = intermediate % num3; break;
        }
    } else {
        // Calculate num2 and num3 first if operator2 has higher precedence
        int intermediate;
        switch (operator2) {
            case '+': intermediate = num2 + num3; break;
            case '-': intermediate = num2 - num3; break;
            case '*': intermediate = num2 * num3; break;
            case '/': intermediate = num2 / num3; break;
            case '%': intermediate = num2 % num3; break;
        }
        switch (operator1) {
            case '+': ans = num1 + intermediate; break;
            case '-': ans = num1 - intermediate; break;
            case '*': ans = num1 * intermediate; break;
            case '/': ans = num1 / intermediate; break;
            case '%': ans = num1 % intermediate; break;
        }
    }

    // Print the problem for the user to solve
    printf("Solve: %d %c %d %c %d = ?\n", num1, operator1, num2, operator2, num3);
    int userAns;
    printf("Your answer: ");
    scanf("%d", &userAns);
    if (userAns == ans) {
        printf("_______________________________\n");
        printf("\nCorrect!, answer = %d\n", ans);
        printf("_______________________________\n\n");
        return 1;
    } else {
        printf("_______________________________\n");
        printf("\nIncorrect. The correct answer is %d.\n", ans);
        printf("_______________________________\n");
        return 0;
    }
}


int main()
{
  srand(time(NULL));
  generateHarderMathProblem(-10,10);
}