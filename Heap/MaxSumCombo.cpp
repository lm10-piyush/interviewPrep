// https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector <int> ptr(n, n - 1);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    set <array<int, 2>, greater <array<int, 2>>> s;
    for (int i = 0; i < n; ++i) {
        s.insert({A[i] + B[n - 1], i});
    }
    vector <int> ans;
    while (C--) {
        auto t = *s.begin();
        s.erase(s.begin());
        ans.push_back(t[0]);
        int idx = t[1];
        ptr[idx]--;
        if (ptr[idx] >= 0) {
            s.insert({A[idx] + B[ptr[idx]], idx});
        }
    }
    return ans;
}
/*
sort the both arrays
Just Maintain the an array of kind of pointers (indices) such that A[i] combine with B[ptr[i]], ith pointer will combine with ptr[i].
Which means ith element of A[i] can get the best sum value with B[ptr[i]]. Once ith is used, ptr[i] will get decremented.
*/