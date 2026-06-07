#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m];
    int avail[m], finish[n];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Initialize finish array
    for(i = 0; i < n; i++) {
        int flag = 0;
        for(j = 0; j < m; j++) {
            if(alloc[i][j] != 0) {
                flag = 1;
                break;
            } 
        }

        if(flag)
            finish[i] = 0;
        else
            finish[i] = 1;
    }

    int found;

    do {
        found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {

                for(j = 0; j < m; j++) {
                    if(request[i][j] > avail[j])
                        break;
                }

                if(j == m) {
                    for(k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while(found);

    int deadlock = 0;

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            deadlock = 1;
            printf("Process P%d is deadlocked.\n", i);
        }
    }

    if(deadlock == 0)
        printf("\nNo Deadlock Detected.\n");

    return 0;
}