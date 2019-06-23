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
 Funktion:  printTime
 Parameter:
 Ergebnis:  Ausgabe Time
 Beschreib: Gibt Time mit führenden Nullen aus // ohne /n
 ***************************************************************************/

 void printTime(TTime *Time)
 {
   printf("%02d:%02d", Time->Hour, Time->Minute);
 }
