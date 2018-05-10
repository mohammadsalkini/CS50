/**************************************************
* water.c
*
* refugees{code} Intake #3
*
* code written by: Mohammad Alsalkini
* graded by: TUTOR INSERTS NAME HERE ONCE GRADED
* pset design by Harvard CS50
*
* Calculates how much bottles of water are used while showering for a given number of minutes.
* Asks for the minutes as input.
***************************************************/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int n;
  do
  {
      printf("Minutes: ");
      n = get_int();
      printf("Bottles: %i \n", n*12);
      return 0;
  }
    while (n>0);
    printf("retry\n");
}