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


void waitForEnter()
{
    char enter;
    do
    {
        scanf("%c", &enter);
    } while(enter != '\n');
}
