/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];
int won_board[DIM_MAX][DIM_MAX];



// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();
    

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(200000);
        }

        // sleep thread for animation's sake
        usleep(200000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(200000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int total = (d * d - 1);
    
    // initializes odd board 
    if (d % 2 != 0)
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                board[i][j] = total;
                // printf("board[%i][%i]: %i\n", i, j, board[i][j]);
                total -= 1;
            }
        }
    }    
    
    // initializes even starting board with reversed 1/2 starting positions
    if (d % 2 == 0)
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                board[i][j] = total;
                // printf("board[%i][%i]: %i\n", i, j, board[i][j]);
                total -= 1;
            }
        }
        board[(d-1)][(d-2)] = 2;
        board[(d-1)][(d-3)] = 1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf("  _");
            }
            else
            {
                printf(" %2i", board[i][j]);
            }
        }
    printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // if chosen tile is valid
    if (tile <= (d*d-1) && tile >= 1)
    {
        // find zerotile location
        int tile0i;
        int tile0j;
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (board[i][j] == 0)
                {
                    //printf("i: %i\n j: %i\n", i, j);
                    tile0i = i;
                    tile0j = j;
                    //usleep(2000000);
                    break;
                }
            }
        }
        
        // find tile location
        int tilei;
        int tilej;
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (board[i][j] == tile)
                {
                    //printf("i: %i\n j: %i\n", i, j);
                    tilei = i;
                    tilej = j;
                    //usleep(2000000);
                    break;
                }
            }
        }
        // printf(" i:  %i     j: %i\n", tilei, tilej);
        // printf("i0: %i     j0: %i\n", tile0i, tile0j);
        // usleep(2000000);
        
        // reign in aberrant beharvior

        
        // move tile if in valid location
        if (((tilei-tile0i)*(tilei - tile0i) + ((tilej - tile0j)*(tilej - tile0j))) != 1)
        {
            return false;
        }
        else if (board[tilei-1][tilej] == board[tile0i][tile0j])
        {
            board[tilei][tilej] = 0;
            board[tile0i][tile0j] = tile;
            return true;
        }
        // if zerotile is below tile
        else if (board[tilei+1][tilej] == board[tile0i][tile0j])
        {
            board[tilei][tilej] = 0;
            board[tile0i][tile0j] = tile;
            return true;
        }
        // if zerotile is left of tile
        else if (board[tilei][tilej-1] == board[tile0i][tile0j])
        {
            board[tilei][tilej] = 0;
            board[tile0i][tile0j] = tile;
            return true;
        }       
        // if zerotile is right of tile
        else if (board[tilei][tilej+1] == board[tile0i][tile0j])
        {
            board[tilei][tilej] = 0;
            board[tile0i][tile0j] = tile;
            return true;
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{   
    // init winning board 1 => 15 in order
    int flag = 1;
    int counter = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            won_board[i][j] = counter;
            counter += 1;
        }
    }
    won_board[d-1][d-1] = 0;
    // test to see if current board == winning board
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] != won_board[i][j])
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1)
    {
        return true;
    }
    else
    {
        return false;
    }

}
