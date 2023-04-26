class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int maxProd = 1;
        int minProd = 1;
        int best = INT_MIN;

        for (const auto& num : nums)
        {
            if (num < 0)
                swap(maxProd, minProd);
            
            maxProd = max(maxProd * num, num);
            minProd = min(minProd * num, num);

            best = max(best, maxProd);
        }

        return best;
    }
};