#include "cstdio"
#include "cstdlib"

// 二叉树 层序遍历 使用队列实现

typedef char E;

//二叉树部分构建
struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int flag;
};

typedef TreeNode * Node;

// 队列部分

typedef Node T;

struct QueueNode{
    T element;
    struct QueueNode * next;
};

typedef QueueNode * QNode;

struct Queue{
    QNode front,rear;
};

typedef Queue * ListQueue;

bool initQueue(ListQueue queue){
    QNode node =(QueueNode *)malloc(sizeof(QueueNode));
    if(node == NULL) return false;
    queue->front = queue->rear = node;
    return true;
}

bool offerQueue(ListQueue queue,T element){
    QNode node =(QueueNode *)malloc(sizeof(QueueNode));
    if(node == NULL) return false;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return true;
}

bool isEmpty(ListQueue queue){
    return queue->rear == queue->front;
}

T pollQueue(ListQueue queue){
    QNode tmp = queue->front->next;
    T e = queue->front->next->element;
    queue->front->next = queue->front->next->next;
    if(queue->rear == tmp) queue->rear = queue->front;
    free(tmp);
    return e;
}
//队列部分结束

void levelOrder(Node root){
    struct Queue queue;   //先搞一个队列
    initQueue(&queue);
    offerQueue(&queue, root);  //先把根节点入队
    while (!isEmpty(&queue)) {   //不断重复，直到队列空为止
        Node node = pollQueue(&queue);   //出队一个元素，打印值
        printf("%c", node->element);
        if(node->left)    //如果存在左右孩子的话
            offerQueue(&queue, node->left);  //记得将左右孩子入队，注意顺序，先左后右
        if(node->right)
            offerQueue(&queue, node->right);
    }
}

int main(){
    Node a = (Node)malloc(sizeof (struct TreeNode));
    Node b = (Node)malloc(sizeof (struct TreeNode));
    Node c = (Node)malloc(sizeof (struct TreeNode));
    Node d = (Node)malloc(sizeof (struct TreeNode));
    Node e = (Node)malloc(sizeof (struct TreeNode));
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;

    c->left = c->right = NULL;
    d->left = d->right = NULL;
    e->left = e->right = NULL;

    levelOrder(a);
}