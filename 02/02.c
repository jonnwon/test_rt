#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int card[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &card[i]);
    }

    // 오름차순 정렬
    qsort(card, n, sizeof(int), compare);

    int max_sum = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = n - 1; k > j; k--) {
                int sum = card[i] + card[j] + card[k];
                if (sum > m) continue; // 블랙잭 룰 위반
                if (sum > max_sum) max_sum = sum;
                break; // k 더 줄이면 sum 더 작아지니 break
            }
        }
    }

    printf("%d\n", max_sum);
    return 0;
}
