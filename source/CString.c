//
// Created by peter on 2019/10/16.
//
#include "Object.h"
#include "CString.h"

int CStringViolentMatch(char* source, char* dest) {
    int index = 0;
    if (IsCStringEmpty(source) || IsCStringEmpty(dest))
    {
        return -1;
    }

    char *p = source;
    char *q = dest;

    int destLen = CStringLength(dest);
    int destSearchLength = 0;

    while (*p != '\0') {
        if (*p == *q) {
            q ++;
            destSearchLength ++;
        } else {
            if (destSearchLength > 0)
            {
                q = dest;
                p = p - destSearchLength + 1;
            }

        }
        p ++;
        index ++;
        if (*q == '\0')
        {
            return (index - destLen);
        }
    }
    return -1;
}

bool IsCStringEmpty(char *p)
{
    return *p == '\0';
}

int CStringLength(char * p)
{
    int len = 0;
    while(*p != '\0')
    {
        p ++;
        len ++;
    }
    return len;
}

int CStringKMPMatch(char* source, char* dest)
{

}