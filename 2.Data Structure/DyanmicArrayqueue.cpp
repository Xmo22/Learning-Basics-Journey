#include <iostream>
#include <cassert>
using namespace std;


class queuearray{

    private:
    int rear;
    int front;
    int *arr;
    int count;
    int max_length;


    public:
    queuearray(int size){
        if(size <= 0){
            max_length = 100;
        }
        else{
            max_length = size;
        }
        arr = new int[max_length];
        rear = max_length - 1;
        front = 0;
        count = 0;
    }
    ~queuearray() {
        delete[] arr;
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

int searchqueue(int num) {

    if (isEmpty()) {
        return -1; 
    }

    for (int i = 0; i < count; i++) {
        
        int index = (front + i) % max_length;
        if (arr[index] == num) {
            return index; 
        }
    }
    return -1;
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
            cout << "]" << endl;
        }
    }


};



int main(){
    queuearray q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    cout << "Front item: " << q1.getFront() << endl; 
    cout << "Rear item: " << q1.getRear() << endl;   
    q1.display_info();
    q1.enqueue(60);
    q1.dequeue();
    cout << q1.getFront() << endl;;
    q1.display_info();
    cout << q1.searchqueue(40) << endl;
    q1.enqueue(60);
    cout << q1.getRear() << "\n";
    q1.display_info();
    
   

    
  
    
}