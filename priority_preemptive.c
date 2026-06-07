#include<stdio.h>

int main()
{
    int n,i;
    int at[10],bt[10],pr[10];
    int rem[10],ct[10],tat[10],wt[10];
    int time=0,count=0,high;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter AT BT Priority:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rem[i]=bt[i];
    }

    while(count<n)
    {
        high=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rem[i]>0)
            {
                if(high==-1 || pr[i]<pr[high])
                    high=i;
            }
        }

        if(high==-1)
        {
            time++;
            continue;
        }

        rem[high]--;            //preemtive 
        time++;

        if(rem[high]==0)
        {
            ct[high]=time;
            tat[high]=ct[high]-at[high];
            wt[high]=tat[high]-bt[high];
            count++;
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],pr[i],
               ct[i],tat[i],wt[i]);
    }

    return 0;
}