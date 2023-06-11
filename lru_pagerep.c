#include <stdio.h>
int find1(int a[], int p, int x[], int size)
{
    int j, i, t[5], q, m = 999, k = 0;
    j = 0;
    do
    {
        for (i = p; i >= 0; i--)
        {
            if (x[j] == a[i])
                break;
        }
        t[k++] = i;
        j++;
    } while (j < size);
    i = 0;
    while (i < size)
    {
        if (m > t[i])
        {
            m = t[i];
            q = i;
        }
        i++;
    }
    return q;
}
int check(int d, int x[], int size)
{
    int flag = 0, i;
    for (i = 0; i < size; i++)
    {
        if (x[i] == d)
            flag = 1;
    }
    return flag;
}
int print(int x[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (x[i] == -1)
            printf("\t%c", '-');
        else
            printf("\t%d", x[i]);
    }
}
int main()
{
    int i, size, n, a[20], ch;
    printf("\nENTER THE FRAME SIZE: ");
    scanf("%d", &size);
    printf("\nHOW MANY PAGES DO YOU WANT TO ENTER: ");
    scanf("%d", &n);
    printf("\nENTER THE SEQUENCE OF PAGES: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int x[5], flag, fault = 0, k = 1;
    float s;
    for (i = 0; i < size; i++)
    {
        x[i] = -1;
    }
    int j = -1;
    for (i = 0; i < n; i++)
    {
        flag = check(a[i], x, size);
        if (!flag)
        {
            if (fault >= 3)
                j = find1(a, i - 1, x, size);
            else
                j++;
            x[j] = a[i];
            fault++;
            printf("\nPAGE FRAME:%d", k++);
            print(x, size);
        }
    }
    printf("\nTOTAL NO FAULTS ARE:%d", fault);
    s = (float)fault / (float)n;
    printf("\nFAULT RATE:%f", s);
    return 0;
}