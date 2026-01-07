#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H

#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * CustomVector - A simple dynamic array implementation
 *
 * This class demonstrates THE RULE OF THREE:
 * - Destructor
 * - Copy constructor
 * - Copy assignment operator
 *
 * Why? Because CustomVector manages DYNAMIC MEMORY (int* data)
 */
class CustomVector {
public:
    // Constructor - creates empty vector
    CustomVector(size_t initialCapacity = 4);

    // Add element to end of vector
    void push_back(int val);

    // Get element at index (with bounds checking)
    int get(size_t index) const;

    // Set element at index (with bounds checking)
    void set(size_t index, int val);

    // Get current number of elements
    size_t getSize() const { return size; }

    // Get current capacity
    size_t getCapacity() const { return capacity; }

    // Print all elements
    void print() const;

    // ============================================
    // THE BIG THREE - Instructor will demonstrate!
    // ============================================

    // Destructor - MUST clean up dynamic memory
    // TODO: Instructor will implement this LIVE!
    ~CustomVector();

    // Copy constructor - MUST make deep copy
    // Called when: CustomVector v2 = v1;
    // TODO: Instructor will implement this LIVE!
    CustomVector(const CustomVector& other);

    // Copy assignment operator - MUST make deep copy
    // Called when: v2 = v1; (where v2 already exists)
    // TODO: Instructor will implement this LIVE!
    CustomVector& operator=(const CustomVector& other);

private:
    int* data;          // Dynamic array
    size_t size;        // Number of elements currently stored
    size_t capacity;    // Total allocated space

    // Helper function to expand capacity when needed
    void resize();
};

#endif
