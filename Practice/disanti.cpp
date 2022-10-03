#include <vector>
#include "iostream"
using namespace std;

//3.给定个3正整数，请你计算他们的和。
//
//数据范围：
//1 <= 整数长度 <= 100000
//
//输入：
//89787987887
//23647557426
//98797989898
//
//输出：
//212233535211
vector<int> add(vector<int> &A, vector<int> &B);
int main(){
    string a,b,c;
    vector<int> A,B,C;
    cin >> a >> b >> c;
    int la = a.size(),lb = b.size(),lc = c.size();
    for(int i = la -1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }
    for(int i = lb -1; i >= 0; i--){
        B.push_back(b[i] - '0');
    }
    for(int i = lc -1; i >= 0; i--){
        C.push_back(c[i] - '0');
    }
    vector<int> temp = add(A,B);
    vector<int> sum = add(C,temp);
    for(int i = sum.size() - 1; i >= 0; i--){
        cout << sum[i];
    }

}

vector<int> add(vector<int> &A, vector<int> &B){
    vector<int> C;
    if(A.size() < B.size()) return add(B,A); //一定要保证是大+小
    int t = 0;
    for(int i = 0; i < A.size(); i++){
        t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t%10); //取其个位
        t /= 10; //进位
    }
    if(t) C.push_back(t);
    return C;
}