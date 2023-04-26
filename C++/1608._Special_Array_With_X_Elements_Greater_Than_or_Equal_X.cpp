class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n;
        
        sort(nums.begin(), nums.end(), greater<>());

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] <= mid)
                r = mid;
            else
                l = mid + 1;
        }

        return (l < n && l == nums[l]) ? -1 : l;
    }
};