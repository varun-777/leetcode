class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int flag = 0;
                    for (int k = 0; k < m; k++) {
                        if (grid[i][k] == 1 && k != j) {
                            count++;
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag) {
                        for (int k = 0; k < n; k++) {
                            if (grid[k][j] == 1 && k != i) {
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};