#include <stdio.h>

// condition이 1이면 두 정수를 교환하고, 0 이면 교환하지 않습니다.
void swap_if(int *a, int *b, int condition) {
    int mask = -condition;      // 1 -> 0xFFFFFFFF, 0 -> 0x00000000
    int tmp = *a;
    
    *a = (tmp & ~mask) | (*b & mask);
    *b = (tmp & mask) | (*b & ~mask);
}

// x의 절대값을 반환합니다.
int compute_abs(int x) {
    int mask = x >> 31;     // 양수면 0, 음수면 -1
    return (x ^ mask) - mask;
}

// a와 b 중 큰 값을 반환합니다.
int get_max(int a, int b)
{
    int diff = a - b;
    int mask = diff >> 31;          // 음수면 -1 (b가 큼), 양수면 0 (a가 큼)
    return (a & ~mask) | (b & mask);
}

// a와 b 중 작은 값을 반환합니다.
int get_min(int a, int b) {
    int diff = a - b;
    int mask = diff >> 31;
    return (b & ~mask) | (a & mask);
}

// 홀수면 1, 짝수면 0을 반환합니다. 
int check_odd(int x) {
    return x & 1;
}


int main(void)
{
    // swap_if test
    int a = 10, b = 20;
    swap_if(&a, &b, 1);
    printf("swap_if(&a, &b, 1): a = %d, b = %d\n", a, b);  // a = 20, b = 10

    swap_if(&a, &b, 0);
    printf("swap_if(&a, &b, 0): a = %d, b = %d\n", a, b);  // a = 20, b = 10

    // compute_abs test
    printf("compute_abs(5) = %d\n", compute_abs(5));     // 5
    printf("compute_abs(-5) = %d\n", compute_abs(-5));   // 5

    // get_max test
    printf("get_max(10, 20) = %d\n", get_max(10, 20));   // 20
    printf("get_max(30, 20) = %d\n", get_max(30, 20));   // 30

    // get_min test
    printf("get_min(10, 20) = %d\n", get_min(10, 20));   // 10
    printf("get_min(30, 20) = %d\n", get_min(30, 20));   // 20

    // check_odd test
    printf("check_odd(3) = %d\n", check_odd(3));         // 1
    printf("check_odd(4) = %d\n", check_odd(4));         // 0

    return 0;
}

