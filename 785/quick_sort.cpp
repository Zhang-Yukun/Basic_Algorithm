
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], n;

void quick_sort(int left, int right);

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
}

void quick_sort(int left, int right) {
    if (left >= right) return;
    int l = left, r = right, pivot = q[l + ((r - l) >> 1)];
    while (true) {
        while (q[l] < pivot) l++;
        while (q[r] > pivot) r--;
        if (l >= r) {
            break;
        }
        swap(q[l++], q[r--]);
    }
    quick_sort(left, r);
    quick_sort(r + 1, right);
}