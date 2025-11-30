#include <iostream>
using namespace std;

string reversed_string(string str){
    string reversed = "";
    for(int i = str.length() ; i >= 0; i--){
        reversed += str[i];
    }
    return reversed;
}

int main(){
cout << reversed_string("Mohamed") << "\n";
}