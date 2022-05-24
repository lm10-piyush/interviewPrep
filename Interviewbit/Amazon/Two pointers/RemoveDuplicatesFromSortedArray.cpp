//https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    int len = 1;
    for (int i = 1, j = 0; i < n; ++i) {
        if (A[i] == A[j]) continue;
        len++;
        A[++j] = A[i];
    }
    return len;
}

/*
1 1 1 2 2 3 4 5 5

*/