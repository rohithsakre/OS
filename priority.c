#include<stdio.h>

int main()
{
    int n,i,time=0,count=0,high;
    int at[10],bt[10],pr[10];
    int ct[10],tat[10],wt[10];
    int completed[10]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter AT BT Priority:\n");

    for(i=0;i<n;i++)
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    int order[10];
    int k=0;
    while(count<n)
    {
        high=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && completed[i]==0)
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
        
        order[k++]=high;

        time += bt[high];
        ct[high]=time;
        tat[high]=ct[high]-at[high];
        wt[high]=tat[high]-bt[high];

        completed[high]=1;
        count++;
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    
                printf("execution order");
    for(int i=0;i<k;i++)
    {
        printf("P%d",order[i]+1);

        if(i!=k-1)
        {
            printf("->");
        }
    }
    return 0;

    
}