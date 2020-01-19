#include <iostream>
#include <thread>
#include <stack>

using namespace std;

class StackSorter
{
private:
    stack<int>& mystack;
public:
    StackSorter(stack<int>& stack) : mystack(stack) {}
    void sort() {
        if (mystack.empty())
        {
            return;
        }
        else
        {
            int v = mystack.top();
            mystack.pop();
            sort();
            insert(v);
        }
    }

    void insert(int val)
    {
        if (mystack.empty() || val <= mystack.top())
        {
            mystack.push(val);

            return;
        }
        int v = mystack.top();
        mystack.pop();
        insert(val);
        mystack.push(v);
        return;
    }
};

int test() {
    stack<int> stack({ 3, 2, 5, 6, 1, 4 });
    StackSorter stack_sorter(stack);
    stack_sorter.sort();
    while (!stack.empty())
    {
        int v = stack.top();
        stack.pop();
        std::cout << v << endl;
    }
    std::move(stack);
}
