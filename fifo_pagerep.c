#include <stdio.h>
int check(int d, int x[], int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (x[i] == d)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
void print(int x[], int size)
{
    int i;
    for (int i = 0; i < size; i++)
    {
        if (x[i] == -1)
        {
            printf("\t%c", '-');
        }
        else
        {
            printf("\t%d", x[i]);
        }
    }
}
int main()
{
    int size, n, a[20];
    printf("Enter frame size: ");
    scanf("%d", &size);
    printf("\nHow many pages do you want : ");
    scanf("%d", &n);
    printf("\nEnter the sequence of pages : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int x[5];
    for (int i = 0; i < size; i++)
    {
        x[i] = -1;
    }
    int j = 0;
    int fault = 0;
    int k = 1;
    float s;
    for (int i = 0; i < n; i++)
    {
        int flag = check(a[i], x, size);

        if (!flag)
        {
            x[j] = a[i];
            fault++;
            printf("\nPage Frame %d : ", k++);
            print(x, size);
            j = (j + 1) % 3;
        }
    }
    s = (float)fault / (float)n;
    printf("\nTotal Number of page faults are %d ", fault);
    printf("\nFault rate is %f ", s);

    return 0;
}