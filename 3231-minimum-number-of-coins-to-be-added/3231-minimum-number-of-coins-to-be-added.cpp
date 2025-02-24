class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        int curr_sum = 0;
        int i = 0;
        while(curr_sum < target){
            if(i < coins.size() && coins[i] <= (curr_sum +1)){
                curr_sum += coins[i];
                i++;
            }
            else {
                ans++;
                curr_sum += curr_sum + 1;
            }
        }
        return ans;
    }
};