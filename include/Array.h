#ifndef __ARRAY_H__
#define __ARRAY_H__
#include "Object.h"

/***************************************************************
 * 宏定义函数
 * function     : parent(int i) 找出父节点下标
 * function     : left(int i) 找出左子节点下标
 * function     : right(int i) 找出右子节点下标
 **************************************************************/
#define PARENT(i) ((i)/2)
#define LEFT(i) ((i)*2+1)
#define RIGHT(i) ((i)*2+2)


void ArrayQuickSort(Object* [], int, int);
void ArrayInsertSort(Object* [], int);
void HeapSort(int [], int);
void ArraySelectSort(Object* [], int);
int ArrayPartition(Object* [], int low, int high);
void ArrayQuickSortNonRecursive(Object* [], int, int);

#endif