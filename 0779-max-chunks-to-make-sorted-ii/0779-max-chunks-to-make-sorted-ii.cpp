class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        long long runningSum = 0, expectedSum = 0; // Use long long to avoid overflow
        int chunks = 0;
        vector<int> n = arr;
        sort(n.begin(), n.end());
        for (int i = 0; i < arr.size(); i++) {
            runningSum += n[i];
            expectedSum += arr[i];
            if (runningSum == expectedSum)
                chunks++;
        }
        return chunks;
    }
};
