//https://www.interviewbit.com/problems/combination-sum/

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int n = A.size();
    vector<vector <int>> ans;
    vector <int> curr;
    sort(A.begin(), A.end());
    A.resize(unique(A.begin(), A.end()) - A.begin());
    n = A.size();
    function <void(int, int)> go = [&](int pos, int sum) {
        if (sum < 0 or pos >= n) return;
        if (sum == 0) {
            ans.push_back(curr);
            return;
        }
        go(pos + 1, sum);
        curr.push_back(A[pos]);
        go(pos, sum - A[pos]);
        curr.pop_back();
    };
    go(0, B);
    sort(ans.begin(), ans.end());
    return ans;
}
