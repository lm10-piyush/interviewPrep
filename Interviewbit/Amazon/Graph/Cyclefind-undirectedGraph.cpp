
// https://www.interviewbit.com/problems/cycle-in-undirected-graph/

int Solution::solve(int A, vector<vector<int> > &B) {
    vector <vector <int>> graph(A + 1);
    for (auto a : B) {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }
    int ok = 0;
    vector <bool> used(A + 1, false);
    function <void(int, int)> dfs = [&](int u, int par = -1) {
        used[u] = true;
        for (int v : graph[u]) {
            if (v == par) continue;
            if (used[v]) ok = true;
            else dfs(v, u);
        }
    };
    for (int i = 1; i <= A; ++i) {
        if (!used[i])
            dfs(i, -1);
    }
    return ok;
}
