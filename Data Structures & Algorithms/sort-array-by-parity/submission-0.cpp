class Solution {
public:
    struct st{
        bool operator()(int a, int b){
            // return ( a % 2 == 0) ? a : b;
            return (a % 2 != 0) && (b % 2 == 0);
        }
    };
    vector<int> sortArrayByParity(vector<int>& nums) {
        priority_queue<int, vector<int> , st> pq;

        for(auto num : nums){
            pq.push(num);
        }
        nums.clear();

        while(!pq.empty()){
            nums.push_back(pq.top());
            pq.pop();
        }
        return nums;
    }
};