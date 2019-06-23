
#include<stdio.h>
#include<stdlib.h>
#include"datetime.h"
#include"../datastructure.h"

/**********************************************************************************************************************************************
Die Funktion calcWeekDay gibt den passenden Wochentag auf das eingegebene Datum zurueck.
Folgt folgender Formel von Wikipedia:
if (m < 3) y = y - 1;
w = ((d + floor (2.6 * ((m + 9) % 12 + 1) - 0.2) + y % 100 + floor (y % 100 / 4) + floor (y / 400) - 2 * floor (y / 100) - 1) % 7 + 7) % 7 + 1;
***********************************************************************************************************************************************/

TDayOfTheWeek calcWeekDay(TDate *pDate)
{
    int Tag = pDate->Day;
    int Monat = pDate->Month;
    int Jahr = pDate->Year;

    TDayOfTheWeek weekDay;
    int w; // Wochentags Ergebnis
    int zErg1, zErg2, zErg3, zErg4; // Zwischenergebnisse fuer die Berechnung
    if(Monat < 3) // Wenn Jan oder Feb wird die Jahreszahl fuer die Berechnung um eins veringert
        Jahr --;

    zErg1 = 2.6 * ((Monat + 9) % 12 + 1) - 0.2;
    zErg2 = Jahr % 100 / 4;
    zErg3 = Jahr / 400;
    zErg4 = Jahr / 100;

    w = ((Tag + zErg1 + (Jahr % 100) + zErg2 +zErg3 - 2*zErg4 - 1) % 7 + 7) % 7 + 1;

    switch(w)
    {
        case 1: weekDay = Mo;
                break;
        case 2: weekDay = Tu;
                break;
        case 3: weekDay = We;
                break;
        case 4: weekDay = Th;
                break;
        case 5: weekDay = Fr;
                break;
        case 6: weekDay = Sa;
                break;
        case 7: weekDay = Su;
                break;
        default: return 0;
    }
    return weekDay;
}

