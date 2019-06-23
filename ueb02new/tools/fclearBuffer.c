//
//  fclearBuffer.c
//  ueb02new
//
//  Created by Tom Mertens on 20.06.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include <stdio.h>
void fclearBuffer(FILE *file){
    char dummy;
    do{
        dummy = fgetc(file);
    } while (dummy != '\n');
        
}
