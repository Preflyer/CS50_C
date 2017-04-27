#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DIM_MIN 3
#define DIM_MAX 9

int main(void)
{
    /* local variable definition */
    printf("Provide d: ");
    int d = get_int();
    int board[DIM_MAX][DIM_MAX];
    // eprintf("d: %i\n", d);
    int total = (d * d - 1);
    // eprintf("total = %i\n", total);
    
    switch(d)
    {
        case 3:
        case 5:
        case 7:
        case 9:
            for (int i = 0; i < d; i++)
            {
                for (int j = 0; j < d; j++)
                {
                    board[i][j] = total;
                    printf("board[%i][%i]: %i\n", i, j, board[i][j]);
                    total -= 1;
                }
            }
            printf("odd");
            break;
        case 4:
        case 6:
        case 8:
            for (int i = 0; i < d; i++)
            {
                for (int j = 0; j < d; j++)
                {
                    board[i][j] = total;
                    total -= 1;
                }
            }
            board[(d-1)][(d-2)] = 2;
            board[(d-1)][(d-3)] = 1;
            for (int i = 0; i < d; i++)
            {
                for (int j = 0; j < d; j++)
                {
                    printf("board[%i][%i]: %i\n", i, j, board[i][j]);
                }
            }
            break;
        default:
            printf("error\n");
        
    }
}
