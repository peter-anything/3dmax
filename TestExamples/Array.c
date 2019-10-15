#include "Array.h"

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