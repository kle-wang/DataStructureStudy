#include "cstdio"
#include "cstdlib"

// 使用 顺序表 实现队列

typedef int E;

struct Queue{
    E * array;
    int capacity;
    int rear,front;
};

typedef struct Queue * ArrayQueue;

bool initQueue(ArrayQueue queue){
    queue->array = (E *)malloc(sizeof(struct Queue));
    if(queue->array == NULL) return false;
    queue->capacity = 10;
    queue->rear = queue->front = 0;
    return true;
}

bool offerQueue(ArrayQueue queue,E element){
    if((queue->rear + 1) % queue->capacity == queue->front)
        return false;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
}

bool isEmpty(ArrayQueue queue){
    return queue->rear == queue->front;
}

E pollQueue(ArrayQueue queue){
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

void printQueue(ArrayQueue queue){
    printf("<<< ");
    int i = queue->front;   //遍历队列需要从队首开始
    do {
        i = (i + 1) % queue->capacity;   //先向后循环移动
        printf("%d ", queue->array[i]);  //然后打印当前位置上的元素
    } while (i != queue->rear);   //当到达队尾时，结束
    printf("<<<\n");
}

int main(){
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 5; ++i) {
        offerQueue(&queue, i * 100);
    }
    printQueue(&queue);
    while (!isEmpty(&queue)) {
        printf("%d ", pollQueue(&queue));
    }
}