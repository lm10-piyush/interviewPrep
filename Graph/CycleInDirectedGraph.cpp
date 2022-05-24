//https://www.interviewbit.com/problems/cycle-in-directed-graph/

vector <vector<int>> graph;
vector <int> used;


/*
Doing it using the coloring:
unvisited nodes : 0
visited nodes but in recursion : 1
visited and completed from recursion: 2

*/

int Solution::solve(int A, vector<vector<int> > &B) {
    int n = A;
    graph = vector <vector <int>> (A + 1);
    used.assign(A + 1, 0);
    for (int i = 0; i < B.size(); ++i) {
        int u = B[i][0], v = B[i][1];
        graph[u].push_back(v);
    }

    int ok = 0;
    function<void(int)> dfs = [&](int u) {
        used[u] = 1;
        for (int v : graph[u]) {
            if (used[v] == 1) {
                ok = 1;
            }
            else if (!used[v])
                dfs(v);
        }
        used[u] = 2;
    };
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) dfs(i);
    }
    return ok;
}
