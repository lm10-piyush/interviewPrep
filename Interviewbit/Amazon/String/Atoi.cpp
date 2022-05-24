//https://www.interviewbit.com/problems/atoi/

int Solution::atoi(const string A) {
    if (A.empty()) return 0;
    long long ans = 0;
    bool neg = A[0] == '-';
    for (int i = (A[0] == '+' or A[0] == '-'); i < A.size(); ++i) {
        if (!isdigit(A[i])) {
            if (neg) ans *= -1;
            return ans;
        }
        ans = ans * 10 + A[i] - '0';
        long long num = (neg ? ans * -1LL : ans);
        if (num > INT_MAX) return INT_MAX;
        if (num < INT_MIN) return INT_MIN;
    }
    if (neg) ans *= -1;
    return ans;
}
/*

*/