// bst.cpp
#include <iostream>
#include <random>
#include <set>
using namespace std;


// bst is an Abstract Data Type
class bst{
public:
    // initialization routine: constructor
    bst() : root(nullptr) {}
    // accessors or getter
    bool find(int key) const; // searches for a key
    void printInorder() const;
    int getHeight() const; // returns the height of the tree
    vector<int> linearize() const; // NEW!

    // mutators or setter
    void insert(int key);
    void clear();
    void erase(int key);

private:
    struct Node{
        int data;
        Node *parent;
        Node *left;
        Node *right;
        Node(int d, Node* p = nullptr) : data(d), parent(p){
            left = right = nullptr;
        }
    };
    Node *root;
    int getHeight(Node *r) const;
    void printInorder(Node *r) const;
    void insert(int value, Node *r);
    void linearize(Node *r, vector<int>& result) const;
};
void bst::linearize(Node *r, vector<int>& result) const{
    if(!r) return;
    //cout << r->data << " ";
    result.push_back(r->data);
    linearize(r->left, result);
    linearize(r->right, result);

}
vector<int> bst::linearize() const{
    vector<int> result;
    // Call helper function
    linearize(root, result);
    return result;
}

void bst::insert(int key){
    //TO DO
}

void bst::insert(int key, Node *r) {
   // TO DO
}

// Helper recursive function
void bst::printInorder(Node *r) const{
}

// Helper getHeight recursive
int bst::getHeight(Node *r) const{
    if (!r){
        return -1;
    }
    int hleft = getHeight(r->left);
    int hright = getHeight(r->right);
    return max(hleft, hright) + 1;
}

bool bst::find(int value) const{
    return false;
}

void bst::printInorder() const{
    printInorder(root);
}

void bst::clear(){
    return;
}

void bst::erase(int value){
    return;
}

int bst::getHeight() const{
    return getHeight(root); // call helper
}

int main(){
    bst b;
    b.insert(41);
    b.insert(45);
    b.insert(32);
    b.insert(42);
    b.insert(12);
    b.printInorder();
    cout << endl;
    cout << "Height = "<< b.getHeight() << endl;
    return 0;
}