// Adding val in the x'th index of array (1-based) of size N
void add(int x, int val, int N) {
    while (x <= N) {
        bit[x] += val;
        x += x&-x;
    }
}
// Prefix sum of first x (1-based) numbers in the array of size N 
int query(int x, int N) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= x&-x;
    }
    return ans;
}

