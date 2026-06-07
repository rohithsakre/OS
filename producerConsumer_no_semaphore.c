#include<stdio.h>

int mutex = 1, full = 0, empty = 5;
int buffer[5];
int in = 0, out = 0;

void wait(int *s)
{
    if(*s > 0)
        (*s)--;
}

void signal(int *s)
{
    (*s)++;
}

void produce(int item)
{
    wait(&empty);
    wait(&mutex);

    buffer[in] = item;
    printf("Produced item %d\n", item);

    in = (in + 1) % 5;

    signal(&mutex);
    signal(&full);
}

void consume()
{
    int item;

    wait(&full);
    wait(&mutex);

    item = buffer[out];
    printf("Consumed item %d\n", item);

    out = (out + 1) % 5;

    signal(&mutex);
    signal(&empty);
}

int main()
{
    int ch, item;

    while(1)
    {
        printf("\n1. Produce");
        printf("\n2. Consume");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                if(empty > 0)
                {
                    printf("Enter item: ");
                    scanf("%d", &item);
                    produce(item);
                }
                else
                {
                    printf("Buffer Full\n");
                }
                break;

            case 2:
                if(full > 0)
                {
                    consume();
                }
                else
                {
                    printf("Buffer Empty\n");
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}