#include "../includes/game.h"
#include "../includes/board.h"


void finishgame(int playerId)
{
    printf("Bien joué jeun oizal: %d\n", playerId - 200);
}

int determineheight(int matrix[7][7], int choice) 
{

    for(int i=6; i>=0; --i)
    {
        if(matrix[i][choice] == 0)
            return i;
    }
    return EXIT_FAILURE;
}   

int iscolumnfull(int matrix[7][7], int choice)
{
    return matrix[0][choice] != 0;
}

void launchgame()
{
    printf("Bienvenue jeune oizal dans Pouissance4 !\n");
    int matrix[7][7] = {0};
    displayBoard(matrix);

    int currentPlayer = 1;
    int state = 1; //running
    do {
        state = gameround(matrix, &currentPlayer);    
    } while(state != endgame && state != player1won && state != player2won);

    finishgame(state);
}

int isboardfull(int matrix[7][7]) 
{
    for(int i=0; i<7; ++i)
    {
        if(!iscolumnfull(matrix, i))
            return 0;
    }
    return 1;
}

int isplayerwon(int matrix[7][7], int playerId)
{
    for(int i=0; i<7; ++i) 
    {
        for(int j=0; j<7; ++j)
        {
            if(matrix[i][j] == playerId) // on a une piece
            {
                if ((j+3)<7 && matrix[i][j] == matrix[i][j+1] && matrix[i][j] == matrix[i][j+2] && matrix[i][j] == matrix[i][j+3])
                    return 1; 

                if ((i+3)<7 && matrix[i][j] == matrix[i+1][j] && matrix[i][j] == matrix[i+2][j] && matrix[i][j] == matrix[i+3][j]) // colonne
                    return 1;
                
                if ((i+3)<7 && (j+3)<7 && matrix[i][j] == matrix[i+1][j+1] && matrix[i][j] == matrix[i+2][j+2] && matrix[i][j] == matrix[i+3][j+3]) // diagonal
                    return 1;

                if ((i-3)>0 && (j+3)<7 && matrix[i][j] == matrix[i-1][j+1] && matrix[i][j] == matrix[i-2][j+2] && matrix[i][j] == matrix[i-3][j+3]) // diagonal 
                    return 1;
            }
        }
    } 
    return 0;
}


int gameround(int matrix[7][7], int * playerId)
{
    printf("Player %d turn\n", *playerId);
    int choice = -1; 
    while(choice == -1 || ((0 > choice) || (choice > 6)) || iscolumnfull(matrix, choice))
    {
        printf("Jeun oizal 1: O | Jeun oizal 2: X\n");
        printf("Choose a number between 0 and 6: ");
        if(scanf("%d", &choice) != 1)
            choice = -1;
        fflush(stdin);
    }
    fflush(stdin);
    
    int height = determineheight(matrix, choice);

    matrix[height][choice] = (*playerId == 1) ? 1 : 2;
    displayBoard(matrix);

    if (isplayerwon(matrix, *playerId))
        return *playerId + 200;
    
    *playerId = *playerId == 1 ? 2: 1;

    if (isboardfull(matrix))
        return endgame;
    else
        return 1;
}
