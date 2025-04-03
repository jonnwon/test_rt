#include <stdio.h>
#include <string.h>
#define NUM_MAX 1024

typedef struct stack_s {
    int top;           
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

int size(stack *s) {
    return s->top + 1;
}

int empty(stack *s) {
    return s->top == -1 ? 1 : 0;
}

int top(stack *s) {
    if (s->top != -1)
        return s->value[s->top];
    return -1;
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
            printf("%d\n", pop(&st));
        } else if (!strcmp(s, "size")) {
            printf("%d\n", st.top + 1);
        } else if (!strcmp(s, "empty")) {
            printf("%d\n", empty(&st));
        } else if (!strcmp(s, "top")) {
            printf("%d\n", top(&st));
        }
    }
    return 0;
}
