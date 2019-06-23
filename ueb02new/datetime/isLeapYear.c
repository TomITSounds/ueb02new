
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
 Funktion:  isLeapYear
 Parameter: Jahreszahl als int
 Ergebnis:  Wahrheitswert
 Beschreib: Wahr = Jahr ist ein Schaltjahr
 ***************************************************************************/
int isLeapYear(int year)
{   int leapYear = 0;
    if ((year % 4) == 0)
        if ((year % 100) == 0)
            if ((year % 400) == 0)
                leapYear = 1;
            else
                leapYear = 0;
        else
            leapYear = 1;

    return leapYear;
}
