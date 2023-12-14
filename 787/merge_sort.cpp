#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int m[N], t[N], n;

void merge_sort(int l, int r);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &m[i]);
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", m[i]);
    return 0;
}

void merge_sort(int l, int r) {
    if (l >= r) return;
    int middle = l + ((r - l) >> 1), i = l, j = middle + 1, k = 0;
    merge_sort(l, middle);
    merge_sort(middle + 1, r);
    while ((i <= middle) && (j <= r)) {
        if (m[i] <= m[j]) t[k++] = m[i++];
        else t[k++] = m[j++];
    }
    while (i <= middle) t[k++] = m[i++];
    while (j <= r) t[k++] = m[j++];
    k = 0;
    for (i = l; i <= r; i++) m[i] = t[k++];
}