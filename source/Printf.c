//
// Created by peter on 2019/10/17.
//

#include "Printf.h"
#include <stdio.h>
#include <stdarg.h>

void Printf(__const char *__restrict __format, ...)
{
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
}

void PrintfLine(__const char *__restrict __format, ...)
{
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
    printf("\n");
}

void PrintArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}

void PrintInt(int t)
{
    printf("%d\n", t);
}