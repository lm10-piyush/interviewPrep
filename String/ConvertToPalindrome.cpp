//https://www.interviewbit.com/problems/convert-to-palindrome/

bool palin(string s) {
    int l = 0, r = (int)s.size() - 1;
    while (l <= r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

int Solution::solve(string A) {
    int l = 0, r = (int)A.size() - 1;
    while (l <= r) {
        if (A[l] != A[r]) {
            int len = r - l;
            if (palin(A.substr(l, len)) or palin(A.substr(l + 1, len))) return 1;
            return 0;
        }
        else {
            l++; r--;
        }
    }
    if ((int)A.size() % 2 == 1) return 1;
    return 0;
}
/*
Move the left and right pointer from ends and check the palindromicity and if A[l] != A[r] then check is the rest of the part is palindrome or not.

*/
