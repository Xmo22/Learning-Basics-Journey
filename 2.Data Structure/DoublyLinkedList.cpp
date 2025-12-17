#include <iostream>
using namespace std;

struct Node{
int data;
Node* next;
Node* prev;

Node(int val){
    data = val;
    next = NULL;
    prev = NULL;
}

};

class doublyLinkedList{
    private:
    Node* head;
    Node* tail;
    int count;

    public:
    doublyLinkedList(){
        head = tail = NULL;
        count = 0;
    }
    bool isEmpty(){
        return count == 0;
    }
    
    void InsertAtbegin(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){

            head = tail = newNode;
        }
        else{

            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    void insertAtend(int val){
         Node* newNode = new Node(val);
        if(isEmpty()){

            head = tail = newNode;
        }
        else{
        tail->next = newNode;
        newNode->prev = tail;
        tail=newNode;
        }
        count++;
    }

    void insertBYposition(int pos , int val){
        if(pos == 0){
            return InsertAtbegin(val);
        }
        else if (pos == count){
            return insertAtend(val);
        }
        else if (pos <0 || pos > count){
            cout << "Out of range\n";
        }
        else{
         Node* newNode = new Node(val);
         Node* temp = head;
        for(int i = 0; i < pos ; i++){
            temp = temp->next;
        }
            newNode->next = temp;
            newNode -> prev = temp -> prev;
            temp -> prev -> next = newNode;
            temp -> prev = newNode;


        }
        count ++;
    }

    void removeATfirst(){
        if(isEmpty())return;
        else if(count == 1){
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            head -> prev = NULL;
            delete temp;
        }
        count -- ;
    }

    void removeATend(){
        if(isEmpty())return;
        else if(count == 1){
            head = tail = NULL;
        }
        else{
            Node* temp = tail;
            tail = tail->prev;
            tail -> next = NULL;
            delete temp;
        }
        count--;
    }

    void removeBYposition(int pos){
        if(pos == 0){
            return removeATfirst();
        }
        else if(pos == count - 1){
            return removeATend();
        }
        else{
            Node* temp = head;
            for(int i = 0 ; i < pos ; i++){
                temp = temp->next;
                }
            temp->prev->next =temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
        count--;
    }


        int get_size(){
         return count;
    }

    void print()
    {
        Node* temp = head;
         cout << "NULL <-> ";
        while(temp != NULL){

            cout << temp -> data << " <-> ";
            temp = temp -> next;
        }
        cout << "NULL";
        cout << "\n";
    }



    int search(int val) {
        Node* temp = head;
        int index = 0;
        while (temp != NULL) {
            if (temp->data == val) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void reverse() {
    if (isEmpty()) return; 

    Node* curr = head; 
    Node* temp = NULL; 

    while (curr != NULL) {
        
        temp = curr->prev;      
        curr->prev = curr->next; 
        curr->next = temp;      
        curr = curr->prev; 
    }
    temp = head;   
    head = tail;   
    tail = temp;   
}
};

int main(){
    doublyLinkedList dl ;
    dl.InsertAtbegin(10);
    dl.insertAtend(35);
    dl.insertBYposition(1,15);
    dl.insertBYposition(2,20);
    dl.insertBYposition(3,25);
    dl.insertBYposition(4,30);
    dl.insertBYposition(5,50);
    dl.print();
    cout << "Size of the list: " << dl.get_size() << endl;
    cout << "----------------------------\n";
    dl.removeATfirst();
    dl.removeATend();
    dl.removeBYposition(0);
    dl.removeBYposition(1);
    dl.print();
    cout << "Size of the list: " << dl.get_size() << endl;
    cout << "----------------------------\n";
    cout << "number Found at index: " << dl.search(30) << endl;
    dl.reverse();
    dl.print();

    

}