//
//  tools.h
//  ueb01X
//
//  Created by Tom Mertens on 20.04.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef TOOLS_H
#define TOOLS_H TOOLS_H


void clearBuffer(void);

int askYesOrNo(char *Prompt);

void waitForEnter(void);

void clearScreen(void);

void printLine(char Z, int Breite);

int getText(char *Prompt, int MaxLen, char **Pointer, int AllowEmpty);

void fclearBuffer(FILE *file);

#endif /* tools_h */
