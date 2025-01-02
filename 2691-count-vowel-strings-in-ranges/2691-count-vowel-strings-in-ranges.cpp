class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            char first = words[i][0];
            char last = words[i].back();
            if (vowels.count(first) && vowels.count(last)) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }
        
        // Answer queries
        vector<int> result;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            result.push_back(prefixSum[r + 1] - prefixSum[l]);
        }
        
        return result;
    }
};