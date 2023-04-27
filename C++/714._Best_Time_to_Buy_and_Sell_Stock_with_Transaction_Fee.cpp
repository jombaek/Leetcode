class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int free = 0;
        int hold = -prices[0];

        for (const auto& price : prices)
        {
            int tmp = free;
            free = max(free, hold + price - fee);
            hold = max(hold, tmp - price);
        }

        return free;
    }
};