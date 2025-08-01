class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m) return "";

        vector<int> hash(128, 0);
        for (char c : t) hash[c]++;

        int l = 0, r = 0, count = m;
        int minLen = INT_MAX, startIdx = 0;

        while (r < n) {
            if (hash[s[r]] > 0) count--;  
            hash[s[r]]--;
            r++;

            
            while (count == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    startIdx = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) count++;  
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
