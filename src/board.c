
// J1 = O
// J2 = X
// 0 = _
#include "../includes/board.h"

void displayBoard(int matrix[7][7])
{
    printf("\e[1;1H\e[2J");
    printf("_ _ _ _ _ _ _ _\n");
    for(int i=0; i<7; ++i)
    {
        printf("|");

        for(int j=0; j<7; ++j)
        {
            if(matrix[i][j] != 0)
            {
                if(matrix[i][j] == 1)
                    printf("O");
                else
                    printf("X");
            }
            else
                printf(" ");
            printf("|");
        }
        printf("\n");
    }
    printf("---------------\n");
}

