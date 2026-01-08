#include <iostream>
using namespace std;


string removeExclamationMarks(string str){
   string clean = "";
  for (unsigned int i = 0 ; i < str.length() ; i ++){
    if(str[i] == '!'){
      continue;
    }
    clean += str[i];
  }
  return clean;
}

int main(){
    cout << removeExclamationMarks("Hel!lo! !world!") << "\n";
}

