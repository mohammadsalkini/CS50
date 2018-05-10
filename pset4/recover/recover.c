




//* code written by: Mohammad Alsalkini





#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

typedef uint8_t  BYTE;



int main(int argc, string argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }


    FILE *inptr = fopen(argv[1], "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open .\n");
        return 2;
    }
    char filename [10] ;
    BYTE buffer[512];
    int counter = 0;
    FILE *image;
    bool found = false;
    while (fread(&buffer,sizeof(buffer),1,inptr) == 1 )
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (found == false)
            {
                found = true;
            }
            else
            {
                fclose(image);
            }

            sprintf(filename,"%03i.jpg", counter);
            image = fopen(filename,"w");
            counter ++;

        }
        if (found == true)
        {
          fwrite(&buffer, sizeof(buffer), 1, image);
        }

    }

    fclose(inptr);
}