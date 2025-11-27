class SnapshotArray {
public:
    int snap_id;
    // For each index, vector of {snap_id, value}
    vector<vector<pair<int, int>>> history;

    SnapshotArray(int length) {
        snap_id = 0;
        history.resize(length);
        // Initialize each index with (0, 0) so there's always a value
        for (int i = 0; i < length; ++i) {
            history[i].push_back({0, 0});
        }
    }

    void set(int index, int val) {
        auto &vec = history[index];
        if (vec.back().first == snap_id) {
            // Update current snapshot's value
            vec.back().second = val;
        } else {
            // New record for current snapshot
            vec.push_back({snap_id, val});
        }
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int target_snap_id) {
        const auto &vec = history[index];
        int l = 0, r = (int)vec.size() - 1;
        int idx = 0; // we know there is at least (0, 0)

        // Binary search for largest snap_id <= target_snap_id
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid].first <= target_snap_id) {
                idx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return vec[idx].second;
    }
};


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */