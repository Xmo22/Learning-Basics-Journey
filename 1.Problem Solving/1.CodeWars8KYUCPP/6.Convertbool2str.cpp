#include <iostream>
using namespace std;

string convert_boolean(bool b){
    return b ? "true" : "false";
}

int main(){
cout << convert_boolean(false) << endl;
cout << convert_boolean(true) << endl;
}