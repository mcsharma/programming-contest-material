// Given a string, returns a vector of same length, where ans[i] (0<=i<n) i
// the longest proper prefix of s[0..i] that is also a sufix of s[0..i]
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

