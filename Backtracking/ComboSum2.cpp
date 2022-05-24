//https://www.interviewbit.com/problems/combination-sum-ii/

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int n = A.size();
    vector <vector <int>> ans;
    sort(A.begin(), A.end());
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        vector <int> curr;
        for (int j = 0; j < n; ++j) {
            if (mask >> j & 1) {
                curr.push_back(A[j]);
                sum += A[j];
            }
        }
        if (sum == B) {
            ans.push_back(curr);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}
