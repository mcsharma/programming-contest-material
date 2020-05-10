// Returns the parent node index (0-based) of a give node x (0-based)
int parent(int x, vector<int>& par) {
    return par[x] == x ? x : (par[x] = parent(par[x], par));
}
// Merges two sets that x and y belongs to (if they are in different sets)
// Returns 0 if they were already in the same set, 1 otherwise.
int merge(int x, int y, vector<int>& par, vector<int>& depth) {
    int r1 = parent(x, par), r2 = parent(y, par);
    if (r1 == r2) {
        return 0;
    }
    if (depth[r1] > depth[r2]) {
        swap(r1, r2);
    }
    par[r1] = r2;
    if (depth[r1] == depth[r2]) depth[r2]++;
    return 1;
}

