#include <vector>
#include <iostream>
using namespace std;


vector<int> invert(vector<int> values)
{
   for (int &val : values) {
    val *= -1;
 }
    return values;
}

int main(){
    vector<int> result = invert({1,2,3,-4,5});

   
     for(int n : result) {
         cout << n << " ";
     }
     
     return 0;
}