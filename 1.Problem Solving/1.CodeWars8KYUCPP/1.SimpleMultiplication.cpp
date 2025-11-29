#include <iostream>
using namespace std;



int main(){
    int num;
    cout << "Enter number: "; 
    cin >> num;

    if(num % 2 == 0){
        num *= 8;
        cout << num << endl;
    }

    else {
        num *= 9;
        cout << num << endl;
    }
}