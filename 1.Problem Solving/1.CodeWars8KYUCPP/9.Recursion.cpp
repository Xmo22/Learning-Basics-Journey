#include <iostream>
using namespace std;


int factorial(int n){
    if( n==0 || n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int fibonacci(int n){
    if (n==0 || n==1){
        return n;

    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    cout <<"Factorial= " << factorial(7) << endl;
    cout << "Fibonacci number = " << fibonacci(9) << endl;

}