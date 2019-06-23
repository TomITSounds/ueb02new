//
//  getText.c
//  ueb02
//
//  Created by Tom Mertens on 24.05.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include <string.h>

int getText(char *Prompt, int MaxLen, char **Pointer, int AllowEmpty)
{
    char Format[15];        //Formatierung fuer scanf
    int ScanErg;
    int Len;
    
    if(MaxLen <= 0)             //Sicherheitsabfragen
        return 0;
    if(Pointer == NULL)
        return 0;
    *Pointer = NULL;            //oder doch Pointer?
    
    char *Input = calloc(MaxLen+1, sizeof(char));
    
    if (Input)
    {   sprintf(Format, "%%%i[^\n]", MaxLen);   //print in String
        
        do
        {   printf("%s", Prompt);
            ScanErg = scanf(Format, Input);
            clearBuffer();
            Len = strlen(Input);
            if (Len>0)
            {    *Pointer = malloc(Len+1);       //reserviern des Speichers fuer eigentlichen Text
                if (*Pointer)
                    strcpy(*Pointer, Input);
                else
                {   //free(Input);
                    return 0;
                }
            }                       //len >0
            else                    //Abfrage ob Nuterze nur Enter eingegeben hat
            {   if(AllowEmpty){
                    ScanErg = 1;
                }
                else
                    ScanErg = 0;
            }
        } while(ScanErg == 0);        //Wiederhole SOLANGE Erg ==0
        free(Input);
        return 1;
    } // Input
    else
        return 0;
    
}
