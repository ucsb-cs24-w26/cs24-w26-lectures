#include "Complex.h"
#include "CustomVector.h"
#include <iostream>

using namespace std;

/**
 * Lecture 2 Demo - Operator Overloading and The Rule of Three
 *
 * Part 1: Operator overloading with Complex class
 * Part 2: The Rule of Three with CustomVector class
 */

// ============================================
// PART 1: Operator Overloading
// ============================================

void demoOperatorOverloading() {
    cout << "========================================" << endl;
    cout << "  PART 1: Operator Overloading" << endl;
    cout << "========================================" << endl;
    cout << endl;

    // Create complex numbers
    Complex c1(3, 4);   // 3 + 4j
    Complex c2(1, 2);   // 1 + 2j
    cout << c1;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << endl;
    
    // Test operator+
    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;
    cout << endl;

    // Test chaining
    cout << "Chaining test: " << c1 << " + " << c2 << " = " << c3 << endl;
    cout << endl;

    // Test operator==
    if (c1 == c2) {
        cout << "c1 == c2" << endl;
    } else {
        cout << "c1 != c2" << endl;
    }
    cout << endl;
}

// ============================================
// PART 2: The Shallow Copy Problem
// ============================================

void demonstrateShallowCopyProblem() {
    cout << "========================================" << endl;
    cout << "  PART 2: The Shallow Copy Problem" << endl;
    cout << "========================================" << endl;
    cout << endl;

    cout << "Creating v1 and adding elements..." << endl;
    CustomVector v1;
    v1.push_back(42);
    v1.push_back(100);

    cout << "v1 = ";
    v1.print();
    cout << " (size=" << v1.getSize() << ", capacity=" << v1.getCapacity() << ")" << endl;
    cout << endl;

    cout << "Creating v2 as a copy of v1: CustomVector v2 = v1;" << endl;
    CustomVector v2 = v1;  // Copy constructor called! Complex v2(v1)

    cout << "v2 = ";
    v2.print();
    cout << " (size=" << v2.getSize() << ", capacity=" << v2.getCapacity() << ")" << endl;
    cout << endl;

    cout << "Now modifying v2[0] to 999..." << endl;
    v2.set(0, 999);

    cout << "v1 = ";
    v1.print();
    cout << " <-- v1[0] should not change (Shallow copy problem)" << endl;

    cout << "v2 = ";
    v2.print();
    cout << endl;
    cout << endl;

    // NOTE: When this function ends, both destructors will be called
    // If Big Three not implemented correctly → CRASH (double deletion)
    cout << "About to exit function - destructors will be called..." << endl;
    cout << "(If you see a crash, it's the double-deletion problem!)" << endl;
}

// ============================================
// PART 3: Testing Copy Assignment
// ============================================

void demonstrateCopyAssignment() {
    cout << "========================================" << endl;
    cout << "  PART 3: Copy Assignment Operator" << endl;
    cout << "========================================" << endl;
    cout << endl;

    CustomVector v1;
    v1.push_back(10);
    v1.push_back(20);

    CustomVector v2;
    v2.push_back(99);
    v2.push_back(88);
    v2.push_back(77);

    cout << "Before assignment:" << endl;
    cout << "v1 = ";
    v1.print();
    cout << endl;
    cout << "v2 = ";
    v2.print();
    cout << endl;
    cout << endl;

    cout << "Executing: v2 = v1;" << endl;
    v2 = v1;  // Copy assignment operator called!  operator=(v1, v1)
              // v2.operator=(v1);

    cout << "After assignment:" << endl;
    cout << "v1 = ";
    v1.print();
    cout << endl;
    cout << "v2 = ";
    v2.print();
    cout << " <-- v2's old data should be gone!" << endl;
    cout << endl;

    cout << "Modifying v2[0] to 999..." << endl;
    v2.set(0, 999);

    cout << "v1 = ";
    v1.print();
    cout << " <-- v1[0] changed to 999! (Shallow copy problem)" << endl;
    cout << "v2 = ";
    v2.print();
    cout << " <-- Should be [999, 20]" << endl;
    cout << endl;
}

// ============================================
// PART 4: Self-Assignment Test
// ============================================

void demonstrateSelfAssignment() {
    cout << "========================================" << endl;
    cout << "  PART 4: Self-Assignment Test" << endl;
    cout << "========================================" << endl;
    cout << endl;

    CustomVector v1;
    v1.push_back(42);
    v1.push_back(100);

    cout << "v1 = ";
    v1.print();
    cout << endl;

    cout << "Executing: v1 = v1; (self-assignment)" << endl;
    v1 = v1;  // Self-assignment!

    cout << "v1 = ";
    v1.print();
    cout << " <-- Should still be [42, 100]" << endl;
    cout << endl;

    cout << endl;
}

// ============================================
// Main Function
// ============================================

int main() {
    cout << endl;
    cout << "=======================================" << endl;
    cout << "  CS24 Lecture 2 Demo" << endl;
    cout << "  Operator Overloading & Rule of Three" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    // Part 1: Operator Overloading
    demoOperatorOverloading();

    cout << "Press Enter to continue to Part 2...";
    cin.get();
    cout << endl;

    // Part 2: Shallow Copy Problem
    demonstrateShallowCopyProblem();

    cout << "Press Enter to continue to Part 3...";
    cin.get();
    cout << endl;

    // Part 3: Copy Assignment
    demonstrateCopyAssignment();

    cout << "Press Enter to continue to Part 4...";
    cin.get();
    cout << endl;

    // Part 4: Self-Assignment
    demonstrateSelfAssignment();

    cout << "=======================================" << endl;
    cout << "  End of Demo" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    return 0;
}
