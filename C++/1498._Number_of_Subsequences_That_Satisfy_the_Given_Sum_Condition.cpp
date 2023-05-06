class Solution {
public:
    int numSubseq(vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> pows(n, 1);
        int ans = 0, mod = 1000000007;
        int l = 0, r = n - 1;

        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;

        while (l <= r)
        {
            if (nums[l] + nums[r] <= target)
                ans = (ans + pows[r - l++]) % mod;
            else
                --r;
        }

        return ans;
    }
};