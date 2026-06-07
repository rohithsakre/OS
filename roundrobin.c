#include<stdio.h>

int main()
{
    int n,tq;
    int at[10],bt[10],rem[10];
    int ct[10],tat[10],wt[10];
    int i,time=0,done;
    int order[100];
    int k=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter AT and BT:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d%d",&at[i],&bt[i]);
        rem[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    while(1)
    {
        done=1;

        for(int i=0;i<n;i++)
        {
            if(at[i]<=time&&rem[i]>0)
            {
                done=0;
                if(rem[i]>tq)                         //done = 0 → at least one process got CPU time.
                                                        //done = 1 → no process was executed.
                {
                    order[k++]=i;               // whenever CPU gets a turn store it in order so a to print the sequence
                    time+=tq;
                    rem[i]-=tq;
                }
                else{
                    order[k++]=i;
                    time+=rem[i];
                    rem[i]=0;
                    ct[i]=time;
                }
            }
        }
    
        if(done)
        {
            int all = 1;
            for(i=0;i<n;i++)
            {
                if(rem[i]>0)
                {
                    all=0;
                    time++;
                    break;
                }
            }
            if(all)
                break;
        }

    }


printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nExecution Order:\n");
    

for(i=0;i<k;i++)
{
    printf("P%d", order[i]+1);

    if(i != k-1)
        printf(" -> ");
}
    return 0;
}
