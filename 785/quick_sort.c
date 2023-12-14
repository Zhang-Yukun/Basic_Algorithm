#include <stdio.h>

#define N 100005

int q[N], n;

void quick_sort(int left, int right);

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}

void quick_sort(int left, int right) {
    if (left >= right) return;
    int pivot = q[left + ((right - left) >> 1)], l = left, r = right, temp = 0;
    while (1) {
        while (q[l] < pivot) l++;
        while (q[r] > pivot) r--;
        if (l >= r) break;
        temp = q[l];
        q[l++] = q[r];
        q[r--] = temp;
    }
    quick_sort(left, r);
    quick_sort(r + 1, right);
}