#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "analisys.h"

Analysis initAnalysis()
{
    Analysis a;
    a.val = 0;
    return a;
}

void printAnalysis(const int file, Analysis a)
{




    //write(file, a.val, sizeof(int));
}

Analysis readAnalysis(const int file)
{




    
    // Analysis a;
    // read(file, a.val, sizeof(int));
    // return a;
}

void intToStr(ulong value, char str[ULONG_MAXLEN])
{
    int i;
    for(i = 0; i < ULONG_MAXLEN; i++)
    {
        str[i] = '0';
    }

    int index = ULONG_MAXLEN - 1;
    while(value > 0)
    {
        str[index--] = '0' + (value % 10);
        value /= 10;
    }
}

void strToInt(char str[ULONG_MAXLEN], ulong *value)
{
    ulong ul = 0;
    int index = 0;
    char c[1];

    while(index < ULONG_MAXLEN)
    {
        c[0] = str[index++];
        ul = (ul * 10) + atoi(c);
    }

    *value = ul;
}


bool isText(char c)         { return c >= ' ' && c <= '~'; }
bool isUppLetter(char c)    { return c >= 'A' && c <= 'Z'; }
bool isLowLetter(char c)    { return c >= 'a' && c <= 'z'; }
bool isNumber(char c)       { return c >= '0' && c <= '9'; }
bool isMathSymbol(char c)   { return strstr("=<>+-*/", c) != NULL; }
bool isPunctuation(char c)  { return strstr(".,:;'!?`\"", c) != NULL; }
bool isBracket(char c)      { return strstr("()[]{}", c) != NULL; }
bool isSpace(char c)        { return c == ' '; }