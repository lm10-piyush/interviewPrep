//https://www.interviewbit.com/problems/merge-overlapping-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool bothIn(Interval x, Interval y) {
    // return ((x.start <= y.start and y.start <= x.end) or (x.start <= y.end and y.end <= x.end));
    return max(x.start, y.start) <= min(x.end, y.end);
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), [&](auto a, auto b) {
        if (a.start != b.start) return a.start < b.start;
        return a.end < b.end;
    });
    vector <Interval> ans = {A[0]};
    for (int i = 1; i < A.size(); ++i) {
        if (bothIn(ans.back(), A[i])) {
            int m = (int)ans.size() - 1;
            ans[m].end = max(ans[m].end, A[i].end);
        }
        else ans.push_back(A[i]);
    }
    return ans;
}
