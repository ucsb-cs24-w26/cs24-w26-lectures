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
    class iterator;
    // mutators or setter
    void insert(int key);
    void clear();
    void erase(int key);
    iterator begin();
    iterator end();

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
    Node* successor(Node* r) const;
    Node* getmin(Node* r) const;
};

class bst::iterator{
    public:
        iterator(bst::Node* pcurr = nullptr,  bst* ptree = nullptr): curr(pcurr), rtree(ptree){}

        int operator*(){
            return curr->data;
        }
        //preincrement ++it;
        iterator& operator++(){
            curr = rtree->successor(curr);   
            return *this;       
        }

        // Write the == and the != operators

    private:
        bst::Node* curr;
        bst* rtree;

};

bst::iterator bst::begin(){
    return iterator(getmin(root), this);
}
bst::iterator bst::end(){
    return iterator(nullptr, this);
}

bst::Node* bst::getmin(Node* r) const{
    if(!r) return nullptr;
    while(r->left){
        r = r->left;
    }
    return r;

}

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
    if(!root){
     // Insert the key as the root
     root  = new Node(key, nullptr);
     return;
   }
   insert(key, root);
}

void bst::insert(int key, Node *r) {
   // TO DO: non-empty trees
   //  Base case: If leaf node (no left and right children), insert either left or right 
   if(key == r->data){
    return;
   }
   if(key < r->data){
    //insert into the left subtree
    if(!r->left){ // No left child
        r->left = new Node(key, r);
        // insert key as the left child
    }else{
        insert(key, r->left);
    }
   }else{
    //insert into the right subtree
    if(!r->right){
        //insert key as the right child
         r->right = new Node(key, r);
    }else{
        insert(key, r->right);
    }
   }
}

bst::Node* bst::successor(Node* r)const{
    if(!r) return nullptr;
    Node* result = nullptr;
    if(r->right){
        result = getmin(r->right);
    }else{
        Node* p = r->parent;
        while(p && r == p->right){
            r = p;
            p = p->parent;
        }
        result = p;
    }
    return result;
}

// Helper recursive function
void bst::printInorder(Node *r) const{
    if(!r) return;
    printInorder(r->left);
    cout << r->data << " ";
    printInorder(r->right);
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
    cout << "print the tree in order: ";
    b.printInorder();
    cout << endl;
    cout << "Height = "<< b.getHeight() << endl;

    bst::iterator it = b.begin();
    cout << *it << " ";
    ++it;
    cout << *it << " ";

    return 0;
}