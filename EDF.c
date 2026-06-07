#include<stdio.h>

int main()
{
    int n,i,j,temp;
    int bt[10],deadline[10],pid[10];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        pid[i]=i+1;

        printf("Enter BT and Deadline of P%d: ",i+1);
        scanf("%d%d",&bt[i],&deadline[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(deadline[i] > deadline[j])
            {
                temp=deadline[i];
                deadline[i]=deadline[j];
                deadline[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
            }
        }
    }

    printf("\nExecution Order:\n");

    for(i=0;i<n;i++)
    {
        printf("P%d",pid[i]);

        if(i!=n-1)
            printf(" -> ");
    }

    return 0;
}