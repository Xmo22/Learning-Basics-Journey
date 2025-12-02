#include <iostream>
#include <stack>
using namespace std;

int exp_evaluation(string exp){
    stack <int> s;

    for(unsigned int i = 0; i < exp.length() ; i++){
        char c = exp[i];

        if(c >= '0' && c <= '9'){
            s.push(c - '0');
        }
        

        else {

            int op2 = s.top(); s.pop(); 
            int op1 = s.top(); s.pop(); 
            
            int result = 0;

            if(c == '+')      result = op1 + op2;
            else if(c == '-') result = op1 - op2;
            else if(c == '*') result = op1 * op2;
            else if(c == '/') result = op1 / op2;
            

            s.push(result);
        }
    }

    return s.top();
}



int main(){
    string exp ;
    cout << "Enter Postfix Expression: ";  
    cin >> exp;

    cout << "Result = " << exp_evaluation(exp) << endl;
    return 0;
}