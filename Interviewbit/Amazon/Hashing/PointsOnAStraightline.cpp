//https://www.interviewbit.com/problems/points-on-the-straight-line/

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    const int INF = 2e9;
    int n = A.size();
    int ans = n > 0;
    for (int i = 1; i < n; ++i) {
        map <pair<int, int>, int> points;
        int curr = 1; // number of points at (A[i], B[i])
        for (int j = 0; j < i; ++j) {
            if (A[i] == A[j] and B[i] == B[j]) curr++;
            else if (A[i] == A[j]) {
                points[ {INF, INF}]++;
            }
            else {
                int a = (B[i] - B[j]);
                int b = (A[i] - A[j]);
                int sign = 1;
                if ((a < 0) ^ (b < 0))
                    sign = -1;
                a = abs(a); b = abs(b);
                int g = __gcd(a, b);
                points[ {sign * a / g, b / g}]++; //storing slopes in fractions
            }
        }
        for (auto x : points) {
            ans = max(ans, x.second + curr);
        }
        ans = max(ans, curr);
    }
    return ans;
}

/*
 * If you points p2, p3 have same slope from p1 then that means p1, p2, p3 are in same line.

*/