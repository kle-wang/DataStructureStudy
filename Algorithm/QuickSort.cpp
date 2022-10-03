#include <cstdio>

void Swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b =t;
}

int Partition(int *a,int l,int r){
    int i = l, j = r+1;
    int x = a[l];
    while(true){
        while(a[++i] < x && i < r); //左指针向右 遇到比选定的x大的就停止移动  并且 左<右
        while(a[--j] > x); //右指针向左
        if(i >= j) //左右指针相遇 跳出循环
            break;
        Swap(&a[i],&a[j]); //交换i j
    }
    a[l] = a[j]; //基准值与指针的值交换 其实这里 a[j] == a[i] 成立 因为两个指针相遇了 i == j
    a[j] = x;
    return j; //返回x的下标
}


void quickSort(int *a,int l,int r){
    if(l < r){
        int q = Partition(a,l,r); //获取到了基准值 分割
        quickSort(a,l,q-1); //基准值左边的排序
        quickSort(a,q+1,r); //基准值右边的排序
    }
}


int main(){
    int a[10]={1,88,8,9,10,11,12,13,15,23};
    quickSort(a,0,9);
    for(int i : a){

        printf("%d ",i);
    }
    return 0;

}
