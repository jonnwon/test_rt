#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define MAX_EDGES 150

int adj[MAX][MAX_EDGES];
int adj_size[MAX];
int indegree[MAX];
int used[MAX];
int res[MAX];
int res_size = 0;

//  큐
int queue[MAX], front = 0, rear = 0;
void push(int x) { queue[rear++] = x; }
int pop() { return queue[front++]; }
int empty() { return front == rear; }

void add_edge(int from, int to) {
    // 중복간선 방지
    for (int i = 0; i < adj_size[from]; i++) {
        if (adj[from][i] == to) return;
    }
    adj[from][adj_size[from]++] = to;
    indegree[to]++;
}

void topologySort() {
    // 진입차수 0인 노드 큐에 삽임
    for (int i = 0; i < MAX; i++) {
        if (used[i] && indegree[i] == 0) {
            push(i);
        }
    }
    
    while (!empty()) {
        int cur = pop();
        res[res_size++] = cur;
        
        // 간선 사이즈만큼 돌면서  내리기
        for (int i = 0; i < adj_size[cur]; i++) {
            int next = adj[cur][i];
            if (--indegree[next] == 0) {
                push(next);
            }
        }
    }
}

int main() {
    FILE *fp = fopen("./keylog.txt", "r");
    if (!fp) {
        printf("Error file open\n");
        return 1;
    }

    char buf[5];
    while (fgets(buf, sizeof(buf), fp)) {
        int a = buf[0] - '0';
        int b = buf[1] - '0';
        int c = buf[2] - '0';

        used[a] = used[b] = used[c] = 1;
        add_edge(a, b);
        add_edge(b, c);
    }
    fclose(fp);
    topologySort();
    
    // 출력
    printf("Password: ");
    for (int i = 0; i < res_size; i++) {
        printf("%d", res[i]);
    }
    printf("\n");

    return 0;
}
