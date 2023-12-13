#include <bits/stdc++.h>
using namespace std;

int s[100], e[100], g[100];
int kth_smallest(int v[], int k, int sz) {
    int se = 0, ee = 0, ge = 0;

    if (sz == 1) return v[0];

    int p = v[rand() % sz];
    for (int i = 0; i < sz; i++) {
        if (v[i] < p) s[se++] = v[i];
        else if (v[i] == p) e[ee++] = v[i];
        else g[ge++] = v[i];
    }

    if (se >= k) return kth_smallest(s, k, se);
    else if (se + ee >= k) return e[0];
    else return kth_smallest(g, k - se - ee, ge);
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15, 8, 12, 6};
    cout << kth_smallest(arr, 4, 9);

    return 0;
}
