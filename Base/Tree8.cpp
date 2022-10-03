#include <cstring>
#include "cstdio"
#include "cstdlib"

//哈夫曼树
typedef char E;
typedef struct ListTree{
    E element;
    struct ListTree * left;
    struct ListTree * right;
    int value;
} * Node;


typedef Node T;
//队列
typedef struct ListNode{
    T element;
    struct ListNode * next;
} * LNode;

struct Queue{
    LNode front,rear;
};

typedef Queue * ListQueue;

bool initQueue(ListQueue queue){
    LNode node = (ListNode *) malloc(sizeof(struct ListNode));
    if(node == NULL) return false;
    queue->front = queue->rear = node;
    node->next = NULL;
    return true;
}

bool offerQueue(ListQueue queue,T element){
    LNode node = (ListNode *) malloc(sizeof(struct ListNode));
    if(node == NULL) return false;
    node->element = element;
    node->next = NULL;
    LNode pre = queue->front;
    while(pre->next && pre->next->element->value <= element->value)
        pre = pre->next;
    if(pre == queue->rear){
        queue->rear->next = node;
        queue->rear = node;
    }else{
        node->next = pre->next;
        pre->next = node;
    }
    return true;
}

T pollQueue(ListQueue queue){
    T e = queue->front->next->element;
    LNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(queue->front == node) queue->rear = queue->front;
    free(node);
    return e;


}

void printQueue(ListQueue queue){
    printf("<<< " );
    LNode node = queue->front->next;
    while(node){
        printf("%c ",node->element->element);
        node = node->next;
    }
}

Node createNode(E element,int value){
    Node node = (ListTree *) malloc(sizeof(ListTree));
    node->left = node->right = NULL;
    node->element = element;
    node->value = value;
    return node;

}

char * encode(Node root, E e){
    if(root == NULL) return NULL;   //为NULL肯定就是没找到
    if(root->element == e) return "";   //如果找到了就返回一个空串
    char * str = encode(root->left, e);  //先去左边找
    char * s = (char *)malloc(sizeof(char) * 10);
    if(str != NULL) {
        s[0] = '0';
        str = strcat(s, str);   //如果左边找到了，那么就把左边的已经拼好的字符串拼接到当前的后面
    } else {    //左边不行那再看看右边
        str = encode(root->right, e);
        if(str != NULL) {
            s[0] = '1';
            str = strcat(s, str);   //如果右边找到了，那么就把右边的已经拼好的字符串拼接到当前的后面
        }
    }
    return str;   //最后返回操作好的字符串给上一级
}

void printEncode(Node root, E e){
    printf("%c 的编码为：%s", e, encode(root, e));   //编码的结果就是了
    putchar('\n');
}


int main(){
    struct Queue queue;
    initQueue(&queue);
    offerQueue(&queue, createNode('A',5));
    offerQueue(&queue, createNode('B',16));
    offerQueue(&queue, createNode('C',8));
    offerQueue(&queue, createNode('D',13));
    while (queue.front->next != queue.rear) {   //如果front的下一个就是rear那么说明队列中只有一个元素了
        Node left = pollQueue(&queue);
        Node right = pollQueue(&queue);
        Node node = createNode(' ', left->value + right->value);   //创建新的根结点
        node->left = left;
        node->right = right;
        offerQueue(&queue, node);   //最后将构建好的这棵树入队
    }

    Node root = pollQueue(&queue);   //最后出来的就是哈夫曼树的根结点了

    printEncode(root, 'A');
    printEncode(root, 'B');
    printEncode(root, 'C');
    printEncode(root, 'D');



}