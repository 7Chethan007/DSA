class TimeMap {
public:
    // key -> list of {timestamp, value}, sorted by timestamp
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";

        const auto &vec = mp[key];
        int l = 0, r = (int)vec.size() - 1;
        int idx = -1;

        // Binary search for largest timestamp <= given timestamp
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid].first <= timestamp) {
                idx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (idx == -1) return "";
        return vec[idx].second;
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */