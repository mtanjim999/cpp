#include<iostream>
using namespace std;
int main(){
    int n = 13;
    bool isPrime = true;
    for (int i = 2; i*i<=n; i++){
        if(n%i == 0){
            bool isPrime = false;
            break;
        }
    }
    if (isPrime = true){
        cout << "Prime num\n";
    }else{
        cout << "Non prime num\n";
    }
    return 0;
}
