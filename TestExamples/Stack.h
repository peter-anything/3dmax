typedef int StackElementType;
#define STACK_MAX_SIZE 20

typedef struct Stack {
    StackElementType* base;
    int top;
    int bottom;
    int maxSize;
    int size;
} Stack;

Stack* CreateStack();

void PushStack(Stack* stack, const StackElementType data);

bool IsEmptyStack(Stack* stack);

StackElementType GetTopStack(Stack* stack);

void PopStack(Stack* stack, StackElementType *data);
