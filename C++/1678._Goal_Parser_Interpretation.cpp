class Solution {
public:
    string interpret(string command)
    {
        string answer = "";
        int n = command.size();

        for (int i = 0; i < n; ++i)
        {
            if (command[i] == 'G')
                answer += "G";
            else if (i != n && command[i] == '(' && command[i + 1] == ')')
                answer += "o";
            else if (i != n && command[i] == 'a' && command[i + 1] == 'l')
                answer += "al";
        }

        return answer;
    }
};