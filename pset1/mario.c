/**************************************************
* mario.c
*
* refugees{code} Intake #3
*
* code written by: Mohammad Alsalkini
* graded by: Alexander Hartveld
* pset design by Harvard CS50
*
* This program prints a pyramid consisting of hashtags.
* It ask for input for thei height and prints a dynamic output.
***************************************************/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    //the input of the user
    height = get_int("Height: ");
    while (height)
    {
        //checking the number
        if (height >= 0 && height <= 23)
        {
            //print the spaces
            for ( int line = 0; line < height; line++)
            {
                for ( int spaces = 0; spaces < height - line - 1; spaces++)
                {
                    printf(" ");
                }

                //reight side
                for ( int hashes = 0; hashes <= line; hashes++)
                {
                    printf("#");
                }
                printf ("  ");

                //left side
                for ( int hashes2 = 0; hashes2 <= line; hashes2++)
                {
                    printf("#");

                }
                printf ("\n");

            }
            return 0;

        }

        //invalid number
        else
        {
            printf("Height: ");
            height = get_int();

        }

    }

}
