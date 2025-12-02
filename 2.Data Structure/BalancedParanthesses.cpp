#include <iostream>
using namespace std;
#include <stack>


bool are_pair(char o , char c){
    if(o == '(' && c == ')') return true;
    if(o == '[' && c == ']') return true;
    if(o == '{' && c == '}') return true;
    return false;
    }


bool are_balanced(string exp){
    stack <char> s;

    for(unsigned int i = 0 ; i < exp.length(); i++ ){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            s.push(exp[i]);
        }

        

        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){

             if(s.empty()) return false;

             if(are_pair(s.top(),exp[i])) {
                s.pop();
            }
         else return false;   

        }

        }
        return s.empty();
    }


    int main(){
    string exp = "([}])";
    if(are_balanced(exp)){
        cout << "Balanced" <<"\n";
        }
    else cout << "Unbalanced" <<"\n";
    }


