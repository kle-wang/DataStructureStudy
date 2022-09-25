#include "cstdio"
#include "cstdlib"

//平衡二叉树

typedef int E;

typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int height;
}* Node;

Node createNode(E element){
    Node node = (TreeNode *) malloc(sizeof(struct TreeNode));
    node->element = element;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a,int b){
    return a > b ? a : b;
}

int getHeight(Node root){
    if(root == NULL) return 0;
    return root->height;
}

Node leftRotation(Node root){
    Node newRoot = root->left;
    root->left = newRoot->right;
    newRoot->left = root;

    root->height = max(getHeight(root->right), getHeight(root->left) + 1);
    newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)+1);

    return newRoot;
}

Node rightRotation(Node root){
    Node newRoot = root->right;
    root->left = newRoot->right;
    newRoot->left = root;

    root->height = max(getHeight(root->right), getHeight(root->left) + 1);
    newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left) + 1);

    return newRoot;
}

Node leftRightRotation(Node root){
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

Node rightLeftRotation(Node root){
    root->right = rightRotation(root->right);
    return leftRotation(root);
}


Node insert(Node root,E element){
    if(root == NULL){
        root = createNode(element);
    }else if(root->element > element) {
        root->left = insert(root->left, element);
        if(getHeight(root->left) - getHeight(root->right) > 1) {   //插入完成之后，需要计算平衡因子，看看是否失衡
            if(root->left->element > element) //接着需要判断一下是插入了左子树的左边还是右边，如果是左边那边说明是LL，如果是右边那说明是LR
                root = rightRotation(root);   //LL型得到左旋之后的结果，得到新的根结点
            else
                root = leftRightRotation(root);    //LR型得到先左旋再右旋之后的结果，得到新的根结点
        }
    }else if(root->element < element){
        root->right = insert(root->right,element);
        if(getHeight(root->left) - getHeight(root->right) < -1){
            if(root->right->element < element)
                root = leftRotation(root);
            else
                root = rightLeftRotation(root);
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

void inOrder(Node root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->element);
    inOrder(root->right);
}


int main(){
    Node root = insert(NULL, 18);   //插入后，得到根结点
    insert(root, 10);
    insert(root, 20);
    insert(root, 7);
    insert(root, 15);
    insert(root, 22);
    insert(root, 9);
    inOrder(root);


}