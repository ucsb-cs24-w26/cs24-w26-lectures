#include "hashtable.h"
#include <iostream>
#include <random>

uint32_t generate_ip(std::mt19937& gen, bool unif_rnd, size_t m) {
    if (!unif_rnd) {
        // Generate an integer multiple of m
        uint32_t ip = (gen() % (UINT32_MAX / m)) * m;
        return ip;
    } else {
        // Generate standard random IP
        std::uniform_int_distribution<int> octet_dist(0, 255);
        std::ostringstream oss;
        oss << octet_dist(gen) << "." << octet_dist(gen) << "."
            << octet_dist(gen) << "." << octet_dist(gen);

        // oss << "0.0.0."<< octet_dist(gen);
        return ip_to_uint32(oss.str());
    }
}

int main() {
    // Init RNG
    std::random_device rd;
    std::mt19937 gen(rd());

    // Hash table setup
    size_t m = 20;
    size_t n = 20;
    HashTable ht(m);
   

    // Option: use multiples of m or not
    bool uniform_random_ip = true;
    auto key = 10;
    std::cout << "Inserting " << n << (uniform_random_ip ?" uniformly random IPs:\n" : " IPs are multiples of m:\n");
    for (int i = 0; i < n; i++) {
        uint32_t ip = generate_ip(gen, uniform_random_ip, m);
        std::string ip_str = uint32_to_ip(ip);
        ht.insert(ip);
        std::cout << "Inserted IP: IP String: " << std::setw(15) << std::left << ip_str
                  << " | IP Integer: " << std::setw(10) << ip << "\n";
        key = ip;
    }
    
    ht.visualize();
    std::cout << " Is " << uint32_to_ip(key) << " in HT ? " << std::boolalpha << ht.find(key) << std::endl;
    ht.stats();
    return 0;
}
