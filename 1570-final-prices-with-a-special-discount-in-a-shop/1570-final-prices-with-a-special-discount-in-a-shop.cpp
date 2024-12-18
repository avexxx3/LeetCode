class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int i=0; i<prices.size(); i++) {
            if(i + 1 >= prices.size())
                break;

            for(int j= i + 1; j < prices.size(); j++)
                if(prices[i] >= prices[j]) {
                    prices[i] -= prices[j];
                    break;
                }
        }

        return prices;
    }
};