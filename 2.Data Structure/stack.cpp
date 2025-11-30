#include  <iostream>
using namespace std;
const int max_Size = 100;

class Stack{

private:
int top;
int item[max_Size];

public:
Stack(){
    top = -1;
}

bool isfull(){
return top == max_Size - 1;
}

void push(int element){
if(isfull()){
    cout << "Stack is full\n";
}
else{
    top++;
    item[top]= element;
    // cout << "Item is added successfully\n";
}
}

bool isempty(){
    return top == -1;
}

void pop(){
    if(isempty()){
        cout << "Stack is empty there is nothing to remove\n";
    }
    else{
        top --;
    }
}
void pop(int &element){
    if(isempty()){
        cout << "Stack is empty there is nothing to remove\n";
    }
    else{
        element = item[top];
        top --;
        cout << element << "\n";
    }
}

void get_top(int &stacktop){
    if(isempty()){
        cout << "Stack is empty there is nothing to remove\n";
    }
    else{
        
        stacktop = item[top];
        cout << stacktop << "\n";
    }
}

void display_arr(){
    cout << "[ " ;
    for(int i = top; i >= 0; i--){
        cout <<item[i]<<" ";
    }
    cout << "]";
    cout << endl;
}
  

};




int main(){

    Stack s1;
    s1.push(5);
    s1.push(10);
    s1.push(15);
    s1.push(20);
    s1.push(25);
    // s1.display_arr();
    int y;
    s1.get_top(y); //25
    s1.pop(y); //25
    s1.get_top(y); //20
    s1.pop(); // 20 but will not appear
    s1.get_top(y);//15
    s1.pop(y); // 15
    s1.get_top(y); //10
    s1.display_arr();
}