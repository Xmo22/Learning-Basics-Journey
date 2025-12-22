#include <iostream>
using namespace std;
#include <queue>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }

};

class BinaryTreeTraversal{
private:

Node* root;

void PreOrder(Node* current){
    if(current == NULL) return;
    cout << current->data << " ";
    PreOrder(current->left);
    PreOrder(current->right);

}

void inOrder(Node* current){
    if(current == NULL) return;

    inOrder(current->left);
    cout << current->data << " ";
    inOrder(current->right);

}

void PostOrder(Node* current){
    if(current == NULL) return;

    PostOrder(current->left);
    PostOrder(current->right);
    cout << current->data << " ";

}
    Node* insert(Node* current, int val) {
    

    if (current == NULL) {
        return new Node(val); 
    }


    if (val < current->data) {

        current->left = insert(current->left, val);
    }

    else if (val > current->data) {
        current->right = insert(current->right, val);
    }

    return current;
}
public:

    BinaryTreeTraversal() {
        root = NULL;
    }

 
    void printPreOrder() {
        PreOrder(root); 
        cout << endl;
    }

    void printInOrder() {
        inOrder(root);
        cout << endl;
    }

    void printPostOrder() {
        PostOrder(root);
        cout << endl;
    }

    void insert(int val) {
        root = insert(root, val);
    }
    void levelOrder() {
    if (root == NULL) return;

    queue<Node*> q; 
    q.push(root);   

    while (!q.empty()) {

        Node* current = q.front();
        q.pop(); 


        cout << current->data << " ";


        if (current->left != NULL) {
            q.push(current->left);
        }

   
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
    cout << endl;
}
};

int main() {

    BinaryTreeTraversal myTree;

  
    myTree.insert(50);
    myTree.insert(30);
    myTree.insert(20);
    myTree.insert(40);
    myTree.insert(70);
    myTree.insert(60);
    myTree.insert(80);

    cout << "In-Order (Sorted): ";
    myTree.printInOrder(); 


    cout << "Pre-Order (Structure): ";
    myTree.printPreOrder();


    cout << "Post-Order (Bottom-Up): ";
    myTree.printPostOrder();

    cout << "Level Order Traversal (Level by Level): " << endl;
    myTree.levelOrder();
    return 0;
}