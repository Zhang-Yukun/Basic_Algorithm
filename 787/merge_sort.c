// #include <stdio.h>

// #define N 100005

// int m[N], t[N];

// void merge_sort(int m[], int left, int right);

// int main() {
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &m[i]);
//     }
//     merge_sort(m, 0, n - 1);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", m[i]);
//     }
//     return 0;
// }
// void merge_sort(int m[], int left, int right) {
//     if (left >= right) {
//         return;
//     }
//     int middle = left + ((right - left) >> 1);
//     merge_sort(m, left, middle);
//     merge_sort(m, middle + 1, right);
//     int i = left, j = middle + 1, k = 0;
//     while ((i <= middle) && (j <= right)) {
//         if (m[i] <= m[j]) {
//             t[k++] = m[i++];
//         } else {
//             t[k++] = m[j++];
//         }
//     }
//     while (i <= middle) {
//         t[k++] = m[i++];
//     }
//     while (j <= right) {
//         t[k++] = m[j++];
//     }
//     for (int i = 0; i < k; i++) {
//         m[left + i] = t[i];
//     }
// }

#include <stdio.h>

#define N 100005

int m[N], t[N], n;

void merge_sort(int left, int right);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &m[i]);
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", m[i]);
    return 0;
}

void merge_sort(int left, int right) {
    if (left >= right) return;
    int middle = left + ((right - left) >> 1), i = left, j = middle + 1, k = 0;
    merge_sort(left, middle);
    merge_sort(middle + 1, right);
    while ((i <= middle) && (j <= right)) {
        if (m[i] <= m[j]) t[k++] = m[i++];
        else t[k++] = m[j++];
    }
    while (i <= middle) t[k++] = m[i++];
    while (j <= right) t[k++] = m[j++];
    k = 0;
    for (int l = left; l <= right; l++) m[l] = t[k++];
}