//
//  calendar.c
//  ueb02X
//
//  Created by Tom Mertens on 01.05.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include "calendar.h"
#include <stdio.h>
#include "../datetime/datetime.h"
#include "../tools/tools.h"
#include "../datastructure.h"
#include <stdlib.h>
#include <string.h>

/***************************************************************************
 Funktion: getMenu
 Parameter: char *Menu[8] - ein Array von Zeigern(Strings) für die einzelnen
            Menupunkte
 Ergebnis:  -
 Beschreib: Gibt zeilenweise die uebergebenen Strings aus und nummeriert die
            7 Menupunkte automatischen
 ***************************************************************************/

void getMenu(char **Menu)
{
    int i=0;
    printf("%s",*Menu);
    i ++;
    printLine('=', strlen(*(Menu+i)));
    for ( ; i<8; i++)
        printf("%i. %s", i, *(Menu+i));
    printf("\n");
}
