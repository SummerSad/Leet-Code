// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution
{
      public:
        int guessNumber(int n)
        {
                int from = 1;
                int to = n;
                int mid;
                while (from <= to) {
                        mid = from + (to - from) / 2;
                        int result = guess(mid);
                        if (result == 0)
                                break;
                        else if (result == -1)
                                to = mid - 1;
                        else
                                from = mid + 1;
                }
                return mid;
        }
};
