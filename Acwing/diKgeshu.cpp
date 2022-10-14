//786. 第k个数 https://www.acwing.com/problem/content/description/788/
#include <iostream>
using namespace std;

const int N = 100010;
int q[N];

void quicksort(int q[],int l,int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i],q[j]);
    }
    quicksort(q,l,j);
    quicksort(q,j + 1,r);
}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> q[i];
    }
    quicksort(q,0,n-1);
    cout << q[k - 1];
    return 0;

}