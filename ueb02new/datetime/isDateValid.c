
//
//  datetime.c
//  ueb01X
//
//  Created by Tom Mertens on 20.04.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include <stdio.h>
#include "../datetime/datetime.h"
#include "../tools/tools.h"
#include "../datastructure.h"
#include <stdlib.h>
#include <math.h>


/***************************************************************************
 Funktion:  isDateValid
 Parameter: struct TDate
 Ergebnis:  Wahrheitswert als int
 Beschreib: Angeben ob das uebergebene Datum gueltig ist
 ***************************************************************************/
int isDateValid(TDate *Date)
{
    int YearMax=3000;
    int YearMin=1;

    //Jahr gueltig ?
    if (Date->Year < YearMin || Date->Year > YearMax)
    {
        return 0;
    }

    int DayMax;

    switch (Date->Month){                           //versch. Cases für alle Monate

        case 1: DayMax=31;
            break;
        case 2: if(isLeapYear(Date->Year)){
                    DayMax=29;
                } else
                    DayMax=28;
                break;
        case 3: DayMax=31;
            break;
        case 4: DayMax=30;
            break;
        case 5: DayMax=31;
            break;
        case 6: DayMax=30;
            break;
        case 7: DayMax=31;
            break;
        case 8: DayMax=31;
            break;
        case 9: DayMax=30;
            break;
        case 10: DayMax=31;
            break;
        case 11: DayMax=30;
            break;
        case 12: DayMax=31;
            break;

        default:    return 0;
            break;
    }

    // Tag gueltig ?
    if(Date->Day < 1 || Date->Day > DayMax)
    {
        return 0;
    }

    return 1;
}
