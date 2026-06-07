#include<stdio.h>

int main()
{
    int n,i;
    int bt[10],rem[10];
    int ct[10],tat[10],wt[10];

    int q1=4,q2=8;
    int time=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Burst Times:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rem[i]=bt[i];
    }

    printf("\nQueue 1 (RR, Quantum = 4)\n");

    for(i=0;i<n;i++)
    {
        if(rem[i]>q1)
        {
            printf("P%d -> Q2\n",i+1);
            rem[i]-=q1;
            time+=q1;
        }
        else
        {
            time+=rem[i];
            rem[i]=0;
            ct[i]=time;

            printf("P%d Finished\n",i+1);
        }
    }

    printf("\nQueue 2 (RR, Quantum = 8)\n");

    for(i=0;i<n;i++)
    {
        if(rem[i]>0)
        {
            if(rem[i]>q2)
            {
                printf("P%d -> Q3\n",i+1);

                rem[i]-=q2;
                time+=q2;
            }
            else
            {
                time+=rem[i];
                rem[i]=0;
                ct[i]=time;

                printf("P%d Finished\n",i+1);
            }
        }
    }

    printf("\nQueue 3 (FCFS)\n");

    for(i=0;i<n;i++)
    {
        if(rem[i]>0)
        {
            time+=rem[i];
            rem[i]=0;
            ct[i]=time;

            printf("P%d Finished\n",i+1);
        }
    }

    printf("\nProcess\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i];
        wt[i]=tat[i]-bt[i];

        printf("P%d\t%d\t%d\t%d\t%d\n",
               i+1,bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}