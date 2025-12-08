#include <iostream>
#include <cassert>
using namespace std;
const int max_length = 100;

class queuearray{

    private:
    int rear;
    int front;
    int arr[max_length];
    int count;


    public:
    queuearray(){
        rear = max_length - 1;
        front = 0;
        count = 0;
    }

    bool isEmpty(){
        return count == 0;
    }

    bool isFull(){
        return count == max_length;
    }

    void enqueue(int num){
        if(isFull()){
            cout << "Queue is full you can't add any item" << "\n";
        }
        else{

        
        rear = (rear + 1) % max_length;
        arr[rear] = num;
        count ++;
    }
    }
    void dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty there is nothing to delete" << "\n";
        }
        else{

        front = (front + 1) % max_length ;
        count--;
        }
    }
    int getFront(){
        assert(!isEmpty());
        return arr[front];
    }
    int getRear(){
        assert(!isEmpty());
        return arr[rear];
    }

    void display_info(){
        if(isEmpty()){
            cout << "Queue is Empty there is no thing to display" << "\n";
        }
        else{
            cout << "[ ";
            for(int i = 0 ; i < count ; i++){
            int index = (front + i) % max_length ;
            cout << arr[index] << " " ;
            }
            cout << "]";
        }
    }


};



int main(){
    queuearray q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    cout << "Front item: " << q1.getFront() << endl; 
    cout << "Rear item: " << q1.getRear() << endl;   
    q1.display_info();
    q1.dequeue();
    cout << "Front item: " << q1.getFront() << endl; 
    q1.display_info();
    
  
    
}