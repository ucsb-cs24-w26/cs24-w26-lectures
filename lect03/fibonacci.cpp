#include <iostream>
#include <cstdlib>
#include <chrono>    // For getting precise timing data
#include <iomanip>
#include <vector>

using namespace std;

double Fib(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return Fib(n - 1) + Fib(n - 2);
}

double FibIterative(int n) {
    if (n < 2) return 1;
    vector<double> arr(n + 1);
    arr[0] = arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage : " << argv[0] << " i/r number" << endl;
        exit(1);
    }

    int n = atoi(argv[2]);
    string algo = string(argv[1]);
    cout.setf(ios::fixed);
    double result;

    for (int i = 0; i <= n; i++) {
        // Start timing with chrono
        auto start = chrono::high_resolution_clock::now();

        if (algo == "r") {
            result = Fib(i);
        } else {
            result = FibIterative(i);
        }

        // End timing
        auto end = chrono::high_resolution_clock::now();

        // Calculate duration in microseconds (as a double)
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        double time_taken = duration.count() / 1000.0;  // Convert to milliseconds

        // Output formatting
        cout.width(10);
        cout.precision(0);
        cout << " Fibonacci of " << setw(2) << i << " is: " << setw(45) << result;
        cout.precision(2);

        if (time_taken < 1.0) {
            cout << " Time : " << setw(4) << time_taken * 1000 << " microsec" << endl;  // Convert back to microsec if < 1ms
        } else {
            cout << " Time : " << setw(4) << time_taken << " ms" << endl;
        }
    }

    return 0;
}