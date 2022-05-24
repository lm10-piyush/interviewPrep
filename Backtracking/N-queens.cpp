//https://www.interviewbit.com/problems/nqueens/



vector<vector<string> > Solution::solveNQueens(int A) {
	vector <vector <string>> ans;
	vector <string> curr;
	vector <int> ld(30, 0);
	vector <int> rd(30, 0);
	vector <int> col(30, 0);
	function <void(int)> go = [&](int r) {
		if (r == A) {
			ans.push_back(curr);
			return;
		};
		//r-c => left diagonal, r + c => right diagonal
		for (int c = 0; c < A; ++c) {
			if (!col[c] and !ld[r - c + A - 1] and !rd[r + c]) {
				col[c] = true;
				ld[r - c + A - 1] = true;
				rd[r + c] = true;
				string s(A, '.');
				s[c] = 'Q';
				curr.push_back(s);
				go(r + 1);
				curr.pop_back();
				col[c] = false;
				ld[r - c + A - 1] = false;
				rd[r + c] = false;
			}
		}
	};
	go(0);
	return ans;
}
