class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        vector<vector<int>> answer(2);
        unordered_set<int> uset1, uset2;

        for (const auto& num : nums1)
            uset1.insert(num);
        
        for (const auto& num : nums2)
            uset2.insert(num);

        for (const auto& num : uset1)
        {
            if (!uset2.count(num))
                answer[0].push_back(num);
        }

        for (const auto& num : uset2)
        {
            if (!uset1.count(num))
                answer[1].push_back(num);
        }

        return answer;
    }
};