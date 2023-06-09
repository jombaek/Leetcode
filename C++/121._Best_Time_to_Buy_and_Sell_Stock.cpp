class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int l = 0;
        int r = 1;
        int maxProfit = 0;

        while (r < n)
        {
            if (prices[l] < prices[r])
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            else
                l = r;
            ++r;
        }

        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); ++i)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};