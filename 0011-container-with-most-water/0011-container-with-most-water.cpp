class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            int width = right - left;
            int ht = min(height[left], height[right]);
            int currentwater = width * ht;
            maxwater = max(maxwater, currentwater);

            (height[left] < height[right]) ? left++ : right--;
        }
        return maxwater;
    }
};
