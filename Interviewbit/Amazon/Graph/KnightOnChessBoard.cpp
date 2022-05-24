//https://www.interviewbit.com/problems/knight-on-chess-board/

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int n = A, m = B;
    const int INF = 1e9;
    vector <vector <int>> used(n, vector <int> (m, INF));
    queue <pair<int, int>> q;
    q.push({C - 1, D - 1});
    used[C - 1][D - 1] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int r = p.first, c = p.second;
        int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
        int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
        for (int i = 0; i < 8; ++i) {
            int x = r + dx[i], y = c + dy[i];
            if (x < 0 or y < 0 or x >= n or y >= m or used[x][y] < INF) continue;
            used[x][y] = used[r][c] + 1;
            q.push({x, y});
        }
    }
    int ans = used[E - 1][F - 1];
    if (ans == INF) ans = -1;
    return ans;
}

