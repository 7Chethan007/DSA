#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st; // (price, index)
    int index;

public:
    StockSpanner() {
        index = -1;
    }

    int next(int price) {
        index++; // increment day counter

        // Pop until we find a greater price
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        // Compute span
        int prevGreaterIndex = st.empty() ? -1 : st.top().second;
        int span = index - prevGreaterIndex;

        // Push current (price, index)
        st.push({price, index});

        return span;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */