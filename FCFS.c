#include <stdio.h>

int main()
{
    int n,i,j,temp, at[10], pid[10], bt[10], wt[10], tat[10],ct[10];
    int time = 0;
    printf("enter the number of processes\n");
    scanf("%d", &n);
    printf("enter the arrival time of each processes\n");
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        scanf("%d", &at[i]);
    }
    printf("enter the burst time of the processes\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    // sorting acc to arrival time;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;

                
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(time<at[i])
        {
            time=at[i];
        }
        ct[i]=time+bt[i];
        time=ct[i];

        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

    }
     printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
