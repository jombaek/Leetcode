class Solution {
public:
    int getMaxLen(vector<int>& nums)
    {
        int n = nums.size();
        int positive = 0, negative = 0;
        int ans = 0;

        for (const auto& num : nums)
        {
            if (num == 0)
            {
                positive = 0;
                negative = 0;
            }
            else if (num > 0)
            {
                positive++;
                negative = negative == 0 ? 0 : negative + 1;
            }
            else
            {
                int tmp = positive;
                positive = negative == 0 ? 0 : negative + 1;
                negative = tmp + 1;
            }

            ans = max(ans, positive);
        }

        return ans;
    }
};