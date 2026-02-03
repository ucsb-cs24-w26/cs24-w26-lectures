// BST.h
// Modified version of lab02 starter code for demo purposes

#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>
using namespace std;

class BST {
 public:
    // ctor, dtor, insert and one print method already done in BST.cpp:
    BST();                   // constructor
    ~BST();                  // destructor
    bool insert(int value);     // insert value; return false if duplicate
    bool contains(int value) const;  // true if value is in tree
    void printPreOrder() const; // prints tree data pre-order to cout
    void printBreadthFirst(vector<int>& v) const;
   
 private:

    struct Node {
	    int info;
	    Node *left, *right, * parent;
        Node(int v = 0) : info(v), left(nullptr), right(nullptr), parent(nullptr) { }
    };

    Node *root;
    // recursive utility functions for use by public methods above
    //Node* getNodeFor(int value, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(int value, Node *n); // note overloading names for simplicity
    void printPreOrder(Node *n) const;    
};


#endif
