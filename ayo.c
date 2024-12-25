#include <stdio.h>
#include <stdlib.h>  // For rand() and srand()
#include <time.h>    // For time()

#ifdef _WIN32
#include <windows.h>  // For Sleep() in Windows
#else
#include <unistd.h>   // For sleep() in Linux/Unix
#endif


void diceDelay(int milliseconds) {
    #ifdef _WIN32
    Sleep(milliseconds);  // Sleep takes milliseconds in Windows
    #else
    usleep(milliseconds * 1000);  // usleep takes microseconds in Linux/Unix
    #endif
}

int simulateDiceRoll(int duration) {
    int finalNumber = 0;
    printf("Rolling the dice: ");
    for (int i = 0; i < duration; i++) {
        int randomNum = (rand() % 6) + 1;  // Generate a random number between 1 and 6
        printf("\rRolling the dice: %d", randomNum);  // Use '\r' to overwrite the line
        fflush(stdout);  // Ensure immediate output
        diceDelay(200);  // 200 ms delay for each iteration
        finalNumber = randomNum;  // Update the final number each iteration
    }
    printf("\n");
    return finalNumber;
}

int main() {
    simulateDiceRoll(20);  // Simulate the dice rolling for 20 iterations (approx. 4 seconds)
    return 0;
}