//https://www.interviewbit.com/problems/maximum-absolute-difference/

int Solution::maxArr(vector<int> &A) {
    int n = A.size();

    int mx1 = INT_MIN, mn1 = INT_MAX; // for max and min of (A[i] + i)
    int mx2 = INT_MIN, mn2 = INT_MAX; // for max and min of (A[i] - i)
    for (int i = 0; i < n; ++i) {
        int x = A[i] + i;
        int y = A[i] - i;
        mx1 = max(mx1, x);
        mn1 = min(mn1, x);
        mx2 = max(mx2, y);
        mn2 = min(mn2, y);
    }

    int ans = max(mx1 - mn1, mx2 - mn2);
    return ans;
}
/*
A[i] - A[j] + i - j => (A[i] + i) - (A[j] + j)
A[i] - A[j] - i + j => (A[i] - i) - (A[j] - j)
-A[i] + A[j] + i - j => -(A[i] - i) + (A[j] - j)
-A[i] + A[j] - i + j => -(A[i] + i) + (A[j] + j)

case 1, 4 are same and Case 2, 3 are same.
=> You might be thinking that we should open the modulo accordingly, but we are opening it kind of randomly (correct and wrong both),
   so is it wrong??
=> Ans is NO, because we have to maximize the answer. So, if we are opening the mod in wrong way it would lead to less maximum number
    which can be the real answer and we are also opening the bracktes in correct way which leads to larger number, so correct way will
    shadow the incorrect way. Thats why we can say when we have to find the Minimum ans this strategy won't work, because modulus doesn't give
    negative result by our way is giving it.


*/