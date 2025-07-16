class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long total = 0, curr = 0;
        int start;

        for(int i = 0; i < gas.size(); i++){
            long diff = gas[i] - cost[i];
            curr += diff;
            total += diff;

            if(curr < 0) {
                start = i + 1;
                curr = 0;
            }
        } 
        return  total >= 0 ? start : -1;
    }
};