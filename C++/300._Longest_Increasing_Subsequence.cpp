class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int x)
    {
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> sub(nums.size());
        int size = 0;

        for (const auto& num : nums)
        {
            int l = 0, r = size;

            l = binarySearch(sub, l, r, num);

            sub[l] = num;
            size = max(size, l + 1);
        }

        return size;
    }
};