#include<stdio.h>

int main()
{
    int n,i,time=0,count=0,min;
    int at[10],bt[10],rem[10],dl[10];
    int ct[10],tat[10],wt[10];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter AT BT Deadline:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&at[i],&bt[i],&dl[i]);
        rem[i]=bt[i];
    }

    while(count<n)
    {
        min=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rem[i]>0)
            {
                if(min==-1 || dl[i]<dl[min])
                    min=i;
            }
        }

        if(min==-1)
        {
            time++;
            continue;
        }

        rem[min]--;
        time++;

        if(rem[min]==0)
        {
            ct[min]=time;
            tat[min]=ct[min]-at[min];
            wt[min]=tat[min]-bt[min];
            count++;
        }
    }

    printf("\nP\tAT\tBT\tDL\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],dl[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}