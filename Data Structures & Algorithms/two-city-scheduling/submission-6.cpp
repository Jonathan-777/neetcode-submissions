
class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        // Sort the vector by the relative cost difference: (costA - costB)
        std::sort(costs.begin(), costs.end(), 
            [](const std::vector<int>& a, const std::vector<int>& b) {
                return (a[0] - a[1]) < (b[0] - b[1]);
            });

        int total_cost = 0;
        int n = costs.size()/2;// half of half

        // The first n elements have the lowest relative cost for City A
        // The remaining n elements are optimal for City B
        for (int i = 0; i < n; ++i) {
            total_cost += costs[i][0];       // Add cost for City A
            total_cost += costs[i + n][1];   // Add cost for City B
        }

        return total_cost;
    }
};