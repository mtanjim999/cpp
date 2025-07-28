#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<< "Enter char: ";
    cin >>ch;

    if(ch >= 'a' && ch <= 'z'){  //This probolem also solved by Ascii value
        cout << "Lowercase\n";  //suppose [A-Z == 65-90].In that case cout Uppercase

    }else{
        cout << "Uppercase\n";
    }



    return 0;
}
