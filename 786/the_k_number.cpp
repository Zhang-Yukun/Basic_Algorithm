// #include <iostream>

// using namespace std;

// const int N = 1e5 + 5;
// int n, k;
// int q[N];

// void quick_sort(int q[], int left, int right, int k);

// int main() {
//     scanf("%d %d", &n, &k);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &q[i]);
//     }
//     quick_sort(q, 0, n - 1, k);
//     printf("%d", q[k - 1]);
//     return 0;
// }

// void quick_sort(int q[], int left, int right, int k) {
//     if (left >= right) {
//         return;
//     }
//     int pivot = q[left + ((right - left) >> 1)], l = left, r = right;
//     while (true) {
//         while (q[l] < pivot) l++;
//         while (q[r] > pivot) r--;
//         if (l >= r) {
//             break;
//         }
//         swap(q[l++], q[r--]);
//     }
//     if (k <= r - left + 1) {
//         quick_sort(q, left, r, k);
//     } else {
//         quick_sort(q, r + 1, right, k - (r - left + 1));
//     }
// }

// #include <iostream>

// using namespace std;

// const int N = 1e5 + 10;
// int q[N], n, k;

// int quick_sort(int q[], int left, int right, int k);

// int main() {
//     scanf("%d %d", &n, &k);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &q[i]);
//     }
//     printf("%d", quick_sort(q, 0, n - 1, k));
//     return 0;
// }

// int quick_sort(int q[], int left, int right, int k) {
//     if (left >= right) {
//         return q[left];
//     }
//     int l = left, r = right, pivot = q[l + ((r - l) >> 1)];
//     while (true) {
//         while (q[l] < pivot) l++;
//         while (q[r] > pivot) r--;
//         if (l >= r) {
//             break;
//         }
//         swap(q[l++], q[r--]);
//     }
//     if (k <= r - left + 1) {
//         return quick_sort(q, left, r, k);
//     } else {
//         return quick_sort(q, r + 1, right, k - (r - left + 1));
//     }
// }

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], n, k, result;

int quick_sort(int left, int right, int k);

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    result = quick_sort(0, n - 1, k);
    printf("%d", result);
    return 0;
}

int quick_sort(int left, int right, int k) {
    if (left >= right) return q[left];
    int l = left, r = right, pivot = q[l + ((r - l) >> 1)];
    while (true) {
        while (q[l] < pivot) l++;
        while (q[r] > pivot) r--;
        if (l >= r) break;
        swap(q[l++], q[r--]);
    }
    if (k <= r - left + 1) return quick_sort(left, r, k);
    else return quick_sort(r + 1, right, k - (r - left + 1));
}