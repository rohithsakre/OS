#include<stdio.h>

int main()
{
    int at[10],bt[10],ct[10],tat[10],wt[10];
    int n, i,min;
    int time=0,completed[10]={0},count=0;;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter AT and BT:\n");

    for(i=0;i<n;i++)
        scanf("%d%d",&at[i],&bt[i]);
    int order[10];
    int k=0;

    while(count<n)
    {   
        min=-1;
         for(int i=0;i<n;i++)
         {
            if(at[i]<=time&&completed[i]==0)
            {
                if(min==-1||bt[i]<bt[min])
                {
                    min=i;
                }
            }
         }

         if(min==-1)
         {
            time++;
            continue;
         }
         order[k++]=min;

         time+=bt[min];

         ct[min]=time;
         tat[min]=ct[min]-at[min];
         wt[min]=tat[min]-bt[min];
         completed[min]=1;
         count++;

    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1,at[i],bt[i],ct[i],tat[i],wt[i]);


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