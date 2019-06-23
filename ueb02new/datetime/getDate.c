//
//  datetime.c
//  ueb03X
//
//  Created by Justina Kuss on 20.05.19.
//  Copyright © 2019 Justina Kuss. All rights reserved.
//

#include <stdio.h>
#include "../datetime/datetime.h"
#include "../tools/tools.h"
#include "../datastructure.h"
#include <stdlib.h>
#include <math.h>

/***************************************************************************
 Funktion:  getDate
 Parameter:
 Ergebnis:  1 wenn erfolgreiche Eingabe 0 wenn falsche Eingabe
 Beschreib: Fragt nach Date vom Nutzer und speichert im *Date
 ***************************************************************************/

int getDate (char*Prompt, TDate*Date){

    char Input[51];
    printf("%s", Prompt);

    scanf("%50[^\n]", Input);
    clearBuffer();

    int inputCheck = getDateFromString(Input, Date);
    if(inputCheck == 1)
        return 1;
    else{
        printf("\nDatum ungültig\n");
        return 0;
        }
    }
