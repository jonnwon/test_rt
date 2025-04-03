#include <stdio.h>
#include <math.h>

int func1(int n) {         // 제곱의 합
    int res = 0; 

    for (int i = 1; i <= n; i++) {
        res += i * i;
    }
    return res;
}

int func2(int n) {          // 햡의 제곱
    int res = 0;
    
    for (int i = 1; i <= n; i++) {
        res += i;
    }
    return res * res;
}

int main() {
    printf("%d\n", func2(100) - func1(100));

    return 0;
}
