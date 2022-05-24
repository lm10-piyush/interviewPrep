//https://www.interviewbit.com/problems/longest-consecutive-sequence/

int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set <int> s;
    for (int i : A)
        s.insert(i);
    int ans = 0, n = A.size();
    for (int i = 0; i < n; ++i) {
        if (!s.count(A[i] - 1)) {
            int l = 1;
            while (s.count(A[i] + l)) {
                l++;
            }
            ans = max(ans, l);
        }
    }
    return ans;
}
