// Mahesh Sharma
// Beauty is in the struggle!
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
#define SS                      ({int x;cin>>x;x;})
#define SL                      ({long long x;cin>>x;x;})
#define pb                      push_back
#define mp                      make_pair
#define fill(a, v)              memset(a, v, sizeof(a))
#define all(a)                  a.begin(),a.end()
#define inf                     ((int)1e9)
#define linf                    ((long long)1e18)
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define PA(arr1, arr2)          for(auto it = arr1; it != arr2; it++) cout<<*it<<" "; cout<<"\n";
#define EL cout<<"\n"
#define ELR cerr<<"\n"

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// Credit: yashChandnani
void _P(int x) {cerr << x;}
void _P(long long x) {cerr << x;}
void _P(float x) {cerr << x;}
void _P(double x) {cerr << x;}
void _P(long double x) {cerr << x;}
void _P(char x) {cerr << '\'' << x << '\'';}
void _P(const char *x) {cerr << '\"' << x << '\"';}
void _P(const string &x) {cerr << '\"' << x << '\"';}
void _P(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void _P(const pair<T, V> &x) {cerr << '{'; _P(x.first); cerr << ","; _P(x.second); cerr << '}';}
template<typename T>
void _P(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), _P(i); cerr << "}";}
template<typename T>
void P(T val) {_P(val); ELR;}
template<typename T>
void P(S label, T val) {cerr<<label<<": "; _P(val); ELR;}
// **************** Program body starts here *********************


void _main(int test) {
    // Hello World!
}
// **************** Program body ends here ***********************


int main(int argc, char *argv[]) {
//     freopen ("input.txt", "r", stdin);
//     freopen ("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    t = SS;
    fori(i, 1, t + 1) {
        _main(i);
    }
    return 0;
}

