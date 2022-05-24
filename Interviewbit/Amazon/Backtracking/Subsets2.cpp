//https://www.interviewbit.com/problems/subsets-ii/

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    vector <vector <int>> ans;
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector <int> curr;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                curr.push_back(A[i]);
            }
        }
        ans.push_back(curr);
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}
