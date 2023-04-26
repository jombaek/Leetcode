class Solution {
public:
    int countOdds(int low, int high)
    {
        int countNumbers = (high - low + 1);
        if (countNumbers % 2 == 0 || low % 2 == 0)
            return countNumbers / 2;
        else
            return (countNumbers + 1) / 2;

        return 0;
    }
};