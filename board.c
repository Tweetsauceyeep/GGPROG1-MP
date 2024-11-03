#include <stdio.h>

char getPlayerOnTile(int tile, int player1Pos, int player2Pos, int player3Pos, int player4Pos, int activePlayers) 
{
  int playerCount = 0;
  char playerOnTile = ' ';
  if (activePlayers >= 1 && tile == player1Pos) {playerOnTile = 'A'; playerCount++;}
  if (activePlayers >= 2 && tile == player2Pos) {playerOnTile = 'B'; playerCount++;}
  if (activePlayers >= 3 && tile == player3Pos) {playerOnTile = 'C'; playerCount++;}
  if (activePlayers >= 4 && tile == player4Pos) {playerOnTile = 'D'; playerCount++;}

  if (playerCount > 1) {
    return '*';
  }

  return playerOnTile;
}

void displayGameBoard(int totalTiles, int tilesPerRow, int player1Pos, int player2Pos, int player3Pos, int player4Pos, int numPlayers){
  int rows = totalTiles / tilesPerRow;
  int currentTile;

  printf("\n\tGAMEBOARD\t\n");
  printf("\n---------------------------------------------------\n");
  for (int row = rows - 1; row >=0; row--) {
    int isLeftToRight = (row % 2 == 0);

    if (isLeftToRight) {
      // even row, left to right
      for (int col = 0; col < tilesPerRow; col++) {
        currentTile = row * tilesPerRow + col + 1;
        // extract to func
        printf("|");
        char playerOnTile = getPlayerOnTile(currentTile, player1Pos, player2Pos, player3Pos, player4Pos, numPlayers);
        if (playerOnTile != ' '){
          printf(" (%c)", playerOnTile);
        } else{
          printf("%3d ", currentTile);
        }
      }
      printf("|");
    } else {
      for (int col = tilesPerRow - 1; col >= 0; col--) {
        currentTile = row * tilesPerRow + col + 1;
        // extract to func
        printf("|");
        char playerOnTile = getPlayerOnTile(currentTile, player1Pos, player2Pos, player3Pos, player4Pos, numPlayers);
        if (playerOnTile != ' '){
          printf(" (%c)", playerOnTile);
        } else{
          printf("%3d ", currentTile);
        }
      }
      printf("|");
    } 
    printf("\n---------------------------------------------------\n");
  }
}



//int main()
//{
//  // totalTiles = winningPosition in main file.
//  int totalTiles = 50;
//  int tilesPerRow = 10;
//  int player1Pos = 1, player2Pos = 20, player3Pos = 20, player4Pos = 40;
//
//  displayGameBoard(totalTiles, tilesPerRow, player1Pos, player2Pos, player3Pos, player4Pos);
//}
