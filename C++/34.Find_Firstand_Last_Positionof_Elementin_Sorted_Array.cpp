class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        vector<int> ans(2, -1);

        while (l < r)
        {
            mid = l + (r - l) / 2;

            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }

        if (l < n && nums[l] == target)
            ans[0] = l;
        else
            return ans;

        r = n - 1;

        while (l < r)
        {
            mid = l + (r - l + 1) / 2;

            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        
        ans[1] = r;

        return ans;
    }
};