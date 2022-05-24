//https://www.interviewbit.com/problems/region-in-binarymatrix/

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector <vector <int>> used(n, vector <int> (m, 0));
    int ans = 0, curr = 0;
    function <void(int, int)> go = [&](int r, int c) {
        used[r][c] = 1;
        curr++;
        int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
        int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

        for (int i = 0; i < 8; ++i) {
            int x = r + dx[i], y = c + dy[i];
            if (x < 0 or y < 0 or x >= n or y >= m or used[x][y] or A[x][y] != 1) continue;
            go(x, y);
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] and A[i][j] == 1) {
                curr = 0;
                go(i, j);
                ans = max(ans, curr);
            }
        }
    }
    return ans;
}
