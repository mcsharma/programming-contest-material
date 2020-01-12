// Problem link: https://codeforces.com/contest/1200/problem/D

#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>
#include <deque>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
 
#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")
 
typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;

S s[2000];


V<vi> solve(int n, int k) {
    V<pii> ends;
    V<vi> ans(n);
    rep(i, n) ans[i] = vi(n);
    int common = 0;
    rep(i, n) {
        int fi = -1, la = -1;
        rep(j, n) {
            if (s[i][j] == 'B' && fi == -1) fi = j;
            if (s[i][j] == 'B') la = j;
        }
        ends.pb({fi, la});
        if (fi == -1) common++;
    }
    rep(j, n-k+1) {
        int c = 0;
        rep(i, k) {
            if (ends[i].XX != -1 && j <= ends[i].XX && j+k-1 >= ends[i].YY) {
                c++;
            }
        }
        ans[0][j] = c + common;
        fori(i, 1, n-k+1) {
            if (ends[i-1].XX != -1 && j <= ends[i-1].XX && j+k-1 >= ends[i-1].YY) {
                c--;
            }
            if (ends[i+k-1].XX != -1 && j <= ends[i+k-1].XX && j+k-1 >= ends[i+k-1].YY) {
                c++;
            }
            ans[i][j] = c + common;
        }
    }
    return ans;
}

int main() {
    int n = SS, k = SS;
    rep(i, n) cin>>s[i];
    int ans = 0;
    V<vi> ansRow = solve(n, k);
    rep(i, n) fori(j, i+1, n) {
        char c = s[i][j];
        s[i][j] = s[j][i];
        s[j][i] = c;
    }
    V<vi> ansCol = solve(n, k);
    rep(i, n-k+1) rep(j, n-k+1) {
        ans = max(ans, ansRow[i][j] + ansCol[j][i]);
    }
    cout<<ans<<"\n";

    
}

