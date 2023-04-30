// DP O(n) time and space
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();

        if (n < 3)
            return 0;
        
        vector<int> dp(n);

        if (nums[2] - nums[1] == nums[1] - nums[0])
            dp[2] = 1;
        
        int count = dp[2];

        for (int i = 3; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] += dp[i - 1] + 1;
            
            count += dp[i];
        }

        return count;
    }
};

// DP constant space
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();

        if (n < 3)
            return 0;
        
        int count = 0, diff = 0, ind = 0;
        int prevDiff = nums[1] - nums[0];
        
        for (int i = 2; i < n; ++i)
        {
            diff = nums[i] - nums[i - 1];

            if (diff == prevDiff)
                ind++;
            else
            {
                prevDiff = diff;
                ind = 0;
            }
            
            count += ind;
        }

        return count;
    }
};