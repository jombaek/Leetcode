class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;

        int prev = 1;
        int cur = 2;

        for (int i = 3; i <= n; ++i)
        {
            int res = prev + cur;
            prev = cur;
            cur = res;
        }

        return cur;
    }
};