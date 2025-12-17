#include <iostream>
using namespace std;

struct Node{
int data;
Node *next;

Node(int val){
data = val;
next  = NULL;
}
};

class LinkedList{
    private:
    int count;
    Node* head;
    Node* tail;


    public:

    LinkedList() {
        head = tail = NULL;
        count = 0;
    }

    int isEmpty(){
        return count == 0;
    }

    void insertAtbegin(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        count ++;
        }

        void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail=newNode;
        }
        count++;
        }
    
    void insertBYpostion(int pos , int val){

        if(pos==0){
            insertAtbegin(val);
        }
        else if(pos == count){
            insertAtEnd(val);
        }
        else if(pos < 0 || pos>count){
            cout << "Out of Range\n";
        }
        else{
            Node* newNode = new Node(val);
            Node* temp = head;
            for(int i = 0 ; i < pos - 1 ; i++){
                temp = temp->next;
            }
            newNode->next = temp -> next;
            temp -> next = newNode;
                    count++;
        }

    }

    int get_size(){
         return count;
    }

    void print()
    {
        Node* temp = head;

        while(temp != NULL){
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL";
        cout << "\n";
    }




    int removeAtbegin(){
        if(isEmpty()){
            return -1;
        }
        else {
            int deletedVal = head->data;
            Node* temp = head;
            head = head->next;
            if(head==NULL){
                tail = NULL;
            }
            delete temp;
            count --;
            return deletedVal;

        }

    }

        int removeAtend(){
        if(isEmpty()){
            return -1;
        }

        else if(head->next==NULL){
           return removeAtbegin();

        }

        else {
            int deletedVal = tail->data;
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
                delete tail;
                tail = temp;
                tail->next=NULL;
                 count --;
            return deletedVal;
            }


        }


    int removeBYposition(int pos){
        if(pos == 0){
            return removeAtbegin();
        }
        else if(pos == count - 1){
            return removeAtend();
        }
        else if(pos < 0 || pos >= count){
            return -1;
        }

        else{
            Node* temp = head;
            for(int i = 0 ; i < pos - 1 ; i++){
                temp = temp->next;
            }
            Node* delNode = temp->next;
            int delval = delNode->data;
            temp -> next = temp -> next -> next;
            delete delNode;
            count --;
            return delval;
        }
    }

    int searchLL(int num){
        Node* temp = head;
        int index = 0;
        while(temp != NULL){
            if(temp->data == num){
                return index;
            }
            temp = temp->next;
            index++;

    }
                return -1;
    }

    void reverse(){
        if(head == NULL || head->next == NULL)
         return;
        Node* curr,*prev,*next;
        prev = NULL;
        curr = head;
        tail = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main(){
    LinkedList LL;
    LL.insertAtbegin(20);
    LL.insertAtEnd(30);
    LL.insertBYpostion(0,10);
    LL.insertBYpostion(2,25);
    LL.insertBYpostion(3,50);
    LL.insertBYpostion(5,60);
    LL.print();
    cout << "Size of the list is: " << LL.get_size() << endl;
    cout << "========================\n";
    LL.removeAtbegin();
    LL.removeAtend();
    LL.removeBYposition(1);
    LL.print();
    cout << "Size of the list is: " << LL.get_size() << endl;
    cout << "========================\n";
    cout << "You are seaching for: "<<  LL.searchLL(30) << endl;
    cout << "You are seaching for: "<<  LL.searchLL(70) << endl;
    cout << "========================\n";                                           
    LL.reverse();
    LL.print();
    cout << "Size of the list is: " << LL.get_size() << endl;
}