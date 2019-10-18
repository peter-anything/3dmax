//
// Created by peter on 2019/10/16.
//

#ifndef __CSTRING_H__
#define __CSTRING_H__

#include <stdbool.h>

int CStringViolentMatch(char*, char*);
int CStringKMPMatch(char*, char*);
bool IsCStringEmpty(char *);
int CStringLength(char *);

#endif
