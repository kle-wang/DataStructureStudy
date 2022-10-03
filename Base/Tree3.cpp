#include "cstdio"
#include "cstdlib"

// 二叉树 线索化二叉树 前序遍历

typedef char E;

typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int leftTag,rightTag;
} * Node;

Node createNode(E element){
    Node node = (TreeNode *) malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->leftTag = node->rightTag = 0;
    node->element = element;
    return node;
}


//对二叉树线索化
Node pre = NULL;
void preOrderThreaded(Node root){
    //前序遍历
    if(root == NULL) return;

    if(root->left == NULL){
        root->left = pre;
        root->leftTag = 1;
    }
    if(pre && pre->right == NULL){
        pre->right = root;
        pre->rightTag = 1;
    }

    pre = root;
    if(root->leftTag == 0){
        preOrderThreaded(root->left);
    }
    if(root->rightTag == 0){
        preOrderThreaded(root->right);
    }

}

//遍历二叉树
void preOrder(Node root){
    while(root){
        printf("%c ",root->element);
        if(root->leftTag == 0){
            root = root->left;
        }else{
            root = root->right;
        }
    }
}


int main(){
    Node a = createNode('A');
    Node b = createNode('B');
    Node c = createNode('C');
    Node d = createNode('D');
    Node e = createNode('E');

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    preOrderThreaded(a);
    preOrder(a);
}
