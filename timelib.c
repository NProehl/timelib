#include <stdio.h>
#include <stdlib.h>

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


int get_days_for_month(int month, int year)
{
#define Februar 28

    int days = 0;
    if(month == 2)
    {
        int leapyear_check = is_leapyear(year);
        days = Februar + leapyear_check ;
        return days;
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


int exists_date(int day, int month, int year)
{
    int test_days = 0;
#define Februar
    if(year >= 1582 && year <= 2400)
    {
        if(month >= 1 && month <= 12)
        {
            test_days = get_days_for_month(month, year);

            if (test_days <= get_days_for_month(month, year) && test_days >= 1)
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
