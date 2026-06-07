#include<stdio.h>

int mutex = 1, full = 0, empty = 3;
int item = 0;

int wait(int *s)
{
    if(*s > 0)
    {
        (*s)--;
        return 1;
    }

    printf("Blocked\n");
    return 0;
}

void signal(int *s)
{
    (*s)++;
}

void producer()
{
    if(wait(&empty) && wait(&mutex))
    {
        item++;

        printf("Produced Item %d\n", item);

        signal(&mutex);
        signal(&full);
    }
}

void consumer()
{
    if(wait(&full) && wait(&mutex))
    {
        printf("Consumed Item %d\n", item);

        item--;

        signal(&mutex);
        signal(&empty);
    }
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1. Produce");
        printf("\n2. Consume");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: producer(); break;
            case 2: consumer(); break;
            case 3: return 0;
        }

        printf("Full=%d Empty=%d\n",full,empty);
    }
}