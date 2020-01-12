// Problem: https://codeforces.com/contest/1285/problem/E
#include<bits/stdc++.h>
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
#define P(x)                    cout<<x<<"\n"
#define PVI(v)                  rep(i, si(v)) cout<<v[i]<<" "; puts("")
#define PPI(p)                  cout<<"("<<p.first<<", "<<p.second<<")\n"
#define PVPI(v)                 rep(i, si(v)) cout<<"("<<v[i].first<<", "<<v[i].second<<")"<<(i==si(v)-1?"":", ");puts("")
#define PA(arr1, arr2)          for(auto it = arr1; it != arr2; it++) cout<<*it<<" "; puts("");
typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;
const int MOD7 = 1000000000+7;
const int MOD9 = 1000000000+9;
/* ################### Program Body starts here ################ */

int main() {
    int t = SS;
    while (t--) {
        map<int, int> allCords;
        map<int, vi> start, end;
        int n = SS;
        vi extra(n);
        rep(i, n) {
            int x = SS, y = SS;
            start[x].pb(i);
            end[y].pb(i);
            allCords[x] = allCords[y] = 1;
        }
        
        int numSegments = 0, init = 0;
        for (auto e : allCords) {
            int x = e.XX;
            if (si(start[x]) && numSegments == 0) {
                init++;
            }
            numSegments += si(start[x]);
            numSegments -= si(end[x]);
        }
        
        set<int> segments;
        for (auto e : allCords) {
            int x = e.XX;
            if (si(segments) == 1 && si(start[x])) {
                // means deleting the only segment we have in set will result in 1 extra left border
                extra[*segments.begin()]++;
            }
            if (si(segments) == 0 && si(start[x]) == 1) {
                // This is a left border of original union, so removing it will reduce left borders by 1
                extra[start[x][0]]--;
            }
            for (auto index : start[x]) {
                segments.insert(index);
            }
            for (auto index : end[x]) {
                segments.erase(index);
            }
        }
        
        cout<<init + *max_element(all(extra))<<"\n";
    }
}

