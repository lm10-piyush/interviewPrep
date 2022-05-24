//https://www.interviewbit.com/problems/maximum-edge-removal/

//DP

int Solution::solve(int A, vector<vector<int> > &B) {
    vector <vector <int>> tree(A + 1);
    for (int i = 0; i < A - 1; ++i) {
        int u = B[i][0], v = B[i][1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector <int> subTree(A + 1);
    function<int(int, int)> dfs = [&](int u, int p = -1) {
        subTree[u] = 1;
        int ans = 0;
        for (int v : tree[u]) {
            if (v != p) {
                ans += dfs(v, u);
                subTree[u] += subTree[v];
                if (subTree[v] % 2 == 0)
                    ans++;
            }
        }
        return ans;
    };
    return dfs(1, -1);
}
