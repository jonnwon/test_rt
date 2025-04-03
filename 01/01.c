#include <stdio.h>

int main() {
    int map[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    int x = 1, y = 1;

    while (1) {
        if (map[x][y] == 0) {
            map[x][y] = 9;
        } else if (map[x][y] == 2) {
            map[x][y] = 9;
            break;
        }
        
        if (map[x][y + 1] != 1) {
            y++;
        } else if (map[x + 1][y] != 1) {
            x++;
        } else {
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
