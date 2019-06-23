//
//  tools.c
//  ueb01X
//
//  Created by Tom Mertens on 20.04.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include <stdio.h>
#include "tools.h"
#include <stdlib.h>

/**********************************************************
 * Funktion: clearBuffer
 * Beschreibung: Leert den Tasturpuffer
 * Parameter: Character
 * Ergebnis:
 **********************************************************/
void clearBuffer()
{  char dummy;
    do
    {  scanf("%c", &dummy);
    }  while (dummy != '\n');
}
