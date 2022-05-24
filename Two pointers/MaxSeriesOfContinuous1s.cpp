// https://www.interviewbit.com/problems/remove-element-from-array/

vector<int> Solution::maxone(vector<int> &A, int B) {
	int n = A.size();
	int l = 0, r = 0;
	int ones = 0;
	int mxOnes = 0, lBest = 0, rBest = -1;
	while (r < n) {
		ones += A[r];
		while (1) {
			int zeros = r - l + 1 - ones;
			if (zeros <= B) break;
			if (A[l] == 1) ones--;
			l++;
		}
		int len = r - l + 1;
		if (len > mxOnes) {
			mxOnes = len;
			lBest = l;
			rBest = r;
		}
		r++;
	}
	vector <int> ans;
	for (int i = lBest; i <= rBest; ++i) {
		ans.push_back(i);
	}
	return ans;
}

