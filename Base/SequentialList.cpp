#include "cstdio"
#include "cstdlib"
//实现顺序表

typedef int E;

struct List{
    E *array;
    int size; //元素个数
    int capacity; //数组总大小
};

typedef struct List * ArrayList;

bool initList(ArrayList list){
    list->array = (E *) malloc(sizeof(E) * 10);
    if(list->array == NULL) return false;
    list->capacity = 10; //底层数组大小
    list->size = 0;   //元素数量默认为0
    return true;
}

bool insertList(ArrayList list,E element,int index){
    if(index < 1 || index > list->size + 1) return false; //判断索引是否越界
    //扩容
    if(list->size == list->capacity){
        int newCapacity = list->capacity + list->capacity*2; //新容量
        E * newArray = (E *)realloc(list->array,newCapacity * sizeof(E)); //新数组
        list->capacity = newCapacity;
        list->array = newArray;
    }
    //开始按索引插入
    for(int i = list->size; i > index - 1; i--){ //从后往前插
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = element;
    list->size++;
    return true;
}

bool deleteList(ArrayList list,int index){
    if(index < 1 || index > list->size) return false; //判断索引是否越界
    for(int i = index - 1; i < list->size - 1; i++){
        list->array[i] = list->array[i+1];
    }
    list->size--;
    return true;
}

int sizeList(ArrayList list){
    return list->size;
}

E * getList(ArrayList list, int index){
    if(index < 1 || index > list->size) return NULL;
    return &list->array[index - 1]; //顺序表索引1开始 但是数组是从0开始的
}

int findList(ArrayList list, E element){
    for (int i = 0; i < list->size; ++i) {
        if(list->array[i] == element) return i + 1; //顺序表索引1开始 但是数组是从0开始的
    }
    return -1; //没找到
}


int main(){
    struct List list;
    initList(&list);
    insertList(&list,15,1);
    insertList(&list,20,2);
    insertList(&list,30,3);
    insertList(&list,40,1);
    insertList(&list,100,1);
    insertList(&list,88,1);
    insertList(&list,66,1);

    //遍历顺序表
    for(int i = 0; i < sizeList(&list); i++){
        printf("%d ",list.array[i]);
    }

    //寻找顺序表元素索引标
    printf("\nfind：%d\n", findList(&list,15));


    //删除某元素
    deleteList(&list,3);

    //遍历顺序表
    for(int i = 0; i < sizeList(&list); i++){
        printf("%d ",list.array[i]);
    }

    printf("\n%d", *getList(&list,2));




    return 0;
}