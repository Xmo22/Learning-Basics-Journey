#include <iostream>
using namespace std;
#include <cassert>
template <class t>


struct Node{
    t data;
    Node<t>* next;

    Node(t val){
        data = val;
        next = NULL;

    }

};
template <class t>
class Queue{

    private:
    Node<t> * front;
    Node<t> * rear;
    int count;

    public:
    Queue(){
        front = NULL;
        rear = NULL;
        count = 0;
    }

    bool isEmpty(){
        return count == 0;
    }

    void enqueue(t val){
        Node<t>* newNode = new Node<t>(val);
        if(isEmpty()){
           rear = front = newNode;
        }
        else{
            
            rear->next = newNode;
            rear = newNode;
        }
        count ++;

    }
    
    void dequeue(){
       if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        Node<t>* temp = front;
        if(front == rear){
            front = rear = NULL;
        }

        else{
            front = front->next;
        }
        delete temp;
        count --;
    }

    t get_front(){
        assert(!isEmpty());
        
        return front->data;
        
    }

     t get_rear(){
        assert(!isEmpty());
        
        return rear->data;
        
    }

    ~Queue() {
        while(!isEmpty()) {
            dequeue(); 
        }

    }


    int getSize() {
        return count;
    }

    void display_queue(){
        if(isEmpty()){
            cout << "Queue is Empty\n";
        }

        else{
            Node<t>* temp = front;
            while(temp!=NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << "\n";
        }
    }
};


int main() {
    Queue <int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    cout << "Front is: " <<q.get_front() << endl;;
    cout << "rear is: " <<q.get_rear() << endl;
    q.display_queue();
    cout << "Number of items: " << q.getSize() << endl;
}