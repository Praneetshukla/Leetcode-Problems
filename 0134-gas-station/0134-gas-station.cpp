class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        
        if (totalGas < totalCost) {
            return -1;
        }

        int tank = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i]; // Accumulate leftover fuel
            if (tank < 0) {
                tank = 0;
                index = i + 1; // Cannot reach from current start, try next
            }
        }

        return index;
    }
};