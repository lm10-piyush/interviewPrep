//https://www.interviewbit.com/problems/maximum-ones-after-modification/

/*
 * Problem is similar like: max continuous series of 1s
*/

int Solution::solve(vector<int> &A, int B) {
	int n = A.size();
	int l = 0, r = 0;
	int ones = 0;
	int mxOnes = 0;
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
		}
		r++;
	}
	return mxOnes;
}
