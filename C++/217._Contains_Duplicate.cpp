class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> mySet;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (mySet.find(nums[i]) == mySet.end())
                mySet.insert(nums[i]);
            else
                return true;
        }

        return false;
    }
};