




//* code written by: Mohammad Alsalkini





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
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
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
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // geting the higher number
    int number =d*d;
    //distributing the numbers inside the board
    for (int row = 0; row < d; row++)
    {
        for (int column = 0; column < d; column++)
        {
            number--;
            board[row][column] = number;
        }

    }
    board[d - 1][d - 1] = 95;
    //swapping the last 2 numbers
    if (d % 2 == 0)
    {
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 3] = 1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    //printing out the numbers
     for (int row = 0; row < d; row++)
     {
         for (int column = 0; column < d; column++)
         {
             if(board[row][column] == 95)
             {
                 printf("%2c", (char)board[row][column]);

             }
             else
             {
                 printf("%2i", board[row][column]);

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
    int row_tile;
    int column_tile;
    int temp;
    //checking out of the input
    if (tile > d*d-1 || tile < 1)
    {
        return false;

    }
    //Finding the row and column of tile
    for (int row = 0; row < d; row++)
     {
         for (int column = 0; column < d; column++)
         {
             if(board[row][column] == tile)
             {
                 row_tile = row;
                 column_tile = column;
             }

         }

     }

    if ( board[row_tile - 1][column_tile] == 95)
    {
        temp = board[row_tile][column_tile];
        board[row_tile][column_tile] = 95;
        board[row_tile - 1][column_tile] = temp;
        return true;
    }
    if ( board[row_tile + 1][column_tile] == 95)
    {
        temp = board[row_tile][column_tile];
        board[row_tile][column_tile] = 95;
        board[row_tile + 1][column_tile] = temp;
        return true;
    }
    if ( board[row_tile][column_tile - 1] == 95)
    {
        temp = board[row_tile][column_tile];
        board[row_tile][column_tile] = 95;
        board[row_tile][column_tile - 1] = temp;
        return true;
    }
    if ( board[row_tile][column_tile + 1] == 95)
    {
        temp = board[row_tile][column_tile];
        board[row_tile][column_tile] = 95;
        board[row_tile][column_tile + 1] = temp;
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int number = 1;
    for (int row = 0; row < d; row++)
    {
        for (int column = 0; column < d; column++)
        {
            if(board[row][column] == number)
             {
                 number ++;
             }
        }

    }
    if (number == (d * d ) && board[d - 1][d - 1] == 95)
    {
        return true;
    }
    else
    {
        return false;
    }
}