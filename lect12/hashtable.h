#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <iomanip>
#include <cstdint>
#include <sstream>

#ifndef HASHATABLE_H
#define HASHATABLE_H

uint32_t ip_to_uint32(const std::string& ip);
std::string uint32_to_ip(uint32_t ip);

// Hash table with separate chaining
class HashTable {
private:
    std::vector<std::list<uint32_t>> buckets; // Buckets as vector of linked lists
    size_t m; // Number of buckets
    size_t n; // Number of keys

    // Simple modular hash function: h(x) = x mod m
    size_t hash(uint32_t key) const {
        return key % m;
    }

public:
    HashTable(size_t table_size):m(table_size), n(0) {
        buckets.resize(m);
    }

    // Insert a key
    void insert(uint32_t key) {
        size_t index = hash(key);
        buckets[index].push_back(key);
        n++;
    }

    // Search for a key
    bool find(uint32_t key) const {
        size_t index = hash(key);
        for(auto e : buckets[index]){
            if (e == key) return true;
        }
        return false;
    }


    // Visualize the hash table
    void visualize() const {
        std::cout << "Hash Table (m = " << m << ", n = " << n << ", load factor = " 
                  << std::fixed << std::setprecision(2) << (double)n / m << "):\n";
        for (size_t i = 0; i < m; ++i) {
            std::cout << "Bucket " << std::setw(2) << i << ": ";
            if (buckets[i].empty()) {
                std::cout << "[]";
            } else {
                std::cout << "[";
                bool first = true;
                for (const auto& key : buckets[i]) {
                    if (!first) std::cout << " -> ";
                    std::cout << uint32_to_ip(key); // Print as IP address
                    first = false;
                }
                std::cout << "]";
            }
            std::cout << "\n";
        }
    }

    // Get statistics
    void stats() const {
        size_t max_size = 0;
        double avg_size = 0.0;
        size_t non_empty = 0;
        for (const auto& bucket : buckets) {
            if (!bucket.empty()) {
                non_empty++;
                avg_size += bucket.size();
                max_size = std::max(max_size, bucket.size());
            }
        }
        avg_size = non_empty ? avg_size / m : 0.0;
        std::cout << "Stats:\n";
        std::cout << "  Non-empty buckets: " << non_empty << "\n";
        std::cout << "  Average bucket size: " << std::fixed << std::setprecision(2) << avg_size << "\n";
        std::cout << "  Maximum bucket size: " << max_size << "\n";
    }
};
// Convert IP address (string) to uint32_t
uint32_t ip_to_uint32(const std::string& ip) {
    uint32_t result = 0;
    size_t start = 0;
    for (int i = 0; i < 4; ++i) {
        size_t end = ip.find('.', start);
        if (end == std::string::npos) end = ip.length();
        result = (result << 8) + std::stoi(ip.substr(start, end - start));
        start = end + 1;
    }
    return result;
}

// Convert uint32_t to IP address (string)
std::string uint32_to_ip(uint32_t ip) {
    std::ostringstream oss;
    oss << ((ip >> 24) & 0xFF) << "."
        << ((ip >> 16) & 0xFF) << "."
        << ((ip >> 8) & 0xFF) << "."
        << (ip & 0xFF);
    return oss.str();
}
#endif