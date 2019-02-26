/***
*Tag des Jahres
*
*Niklas Pröhl
*15.01.2018
*
***/
#include <stdio.h>
#include <stdlib.h>

// Februar mit 28 Tagen definieren
#define Februar 28

/* is_leapyear
überprüft ob das eingegebene Jahr ein Schaltjahr ist
return 0 = kein Schaltjahr
return 1 = Schaltjahr
return -1 = falsches Jahr eingegeben*/

int is_leapyear(int year)
{
    if(year >= 1582)
    {
        if ( year %4 != 0)
        {
            //printf("Dieses Jahr ist kein Schaltjahr");
            return 0;
        }

        else if( year %4 == 0)
        {
            if ( year %100 != 0 )
            {
                //printf("Diese Jahr ist ein Schaltjahr");
                return 1;
            }

            else if (year %100 == 0 && year %400 == 0)
            {
                //printf("Dieses Jahr ist ein Schaltjahr");
                return 1;
            }

            else
            {
                //printf("Dieses Jahr ist kein Schaltjahr");
                return 0;
            }

        }

        else
        {
            //printf("Bitte geben Sie eine richtige Jahreszahl ein!");
            return -1;
        }

    }
    return -1;
}

/* input_date
ließt einen Tag, einen Monat und ein Jahr ein
*/

int input_date(int *day, int *month, int *year)
{
    printf("Tag des Jahres\n");
    printf("---------------\n");
    printf("Bitte geben Sie einen Tag ein: ");
    scanf("%i",day);
    printf("Bitte geben Sie einen Monat ein: ");
    scanf("%i",month);
    printf("Bitte geben Sie ein Jahr ein: ");
    scanf("%i",year);

    return 0;
}


/*get_days_for_month
berechnet wie viele Tage ein Monat hat
return 31 = Monat hat 31 Tage
return 30 = Monat hat 30 Tage
days = Tage im Februar
*/

int get_days_for_month(int month, int year)
{

    int days = 0;
    if(month == 2)
    {
        int leapyear_check = is_leapyear(year);
        if (is_leapyear == 1)
        {
            days = Februar + 1 ;
            return days;
        }
        else
        {
            return Februar;
        }

    }
    if((month <= 7 && month % 2 != 0) || (month >= 8 && month % 2 == 0))
    {
        return 31;
    }
    else
    {
        return 30;
    }
}

/*exists_date
überprüft ob das eingegebene Datum gültig ist
return 1 = Datum ist korrekt
return 0 = Datum ist falsch
*/

int exists_date(int day, int month, int year)
{


    if(year >= 1582 && year <= 2400)
    {
        if(month >= 1 && month <= 12)
        {

            if (day <= get_days_for_month(month, year) && day >= 1)
            {

                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

/*day_of_the_year
berechnet den Tag
return Zaehler = Anzahl der Tage bis zum Datum
return -1 = Fehler
*/

int day_of_the_year(int day, int month, int year)
{

    int Zaehler = day;

    if (exists_date(day, month, year) == 1 )
    {
        for(int i = 1; i <= (month - 1); i++)
        {
            int j = get_days_for_month(i, year);
            Zaehler += j;
        }
        return Zaehler;
    }
    else
    {
        return -1;
    }
}
