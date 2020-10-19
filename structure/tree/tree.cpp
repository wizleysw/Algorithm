#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
    Node* left;
    Node* right;
        
public:
    int value;
    
    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
    
    Node* getLeft(){
        return this->left;
    }
    
    Node* getRight(){
        return this->right;
    }
    
    void setLeft(int value){
        this->left = new Node(value);
    }
    
    void setRight(int value){
        this->right = new Node(value);
    }
    
};

class Tree {
    Node *root;
    int size = 0;
    
public:
    void insert(int value){
        if(root == NULL){
            root = new Node(value);
            size++;
        } else {
            Node* cur = root;
            Node* parent = NULL;
            while(cur != NULL){
                parent = cur;
                if(cur->value> value){
                    cur = cur->getLeft();
                } else if(cur->value < value){
                    cur = cur->getRight();
                } else {
                    break;
                }
            }
            
            if(parent->value < value){
                parent->setRight(value);
                size++;
            } else {
                parent->setLeft(value);
                size++;
            }
        }
    }
    
    Node* getRoot(){
        return this->root;
    }
    
    void inOrder(Node* cur){
        if(cur == NULL) return;
        
        inOrder(cur->getLeft());
        cout << cur->value << " ";
        inOrder(cur->getRight());
    }
    
    void preOrder(Node *cur){
        if(cur == NULL) return;
        
        cout << cur->value << " ";
        preOrder(cur->getLeft());
        preOrder(cur->getRight());
    }
    
    void postOrder(Node *cur){
        if(cur == NULL) return;
        
        postOrder(cur->getLeft());
        postOrder(cur->getRight());
        cout << cur->value << " ";
    }
    
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Tree *tree = new Tree();
    tree->insert(3);
    tree->insert(2);
    tree->insert(7);
    tree->insert(10);
    tree->insert(5);
    tree->insert(13);

    cout << "inOrder : ";
    tree->inOrder(tree->getRoot());
    cout << "\n";
    
    cout << "preOrder : ";
    tree->preOrder(tree->getRoot());
    cout << "\n";
    
    cout << "postOrder : ";
    tree->postOrder(tree->getRoot());
    cout << "\n";
    
    return 0;
    
}
