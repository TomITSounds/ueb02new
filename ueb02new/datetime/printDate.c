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
 Funktion:  printDate
 Parameter:
 Ergebnis: Ausgabe Date
 Beschreib: Gibt Date mit führenden Nullen aus // ohne /n
 ***************************************************************************/

void printDate(TDate *Date)
{
  switch(Date->DotW) // 
  {
    case 1: printf("Mo, ");
            break;
    case 2: printf("Di, ");
            break;
    case 3: printf("Mi, ");
            break;
    case 4: printf("Do, ");
            break;
    case 5: printf("Fr, ");
            break;
    case 6: printf("Sa, ");
            break;
    case 7: printf("So, ");
            break;
    
    default: printf("    ");
  }
  printf("%02d.%02d.%04d", Date->Day, Date->Month, Date->Year);
}
