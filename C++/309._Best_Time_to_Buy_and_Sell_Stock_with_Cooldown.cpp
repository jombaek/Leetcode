class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int buy = INT_MIN;
        int cell = 0;
        int prevBuy;
        int prevCell = 0;

        for (const auto& price : prices)
        {
            prevBuy = buy;
            buy = max(buy, prevCell - price);
            prevCell = cell;
            cell = max(cell, prevBuy + price);
        }

        return cell;
    }
};