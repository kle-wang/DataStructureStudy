#include "cstdio"
#include "cstdlib"

//栈 先进后出 顺序表实现

typedef int E;

struct Stack{
    E * array;
    int capacity;
    int top;
};

typedef struct Stack * ArrayStack;

bool initStack(ArrayStack stack){ //初始化栈
    stack->array = (E *)malloc(sizeof(struct Stack));
    if(stack->array == NULL) return false;
    stack->capacity = 10;
    stack->top = -1;
    return true;
}

//开始插入数据 入栈
bool pushStack(ArrayStack stack,E element){
    if(stack->top + 1 == stack->capacity){
        int newCapacity = stack->capacity * 2;
        E * newArray = (E *)realloc(stack->array, sizeof(E) *newCapacity);
        if(newArray  == NULL) return false;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[stack->top + 1] = element;
    stack->top++;
    return true;
}

//出栈

E popStack(ArrayStack stack){
    return stack->array[stack->top--];
}

//是否为空

bool isEmpty(ArrayStack stack){
    return stack->top == -1;
}


void printStack(ArrayStack stack){
    printf("| ");
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d, ", stack->array[i]);
    }
    printf("\n");
}



int main(){
    struct Stack stack;
    initStack(&stack);
    for (int i = 0; i < 3; ++i) {
        pushStack(&stack, i*100); //入栈
    }
    printStack(&stack);

    while (!isEmpty(&stack)) {
        printf("%d,", popStack(&stack));   //将栈中所有元素依次出栈
    }
}
