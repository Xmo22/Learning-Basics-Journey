#include <iostream>
using namespace std;
#include <cassert>

class ArrayList{
    private:

    int *arr;
    int maxSize;
    int count;


    public:
    ArrayList(int size){
        if(size<0){
            maxSize = 10;
        }
        else{
            maxSize = size;
        }

        arr = new int[maxSize];
        count = 0;

    }

    ~ArrayList() {
        delete[] arr;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == maxSize;
    }

    int getSize(){
        return count;
    }

    void displayArr(){
        cout << "\n";
        cout << "[ " ;
        for(int i = 0 ; i < count ; i++){
            cout << arr[i] << " ";
        }
        cout << "]" << "\n";
              
    }

    void InsertAT (int pos , int item){
        if(isFull()){
            cout << "Array is Full you can't insert\n";
        }
        else if(pos < 0 || pos > count){
            cout << "Out of Range..!\n";

        }
        else{
            for(int i = count ; i > pos ; i--){
                arr[i] = arr[i-1];
                
            }
            arr[pos] = item;
            count ++;
        }
    }
    void RemoveElement (int pos){
        if(isEmpty()){
            cout << "Array is Empty you can't delete\n";
        }
        else if(pos < 0 || pos >= count){
            cout << "Out of range\n";
        }
        else{
            for(int i = pos ; i < count - 1 ; i++){
                arr[i] = arr[i+1];
            }
            count --;
        }
    }

    int retrieve(int pos){
        assert(pos>=0 && pos < count);
        return arr[pos];
    }

    void replaceAt(int pos, int newItem){
        if(pos < 0 || pos >= count){
            cout << "Out of Range\n";
        } else {
            arr[pos] = newItem;
        }
    }

    int SearchArr(int item){
        for(int i = 0; i < count ; i++){
            if(arr[i]==item){
                return i;
            }
        }
        return -1;
    }

};


int main(){

    ArrayList arr(5);
    arr.InsertAT(0,5);
    arr.InsertAT(1,10);
    arr.InsertAT(2,15);
    arr.InsertAT(3,20);
    arr.InsertAT(4,25);
    arr.displayArr();
    cout << "size of array: " << arr.getSize() << endl;;
    arr.RemoveElement(2);
    arr.displayArr();
    cout << "size of array " << arr.getSize() << endl;;
    arr.replaceAt(3,28);
    cout << "Postion of element is: " << arr.SearchArr(28) << endl;
    cout << "Element at index 0 is: " << arr.retrieve(0) << endl;
    arr.displayArr();
    cout << "size of array: " << arr.getSize() << endl;
    arr.SearchArr(30);
    return 0;
}