class Solution {
public:
    double average(vector<int>& salary)
    {
        int n = salary.size();
        int minSalary = salary[0];
        int maxSalary = salary[0];
        double sumSalary = 0;

        for (int i = 0; i < n; ++i)
        {
            sumSalary += salary[i];
            minSalary = min(minSalary, salary[i]);
            maxSalary = max(maxSalary, salary[i]);
        }

        return (sumSalary - minSalary - maxSalary) / (n - 2);
    }
};