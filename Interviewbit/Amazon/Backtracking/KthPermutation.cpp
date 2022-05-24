//https://www.interviewbit.com/problems/kth-permutation-sequence/

long long fac(int n) {
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

string Solution::getPermutation(int A, int B) {
    int n = A, k = B;
    vector <int> ans(A);
    for (int i = 1; i <= A; ++i) {
        ans[i - 1] = i;
    }
    int start = max(n - 13, 0);
    vector <int> vals;
    for (int i = start; i < n; ++i) {
        vals.push_back(i + 1);
    }
    for (int i = start; i < n; ++i) {
        long long curr = 0, m = vals.size();
        for (int j = 0; j < m; ++j) {
            long long f = fac(m - 1);
            if (f < k) {
                k -= f;
            } else {
                ans[i] = vals[j];
                break;
            }
        }
        vector <int> nxt;
        for (int j : vals) {
            if (j == ans[i]) continue;
            nxt.push_back(j);
        }
        vals = nxt;
    }

    string s;
    for (auto i : ans) {
        s += to_string(i);
    }
    return s;
}
/*
100
10000000

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888992989690911009497959993
*/