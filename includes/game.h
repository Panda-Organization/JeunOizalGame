#ifndef GAME_H
#define GAME_H

#define endgame 200
#define player1won 201
#define player2won 202

int gameround(int matrix[7][7], int * playerId);
int determineheight(int matrix[7][7], int choice);
void finishgame(int playerId);
void launchgame();
int isplayerwon(int matrix[7][7], int playerId);
int isboardfull(int matrix[7][7]);
int iscolumnfull(int matrix[7][7], int choice);

#endif