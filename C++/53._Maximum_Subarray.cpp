class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        int maxSum = nums[0];
        int curSum = nums[0];

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > curSum + nums[i])
                curSum = nums[i];
            else
                curSum += nums[i];
            
            if (curSum > maxSum)
                maxSum = curSum;
        }

        return maxSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        int maxSum = nums[0];

        dp[0] = nums[0];
        
        for (int i = 1; i < n; ++i)
        {
            dp[i] = max(dp[i -1] + nums[i], nums[i]);

            if (dp[i] > maxSum)
                maxSum = dp[i];
        }

        return maxSum;
    }
};