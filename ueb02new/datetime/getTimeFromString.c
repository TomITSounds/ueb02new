
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
 Funktion:  getTimeFromString
 Parameter: *char Input, *TTime
 Ergebnis:  Wahrheitswert als int bei erfolgreichem Kopieren
 Beschreib: Liest eine Zeit aus einer Zeichenkette und kopiert die in Struct, ruft IsTimeValid auf
 ***************************************************************************/
int getTimeFromString(char *Input, TTime *Time)
{
    char *pHour = NULL;
    char *pMinute = NULL;
   

    if (!*Input) //Falls String leer
        return 0;
    if(*Input<'0' || *Input >'9') //Falls erste character Keine Zahl
        return 0;

    //Stunden einlesen
    pHour = Input;
    do
        Input++;
    while (*Input != ':');
    Time->Hour = atoi(pHour);
    Input++;

    if(*Input > '9' || *Input < '0') // Falls erste character nach ':' Keine Zahl
        return 0;

    // Minuten einlesen
    pMinute = Input;
    do
        Input++;
    while (*Input != ':' || *Input == '\0');
    Time->Minute = atoi(pMinute);

    // Falls gegeben Sekunden einlesen
    if((*Input) == ':')
        Time->Second = atoi(Input+1);
    else
        Time->Second = 0;
   
    return isTimeValid(Time);
}
