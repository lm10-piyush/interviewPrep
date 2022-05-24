//https://www.interviewbit.com/problems/remove-element-from-array/

int Solution::removeElement(vector<int> &A, int B) {
    int n = A.size();
    int shift = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] == B) shift++;
        else A[i - shift] = A[i];
    }
    return n - shift;
}
