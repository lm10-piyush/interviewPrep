//https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    vector <int> height = A;
    height.insert(height.begin(), 0);
    height.push_back(0);
    int n = height.size();
    vector <int> left(n), right(n);
    for (int i = 0, j = n - 1; i < n; ++i, j--) {
        left[i] = height[i];
        right[j] = height[j];
        if (i) {
            left[i] = max(left[i - 1], left[i]);
            right[j] = max(right[j + 1], right[j]);
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        int x = max(min(left[i - 1], right[i + 1]) - height[i], 0);
        ans += max(min(left[i - 1], right[i + 1]) - height[i], 0);
    }
    return ans;

}
