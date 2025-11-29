class Solution {
    public int arrangeCoins(int n) {
        long start = 1, end = n, mid = 0;

        while(start <= end) {
            mid = (start + end) / 2;
            long coins = (mid * (mid + 1)) / 2;
            if (coins == n) 
                return (int) mid;
            else if (coins > n) 
                end = mid - 1;
            else
                start = mid + 1;
        }
        return (int) end;
    }
}