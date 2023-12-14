#include <stdio.h>

#define N 100005

int m[N], n, q, k, l, r;

void binary_search_left(k);
void binary_search_right(k);

int main(){
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        binary_search_left(k);
        binary_search_right(k);
        printf("%d %d\n", l, r);
    }
    return 0;
}

void binary_search_left(k) {
    int left = 0, right = n - 1, middle = left + ((right - left) >> 1);
    while (left <= right) {
        if (m[middle] == k) {
            if ((middle == 0) || (m[middle - 1] < k)) {
                l = middle;
                return;
            }
            right = middle - 1;
        } else if (m[middle] < k) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
        middle = left + ((right - left) >> 1);
    }
    l = -1;
}

void binary_search_right(k) {
    int left = 0, right = n - 1, middle = left + ((right - left) >> 1);
    while (left <= right) {
        if (m[middle] == k) {
            if ((middle == n - 1) || (m[middle + 1] > k)) {
                r = middle;
                return;
            }
            left  = middle + 1;
        } else if (m[middle] < k) {
            left  = middle + 1;
        } else {
            right = middle - 1;
        }
        middle = left + ((right - left) >> 1);
    }
    r = -1;
}