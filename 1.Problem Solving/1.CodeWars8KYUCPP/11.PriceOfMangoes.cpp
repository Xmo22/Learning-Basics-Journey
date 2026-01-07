#include<iostream>
using namespace std;

int mango(int quantity, int price)
{
    return (quantity - quantity/3)*price;
}

int main(){
    cout << "price of mango is: " << mango(8,2) << "\n";
}