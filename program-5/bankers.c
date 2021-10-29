#include <stdio.h>
int n, m;
void read(int alloc[][10], int max[][10], int avail[10], int need[][10], int n, int m);
void display(int temp[][10], int n, int m);
int safety(int alloc[][10], int avail[10], int need[][10], int n, int m);

int main()
{
    int alloc[10][10], max[10][10], avail[10], need[10][10];
    printf("DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n");
    read(alloc, max, avail, need, n, m);
    return 0;
}


void read(int alloc[][10], int max[][10], int avail[10], int need[][10], int n, int m) {

    int i, j;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    printf("Enter total number of resources: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Allocation Resource: ");
        for (j = 0; j < m; ++j) {
            scanf("%d", &alloc[i][j]);
        }
        printf("Maximum Resource: ");
        for (j = 0; j < m; ++j) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nAvailable System Resources: ");
    for (i = 0; i < m; ++i) {
        scanf("%d", &avail[i]);
    }
 
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            need[i][j] = max[i][j] - alloc[i][j];        
        }
    }

    printf("\nProcess\tCurrently-Allocated-Resources\n");
    display(alloc, n, m);
    printf("\nProcess\tMaximum-Resources\n");
    display(max, n, m);
    printf("\nProcess\tPossibly-Needed-Resources\n");
    display(need, n, m);

    safety(alloc, avail, need, n, m);
}





int safety(int alloc[][10], int avail[10], int need[][10], int n, int m)  {

    int i, j, k, index = 0;
    int isDone[10], sequence[10], count = 0;            /* array to store safety sequence */

    for (i = 0; i < n; ++i) {
        isDone[i] = 0;                                  /* array-> |0|0|0|0|0| */
    }

    for (k = 0; k < n; ++k) {                           /* Iterating for possible deadlock to prevent infinite loop */

        // main process starts
        for (i = 0; i < n; ++i)
        {
            if (isDone[i] == 0) {                       /* pending */
                for (j = 0; j < m; ++j)
                {
                    if (avail[j] >= need[i][j]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                if (j == m) {                           /* True: avail >= need */
                    for (j = 0; j < m; ++j) {
                        avail[j] += alloc[i][j];
                    }
                    count++;                            /* done process's count */
                    isDone[i] = 1;
                    sequence[count - 1] = i + 1;        /* safe state sequence */
                }
            }
        }
        
        if (count == n) {                               /* safe state */
            printf("\nIT'S A SAFE STATE\n");
            printf("The safe sequence is\n");
            int i;
            for (i = 0; i < n; ++i) {
                printf("P%d ", sequence[i]);
            }
            printf("\n");
            break;
        }
        // main process ends

    } /* deadlock check loop ends */

    if (count != n) {
        printf("\nDeadlock has occured.\n");            /* deadlock */
    }
}

void display(int temp[][10], int n, int m)
{
    int i, j;
    for (i = 0; i < n; ++i) {
        printf("P%d", i + 1);
        for (j = 0; j < m; ++j) {
            printf("\t%d", temp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
