#include "List.h"
#include <malloc.h>

List* ListCreate()
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

bool ListIsEmpty(List* list)
{
    return list->len == 0;
}

void ListAdd(List* list, void* data)
{
    ListNode* newData = (ListNode*)malloc(sizeof(ListNode));
    if (newData == NULL)
    {
        return;
    }
    newData->value = data;
    newData->next = NULL;
    newData->prev = NULL;
    newData->testValue = (*(int*)data);
    if (list->head == NULL)
    {
        list->head = newData;
        newData->prev = newData;
        newData->next = newData;
        list->head->prev = newData;
    }
    else
    {
        ListNode* cur = list->head->prev;
        cur->next = newData;
        newData->prev = cur;
        newData->next = list->head;
        list->head->prev = newData;
    }

    list->tail = newData;
    list->len++;
}

ListNode* ListFirst(List* list)
{
    return list->head;
}

ListNode* ListLast(List* list)
{
    return list->tail;
}

ListNode* ListLastDelete(List* list)
{
    if (list->len == 0)
    {
        return NULL;
    }
    else if (list->len == 1)
    {
        ListNode* p = list->head;
        list->head = NULL;
        list->len--;
        return p;
    }
    ListNode* last = ListLast(list);
    list->tail = last->prev;
    list->tail->next = list->head;
    list->head->next = list->tail;
    last->next = NULL;
    last->prev = NULL;
    list->len--;
    return last;
}

ListNode* ListGetPop(List* list)
{
    return list->tail;
}

ListIter* ListIterator(List* list)
{
    ListIter* listIter = (ListIter*)malloc(sizeof(ListIter));
    if (listIter == NULL)
    {
        return NULL;
    }

    listIter->next = list->head;
    listIter->len = list->len;

    return listIter;
}

ListNode* ListNext(ListIter* listIter)
{
    ListNode* cur = listIter->next;
    if (listIter->len != 0)
    {
        listIter->next = cur->next;
        listIter->len--;
    }

    return cur;
}

bool ListIterHasNext(ListIter* listIter) {
    return listIter->len != 0;
}

void ListClear(List* list)
{
    while (list->head != list->head->next)
    {
        ListNode* last = list->tail;
        list->tail = last->prev;
        list->tail->next = list->head;
        list->head->prev = list->tail;
        last->prev = NULL;
        last->next = NULL;
        free(last);
    }

    free(list->head);
    list->head = list->tail = NULL;
}

void ListDestroy(List* list)
{
    ListClear(list);
    free(list);
    list = NULL;
}

ListNode* ListFirstDelete(List* list)
{
    if (list->len == 0)
    {
        return NULL;
    }
    else if (list->len == 1)
    {
        ListNode* p = list->head;
        list->head = list->tail = NULL;
        list->len--;
        p->prev = p->next = NULL;
        return p;
    }
    ListNode* first = ListFirst(list);
    list->head = first->next;
    list->tail->next = list->head;
    list->head->prev = list->tail;
    first->next = NULL;
    first->prev = NULL;
    list->len--;
    return first;
}