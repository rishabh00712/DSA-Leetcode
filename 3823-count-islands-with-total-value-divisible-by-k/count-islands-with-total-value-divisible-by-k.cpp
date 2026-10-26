#include <vector>
using namespace std;

class Solution {
public:
    int m, n; // grid dimensions
    vector<vector<bool>> visited;

    void dfs(vector<vector<int>>& grid, int i, int j, long long& islandSum) {
        if (i < 0 || i >= m || j < 0 || j >= n) return; // out of bounds
        if (visited[i][j] || grid[i][j] == 0) return;   // already visited or water

        visited[i][j] = true;
        islandSum += grid[i][j];

        // Explore 4 directions
        dfs(grid, i + 1, j, islandSum);
        dfs(grid, i - 1, j, islandSum);
        dfs(grid, i, j + 1, islandSum);
        dfs(grid, i, j - 1, islandSum);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] > 0) {
                    long long islandSum = 0;
                    dfs(grid, i, j, islandSum);
                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
