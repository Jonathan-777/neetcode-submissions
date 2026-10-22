class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Allocate the scratchpad memory only once
        vector<int> temp(nums.size());
        mergesort(nums, temp, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergesort(vector<int>& A, vector<int>& temp, int left, int right) {
        // Base case: 0 or 1 element
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        // Recursively sort left and right halves
        mergesort(A, temp, left, mid);
        mergesort(A, temp, mid + 1, right);

        // Merge the two sorted halves using the temp buffer
        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (A[i] <= A[j]) {
                temp[k++] = A[i++];
            } else {
                temp[k++] = A[j++];
            }
        }

        // Copy remaining elements of left half (if any)
        while (i <= mid) {
            temp[k++] = A[i++];
        }

        // Copy remaining elements of right half (if any)
        while (j <= right) {
            temp[k++] = A[j++];
        }

        // Copy sorted sub-array back into the original array A
        for (int idx = left; idx <= right; ++idx) {
            A[idx] = temp[idx];
        }
    }
};