class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp;
    
        for (int i = 0; i < t.size(); ++i)
            mp[t[i]]++;

        int l = 0, r = 0;
        int n = s.size(), count = t.size(), ans = INT_MAX, head = 0;

        while (r < n)
        {
            if (mp[s[r++]]-- > 0)
                --count;
                
            while(count == 0)
            {
                if(r - l < ans)
                    ans = r - (head = l);

                if(mp[s[l++]]++ == 0)
                    count++;
            }
        }

        return (ans == INT_MAX ? "" : s.substr(head, ans));
    }
};