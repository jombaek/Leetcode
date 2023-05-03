class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        string merged = "";
        int first = 0;
        int second = 0;
        int n = word1.size();
        int m = word2.size();

        while (first < n && second < m)
        {
            merged += word1[first++];
            merged += word2[second++];
        }

        while (first < n)
            merged += word1[first++];

        while (second < m)
            merged += word2[second++];
        
        return merged;
    }
};