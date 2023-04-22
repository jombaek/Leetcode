class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int n = 10001;
        vector<int> points(n, 0);
        for (int num : nums)
            points[num] += num;
        
        int prev = 0;
        int cur = 0;

        for (int i = 0; i < n; ++i)
        {
            int tmp = max(points[i] + prev, cur);
            prev = cur;
            cur = tmp;
        }

        return cur;
    }
};