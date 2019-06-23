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
 * Funktion: askAgain
 * Beschreibung: Fragt den Benutzer ob er dass Programm nochmal ausfuehren moecht
 Parameter: Zeile und Spalte der Frage
 *Ergebnis: Wahrheitswert
 **********************************************************/
int askYesOrNo(char *Prompt)
 {   char ans;
 int ask;
 do
 {   printf("\n");
 printf("%s",Prompt);
 printf("\n");
 scanf("%c", &ans);
 if (ans != '\n')
 clearBuffer();
 switch (ans)
 {   case 'j':
     case 'J':   ask = 1; break;
     case 'n':
     case 'N':   ask = 0; break;
     default:    printf("Ungueltige Eingabe.\n"
                        "Wollen sie nochmal? j/n\n");
 }
 }  while ( (ans != 'j') && (ans != 'J') && (ans != 'N') && (ans !='n') );
 return ask;
 }
