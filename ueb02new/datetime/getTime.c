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
 Funktion:  getTime
 Parameter:
 Ergebnis:  1 wenn erfolgreiche Eingabe 0 wenn falsche Eingabe
 Beschreib: Fragt nach Time vom Nutzer und speichert im *Time
 ***************************************************************************/

 int getTime (char*Prompt, TTime *Time){
     char Input[51];
     Input[0] = '\0';
     
     printf("%s", Prompt);
     
     scanf("%50[^\n]", Input);
     clearBuffer();
    
     if(!Input[0])
        return 0;
     int inputCheck = getTimeFromString(Input, Time);
       if(inputCheck == 1)
           return 1;
       else{
           printf("Zeit ungültig\n");
           return 0;
       }
   }
