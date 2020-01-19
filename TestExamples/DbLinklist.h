#ifndef DBNODE_H
#define DBNODE_H

template<class T>
class DbList
{
public:
    struct Node
    {
        Node* prev;
        Node* next;
        T data;
    };

public:
    DbList() {
        head = new Node;
        head->prev = head->next = nullptr;
    }

    bool Empty()
    {
        return head->next == nullptr;
    }

    void Clear()
    {
        if (Empty())
        {
            return;
        }
        Node* p = head->next;
        Node* q = p;
        if (p != nullptr)
        {
            q = p->next;
            free(p);
            p->next = nullptr;
            p = q;
        }
        head->next = nullptr;
    }

    void AppendNode(T& data)
    {
        Node* new_data = new Node;
        new_data->prev = nullptr;
        new_data->next = nullptr;
        new_data->data = data;

        Node* p = head;

        if (p->next == nullptr)
        {
            first = new_data;
        }

        while (p != nullptr && p->next != nullptr)
        {
            p = p->next;
        }

        p->next = new_data;
        new_data->prev = p;
        last = new_data;
    }

private:
    Node* head = nullptr;
public:
    Node* first = nullptr;
    Node* last = nullptr;
};
#endif // !DBNODE_H