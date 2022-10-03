#include "cstdio"
#include "cstdlib"

// 使用 链表 实现队列

typedef int E;


struct LNode{
    E element;
    struct LNode * next;
};

typedef LNode * Node;

struct Queue{
    Node front,rear;
};

typedef struct Queue * ListQueue;

bool initQueue(ListQueue queue){
    Node node = (LNode *) malloc(sizeof(struct LNode));
    if(node == NULL) return false;
    queue->front = queue->rear = node;
    return true;
}

bool offerQueue(ListQueue queue,E element){
    Node node = (LNode *) malloc(sizeof(struct LNode));
    if(node == NULL) return false;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return true;
}

E pollQueue(ListQueue queue){
    E e = queue->front->next->element;
    Node node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(queue->front == node) queue->rear = queue->front;
    free(node);
    return e;
}


void printQueue(ListQueue queue){
    printf("<<< ");
    Node node = queue->front->next;
    while (node) {
        printf("%d ", node->element);  //链表就简单多了，直接挨个遍历就完事
        node = node->next;
    }
    printf("<<<\n");
}

int main(){
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 5; ++i) {
        offerQueue(&queue, i*100);
    }
    printQueue(&queue);

    for (int i = 0; i < 5; ++i) {
        printf("%d ",pollQueue(&queue));
    }
}