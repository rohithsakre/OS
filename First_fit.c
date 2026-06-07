#include <stdio.h>
int main()
{
    int i, j, m, n;
    int p[10], b[10];
    printf("enter the no of blocks\n");
    scanf("%d", &m);

    printf("enter the block sizes\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d",&b[i]);
    }
    printf("enter the no of processes\n");
    scanf("%d", &n);
    printf("enter the proesses sizes\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }

    printf("Process\tSize\tBlock\n");

    for (i = 0; i < n; i++)
    {
        int flag = 0;
        for (j = 0; j < m; j++)
        {
            if (b[j] >= p[i])
            {
                printf("P%d\t%d\t%d\n", i + 1, p[i], j + 1);
                b[j] -= p[i];
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("P%d\t%d\tNot Allocated\n", i + 1, p[i]);
        }
    }

    return 0;
}