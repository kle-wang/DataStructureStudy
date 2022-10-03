#include "iostream"

using namespace std;


int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int & i : arr){
        cin >> i;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n){
            if(arr[i] > arr[j]) sum += 1;
            j++;
        }
    }
    printf("%d",sum);
}

