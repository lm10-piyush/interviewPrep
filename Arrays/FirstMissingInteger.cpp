//https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        if (A[i] <= 0) A[i] = n + 2; //converting the unnecessary non-positive numbers into some meaningful repsentation
    }
    for (int i = 0; i < n; ++i) {
        int x = abs(A[i]) - 1;
        if (x < n and A[x] > 0) A[x] *= -1;
    }
    for (int i = 0; i < n; ++i) {
        if (A[i] >= 0) return i + 1;
    }
    return n + 1;
}

/*
 * ans would be [1..n+1]
 * Idea is iterate through and make the positions negative whose positive value exists, but the only trick remains what about already
 negative numbers then, how to deal with it, then realized that already negative numbers and number greater than n are not important so
 just make them into some other number for convienence that would be n+2. Now we have only positive numbers and those positions are negative
 that means that number exists in the array.

*/
