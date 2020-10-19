#include <stdio.h>
#include <math.h>

struct block
{
    int fno;
    int l;
    int st;
} b[10];

void main()
{
    int free, n, s, i = 0, ch, x, y;
    printf("Enter no of blocks:");
    scanf("%d", &n);
    printf("\nEnter block size:");
    scanf("%d", &s);
    free = n;
    while (1)
    {
        printf("\nEnter File no. & Size\n");
        scanf("%d %d", &x, &y);
        if (free > (double)y / s)
        {
            b[i].fno = x;
            b[i].l = (double)y / s;
            b[i].st = n - free;
            free = free - b[i].l;
            i++;
        }
        else
        {
            printf("/Ran out of memory");
            break;
        }
        printf("\nEnter more?(0/1)\n");
        scanf("%d", &ch);
        if (!ch)
            break;
    }
    printf("\nFile Allocation Table\n");
    printf("\nFile no___Starting block___Length\n");
    for (int j = 0; j < i; j++)
        printf("%d\t\t%d\t\t%d\n", b[j].fno, b[j].st, b[j].l);
}
