#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N,K;
    cin >> N >> K;
    int height[1000010];
    for(int i = 0; i < K; i++){
        int l,r;
        cin >> l >> r;
        while(l-1 <= r-1){
            height[l-1] += 1;
            l++;
        }
    }
    sort(height,height+N);
    int mid = N / 2;
    cout << height[mid];
}