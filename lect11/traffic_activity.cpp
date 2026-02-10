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

// ============================================================
// Part A: How many unique visitors?
// Use: unordered_set
// Expected output: 5
// ============================================================
int uniqueVisitors(const vector<string>& log) {
    // TODO: Your code here


    return 0;
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


    return {};
}

// ============================================================
// Part C: Which IP visited the most?
// Use: unordered_map + linear scan
// Expected output: {"192.168.1.1", 6}
// ============================================================
pair<string, int> mostFrequent(const vector<string>& log) {
    // TODO: Your code here
    // Hint: First count visits, then scan for max

    return {"", 0};
}

// ============================================================
// Part D: Find the top K most frequent visitors
// Use: unordered_map + priority_queue (min-heap of size k)
// Expected output for k=3:
//   192.168.1.1: 6
//   10.0.0.5: 4
//   172.16.0.1: 2  (or 8.8.8.8: 2, tie)
// ============================================================
vector<pair<string, int>> topKVisitors(const vector<string>& log, int k) {
    // TODO: Your code here
    // Hint 1: First count visits with unordered_map
    // Hint 2: Use a min-heap (smallest on top) of size k
    //         - If heap size < k, push
    //         - If current count > heap top, pop and push
    // Hint 3: For min-heap of pairs ordered by count:
    //         auto cmp = [](auto& a, auto& b) { return a.second > b.second; };
    //         priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq(cmp);

    return {};
}

// ============================================================
// Part E (Challenge): Flag suspicious IPs
// Return IPs that visited more than `threshold` times
// ============================================================
vector<string> flagSuspicious(const vector<string>& log, int threshold) {
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

    cout << "=== Part C: Most Frequent ===" << endl;
    auto [top_ip, top_count] = mostFrequent(traffic_log);
    cout << "Top IP: " << top_ip << " with " << top_count << " visits" << endl;
    cout << "Expected: 192.168.1.1 with 6 visits" << endl << endl;

    cout << "=== Part D: Top 3 Visitors ===" << endl;
    auto top3 = topKVisitors(traffic_log, 3);
    for (const auto& [ip, count] : top3) {
        cout << ip << ": " << count << endl;
    }
    cout << endl;

    cout << "=== Part E: Suspicious IPs (threshold=5) ===" << endl;
    auto suspicious = flagSuspicious(traffic_log, 5);
    for (const auto& ip : suspicious) {
        cout << "SUSPICIOUS: " << ip << endl;
    }
    cout << "Expected: 192.168.1.1" << endl;

    return 0;
}
