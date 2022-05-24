//https://www.interviewbit.com/problems/valid-sudoku/

int Solution::isValidSudoku(const vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    int ok = 1;
    auto check = [&](int r1, int c1, int r2, int c2) {
        unordered_map<char, int> cnts;
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                if (!isdigit(A[i][j])) continue;
                cnts[A[i][j]]++;
                if (cnts[A[i][j]] > 1) {
                    return 0;
                }
            }
        }

        return 1;
    };
    for (int i = 0; i < n; ++i) {
        ok = ok && check(i, 0, i, 8);  //row check
        ok = ok && check(0, i, 8, i);  // col check
    }

    for (int i : {2, 5, 8}) {
        for (int j : {2, 5, 8}) {
            ok = ok && check(i - 2, j - 2, i, j);
        }
    }
    return ok;
}

/*

*/