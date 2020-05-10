vector<int> prefixFunction(string& s) {
    int n = int(s.size());
    vector<int> ans(n);
    for(int i = 1; i < n; i++) {
        int j = ans[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = ans[j-1];
        }
        if (s[i] == s[j]) {
            ans[i] = 1 + j;
        }
    }
    return ans;
}
