class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;

        for (const auto& s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> anagrams;
        for (const auto& [key, val] : mp) { 
            anagrams.push_back(val);
        }
        
        return anagrams;
    }
};