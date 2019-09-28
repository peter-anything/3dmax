#include "List.h"
#include <malloc.h>

List* ListCreate(void)
{
    List* list = (List*)malloc(sizeof(List));
    
    if (list == NULL)
    {
        return NULL;
    }

    list->head = NULL;
    list->len = 0;

    return list;
}

bool IsEmptyList(List* list)
{
    return list->len == 0;
}

void ListAdd(List* list, void* data)
{
    ListNode* newData = (ListNode*)malloc(sizeof(ListNode));
    newData->value = data;
    newData->next = NULL;
    if (list->head == NULL)
    {
        list->head = newData;
    }
    else
    {
        ListNode* cur = list->head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = newData;
    }

    list->tail = newData;
    list->len++;
}

ListNode* ListFirst(List* list)
{
    return list->head->next;
}

ListNode* ListLast(List* list)
{
    return list->tail->next;
}

ListNode* ListPop(List* list)
{
    ListNode* first = First(list);
    list->head = first->next;
    return first;
}

ListIter* ListIterator(List* list)
{
    ListIter* listIter = (ListIter*)malloc(sizeof(ListIter));
    if (listIter == NULL)
    {
        return NULL;
    }

    listIter->next = list->head;

    return listIter;
}

ListNode* ListNext(ListIter* listIter)
{
    ListNode* cur = listIter->next;
    if (cur != NULL)
    {
        listIter->next = cur->next;
    }

    return cur;
}

bool ListIterHasNext(ListIter* listIter) {
    return listIter->next != NULL;
}