#include <iostream>
#include <stack>
using namespace std;


int more_piroirity(char op){
    if(op == '^') return 3;
    if(op == '*'|| op =='/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string infix_postfix(string exp){
    string result = "";
    stack <char> s;

    for(unsigned int i = 0 ; i < exp.length() ; i++ ){
        char c = exp[i];

        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ){
            result += c;
            }
        else if(c == '('){
            s.push(c);
        }
        else if (c == ')'){
            while(!s.empty() && s.top() != '('){
                result += s.top();
                s.pop();
                
            }
        if(!s.empty()){
            s.pop();
        }
        }

        else {
                    
                    while (!s.empty() && more_piroirity(s.top()) >= more_piroirity(c)) {
                        result += s.top();
                        s.pop();
                    }
                    
                    s.push(c);
                }
            
    }

      while(!s.empty()){
                result += s.top();
                s.pop();
            }


return result;
        
}



int main(){
    string result = "A+(B*C-(D/E^F)*G)*H" ;
    cout << infix_postfix(result) << " " << endl;
    
}