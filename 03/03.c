#include <stdio.h>
#include <string.h>
#define NUM_MAX 1024
/*
stack 구현
input
*/


typedef struct stack_s {
    int top;                // size = top + 1, empty = (top == -1)
    int value[NUM_MAX];
} stack;

void init(stack *s) {
    s->top = -1;
}

void push(stack *s, int x) {
    s->value[++s->top] = x;
}

int pop(stack *s) {
    if (s->top == -1)
        return -1;
    return s->value[s->top--];
}





int main() {
    stack st;
    int n;

    init(&st);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char s[10];
        scanf("%s", s);
        
        if (!strcmp(s, "push")) {
            int tmp;
            scanf("%d", &tmp);
            push(&st, tmp);
        } else if (!strcmp(s, "pop")) {
            ///

        } else if (!strcmp(s, "size")) {

        } else if (!strcmp(s, "empty")) {

        } else if (!strcmp(s, "top")) {
        }
    }

    printf("%d\n", pop(&st));
    


    return 0;
}
