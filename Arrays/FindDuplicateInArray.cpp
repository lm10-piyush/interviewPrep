//https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0], fast = A[0];
    do {
        slow = A[slow];
        fast = A[A[fast]];
    } while (slow != fast);
    slow = A[0];
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}
