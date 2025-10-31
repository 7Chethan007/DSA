class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        // base cases
        if (target == 0) {               // if we've reached target, record combination
            ans.push_back(ds);
            return;
        }
        if (ind == arr.size()) return;   // ran out of elements

        // pick the element (use it only once -> move to ind + 1)
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind + 1, target - arr[ind], arr, ans, ds); // use next index
            ds.pop_back();
        }

        // skip duplicates: advance i to the next different element, then skip current block
        int i = ind;
        while (i + 1 < (int)arr.size() && arr[i] == arr[i + 1]) i += 1;
        findCombination(i + 1, target, arr, ans, ds); // skip current (and its duplicates)
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
