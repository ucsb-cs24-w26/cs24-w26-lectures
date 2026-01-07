#include "CustomVector.h"

// Constructor - allocates initial capacity
CustomVector::CustomVector(size_t initialCapacity) : data(nullptr), size(0), capacity(initialCapacity) {
    data = new int[capacity];
}

// Add element to end
void CustomVector::push_back(int val) {
    // Check if we need more space
    if (size >= capacity) {
        resize();
    }

    // Add the element
    data[size] = val;
    size++;
}

// Get element at index with bounds checking
int CustomVector::get(size_t index) const {
    if (index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

// Set element at index with bounds checking
void CustomVector::set(size_t index, int val) {
    if (index >= size) {
        throw out_of_range("Index out of bounds");
    }
    data[index] = val;
}

// Print all elements
void CustomVector::print() const {
    cout << "[";
    for (size_t i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

// Helper: Double the capacity when full
void CustomVector::resize() {
    capacity *= 2;

    // Allocate new larger array
    int* newData = new int[capacity];

    // Copy existing elements
    for (size_t i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    // Delete old array
    delete[] data;

    // Update pointer
    data = newData;
}

// ============================================
// THE BIG THREE - INSTRUCTOR WILL LIVE-CODE!
// ============================================

// Destructor - Clean up dynamic memory
// TODO: Instructor will implement this LIVE!
//
// Key teaching points:
// 1. We MUST delete[] the array we allocated in constructor
// 2. If we don't, we get a MEMORY LEAK
// 3. Use delete[] (not delete) for arrays
CustomVector::~CustomVector() {
    // INSTRUCTOR WILL LIVE-CODE THIS!
    // Placeholder - REMOVE THIS WHEN IMPLEMENTING:
    //cout << "WARNING: Destructor not implemented - memory leak!" << endl;
    delete [] data;
}

// Copy constructor - Make a DEEP COPY
// TODO: Instructor will implement this LIVE!
//
// Called when:
// - CustomVector v2 = v1;
// - Passing by value: void foo(CustomVector v)
// - Returning by value: CustomVector foo() { ... return v; }
//
// Key teaching points:
// 1. Default copy constructor does SHALLOW COPY (just copies pointers!)
// 2. We need DEEP COPY (allocate NEW array, copy values)
// 3. Otherwise both vectors share same array → DISASTER!
CustomVector::CustomVector(const CustomVector& other)
    : data(nullptr), size(0), capacity(0) {
    // INSTRUCTOR WILL LIVE-CODE THIS!
    //
    // Strategy:
    // 1. Copy size and capacity from other
    // 2. Allocate NEW array with same capacity
    // 3. Copy all elements from other's array to our array

    // Placeholder - REMOVE THIS WHEN IMPLEMENTING:
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    std::copy(other.data, other.data + size, data);
    //cout << "WARNING: Copy constructor not implemented - shallow copy!" << endl;
}

// Copy assignment operator - Clean up old, then deep copy
// TODO: Instructor will implement this LIVE!
//
// Called when:
// - v2 = v1; (where v2 already exists)
//
// Key teaching points:
// 1. Object already exists (may have data that needs cleanup!)
// 2. Must handle self-assignment: v1 = v1;
// 3. Pattern: Clean up old data + Copy from other
// 4. Return *this for chaining: v1 = v2 = v3;
CustomVector& CustomVector::operator=(const CustomVector& other) {
    if(this == &other){
        return *this;
    }
    delete [] data;
    data = new int[other.capacity];
    capacity = other.capacity;
    size = other.size;
    std::copy(other.data, other.data + size, data);
    return *this;

}
