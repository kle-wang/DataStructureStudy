#include "cstdio"
#include "cstdlib"

// 二叉树 前序遍历 中序遍历 后序遍历

typedef char E;

struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
};

typedef TreeNode * Node;

void preOrder(Node root){
    if(root == NULL) return;

    //前序遍历
//    printf("%c ",root->element);
//    preOrder(root->left);
//    preOrder(root->right);

    //中序遍历
//    preOrder(root->left);
//    printf("%c ",root->element);
//    preOrder(root->right);

    //后序遍历
    preOrder(root->left);
    preOrder(root->right);
    printf("%c ",root->element);


}



int main(){
    Node a = (TreeNode *)malloc(sizeof(struct TreeNode));
    Node b = (TreeNode *) malloc(sizeof(struct TreeNode));
    Node c = (TreeNode *) malloc(sizeof(struct TreeNode));
    Node d = (TreeNode *) malloc(sizeof(struct TreeNode));
    Node e = (TreeNode *) malloc(sizeof(struct TreeNode));
    Node f = (TreeNode *) malloc(sizeof(struct TreeNode));
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    c->left = NULL;
    d->left = e->right = NULL;
    e->left = e->right = NULL;
    f->left = f->right = NULL;

    preOrder(a);
}