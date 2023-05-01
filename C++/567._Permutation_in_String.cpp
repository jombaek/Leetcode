class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> mp, window;
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        for (int i = 0; i < n; ++i)
        {
            mp[s1[i]]++;
            window[s2[i]]++;
        }
        
        if (mp == window)
            return true;

        int k = 0;

        for (int i = n; i < m; ++i)
        {
            if (window[s2[k]] == 1)
                window.erase(s2[k]);
            else
                window[s2[k]]--;

            window[s2[i]]++;
            k++;

            if (mp == window)
                return true;
        }

        return false;
    }
};