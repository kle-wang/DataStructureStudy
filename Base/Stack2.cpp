#include "cstdio"
#include "cstdlib"

// 栈 链表实现

typedef int E;

struct Stack{
    E element;
    struct Stack * next;
};

typedef struct Stack * StackNode;

void initStack(StackNode head){
    head->next = NULL;
}

bool pushStack(StackNode head,E element){
    StackNode node = (Stack *)malloc(sizeof(struct Stack));
    if(node == NULL) return false;
    node->next = head->next;
    node->element = element;
    head->next = node;
    return true;
}

E popStack(StackNode head){
    StackNode tmp = head->next;
    head->next = head->next->next;
    E e = tmp->element;
    free(tmp);
    return e;
}

bool isEmpty(StackNode head){
    return head->next == NULL;
}

void printStack(StackNode head){
    printf("| ");
    head = head->next;
    while (head){
        printf("%d ", head->element);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Stack head;
    initStack(&head);
    for (int i = 0; i < 3; ++i) {
        pushStack(&head, i*100);
    }
    printStack(&head);
    while (!isEmpty(&head)) {
        printf("%d ", popStack(&head));   //将栈中所有元素依次出栈
    }
}