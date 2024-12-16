class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        // DP table to store if s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0; // Start index of the longest palindrome
        int maxLength = 1; // Length of the longest palindrome

        // Base case: Single-character substrings
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Base case: Two-character substrings
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Fill DP table for substrings of length 3 or more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // Ending index of the substring

                // Check if s[i..j] is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        // Extract the longest palindrome substring
        return s.substr(start, maxLength);
    }
};
