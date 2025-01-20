class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Create a lookup for each value in the matrix
        vector<pair<int, int>> lookup(m * n + 1);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                lookup[mat[i][j]] = {i, j};

        // Row and column painted counts
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);

        for (int i = 0; i < m * n; i++) {
            auto [x, y] = lookup[arr[i]];

            row_count[x]++;
            col_count[y]++; 

            if (row_count[x] == n || col_count[y] == m) 
                return i;
        }
        return 0;
    }
};
