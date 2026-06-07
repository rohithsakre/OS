#include <stdio.h>

int main()
{
    int pages[20], frame[10];
    int n, f, i, j, k;
    int faults = 0, found;
    int pos, farthest, index;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            pos = -1;

            for(j = 0; j < f; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
            {
                farthest = -1;

                for(j = 0; j < f; j++)
                {
                    index = n;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frame[j] == pages[k])
                        {
                            index = k;
                            break;
                        }
                    }

                    if(index > farthest)
                    {
                        farthest = index;
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
            faults++;
        }
    }

    printf("Page Faults = %d", faults);

    return 0;
}