#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count the frequency of each task
        vector<int> freq(26, 0);
        int max_freq = 0;
        
        for (char task : tasks) {
            freq[task - 'A']++;
            max_freq = max(max_freq, freq[task - 'A']);
        }
        
        // Step 2: Count how many tasks have that exact maximum frequency
        int max_count = 0;
        for (int count : freq) {
            if (count == max_freq) {
                max_count++;
            }
        }
        
        // Step 3: Apply the mathematical formula
        int calculated_length = (max_freq - 1) * (n + 1) + max_count;
        
        // Step 4: Return the maximum between the formula result and total tasks
        return max((int)tasks.size(), calculated_length);
    }
};