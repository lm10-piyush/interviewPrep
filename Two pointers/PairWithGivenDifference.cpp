//https://www.interviewbit.com/problems/pair-with-given-difference/

/*
 * there is another approach with complexity O(n log n)
 * Sort the array and apply the binary search
*/

int Solution::solve(vector<int> &A, int B) {
    //used base to make the -ve number into +ve
    int base = 1001, N = 2004;
    vector <int> cnts(N, 0);
    for (int i : A) {
        cnts[base + i]++;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (cnts[i] == 0 or cnts[j] == 0) continue;
            if (B == 0 and cnts[i] > 1) return 1;
            if (abs(i - j) == abs(B)) return 1;
        }
    }
    return 0;
}
