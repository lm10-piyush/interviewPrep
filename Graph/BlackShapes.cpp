//https://www.interviewbit.com/problems/black-shapes/

// connected components

int Solution::black(vector<string> &A) {
    int n = A.size(), m = A[0].size();
    int ans = 0;
    vector <vector <int>> used(n, vector <int> (m, 0));
    function <void(int, int)> go = [&](int r, int c) {
        used[r][c] = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i) {
            int x = r + dx[i], y = c + dy[i];
            if (x < 0 or y < 0 or x >= n or y >= m or used[x][y] or A[x][y] != 'X') continue;
            go(x, y);
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] and A[i][j] == 'X') {
                go(i, j);
                ans++;
            }
        }
    }
    return ans;
}
