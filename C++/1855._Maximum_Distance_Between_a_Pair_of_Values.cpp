class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int maxDist = 0;

        for (int i = 0; i < n; ++i)
        {
            int l = i;
            int r = m - 1;

            while (l < r)
            {
                int mid = l + (r - l + 1) / 2;

                if (nums1[i] <= nums2[mid] && i <= mid)
                    l = mid;
                else
                    r = mid - 1;
            }

            maxDist = max(maxDist, l - i);
        }

        return maxDist;
    }
};