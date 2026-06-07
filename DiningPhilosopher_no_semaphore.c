#include<stdio.h>

int fork[5] = {1,1,1,1,1};

int wait(int *s)
{
    if(*s > 0)
    {
        (*s)--;
        return 1;
    }

    return 0;
}

void signal(int *s)
{
    (*s)++;
}

int main()
{
    int p;

    while(1)
    {
        printf("\nEnter Philosopher Number (0-4): ");
        scanf("%d",&p);

        if(wait(&fork[p]))
        {
            if(wait(&fork[(p+1)%5]))
            {
                printf("Philosopher %d is eating\n",p);

                signal(&fork[p]);
                signal(&fork[(p+1)%5]);

                printf("Philosopher %d is thinking\n",p);
            }
            else
            {
                signal(&fork[p]);
                printf("Right fork not available\n");
            }
        }
        else
        {
            printf("Left fork not available\n");
        }
    }
}