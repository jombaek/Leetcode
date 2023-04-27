class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int buy = INT_MIN;
        int cell = 0;
        int prevCell = 0;

        for (const auto& price : prices)
        {
            int tmp = buy;
            buy = max(buy, prevCell - price);
            prevCell = cell;
            cell = max(cell, tmp + price);
        }

        return cell;
    }
};