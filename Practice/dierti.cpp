#include "iostream"
using namespace std;

//2.给定一个已经按升序排好序的数列，请你用你认为的最快的算法找到x的位置。
//
//输入样例：
//6 16
//4 16 77 103 231 332
//
//输出样例：
//1

int binarySearch(int * arr,int l,int r,int target);
int main(){
    int n,target;
    cin >>n >> target;
    int arr[n];
    for(int & i : arr){
        cin >> i;
    }
    printf("%d",binarySearch(arr,0,n-1,target));
}

int binarySearch(int * arr,int l,int r,int target){
    if(l>r) return -1;
    int mid = (l + r) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] < target)
        return binarySearch(arr,mid+1,r,target);
    else
        return binarySearch(arr,l,mid-1, true);
}