//dailytemps.cpp
//solution to leet code problem: https://leetcode.com/problems/daily-temperatures/
#include <vector>
#include <stack>
using namespace std;
class Solution {
    public:
        vector<int> dailyTemperatures_0(vector<int>& temperatures) {
            int n = temperatures.size();
            vector<int> result(n, 0);
            for (int i = n - 1; i >= 0 ; i--){ 
                for(int j = i + 1; j < temperatures.size(); j++){
                    if(temperatures[j] > temperatures[i]){
                        result[i] = j - i;
                        break;
                    }
                }
            } 
            return result;     
        }
    
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n = temperatures.size(); //O(1)
            vector<int> result(n, 0); //O(n)
            stack<int> s; //O(1)
            for (int i = n - 1; i >= 0; i--){
                while( !s.empty() && temperatures[s.top()] <= temperatures[i]){
                    s.pop(); // How many times will we pop() over all? 
                            // Overall: each value is popped no more than once. 
                            // Since n values are pushed in, overall no more than n pops
                                                                            // Overall ---> O(n)

                }
                if(!s.empty()){
                    result[i] = s.top() - i;//O(1) per iteration
                }
                s.push(i); // Each value is push in once per iteration O(1) ---> Total O(n) 
            }
            return result;
            
        }
         
    };