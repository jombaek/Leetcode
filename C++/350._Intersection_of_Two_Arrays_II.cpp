// Hash Table
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {
            mp[nums1[i]]++;
        }

        for (int i = 0; i < m; ++i)
        {
            if (mp[nums2[i]] > 0)
            {
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};

// Binary Search
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> count(1001);
        vector<int> res;

        for (const auto& num : nums2)
            count[num]++;

        sort(nums2.begin(), nums2.end());

        for (const auto& num : nums1)
        {
            int l = 0;
            int r = m - 1;

            while (l <= r)
            {
                int mid = l + (r - l) / 2;

                if (nums2[mid] == num && count[num] > 0)
                {
                    res.push_back(num);
                    count[num]--;
                    break;
                }
                else if (nums2[mid] > num)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return res;
    }
};