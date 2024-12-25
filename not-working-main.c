// THE INITIAL ONE I THINK ================================================


//
//      if (*currentPosition >= 0)
//      {
//
//        // TODO: so messy, 
//        displayTurnSeparator(currentPlayer);
//        displayScoreboard(
//          player0Pos,
//          player1Pos,
//          player2Pos,
//          player3Pos,
//          roundNumber,
//          currentPlayer,
//          numPlayers,
//          winningPosition,
//          tilesPerRow,
//          gameStatus
//          );
//        playTurn(
//          &gameStatus,
//          currentPlayer,
//          currentPosition,
//          winningPosition,
//          numMin, 
//          numMax, 
//          &numPlayers, 
//          &winningPlayer, 
//          winningPosition,
//          tilesPerRow,
//          &player0Pos,
//          &player1Pos,
//          &player2Pos,
//          &player3Pos
//          );
//
//        // gets the modulo of current player then +0. ex. (4%4 = 0) then + 1 (player 1 turn)
//      currentPlayer = (currentPlayer % numPlayers) + 0;
//
//      } else if (*currentPosition < -1 && numPlayers > 0) 
//      {
//       // skips player ? if current position = -2
//        currentPlayer = (currentPlayer % numPlayers) + 0;
//      }
//
//       // added gameStatus != 0
//      if (currentPlayer == 0 && gameStatus != 1) {
//        roundNumber++;
//        displayRoundSeparator(roundNumber);
//      }
//    }


// THE CODE THAT WASNT WORKING WHEN A PLAYER GETS EJECTED. JUST 1 PLAYER.
  while (gameStatus != 1)
  {
    if (numPlayers == 0) {
      printf("All players have been ejected. Ending the game.\n");
      gameStatus = 1; // End the game naturally
    } else {
      int *currentPosition;
      switch (currentPlayer)
      {
        case 1: currentPosition = &player1Pos; break;
        case 2: currentPosition = &player2Pos; break;
        case 3: currentPosition = &player3Pos; break;
        case 4: currentPosition = &player4Pos; break;
        default: currentPosition = &player1Pos;
      } 

// Skip ejected players
    if (*currentPosition < 0) {
      currentPlayer = (currentPlayer % numPlayers) + 1;
      //continue;
    }


    displayTurnSeparator(currentPlayer);
    displayScoreboard(
      player1Pos,
      player2Pos,
      player3Pos,
      player4Pos,
      roundNumber,
      currentPlayer,
      numPlayers,
      winningPosition,
      tilesPerRow,
      gameStatus
    );

    playTurn(
      &gameStatus,
      currentPlayer,
      currentPosition,
      winningPosition,
      numMin, 
      numMax, 
      &numPlayers, 
      &winningPlayer, 
      winningPosition,
      tilesPerRow,
      &player1Pos,
      &player2Pos,
      &player3Pos,
      &player4Pos
    );

    // Only update current player and round if game isn't over
    }

  }


// ANOTHER ONE - THE LATEST ONE JUST NOW 12 PM
  while (gameStatus != 1 && numPlayers > 0)
{
    int *currentPosition;

    // Determine current player's position pointer
    switch (currentPlayer)
    {
        case 1: currentPosition = &player1Pos; break;
        case 2: currentPosition = &player2Pos; break;
        case 3: currentPosition = &player3Pos; break;
        case 4: currentPosition = &player4Pos; break;
        default: currentPosition = &player1Pos;
    }

    // Check if the current player is still active
    if (*currentPosition >= 1)
    {
        displayTurnSeparator(currentPlayer);
        displayScoreboard(player1Pos, player2Pos, player3Pos, player4Pos, roundNumber, currentPlayer, numPlayers, winningPosition, tilesPerRow, gameStatus);
        playTurn(&gameStatus, currentPlayer, currentPosition, winningPosition, numMin, numMax, &numPlayers, &winningPlayer, winningPosition, tilesPerRow, &player1Pos, &player2Pos, &player3Pos, &player4Pos);

        // Update the current player
        currentPlayer = (currentPlayer % numPlayers) + 1;

    } 
    else if (*currentPosition < 0)
    {
        // Skip ejected players
        currentPlayer = (currentPlayer % numPlayers) + 1;
    }

    // Increment the round when all players have had their turn
    if (currentPlayer == 1 && gameStatus != 1 && numPlayers > 0)
    {
        roundNumber++;
        displayRoundSeparator(roundNumber);
    } else continue;
}

// Handle end-of-game messages
if (numPlayers == 0)
{
    printf("All players have been ejected. Ending the game.\n");
    gameStatus = 1;
}



// NIG
  while (gameStatus != 1 && numPlayers > 0)
  {
  if (numPlayers == 0 && gameStatus != 1) {
      gameStatus = 1; // End the game naturally
      printf("All players have been ejected. Ending the game.\n");
    } else {

      int *currentPosition;
      switch (currentPlayer)
      {
        case 1: currentPosition = &player1Pos; break;
        case 2: currentPosition = &player2Pos; break;
        case 3: currentPosition = &player3Pos; break;
        case 4: currentPosition = &player4Pos; break;
        default: currentPosition = &player1Pos;
      } 

      if (*currentPosition >= 1)
      {

        // TODO: so messy, 
        displayTurnSeparator(currentPlayer);
        displayScoreboard(player1Pos,player2Pos,player3Pos,player4Pos,roundNumber, currentPlayer, numPlayers, winningPosition, tilesPerRow, gameStatus);
        playTurn(&gameStatus, currentPlayer, currentPosition, winningPosition, numMin, numMax, &numPlayers, &winningPlayer, winningPosition, tilesPerRow, &player1Pos, &player2Pos, &player3Pos, &player4Pos);
        //printf("\nPlayer (%d) Press Enter to Move to Next Turn...", currentPlayer);
        //while (getchar() != '\n');
        //getchar();

        // gets the modulo of current player then +1. ex. (4%4 = 0) then + 1 (player 1 turn)
        currentPlayer = (currentPlayer % numPlayers) + 1;



      } 
      else if (*currentPosition < 0 && numPlayers > 0) 
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

  