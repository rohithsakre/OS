#include<stdio.h>

int main()
{
    int ns, nu;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    int i, time = 0;

    printf("Enter number of System Processes: ");
    scanf("%d",&ns);

    printf("Enter AT and BT for System Processes:\n");

    for(i=0;i<ns;i++)
        scanf("%d%d",&at[i],&bt[i]);

    printf("\nSystem Queue:\n");
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<ns;i++)
    {
        if(time < at[i])
            time = at[i];

        time += bt[i];

        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        printf("S%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nEnter number of User Processes: ");
    scanf("%d",&nu);

    printf("Enter AT and BT for User Processes:\n");

    for(i=0;i<nu;i++)
        scanf("%d%d",&at[i],&bt[i]);

    printf("\nUser Queue:\n");
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<nu;i++)
    {
        if(time < at[i])
            time = at[i];

        time += bt[i];

        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        printf("U%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}