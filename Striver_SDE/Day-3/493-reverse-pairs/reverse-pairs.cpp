class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        temp.reserve(high - low + 1);
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; ++i) arr[i] = temp[i - low];
    }

    long long countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        long long cnt = 0;
        for (int i = low; i <= mid; ++i) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) ++right;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    long long mergeSort(vector<int> &arr, int low, int high) {
        long long cnt = 0;
        if (low >= high) return cnt;
        int mid = low + (high - low) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        long long ans = mergeSort(nums, 0, n - 1);
        return static_cast<int>(ans); // safe if problem constraints guarantee it fits
    }




        // Recursive
    // int reversePairs(vector<int>& nums) {
    //     int n = nums.size();
    //     int cnt = 0;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             if (nums[i] > 2 * nums[j]) cnt++;
    //         }
    //     }
    //     return cnt;
    // }
};