class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n);

        dp[0] = nums[0];

        for (int i = 1; i < n; ++i)
        {
            if (dp[i - 1] < i)
                return false;
            
            dp[i] = max(dp[i - 1], i + nums[i]);

            if (dp[i] >= n - 1)
                return true;
        }

        return true;
    }
};