
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

TDayOfTheWeek calcWeekDay(TDate *); // verlangt nach Datum und gibt Wochentag zurueck

int getDateFromString(char *Input, TDate *pDate)
    {
        char *pDay = 0;
        char *pMonth = 0;
        char *pYear = 0;

        if (!*Input) //Falls String leer
            return 0;

        pDay = Input;

        while (*Input != '.')           //Zeiger bis Punkt
            Input++;

        Input++;
        pMonth = Input;

        while (*Input != '.')           //Zeiger auf 2. Punkt
        {   Input++;
            pYear =  Input;
        }
        pYear++;

        pDate->Day = atoi(pDay);        //Wert Zuweisungen
        pDate->Month = atoi(pMonth);
        pDate->Year = atoi(pYear);
        pDate->DotW = calcWeekDay(pDate);

        return isDateValid(pDate);
}


