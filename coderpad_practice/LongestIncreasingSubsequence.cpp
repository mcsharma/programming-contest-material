#include <bits/stdc++.h>
using namespace std;
#define si(v) ((int)v.size())
#define inf 1e9


// Longest increasing subsequence in n*log(n)
int lis(vector<int>& v) {
  int n = si(v);
  vector<int> m(n+1, -1);
  m[1] = 0;
  int maxLisLen = 1;
  for(int i = 1; i < n; i++) {
    int lo = 0, hi = i;
    while (hi - lo > 1) {
      int mid = (hi+lo)/2;
      if (m[mid] != -1 && v[m[mid]] < v[i]) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    int x = m[hi] != -1 && v[m[hi]] < v[i] ? hi : lo;
    int lisLen = 1 + x;
    maxLisLen = max(maxLisLen, lisLen);
    if (m[lisLen] == -1 || v[m[lisLen]] > v[i]) m[lisLen] = i;     
  }
  return maxLisLen;
}

int main() {  
  vector<int> v = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};  
  cout<<lis(v)<<"\n";
  return 0;
}

