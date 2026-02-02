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
                    }
                }
            } 
            return result;     
        }
    
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n  = temperatures.size(); 
            vector<int> result(n, 0); 
            stack<int> days;  
            for (int i = n - 1; i >= 0 ; i--){ 
                





                
            }
            return result;   
    
        }
         
    };