// Lecture 6: std::set and iterators
#include <set>
#include<iostream>

int main(int argc, char const *argv[])
{
    std::set<int> s = {30, 25, 20, 10, 40, 60, 35};
    auto it = s.begin();
    while(it != s.end()){
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    for (auto e : s){
        std::cout << e << " ";
    }
    std::cout << std::endl;
    for (auto it = s.begin(); it!=s.end(); it++){
         std::cout << *it << " ";
    }
    return 0;
}
