class Solution {
public:
    static int hammingWeight(int n)
    {
        int count = 0;

        while (n)
        {
            n &= n - 1;
            count++;
        }

        return count;
    }

    static bool compare(int a, int b)
    {
        int n = hammingWeight(a);
        int m = hammingWeight(b);

        if (n == m)
            return a <= b;
        else
            return n < m;
    }

    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), compare);

        return arr;
    }
};