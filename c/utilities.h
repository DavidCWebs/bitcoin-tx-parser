#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void setInput(char **s);
int hexDigitToInt(char digit);
int hexstringToBytes(const char *hexstring, unsigned char **result);

#endif
