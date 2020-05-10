#include <bits/stdc++.h>
using namespace std;
#define si(v) ((int)v.size())
#define inf 1e9

vector<int> djikstra( vector<vector<int> > g, int source) {
  
  int n = si(g);
  vector<int> dis(n, inf);
  vector<bool> vis(n, false);
  int cur = source;
  dis[cur] = 0;
  for(int i = 0; i < n - 1; i++) {
    vis[cur] = true;
    for(int j = 0; j < n; j++) {
      if (g[cur][j] != 0 && (dis[cur] + g[cur][j] < dis[j])) {
        dis[j] = dis[cur] + g[cur][j];
      }
    }
    int nextNode = -1;
    for(int j = 0; j < n; j++) {
      if (!vis[j] && dis[j] != -1 && (nextNode == -1 || dis[j] < dis[nextNode])) {
        nextNode = j;
      }
    }
    cur = nextNode;
  }
  return dis;
}


int main() {
  vector<vector<int> > graph = {
                        { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
  vector<int> dis = djikstra(graph, 0);
  for(int i=0; i<si(graph); i++) {
    cout<<i<<" "<<dis[i]<<"\n";
  }
  return 0;
}

