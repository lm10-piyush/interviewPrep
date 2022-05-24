//https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    vector <vector <int>> ans;
    if (A == 0) return ans;
    vector <int> curr = {1};
    ans.push_back(curr);
    while (A-- > 1) {
        int n = curr.size();
        vector <int> nxt(n + 1);
        for (int i = 0; i <= n; ++i) {
            if (i == 0 or i == n) nxt[i] = 1;
            else nxt[i] = curr[i - 1] + curr[i];
        }
        curr = nxt;
        ans.push_back(curr);
    }
    return ans;
}
