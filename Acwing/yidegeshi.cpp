//801. 二进制中1的个数
#include <iostream>

using namespace std;

int lowbit(int x){
    int re = x & -x;
    return re;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int res = 0;
        while(x) x -= lowbit(x),res++;
        cout << res << " ";
    }
}