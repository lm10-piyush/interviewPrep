//https://www.interviewbit.com/problems/anagrams/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map <vector <int>, vector <int>> mp;
    for (int i = 0; i < (int)A.size(); ++i) {
        vector <int> cnts(26, 0);
        for (auto j : A[i]) {
            cnts[j - 'a']++;
        }
        mp[cnts].push_back(i + 1);
    }
    vector <vector <int>> ans;
    for (auto [a, b] : mp) {
        ans.push_back(b);
    }
    return ans;
}
