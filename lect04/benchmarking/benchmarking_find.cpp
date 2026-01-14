#include <iostream>      // For input/output (e.g., cout)
#include <vector>        // For std::vector to store data
#include <set>           // For std::set to store data in a balanced binary search tree
#include <algorithm>     // For std::find, std::binary_search, std::sort
#include <random>        // For random number generation
#include <chrono>        // For high-precision timing
#include <numeric>       // For std::accumulate to sum times
#include <limits>        // For finding min/max times
#include <cstdint>       // For uint64_t to store large timing values
#include <iomanip>       // For setprecision and fixed formatting

using namespace std;
using namespace std::chrono;

// Step 1: Helper function to generate random data
// This function creates a vector of N random integers between 1 and max_val (default 2,000,000)
// We use this to simulate real-world data for our search benchmarks
vector<int> generate_random_data(int N, int max_val = 2000000) {
    random_device rd;                           // Seed for random number generation
    mt19937 gen(rd());                          // Mersenne Twister random number generator
    uniform_int_distribution<> dis(1, max_val); // Uniform distribution for integers in [1, max_val]

    vector<int> data(N);                        // Create a vector of size N
    for (int &x : data) x = dis(gen);          // Fill the vector with random numbers
    return data;
}

// Step 2: Define the number of searches per trial
// We perform a fixed number of searches (NUM_FINDS_PER_TRIAL) in each trial to measure performance
// This helps average out noise and makes the benchmark run faster than searching N times
// Increased from 100 to 1000 to smooth out curves and reduce noise from cache/CPU variation
const int NUM_FINDS_PER_TRIAL = 1000;

// Step 3: Timing functions to measure search performance
// Each function performs NUM_FINDS_PER_TRIAL searches and returns the average time per search in nanoseconds
// We use nanoseconds for precision, as some searches (e.g., binary search) are very fast

// Linear search on an unsorted vector using std::find (O(N) complexity)
uint64_t time_find_unsorted(const vector<int>& vec, const vector<int>& keys) {
    auto start = high_resolution_clock::now();  // Record the start time
    for (int key : keys) {                      // Perform NUM_FINDS_PER_TRIAL searches
        auto it = find(vec.begin(), vec.end(), key);  // Linear search for the key
        asm volatile("");  // Prevent compiler from optimizing away the search
    }
    auto end = high_resolution_clock::now();    // Record the end time
    // Compute the total time in nanoseconds and divide by NUM_FINDS_PER_TRIAL to get average per search
    return duration_cast<nanoseconds>(end - start).count() / NUM_FINDS_PER_TRIAL;
}

// Binary search on a sorted vector using std::binary_search (O(log N) complexity)
uint64_t time_find_sorted(const vector<int>& vec, const vector<int>& keys) {
    auto start = high_resolution_clock::now();  // Record the start time
    for (int key : keys) {                      // Perform NUM_FINDS_PER_TRIAL searches
        bool found = binary_search(vec.begin(), vec.end(), key);  // Binary search for the key
        asm volatile("");  // Prevent compiler from optimizing away the search
    }
    auto end = high_resolution_clock::now();    // Record the end time
    return duration_cast<nanoseconds>(end - start).count() / NUM_FINDS_PER_TRIAL;
}

// Search in a std::set using set::find (O(log N) complexity due to balanced tree)
uint64_t time_find_set(const set<int>& s, const vector<int>& keys) {
    auto start = high_resolution_clock::now();  // Record the start time
    for (int key : keys) {                      // Perform NUM_FINDS_PER_TRIAL searches
        auto it = s.find(key);                  // Search for the key in the set
        asm volatile("");  // Prevent compiler from optimizing away the search
    }
    auto end = high_resolution_clock::now();    // Record the end time
    return duration_cast<nanoseconds>(end - start).count() / NUM_FINDS_PER_TRIAL;
}

// Step 4: Function to print statistics for each method
// This computes and prints the average, minimum, and maximum times across all trials
// Times are converted from nanoseconds to microseconds for readability
void print_stats(const string& label, const vector<uint64_t>& times) {
    uint64_t sum = accumulate(times.begin(), times.end(), 0ULL);  // Sum of all times
    uint64_t avg = sum / times.size();                           // Average time per trial
    uint64_t min_time = *min_element(times.begin(), times.end()); // Minimum time (best case)
    uint64_t max_time = *max_element(times.begin(), times.end()); // Maximum time (worst case)

    // Convert nanoseconds to microseconds with decimal precision (e.g., 100 ns = 0.1 us)
    double avg_us = avg / 1000.0;
    double min_us = min_time / 1000.0;
    double max_us = max_time / 1000.0;

    // Print the stats in the format expected by the plotting code
    cout << "  " << label << " Avg: " << fixed << setprecision(4) << avg_us << " us, Min: " 
         << fixed << setprecision(4) << min_us << " us, Max: " << fixed << setprecision(4) << max_us << " us\n";
}

// Step 5: Main function to run the benchmark
// We test three search methods (linear search, binary search, set search) for different input sizes
// The results will help us compare their performance for the three-sum problem
int main() {
    // Define the input sizes to test (1000, 10000, ..., 10000000)
    vector<int> sizes = {1000, 10000, 100000, 1000000};//, 10000000};
    int trials = 500;  // Number of trials to run for each size to average out noise 

    // Loop over each input size
    for (int N : sizes) {
        cout << "Data size: " << N << "\n";  // Print the current input size

        // Generate random data of size N
        vector<int> data = generate_random_data(N);

        // Create a sorted copy of the data for binary search
        vector<int> sorted_data = data;
        sort(sorted_data.begin(), sorted_data.end());

        // Create a std::set from the data for set search
        set<int> data_set(data.begin(), data.end());

        // Initialize vectors to store the timing results for each method
        vector<uint64_t> unsorted_times;  // Times for linear search (std::find)
        vector<uint64_t> sorted_times;    // Times for binary search (std::binary_search)
        vector<uint64_t> set_times;       // Times for set search (std::set::find)

        // Set up random number generation to pick keys for searching
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, N - 1);

        // Pre-generate keys for each trial (NUM_FINDS_PER_TRIAL keys per trial)
        // We create 'trials' sets of keys, each with NUM_FINDS_PER_TRIAL keys, to ensure consistency across methods
        vector<vector<int>> trial_keys(trials, vector<int>(NUM_FINDS_PER_TRIAL));
        for (int t = 0; t < trials; ++t) {
            for (int i = 0; i < NUM_FINDS_PER_TRIAL; ++i) {
                trial_keys[t][i] = data[dis(gen)];  // Pick a random existing key from the data
            }
        }

        // Run the benchmark for each trial
        for (int t = 0; t < trials; ++t) {
            const auto& keys = trial_keys[t];  // Get the keys for this trial

            // Warm-up to stabilize cache and reduce variability in measurements
            // We perform the searches once without timing to ensure the CPU and cache are ready
            for (int key : keys) {
                auto result_unsorted = find(data.begin(), data.end(), key);  // Warm-up linear search
                auto result_sorted = binary_search(sorted_data.begin(), sorted_data.end(), key);  // Warm-up binary search
                auto result_set = data_set.find(key);  // Warm-up set search
            }

            // Time each search method and store the results
            unsorted_times.push_back(time_find_unsorted(data, keys));  // Time linear search
            sorted_times.push_back(time_find_sorted(sorted_data, keys));  // Time binary search
            set_times.push_back(time_find_set(data_set, keys));  // Time set search
        }

        // Print the statistics for each method
        print_stats("Unsorted Vector Find Time", unsorted_times);
        print_stats("Sorted Vector Find Time", sorted_times);
        print_stats("std::set Find Time", set_times);
        cout << "-----------------------------\n";  // Separator between sizes
    }

    return 0;
}