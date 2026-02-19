#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

/*
 * Activity: Web Traffic Analysis
 *
 * You're a software engineer at Amazon. Here's a log of IP addresses
 * that visited the site. Your boss wants answers.
 */

vector<string> traffic_log = {
    "192.168.1.1", "10.0.0.5", "192.168.1.1", "172.16.0.1",
    "10.0.0.5", "192.168.1.1", "8.8.8.8", "10.0.0.5",
    "192.168.1.1", "172.16.0.1", "192.168.1.1", "8.8.8.8",
    "192.168.1.1", "10.0.0.5", "203.0.113.42"
};
// Data structures for fast insertion and fast search: BST: std::set 
// insert: O(log n), search : O(log n)
// hashtable: unordered_set: insertions O(1) --- average , search -- O(1) --average
// ============================================================
// Part A: How many unique visitors?
// Use: unordered_set
// Expected output: 5
// ============================================================
int uniqueVisitors(const vector<string>& log) {
    // TODO: Your code here
    unordered_set<string> unique_ips; // hashtable

    for(auto ip : log){
        unique_ips.insert(ip); // O(1) average!!!
    }

    return unique_ips.size();
}

// ============================================================
// Part B: How many times did each IP visit?
// Use: unordered_map
// Expected output:
//   192.168.1.1: 6
//   10.0.0.5: 4
//   172.16.0.1: 2
//   8.8.8.8: 2
//   203.0.113.42: 1
// ============================================================
unordered_map<string, int> countVisits(const vector<string>& log) {
    // TODO: Your code here
    unordered_map<string, int> ipcounts;
    // ipcounts["1.0.0.1"] = 1;
    for( auto ip : log){
        ipcounts[ip]++; // if an ip does not exist, insert the ip (key) with count 0 (value)
        // O(1)    : average
        }

    return ipcounts;
}

// ============================================================
// Part C: Which IP visited the most?
// Use: linear scan over the counts map
// Expected output: {"192.168.1.1", 6}
// ============================================================
pair<string, int> mostFrequent(const unordered_map<string, int>& counts) {
    // TODO: Your code here
    // Hint: Scan through counts to find the max

    return {"", 0};
}

// ============================================================
// Part D (Challenge): Find the top K most frequent visitors
// Use: priority_queue 
// Expected output for k = 3:
//   192.168.1.1: 6
//   10.0.0.5: 4
//   172.16.0.1: 2  (or 8.8.8.8: 2, tie)
// ============================================================
vector<pair<string, int>> topKVisitors_v1(const unordered_map<string, int>& counts, int k) {

    // Priority Queues - self sorting data structure (partially sorted order)
    // max - heap, max element is on the top
    // Approach 1: Insert all n elements from the hashtable into a PQ (max-heap), pop k times
    priority_queue<pair<int, string>> max_heap;
    // standard comparison in a PQ of pair objects is based on compaing pair.first
    for (auto [ip, count] : counts){
        max_heap.push({count, ip});  // O(log n)
    }
    // Total : O(n log n)

    vector<pair<string, int>> top_k;
    // pop k times into the top_k vector
    while(!max_heap.empty() && k > 0){
        auto [count, ip] = max_heap.top(); // O(1)
        // int count = max_heap.top().first;
        // string ip  = max_heap.top().second;

        top_k.push_back({ip, count}); // O(1)
        max_heap.pop(); // O(log n)
        k--;
    }
    // Total for while loop : O(k log n)
    // Total overall :  O(n logn + k logn ) = O(n log n)
    return top_k;
}

// I want to write own way of comparing elements and tell the priority queue --- use my appraoch 
// Functor! Struct that acts like a function

struct CompareCountLess{
    // overload the function operator 
    bool operator()( pair<string, int> a , pair<string, int> b ){
        return a.second < b.second;
    }

};
// Usage: CompareCount cmp;
// cmp(a, b); return true, then the PQ infers that a has lower priority than b.

vector<pair<string, int>> topKVisitors(const unordered_map<string, int>& counts, int k) {

    // Priority Queues - self sorting data structure (partially sorted order)
    // max - heap, max element is on the top
    // Approach 2: Batch insert all n elements from the hashtable into a PQ (max-heap)-- using heapify, pop k times
    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareCountLess> max_heap(counts.begin(), counts.end());
    // Build a heap using heapify --- O(n) 
    vector<pair<string, int>> top_k;
    // pop k times into the top_k vector
    while(!max_heap.empty() && k > 0){
        top_k.push_back(max_heap.top()); // O(1)
        max_heap.pop(); // O(log n)
        k--;
    }
    // Total for while loop : O(k log n)
    // Total overall :  O(n + k logn )
    return top_k;

}



// ============================================================
// Part E: Flag suspicious IPs
// Return IPs that visited more than `threshold` times
// ============================================================
vector<string> flagSuspicious(const unordered_map<string, int>& counts, int threshold) {
    // TODO: Your code here

    return {};
}

// ============================================================
// Test your solutions
// ============================================================
int main() {
    cout << "=== Part A: Unique Visitors ===" << endl;
    cout << "Count: " << uniqueVisitors(traffic_log) << endl;
    cout << "Expected: 5" << endl << endl;

    cout << "=== Part B: Visit Counts ===" << endl;
    auto counts = countVisits(traffic_log);
    for (const auto& [ip, count] : counts) {
        cout << ip << ": " << count << endl;
    }
    cout << endl;

    // Parts C, D, E reuse the counts map from Part B
    cout << "=== Part C: Most Frequent ===" << endl;
    auto [top_ip, top_count] = mostFrequent(counts);
    cout << "Top IP: " << top_ip << " with " << top_count << " visits" << endl;
    cout << "Expected: 192.168.1.1 with 6 visits" << endl << endl;

    cout << "=== Part D: Top 3 Visitors ===" << endl;
    auto top3 = topKVisitors(counts, 3);
    for (const auto& [ip, count] : top3) {
        cout << ip << ": " << count << endl;
    }
    cout << endl;

    cout << "=== Part E: Suspicious IPs (threshold=5) ===" << endl;
    auto suspicious = flagSuspicious(counts, 5);
    for (const auto& ip : suspicious) {
        cout << "SUSPICIOUS: " << ip << endl;
    }
    cout << "Expected: 192.168.1.1" << endl;

    return 0;
}
