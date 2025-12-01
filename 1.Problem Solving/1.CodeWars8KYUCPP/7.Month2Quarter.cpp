#include <iostream>
using namespace std;

int which_quarter(int month){
    return ceil(month/3.0);
}

int main(){
cout << which_quarter(12);
}