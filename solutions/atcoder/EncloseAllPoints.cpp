// Problem: https://atcoder.jp/contests/abc151/tasks/abc151_f
// Find min radius of a circle containing all give points. O(n^4)

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

int collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    // Calculation the area of
    // triangle. We have skipped
    // multiplication with 0.5
    // to avoid floating point
    // computations
    int a = x1 * (y2 - y3) +
            x2 * (y3 - y1) +
            x3 * (y1 - y2);
  
    return a == 0;
}
  
pair<double, double> findCircle(int x1, int y1, int x2, int y2, int x3, int y3) {
    double x12 = x1 - x2, x13 = x1 - x3, y12 = y1 - y2, y13 = y1 - y3;
    double y31 = y3 - y1, y21 = y2 - y1, x31 = x3 - x1, x21 = x2 - x1;
    double sx13 = x1*x1 - x3*x3, sy13 = y1*y1 - y3*y3;
    double sx21 = x2*x2 - x1*x1, sy21 = y2*y2 - y1*y1;
    double f = (sx13 * x12 + sy13 * x12 + sx21 * x13 + sy21 * x13) / (2.0 * (y31 * x12 - y21 * x13));
    double g = (sx13 * y12 + sy13 * y12 + sx21 * y13 + sy21 * y13) / (2.0 * (x31 * y12 - x21 * y13));
    // eqn of circle be x^2 + y^2 + 2*g*x + 2*f*y + c = 0
    // where centre is (h = -g, k = -f) and radius r
    // as r^2 = h^2 + k^2 - c
    return {-g, -f};
}

double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.XX-p2.XX)*(p1.XX-p2.XX) + (p1.YY-p2.YY)*(p1.YY-p2.YY));
}

int check(V<pii>& points, pair<double, double> center, double r) {
    rep(i, si(points)) {
        if (distance(points[i], center) > r+1e-6) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = SS;
    V<pii> points, pts;
    rep(i, n) {
        int x = SS;
        int y = SS;
        points.pb({x, y});
    }
    double ans = inf;
    rep(i, n) fori(j, i+1, n) {
        pair<double, double> center;
        center.XX = (points[i].XX+points[j].XX)/2.0;
        center.YY = (points[i].YY+points[j].YY)/2.0;
        double r = distance(points[i], center);
        if (check(points, center, r)) {
            ans = min(ans, r);
        }
    }
    
    rep(i, n) fori(j, i+1, n) fori(k, j+1, n) {
        if (collinear(points[i].XX, points[i].YY, points[j].XX, points[j].YY, points[k].XX, points[k].YY)) {
            continue;
        }
        pair<double, double> center = findCircle(
            points[i].XX, points[i].YY,
            points[j].XX, points[j].YY,
            points[k].XX, points[k].YY
        );
        double r = distance(points[i], center);
        if (check(points, center, r)) {
            ans = min(ans, r);
        }
    }
    
    printf("%.9lf\n", ans);
}

