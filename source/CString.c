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
            q++;
            destSearchLength++;
        } else {
            if (destSearchLength > 0)
            {
                q = dest;
                p = p - destSearchLength + 1;
                index = index - destSearchLength + 1;
                destSearchLength = 0;
            }

        }
        p++;
        index++;
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
        p++;
        len++;
    }
    return len;
}

int CStringKMPMatch(char* source, char* dest) {
    // hello
    int len = CStringLength(dest);
    if (len < 3) {
        return CStringViolentMatch(source, dest);
    }
    int next[len];
    next[0] = 0;

    for (int i = 1; i < len; i++) {
        int j = next[i - 1];
        while (j > 0 && dest[i] != dest[j]) {
            j = next[j - 1];
        }

        if (dest[i] == dest[j]) {
            j++;
        }
        next[i] = j;
    }
    int index = 0;
    char *p = source;
    char *q = dest;
    int destSearchLength = 0;
    while (*p != '\0') {
        if (*p == *q || destSearchLength == 0) {
            q++;
            p++;
            destSearchLength++;
            index++;
        } else {
            q = dest + next[destSearchLength];
            destSearchLength = next[destSearchLength];
        }

        if (*q == '\0')
        {
            return (index - len);
        }
    }

    return -1;
}