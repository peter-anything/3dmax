#ifndef __LIST_H__
#define __LIST_H__
#endif

typedef struct ListNode {
    struct ListNode* next;
    void* value;
} ListNode;

typedef struct List {
    ListNode* head;
    ListNode* tail;
    unsigned long len;
} List;

typedef struct ListIter {
    ListNode* next;
} ListIter;

List* ListCreate(void);
bool IsEmptyList(List* list);
void ListAdd(List* list, void* data);
ListIter* ListIterator(List* list);
ListNode* ListNext(ListIter* listIter);
ListNode* ListFirst(List* list);
ListNode* ListLast(List* list);
ListNode* Pop(List* list);
bool ListIterHasNext(ListIter* listIter);