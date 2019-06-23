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
 * Funktion:        printLine
 * Beschreibung:    Druckt eine Zeile eines Zeichens in geg. Breite
 Parameter:         char Zeichen, int Breite
 *Ergebnis:         void
 **********************************************************/
void printLine(char Z, int Breite)
{   for( ; Breite--; )
        printf("%c", Z);
    printf("\n");
}
