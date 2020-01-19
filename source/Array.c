#include "Array.h"
#include "Stack.h"
#include "Tool.h"
#include "Printf.h"

void ArrayQuickSort(Object* arr[], int low, int high)
{
    int i = low;
    int j = high;
    if (i < j)
    {
        int pivotPos = ArrayPartition(arr, low, high);
        if (pivotPos - 1 > low)
        {
            ArrayQuickSort(arr, low, pivotPos - 1);
        }

        if (pivotPos + 1 < high)
        {
            ArrayQuickSort(arr, pivotPos + 1, high);
        }
    }
}

void ArrayInsertSort(Object* arr[], int len)
{
    // 10	30	50	70	90	100	110	91	92
    for (int i = 1; i < len; i++) {
        int j = i - 1;
        Object* curObj = arr[i];
        while (ObjectIntValue(arr[j]) > ObjectIntValue(curObj) && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[++j] = curObj;
    }
}

void ArraySelectSort(Object* arr[], int len)
{
    // 10	30	50	70	90	100	110	91	92
    for (int i = 0; i < len; i++) {
        Object* minObj = arr[i];
        int minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (ObjectIntValue(arr[j]) < ObjectIntValue(minObj))
            {
                minObj = arr[j];
                minIndex = j;
            }
        }
        Object* tmp = arr[i];
        arr[i] = minObj;
        arr[minIndex] = tmp;
    }
}

void ArrayQuickSortNonRecursive(Object* arr[], int low, int high)
{
    Stack* stack = StackCreate();

    int pivotPos = ArrayPartition(arr, low, high);
    if (pivotPos - 1 > low)
    {
        int high = pivotPos - 1;
        PushStack(stack, ConvertObjectFromInt(&low));
        PushStack(stack, ConvertObjectFromInt(&high));
    }

    if (pivotPos + 1 < high)
    {
        int low = pivotPos + 1;
        PushStack(stack, ConvertObjectFromInt(&low));
        PushStack(stack, ConvertObjectFromInt(&high));
    }

    while (!IsEmptyStack(stack))
    {
        Object highObj;
        Object lowObj;
        PopStack(stack, &highObj);
        PopStack(stack, &lowObj);
        int low = ObjectIntValue(&lowObj);
        int high = ObjectIntValue(&highObj);

        int pivotPos = ArrayPartition(arr, low, high);
        if (pivotPos - 1 > low)
        {
            int high = pivotPos - 1;
            PushStack(stack, ConvertObjectFromInt(&low));
            PushStack(stack, ConvertObjectFromInt(&high));
        }

        if (pivotPos + 1 < high)
        {
            int low = pivotPos + 1;
            PushStack(stack, ConvertObjectFromInt(&low));
            PushStack(stack, ConvertObjectFromInt(&high));
        }
    }
}

int ArrayPartition(Object* arr[], int low, int high)
{
    int i = low;
    int j = high;

    Object* pivotObj = arr[low];
    int pivot = ObjectIntValue(pivotObj);
    while (i < j)
    {
        while (i < j && ObjectIntValue(arr[j]) >= pivot)
        {
            j--;
        }

        if (i < j)
        {
            arr[i++] = arr[j];
        }

        while (i < j && ObjectIntValue(arr[i]) <= pivot)
        {
            i++;
        }

        if (i < j)
        {
            arr[j--] = arr[i];
        }
    }
    arr[i] = pivotObj;
    return i;
}

void MaxHeapify(int arr[], int i, int heapSize)
{
    int left = LEFT(i);
    int right = RIGHT(i);
    int largest = i;
    if (left < heapSize && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < heapSize && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        Swap(arr, i, largest);
    }
}

void BuildMaxHeap(int arr[], int heapSize)
{
    for (int i = heapSize / 2 - 1; i >= 0; i--)
    {
        MaxHeapify(arr, i, heapSize);
    }
}

void HeapSort(int arr[], int len)
{
    BuildMaxHeap(arr, len);

    int heapSize = len;

    for (int i = len - 1; i > 0; i--)
    {
        Swap(arr, i, 0);
        heapSize -= 1;
        BuildMaxHeap(arr, heapSize);
    }
}

