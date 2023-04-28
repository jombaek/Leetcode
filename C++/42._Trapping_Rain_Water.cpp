class Solution {
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int maxIndex = 0;
        int ans = 0;
        int nowMax;

        for (int i = 1; i < n; ++i)
            if (height[i] > height[maxIndex])
                maxIndex = i;

        nowMax = 0;
        for (int i = 0; i < maxIndex; ++i)
        {
            if (height[i] > nowMax)
                nowMax = height[i];
            
            ans += nowMax - height[i];
        }

        nowMax = 0;
        for (int i = n - 1; i > maxIndex; --i)
        {
            if (height[i] > nowMax)
                nowMax = height[i];
            
            ans += nowMax - height[i];
        }

        return ans;
    }
};