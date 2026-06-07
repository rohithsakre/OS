#include<stdio.h>

int main()
{
    int n,i;
    int weight[10];
    int total=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter weight of P%d: ",i+1);
        scanf("%d",&weight[i]);

        total += weight[i];
    }

    printf("\nCPU Share:\n");

    for(i=0;i<n;i++)
    {
        float share;

        share = ((float)weight[i]/total)*100;

        printf("P%d = %.2f%%\n",i+1,share);
    }

    return 0;
}