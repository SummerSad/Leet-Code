// Since each version is developed based on the previous version, all the
// versions after a bad version are also bad
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
        int from = 1;
        int to = n;
        int mid;
        while (from <= to) {
                mid = from + (to - from) / 2;
                if (isBadVersion(mid)) {
                        if (mid == 1 || !isBadVersion(mid - 1))
                                break;
                        else
                                to = mid - 1;
                } else {
                        from = mid + 1;
                }
        }
        return mid;
}
