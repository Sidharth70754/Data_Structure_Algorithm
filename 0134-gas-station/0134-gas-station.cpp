class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0;
        int current_tank = 0, start = 0;

        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            current_tank += gas[i] - cost[i];
            
            // If the tank is negative, reset the start and current_tank
            if (current_tank < 0) {
                start = i + 1; // Move start to the next station
                current_tank = 0;
            }
        }

        // If total gas is less than total cost, return -1
        return (total_gas >= total_cost) ? start : -1;
    }
};
