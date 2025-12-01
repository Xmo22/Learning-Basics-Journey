#include <iostream>
using namespace std;
template <class t>


class Stack{
    
    struct node{
        t val;
        node *next;
    };

    private:
    node *top ;

    public:

    Stack(){
        top = NULL;
    }

    void push(t element){
        node *push_ptr = new node;
        push_ptr -> val = element;
        push_ptr -> next = top;
        top = push_ptr;
    }

    void pop(){

        if(top == NULL){
            cout << "Stack is already empty\n"; 
        }
        else{

        
        node *tempptr = top;
        top = top->next;
        delete tempptr;
    }
    }

    void pop(t &popped_element){
        if(top == NULL){
        cout <<"Stack is already empty\n"; 
        }
        else{
        popped_element = top->val;
        cout << "Popped element: " << popped_element << endl;
        node *tempptr = top;
        top = top->next;
        delete tempptr;
    }
    }

    void get_top(t &top_element){
        if(top == NULL){
        cout << "Stack is already empty\n"; 
        }
        else{
            top_element = top->val;
            cout << "Top is: " << top_element << endl;

        }
    }

    void display_stack(){
        node *curr = top;
        cout << "[ " ;
        while(curr != NULL){
            cout << curr -> val << " ";
            curr = curr -> next;
        }
        cout << " ]" << "\n";
    }


    };


int main(){
    Stack <int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display_stack();
    s1.pop();
    int x = 0;
    s1.pop(x);




















}


