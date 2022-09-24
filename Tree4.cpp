#include "cstdio"
#include "cstdlib"

// 二叉树 线索化二叉树 中序遍历

typedef char E;

typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int leftTag,rightTag;
} * Node;

Node createNode(E element){
    Node node = (TreeNode *) malloc(sizeof(struct TreeNode));
    node->element = element;
    node->left = node->right = NULL;
    node->leftTag = node->rightTag = 0;
    return node;
}

//对二叉树 中序遍历的 线索化
Node pre = NULL;
void inOrderThreaded(Node root){
    if(root == NULL) return;
    if(root->leftTag == 0) inOrderThreaded(root->left);
    if(root->left == NULL){
        root->left = pre;
        root->leftTag = 1;
    }
    if(pre && pre->right == NULL){
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
    if(root->rightTag == 0) inOrderThreaded(root->right);

}

//中序遍历 区别较大

void inOrder(Node root){
    while(root){
        while(root && root->leftTag == 0)
            root = root->left;

        printf("%c ",root->element);

        while(root && root->rightTag == 1){
            root = root->right;
            printf("%c ",root->element);
        }
        root = root->right;
    }

//这是前序遍历 对比
//    while(root){
//        printf("%c ",root->element);
//        if(root->leftTag == 0){
//            root = root->left;
//        }else{
//            root = root->right;
//        }
//    }

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
    inOrderThreaded(a);
    inOrder(a);
}