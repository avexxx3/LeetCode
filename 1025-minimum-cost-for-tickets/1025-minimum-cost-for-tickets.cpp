class Solution {
    int daysSize = 0;
    vector<int> dp;
public:
    int minCost(int day, vector<int>& days, vector<int>&costs) {
        if(day == days[daysSize - 1])
            return min(min(costs[0], costs[1]), min(costs[0], costs[2]));

        if(day > days[daysSize - 1])
            return 0;

        int i=0;
        while(day > days[i])
            i++;

        if(dp[i] != -1)
            return dp[i];

        day = days[i];
        int minR = minCost(day + 1, days, costs) + costs[0];
        minR = min(minR, minCost(day + 7, days, costs) + costs[1]);
        minR = min(minR, minCost(day + 30, days, costs) + costs[2]);

        dp[i] = minR;

        return minR;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        daysSize = days.size();
        dp.resize(daysSize, -1);
        return minCost(days[0], days, costs);
    }
};