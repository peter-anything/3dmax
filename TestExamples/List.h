#ifndef __LIST_H__
#define __LIST_H__

typedef struct ListNode {
    struct ListNode* prev;
    struct ListNode* next;
    void* value;
    int testValue;
} ListNode1;

typedef struct List {
    ListNode* head;
    ListNode* tail;
    unsigned long len;
} List;

typedef struct ListIter {
    ListNode* next;
} ListIter;

bool ListIsEmpty(List* list);
void ListAdd(List* list, void* data);
ListIter* ListIterator(List* list);
ListNode* ListNext(ListIter* listIter);
ListNode* ListFirst(List* list);
ListNode* ListFirstDelete(List* list);
ListNode* ListLast(List* list);
ListNode* ListLastDelete(List* list);
ListNode* ListGetPop(List* list);
void ListClear(List* list);
void ListDestroy(List* list);
bool ListIterHasNext(ListIter* listIter);
List* ListCreate();
#endif