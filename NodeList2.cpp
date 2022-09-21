#include "cstdio"
#include "cstdlib"

//双向链表

typedef int E;

struct ListNode{
    E element;
    struct ListNode * prev;
    struct ListNode * next;
};

typedef struct ListNode * Node;

bool initList(Node head){
    head->prev = head->next = NULL;
    return true;
}

bool insertList(Node head,E element,int index){
    if(index < 1) return false;
    while(--index){
        head = head->next;
        if(head == NULL) return false;
    }
    Node node = (ListNode *) malloc(sizeof(struct ListNode));
    if(node == NULL) return false;
    node->element = element;
    if(head->next){
        head->next->prev = node;
        node->next = head->next;
    }else{
        node->next = NULL;
    }
    head->next = node;
    node->prev = head;
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
    if(head->next->next){
        head->next->next->prev = head;
        head->next = head->next->next;
    }else{
        head->next = NULL;
    }
    free(tmp);
    return true;
}



int main() {
    struct ListNode head;
    initList(&head);
    for (int i = 0; i < 5; ++i)  //插5个元素吧
        insertList(&head, i * 100, i);

    Node node = &head;   //正向遍历
    do {
        node = node->next;
        printf("%d -> ", node->element);
    } while (node->next != NULL);
    printf("\n");

    deleteList(&head,2);

    node = &head;   //正向遍历
    do {
        node = node->next;
        printf("%d -> ", node->element);
    } while (node->next != NULL);

}
