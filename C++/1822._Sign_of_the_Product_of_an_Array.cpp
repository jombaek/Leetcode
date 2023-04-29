class Solution {
public:
    int arraySign(vector<int>& nums)
    {
        int countNegative = 0;

        for (const auto& num : nums)
        {
            if (num == 0)
                return 0;
            
            if (num < 0)
                countNegative++;
        }

        return countNegative % 2 == 0 ? 1 : -1;
    }
};