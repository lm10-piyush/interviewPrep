//https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {
    int mn = INT_MAX;
    int n = A.size(), curr = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] == 'I') curr++;
        else curr--;
        mn = min(mn, curr);
    }
    int start = (mn < 0 ? abs(mn - 1) : 1);
    if (start == 0) start = 1;
    vector <int> ans = {start};
    for (int i = 0; i < n; ++i) {
        if (A[i] == 'I') start++;
        else start--;
        ans.push_back(start);
    }
    return ans;
}
