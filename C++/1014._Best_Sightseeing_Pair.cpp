class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        int maxScore = 0;
        int cur = 0;

        for (const auto& num : values)
        {
            maxScore = max(maxScore, cur + num);
            cur = max(cur, num) - 1;
        }

        return maxScore;
    }
};