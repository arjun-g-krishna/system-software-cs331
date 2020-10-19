#include <stdio.h>

struct block
{
    int fname;
    int st;
    int bl;
    int bno[10];
} b[10];

void main()
{
    int i, j, x, ch, n;
    printf("Enter no of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        b[i].fname = i + 1;
        printf("\nEnter Starting block of File %d:", b[i].fname);
        scanf("%d", &b[i].st);
        printf("\nEnter no. of Blocks occupied by File:");
        scanf("%d", &b[i].bl);
        b[i].bno[0] = b[i].st;
        printf("\nEnter Blocks of File\n");
        for (j = 1; j <= b[i].bl - 1; j++)
            scanf("%d", &b[i].bno[j]);
    }
    printf("\nFile Allocation Table\n");
    printf("\nFile name______Start__________Size____Block\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t", b[i].fname, b[i].st, b[i].bl);
        for (j = 0; j < b[i].bl - 1; j++)
            printf("%d-->", b[i].bno[j]);
        printf("%d", b[i].bno[j]);
        printf("\n");
    }
}
