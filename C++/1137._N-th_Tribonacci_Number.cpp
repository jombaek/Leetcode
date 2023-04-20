class Solution {
public:
    int tribonacci(int n)
    {
        int prevPrev = 0;
        int prev = 1;
        int cur = 1;

        if (n == 0)
            return prevPrev;
        else if (n == 1)
            return prev;
        
        for (int i = 3; i <= n; ++i)
        {
            int res = cur + prev + prevPrev;
            prevPrev = prev;
            prev = cur;
            cur = res;
        }

        return cur;
    }
};