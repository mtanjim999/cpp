#include<iostream>
using namespace std;
int main(){
    int n = 1000;
    int i=1;
    int sum = 0;
    while(i<=n){
        sum = sum +i;
        i++;
    }
    cout<<"Sum is = "<<sum<<endl;
    return 0;
}
