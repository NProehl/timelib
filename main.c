/***
*Tag des Jahres
*
*Niklas Pröhl
*15.01.2018
*
***/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day, month, year;
    int check = 0;
    int test = 0;

    input_date(&day, &month, &year);
    system("cls");

    check = exists_date(day,month,year);

    if (check == 1)
    {
        printf("Tag:%i\nMonat:%i\nJahr:%i ", day, month, year);
        printf("\n\nDatum erfolgreich eingegeben");
    }

    else
    {
        printf("Bitte geben Sie ein gueltiges Datum ein!!!");

    }

    test = day_of_the_year(day, month, year);
    if(test != -1)
    {
        printf("\nDer eingegebene Tag ist: %i", test);
    }
    else
    {
        printf("\nFalsches Datum");
    }



}

