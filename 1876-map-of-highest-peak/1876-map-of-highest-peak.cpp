class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (isWater[r][c] == 1) {
                    height[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (const auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    height[nr][nc] == -1) {
                    height[nr][nc] = height[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return height;
    }
};