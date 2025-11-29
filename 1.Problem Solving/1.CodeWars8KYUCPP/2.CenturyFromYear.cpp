#include <iostream>
using namespace std;
#include <cmath>


float centuryFromYear(float year) 
{
  
return ceil(year / 100) ;
}
int main(){
 centuryFromYear(250);
}