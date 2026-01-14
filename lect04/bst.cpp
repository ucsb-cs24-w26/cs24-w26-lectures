//bst.cpp
#include <iostream>
using namespace std;

// bst is an Abstract Data Type
class bst{
 public:
    //initialization routine: constructor
    bst():root(nullptr){}
    // accessors or getter
    bool find(int value) const; //searches for a value
    void printInorder() const; 
    int getHeight() const; // returns the height of the tree

    // mutators or setter
    void insert(int value);
    void clear();
    void erase(int value);

 private:
    struct Node{
        int data;
        Node* parent;
        Node* left;
        Node* right;
        Node (int d): data(d){
            parent = left = right = nullptr;
        }
    };
    Node* root;
};

bool bst::find(int value) const{
    return false;
}
void bst::printInorder() const{
    return;
}
void bst::insert(int value){
    return;
}
void bst::clear(){
    return;
}
void bst::erase(int value){
    return;
}
int bst::getHeight() const{
    return 42;
} 



int main() {
    return 0;
}