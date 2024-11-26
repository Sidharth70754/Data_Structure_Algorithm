class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end()); // Use max element as upper bound

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canEatInTime(piles, mid, h)) 
                right = mid - 1; // Try smaller speed
            else 
                left = mid + 1; // Increase speed
        }
        return left;
    }

private:
    bool canEatInTime(vector<int>& piles, int k, int h) {
        long long hours = 0; // Use long long to avoid overflow
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // Efficient ceiling division
            if (hours > h) return false; // Early exit if hours exceed h
        }
        return hours <= h;
    }
};
