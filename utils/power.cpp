int power(int a, int b, int c) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * (long long)a % c;
        a = a * (long long)a % c;
        b /= 2;
    }
    return ans;
}

