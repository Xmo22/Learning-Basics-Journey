#include <iostream>
using namespace std;

bool iseven(int number){
    return number % 2 == 0 ;
}

string isodd(int number){
return number % 2 != 0 ? "True" : "False";
}

int main(){
cout << boolalpha;  // T|F instead of 1|0
 cout << iseven(9) << endl;;
 cout << isodd(9) << endl;
}