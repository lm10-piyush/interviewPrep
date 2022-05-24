//https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    vector <pair<int, int>> B;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        B.push_back({A[i], i});
    }
    sort(B.begin(), B.end());
    int idx = n, ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, B[i].second - idx);
        idx = min(idx, B[i].second);
    }
    return ans;
}
