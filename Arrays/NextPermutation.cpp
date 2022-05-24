// https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        if (A[i] > A[i - 1]) ok = false;
    }
    if (ok) {
        reverse(A.begin(), A.end());
        return A;
    }
    for (int i = n - 2; i >= 0; --i) {
        if (A[i] < A[i + 1]) {
            int idx = i + 1;
            for (int j = i + 1; j < n; ++j) {
                if (A[i] < A[j] and A[j] < A[idx]) {
                    idx = j;
                }
            }
            swap(A[i], A[idx]);
            for (int l = i + 1, r = n - 1; l < r; l++, r--) {
                swap(A[l], A[r]);
            }
            break;
        }
    }
    return A;
}
/*
 * Least significant(nearest) position should be increased by lowest possible amount.
2 3 5 4 1
2 4 1 2 4

2 1 3 4 5
*/
