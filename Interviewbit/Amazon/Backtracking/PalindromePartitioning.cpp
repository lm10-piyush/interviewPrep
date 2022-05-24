// https://www.interviewbit.com/problems/palindrome-partitioning/



bool check(string s) {
	int i = 0, j = (int)s.size() - 1;
	while (i < j) {
		if (s[i++] != s[j--])
			return false;
	}
	return true;
}



vector<vector<string> > Solution::partition(string A) {
	int n = A.size();
	vector <vector <string>> ans;
	vector <string> curr;
	function <void(int)> go = [&](int pos) {
		if (pos == n) {
			ans.push_back(curr);
			return;
		}
		string s;
		for (int i = pos; i < n; ++i) {
			s.push_back(A[i]);
			if (check(s)) {
				curr.push_back(s);
				go(i + 1);
				curr.pop_back();
			}
		}
	};
	go(0);
	return ans;
}
