//https://www.interviewbit.com/problems/valid-path/

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector <vector <bool>> used(A + 2, vector <bool> (B + 2, false));
    queue <pair<int, int>> q;
    auto check = [&](int a, int b) {
        bool inside = false;
        for (int j = 0; j < E.size(); ++j) {
            int x = a - E[j], y = b - F[j];
            if (x * x + y * y <= D * D) {
                inside = true;
            }
        }
        return inside;
    };
    if (!check(0, 0)) {
        q.push({0, 0});
        used[0][0] = true;
    }

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
        int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
        for (int i = 0; i < 8; ++i) {
            int a = r + dx[i], b = c + dy[i];
            if (a < 0 or b < 0 or a > A or b > B or used[a][b]) continue;
            if (!check(a, b)) {
                used[a][b] = true;
                q.push({a, b});
            }
        }
    }
    return (used[A][B] ? "YES" : "NO");
}
