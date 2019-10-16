#ifndef __ARRAY_H__
#define __ARRAY_H__
#include "Object.h"

void ArrayQuickSort(Object* [], int, int);
int ArrayPartition(Object* [], int low, int high);
void ArrayQuickSortNonRecursive(Object* [], int, int);

#endif