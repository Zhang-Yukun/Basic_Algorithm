#include <stdio.h>

#define N 100005

int q[N], n, k;

void quick_sort(int q[], int left, int right);

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    quick_sort(q, 0, n - 1);
    printf("%d", q[k - 1]);
}
void quick_sort(int q[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = q[left + ((right - left) >> 1)], l = left, r = right, temp = 0;
    while (1) {
        while (q[l] < pivot) {
            l++;
        }
        while (q[r] > pivot) {
            r--;
        }
        if (l >= r) {
            break;
        }
        temp = q[l];
        q[l++] = q[r];
        q[r--] = temp;
    }
    quick_sort(q, left, r);
    quick_sort(q, r + 1, right);
}