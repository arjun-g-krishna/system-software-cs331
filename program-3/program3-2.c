#include <stdio.h>

struct block
{
    int fname;
    int index;
    int l;
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
        b[i].index = i;
        printf("\nEnter Starting block & Size of File %d\n", b[i].fname);
        scanf("%d %d", &b[i].st, &b[i].l);
        printf("\nEnter no. of Blocks occupied by File\n");
        scanf("%d", &b[i].bl);
        printf("\nEnter Blocks of File\n");
        for (j = 0; j < b[i].bl; j++)
            scanf("%d", &b[i].bno[j]);
    }
    printf("\nFile Allocation Table\n");
    printf("\nFile name______Index________Length\n");
    for (j = 0; j < n; j++)
        printf("%d\t\t%d\t\t%d\n", b[j].fname, b[j].index, b[j].bl);

    while (1)
    {
        printf("Check for files?(0/1)");
        scanf("%d", &ch);
        if (ch)
        {
            printf("\nEnter File name:");
            scanf("%d", &x);
            i = x - 1;
            if (i < 0 || i >= n)
            {
                printf("\nNo such file exists");
                break;
            }
            printf("Index is:%d\n", b[i].index);
            printf("Blocks occupied are:");
            for (j = 0; j < b[i].bl; j++)
                printf("%d ", b[i].bno[j]);
            printf("\n");
        }
        else
            break;
    }
}
