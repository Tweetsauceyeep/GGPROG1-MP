#include <stdio.h>

// Function to check if a player is on the current tile
char getPlayerOnTile(int tile, int player1Pos, int player2Pos, int player3Pos, int player4Pos) {
    if (tile == player1Pos) return 'A'; // Player 1
    if (tile == player2Pos) return 'B'; // Player 2
    if (tile == player3Pos) return 'C'; // Player 3
    if (tile == player4Pos) return 'D'; // Player 4
    return ' '; // No player on this tile
}

// Function to display the board
void displayBoard(int player1Pos, int player2Pos, int player3Pos, int player4Pos) {
    int totalTiles = 50; // Total number of tiles
    int tilesPerRow = 10; // Tiles per row
    int currentTile = totalTiles; // Start at the last tile

    for (int row = 0; row < totalTiles / tilesPerRow; row++) {
        // Determine direction: left-to-right or right-to-left
        int isLeftToRight = (row % 2 == 0);

        if (isLeftToRight) {
            // Print from left to right
            for (int col = currentTile - tilesPerRow + 1; col <= currentTile; col++) {
                printf("|");
                char playerOnTile = getPlayerOnTile(col, player1Pos, player2Pos, player3Pos, player4Pos);
                if (playerOnTile != ' ') {
                    printf(" %c  ", playerOnTile); // Display player token
                } else {
                    printf(" %2d ", col); // Display tile number
                }
            }
        } else {
            // Print from right to left
            for (int col = currentTile; col > currentTile - tilesPerRow; col--) {
                printf("|");
                char playerOnTile = getPlayerOnTile(col, player1Pos, player2Pos, player3Pos, player4Pos);
                if (playerOnTile != ' ') {
                    printf(" %c  ", playerOnTile); // Display player token
                } else {
                    printf(" %2d ", col); // Display tile number
                }
            }
        }
        currentTile -= tilesPerRow; // Move to the next row up
        printf("|\n"); // End the row

        // Print a separator line for the row
        for (int i = 0; i < tilesPerRow; i++) {
            printf("+----");
        }
        printf("+\n");
    }
}

int main() {
    // Example positions for players
    int player1Pos = 1;
    int player2Pos = 10;
    int player3Pos = 25;
    int player4Pos = 50;

    displayBoard(player1Pos, player2Pos, player3Pos, player4Pos); // Display the board
    return 0;
}
