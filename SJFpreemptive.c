#include <stdio.h>

int main()
{
    int at[10], bt[10], rt[10];
    int ct[10], tat[10], wt[10];
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter AT and BT:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];   // Remaining Time
    }

    int time = 0, count = 0, min;

    while(count < n)
    {
        min = -1;

        // Find process with shortest remaining time
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(min == -1 || rt[i] < rt[min])
                    min = i;
            }
        }

        // No process has arrived yet
        if(min == -1)
        {
            time++;
            continue;
        }

        // Execute for 1 unit of time
        rt[min]--;
        time++;

        // Process completed
        if(rt[min] == 0)
        {
            ct[min] = time;
            tat[min] = ct[min] - at[min];
            wt[min] = tat[min] - bt[min];
            count++;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}