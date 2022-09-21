#include "stdio.h"
#include "stdlib.h"

typedef int E;

//构建二叉树
struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int leftTag,rightTag;
};

typedef struct TreeNode * Node;

Node createNode(E element){
    Node node = (Node) malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->rightTag = node->leftTag = 0;
    node->element = element;
    return node;
}

Node pre = NULL;
void preOrderThreaded(Node root){
    if(root == NULL) return;
    if(root->left == NULL) {   //首先判断当前结点左边是否为NULL，如果是，那么指向上一个结点
        root->left = pre;
        root->leftTag = 1;  //记得修改标记
    }
    if(pre && pre->right == NULL) {  //然后是判断上一个结点的右边是否为NULL，如果是那么进行线索化，指向当前结点
        pre->right = root;
        pre->rightTag = 1;  //记得修改标记
    }

    pre = root;   //每遍历完一个，需要更新一下pre，表示上一个遍历的结点

    if(root->leftTag == 0)   //注意只有标志位是0才可以继续向下，否则就是线索了
        preOrderThreaded(root->left);
    if(root->rightTag == 0)
        preOrderThreaded(root->right);
}

void preOrder(Node root){  //前序遍历一棵线索化二叉树非常简单
    while (root) {   //到头为止
        printf("%c", root->element);   //因为是前序遍历，所以直接按顺序打印就行了
        if(root->leftTag == 0)
            root = root->left;   //如果是左孩子，那么就走左边
        else
            root = root->right;   //如果左边指向的不是孩子，而是线索，那么就直接走右边，因为右边无论是线索还是孩子，都要往这边走了
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

}