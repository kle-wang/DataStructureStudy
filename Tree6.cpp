#include "cstdio"
#include "cstdlib"

// 二叉查找树

typedef int E;

typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
}* Node;

Node createNode(E element){
    Node node = (TreeNode *) malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    return node;
}

Node insert(Node root,E element){
    if(root){
        if(root->element > element)
            root->left = insert(root->left, element);
        else if(root->element < element)
            root->right = insert(root->right, element);
    } else {
            root = createNode(element);
        }
        return root;
    }


void inOrder(Node root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->element);
    inOrder(root->right);
}

Node find(Node root,E target){
    while(root){
        if(root->element > target){
            root = root->left;
        }else if(root->element < target){
            root = root->right;
        }else{
            return root;
        }
    }
    return NULL;
}

Node findMax(Node root){
    while(root && root->right){
        root = root->right;
    }
    return root;
}

Node deleteNode(Node root,E target){
    if(root == NULL) return NULL;
    if(root->element > target){
        root->left = deleteNode(root->left, target);
    }else if(root->element < target){
        root->right = deleteNode(root->right, target);
    }else{

        if(root->left && root->right){
            Node max = findMax(root->left);
            root->element = max->element;
            root->left = deleteNode(root->left,root->element);
        }else{
            Node tmp = root;
            if(root->right){
                root = root->right;
            }else{
                root = root->left;
            }
            free(tmp);
        }

    }
    return root;
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
    printf("\n%p",find(root,20));
    printf("\n%d\n",findMax(root)->element);
    deleteNode(root,18);
    inOrder(root);
}
