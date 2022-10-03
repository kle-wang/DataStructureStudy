#include "cstdio"
#include "cstdlib"
//单链表

typedef int E;

struct ListNode{
    int element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

bool initList(Node head){
    head->next = NULL;
    return true;
}
bool insertList(Node head,E element,int index){
    if(index < 1) return false;
    while(--index){
        head = head->next;
        if(head == NULL) return false;
    }
    Node node = (ListNode *)malloc(sizeof(struct ListNode));
    node->element = element;
    node->next = head->next;
    head->next = node;
    return true;
}

bool deleteList(Node head,int index){
    if(index < 1) return false;
    while(--index){
        head = head->next;
        if(head == NULL) return false;
    }
    if(head->next == NULL) return false;
    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return true;
}

void printList(Node head){
    while(head->next){
        head = head->next;
        printf("%d ",head->element);
    }
}

int findList(Node head,E element){
    head = head->next;
    int i = 1;
    while(head){
        if(head->element == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}

E getList(Node head,int index){
    if(index < 1) return false;
    do{
        head = head->next;
        if(head == NULL) return NULL;
    }while(--index);
    return head->element;
}

int sizeList(Node head){
    int i = -1;
    while(head){
        head = head->next;
        i++;
    }
    return i;
}

int main(){
    struct ListNode node;
    initList(&node);
    insertList(&node,20,1);
    insertList(&node,30,1);
    insertList(&node,40,1);
    insertList(&node,50,1);
    insertList(&node,60,1);
    printList(&node);
    deleteList(&node,1);
    printf("\n");
    printList(&node);
    printf("\n");
    printf("%d",findList(&node,30));
    printf("\n");
    printf("%d", getList(&node,2));
    printf("\n");
    printf("%d", sizeList(&node));
    return 0;
}