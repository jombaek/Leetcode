class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] <= nums[r])
                r = mid;
            else
                l = mid + 1;
        }

        int rot = l;
        l = 0, r = n - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int realMid = (mid + rot) % n;

            if (nums[realMid] == target)
                return realMid;
            else if (nums[realMid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }
};