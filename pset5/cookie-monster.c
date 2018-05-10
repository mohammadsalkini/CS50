#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define COOKIE "cookie"
#define COOKIE_LENGTH 6
#define BUFFER_SIZE 256

void cookie_monster_search(FILE * input_file, FILE * output_file,int *Counter_oF_Cookie_Letter_Position,int *Number_Of_Cookies);
bool read(char * line, FILE * in);
void process(char * letter,int *Counter_oF_Cookie_Letter_Position,int *Number_Of_Cookies);
void write(string input, FILE* output_file);
bool is_In_Word_Cookie(char letter);
bool is_The_Next_Letter_In_Cookie(char letter,int *Counter_oF_Cookie_Letter_Position);
bool we_Found_A_Cookie(int *Counter_oF_Cookie_Letter_Position);

int main(int argc, string argv[])
{
    int  Number_Of_Cookies = 0 ;
    int  Counter_oF_Cookie_Letter_Position= 0;


    if(argc != 3)
    {
        printf("Usage: ./cookie-monster input-file-name output-file-name\n");
        return 1;
    }

    string input_file_name = argv[1];
    string output_file_name = argv[2];

    FILE* input_file = fopen(input_file_name, "r");
    if(input_file == NULL)
    {
        printf("Input file '%s' not found.\n", input_file_name);
        return 1;
    }

    FILE* output_file = fopen(output_file_name, "w");

    cookie_monster_search(input_file, output_file, &Counter_oF_Cookie_Letter_Position, &Number_Of_Cookies);
    printf("Number of cookies found: %i\n", Number_Of_Cookies);

    fclose(input_file);
    fclose(output_file);
}

void cookie_monster_search(FILE * input_file, FILE * output_file,int *Counter_oF_Cookie_Letter_Position,int *Number_Of_Cookies)
{
    char line[BUFFER_SIZE];

    while(read(line, input_file))
    {
        process(line,Counter_oF_Cookie_Letter_Position,Number_Of_Cookies);
        write(line, output_file);
    }
}

bool read(char * line, FILE * reader)
{
    return fgets(line, BUFFER_SIZE, reader) != NULL;
}

// here I add two new parameters Counter_oF_Cookie_Letter_Position, Number_Of_Cookies
void process(char * letter,int *Counter_oF_Cookie_Letter_Position,int *Number_Of_Cookies)
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if (is_In_Word_Cookie(letter[i]))
        {
            letter[i] = toupper(letter[i]);
            if (is_The_Next_Letter_In_Cookie(letter[i],Counter_oF_Cookie_Letter_Position))
            {
                * Counter_oF_Cookie_Letter_Position+=1;
            }
        }
        else
        {
            letter[i] = tolower(letter[i]);
        }
        if (we_Found_A_Cookie(Counter_oF_Cookie_Letter_Position))
        {
            *Number_Of_Cookies +=1;
        }
    }
}

// Write the string_output to the output_file
void write(string string_output, FILE* output_file)
{
    fprintf(output_file, "%s", string_output);
}

bool is_In_Word_Cookie(char letter)
{
    for (int i = 0; i < COOKIE_LENGTH; i++)
    {
        if (tolower(letter) == COOKIE [i])
        {
            return true;
        }
    }
    return false;
}

bool is_The_Next_Letter_In_Cookie(char letter,int *Counter_oF_Cookie_Letter_Position)
{
    return COOKIE[*Counter_oF_Cookie_Letter_Position] == tolower(letter);
}

bool we_Found_A_Cookie(int *Counter_oF_Cookie_Letter_Position)
{
    if (*Counter_oF_Cookie_Letter_Position == COOKIE_LENGTH)
    {
        *Counter_oF_Cookie_Letter_Position = 0;
        return true;
    }
    return false;
}