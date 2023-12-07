class Solution {
public:
    int getNext(int n) {
        int temp = 0;
        while (n != 0) {
            temp += pow(n % 10, 2);
            n = n / 10;
        }
        return temp;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        } while (slow != fast);

        return slow == 1;
    }
};
