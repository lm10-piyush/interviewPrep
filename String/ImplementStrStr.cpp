//https://www.interviewbit.com/problems/implement-strstr/

int Solution::strStr(const string A, const string B) {
    if (A.empty() or B.empty()) return -1;
    int n = A.size(), m = B.size();
    for (int i = 0; i + m <= n; ++i) {
        if (A.substr(i, m) == B) return i;
    }
    return -1;
}
