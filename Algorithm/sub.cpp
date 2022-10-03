//高精度减法
#include <iostream>
#include <vector>
using namespace std;

//比较是否A >= B
bool cmp(vector <int> &A,vector <int> &B){
    if (A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] != B[i]){
            return A[i] >= B[i];
        }
    }
    return true;
}

// 进行 C = A - B
vector<int> sub(vector <int> &A,vector <int> &B){
    vector<int> C;
    for(int i = 0, t = 0; i < A.size(); i++){
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t+10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}


int main(){
    string a,b;
    vector<int>A,B;
    cin>>a>>b;
    //字符串转到数组里 倒序插入
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    //比大小
    if(cmp(A,B)){
        // A>=B
        auto C = sub(A,B);
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }else{
        //A<B
        auto C = sub(B,A);
        cout << "-";
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }
}