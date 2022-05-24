//https://www.interviewbit.com/problems/3-sum/

/*
 * By the way the brute force O(n3) also passes.
 * Another approach by binary search, fix two pointers and make binary search.
 * fix one pointer and new target would be: B - A[i], now find the pair whose sum is closest to new target, complexity: O(n * n). No log(n) factor.
 * We can use Hashing also, but it can use O(n) space also.


*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(), A.end());
    long long ans = 4e9;
    for (int i = 0; i < n; ++i) {
        int l = i + 1, r = n - 1;
        long long target = B - A[i] * 1LL;
        while (l < r) {
            if (abs(ans - B) > abs(A[i] * 1LL + A[l] + A[r] - B))
                ans = A[i] * 1LL + A[l] + A[r];
            if (A[l] * 1LL + A[r] < target)
                l++;
            else r--;
        }
    }
    return ans;
}

/*
A : [ 2147483647, -2147483648, -2147483648, 0, 1 ]
B : 0


*/