class Solution {
public:
    int getNext(int n)
    {
        int totalSum = 0;

        while (n)
        {
            int d = n % 10;
            n /= 10;
            totalSum += d * d;
        }

        return totalSum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = getNext(n);

        while (fast != 1 && slow != fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }
};