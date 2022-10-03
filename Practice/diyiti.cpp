#include "iostream"
using namespace std;

//1.有一个长度为n的整数序列，给定一个整数x，请用快速选择算法求出排序后x所在的位置。
//
//输入样例：
//8 78
//132 99 2 56 21 78 898 1
//
//输出样例：
//4
void QuickSort(int * arr,int l,int r);
int Partition(int * arr,int l,int r);
void Swap(int *a,int *b);
int main(){
    int n,target;
    cin >>n >> target;
    int arr[n];
    for(int & i : arr){
        cin >> i;
    }
    QuickSort(arr,0,n-1);
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            printf("%d",i);
            break;
        }
    }
}

void QuickSort(int * arr,int l,int r){
    if(l < r){
        int q = Partition(arr,l,r);
        QuickSort(arr,l,q-1);
        QuickSort(arr,q+1,r);
    }
}

int Partition(int * arr,int l,int r){
    int i = l, j = r + 1;
    int x = arr[l];
    while(true){
        while(arr[++i] < x && i < r);
        while(arr[--j] > x);
        if(i >= j) break;
        Swap(&arr[i],&arr[i+1]);
    }
    arr[l] = arr[j];
    arr[j] = x;
    return j;
}

void Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}