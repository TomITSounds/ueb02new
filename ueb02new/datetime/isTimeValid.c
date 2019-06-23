
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
 Funktion:  isTimeValid
 Parameter: struct TTime
 Ergebnis:  Wahrheitswert als int
 Beschreib: Angeben ob die uebergebene Uhrzeit gueltig ist
 ***************************************************************************/
int isTimeValid(TTime *Time)
{   // Stunden gueltig ?
    if(Time->Hour < 0 || Time->Hour > 23)
        return 0;
    
    // Minuten gueltig ?
    if(Time->Minute < 0 || Time->Minute > 59)
        return 0;
    
    // Sekunden gueltig ?
    if(Time->Second < 0 || Time->Second > 59)
        return 0;
    
    // Wenn alles gueltig
    return 1;
}
