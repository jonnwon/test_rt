#include <stdio.h>
#include <limits.h>

/*
3중
*/

int my_max(int a, int b) {
    if (a >= b)
        return a;
    return b;
}

int my_min(int a, int b) {
    if (a > b)
        return b;
    return a;
}


int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    
    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    int sum = 0;
    int distance = INT_MAX;                                 // 합과 m과의 차이
    int answer = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                sum = num[i] + num[j] + num[k];              // 합
                int tmp = my_max(sum, m) - my_min(sum, m);   // 현재 합과 m과의 차이
                if (tmp < distance) {
                    distance = tmp;
                    answer = sum;
                }
            }
        }
    }
    printf("%d\n", answer);

    return 0;
}
