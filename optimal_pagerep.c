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
int find0(int a[], int n, int x[], int size, int p)
{
    int k = 0, t[5], m = -1, j, i, q;
    j = 0;
    do
    {
        for (i = p; i < n; i++)
        {
            if (x[j] == a[i])
                break;
        }
        t[++k] = i;
        j++;
    } while (j < size);
    for (i = 0; i < size; i++)
    {
        if (t[i] > n)
            return i;
    }
    i = 0;
    while (i < size)
    {
        if (m < t[i])
        {
            m = t[i];
            q = i;
        }
        i++;
    }
    return q;
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
    int size, n;
    printf("Enter frame size ");
    scanf("%d", &size);
    printf("\n How many pages do you want : ");
    scanf("%d", &n);
    int a[10];
    printf("\nEnter sequence of pages:\n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int i, x[5], j, flag, fault = 0, k = 1;
    float s;
    for (i = 0; i < size; i++)
        x[i] = -1;
    j = -1;
    for (i = 0; i < n; i++)
    {
        flag = check(a[i], x, size);
        if (!flag)
        {
            if (fault >= size)
                j = find0(a, n, x, size, i + 1);
            else
                j++;
            x[j] = a[i];
            fault++;
            printf("\nPAGE FRAME:%d", k++);
            print(x, size);
        }
    }
    printf("\nTOTAL NO OF FAULTS ARE:%d", fault);
    s = (float)fault / (float)n;
    printf("\nFAULT RATE:%f", s);
    return 0;
}