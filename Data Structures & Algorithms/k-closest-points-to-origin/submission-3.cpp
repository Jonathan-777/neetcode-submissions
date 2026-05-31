class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        nth_element(points.begin(), points.begin() + k, points.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return (pow(a[0] ,2) + pow(a[1] ,2)) < (pow(b[0] ,2) + pow(b[1] ,2) ) ;
            });
        
        // The first k elements are now the closest points (though not necessarily sorted among themselves)
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

/*
How C++ optimizes it (Introselect):C++'s std::nth_element uses a hybrid algorithm called Introselect (Introspective Selection).It starts by doing standard Quickselect.It tracks how deep the recursion is going.
If it detects that Quickselect is having a "bad day" (i.e., making terrible pivot choices and edging towards that $O(N^2)$ worst-case), it automatically bails out and switches to a different algorithm called
HeapSelect, which has a strict worst-case guarantee of $O(N \log N)$.*/