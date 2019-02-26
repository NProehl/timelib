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
    // Variablen deklarieren
    int day, month, year;
    int check = 0;
    int test = 0;

    input_date(&day, &month, &year);
    system("cls");

    check = exists_date(day,month,year);

    // Überprüfen ob ein korrektes Datum eingegeben wurde

    if (check == 1)
    {
        printf("Tag:%i\nMonat:%i\nJahr:%i ", day, month, year);
        printf("\n\nDatum erfolgreich eingegeben\n");
    }

    else
    {
        printf("Bitte geben Sie ein gueltiges Datum ein!!!");

    }

    // Ausgabe des Tages

    day = day_of_the_year(day, month, year);

    if(test != -1)
    {
        printf("\nDer eingegebene Tag ist der: %i Tag im Jahr", day);
    }
    else
    {
        printf("\nFalsches Datum");
    }






}

