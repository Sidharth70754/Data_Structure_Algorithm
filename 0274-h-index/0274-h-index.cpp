class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0;
        while (h < citations.size() && citations[h] > h)
            ++h;
        return h;
    }
};