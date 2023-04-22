class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int l = 0;
        int r = letters.size() - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (letters[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }

        return letters[l] > target ? letters[l] : letters[0];
    }
};