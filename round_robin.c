#include <stdio.h>
struct process
{
    int bt, wt, tat, no;
};
int main()
{
    struct process p[10], t;
    float avg_wt, avg_tat;
    int qntm, n;
    printf("Enter number or processes : ");
    scanf("%d", &n);
    printf("\nEnter Time Quantum : ");
    scanf("%d", &qntm);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for P%d ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].no = p[i].bt;
        p[i].wt = 0;
        p[i].tat = 0;
    }
    printf("\nGantt Chart is : ");
    printf("\n0 ");
    int c = 0;
    int i = 0;
    int j = 0;
    while (c < n)
    {
        if (p[i].bt > 0)
        {
            if (p[i].bt < qntm)
            {
                p[i].wt = p[i].wt + (j - p[i].tat);
                c++;
                j += p[i].bt;
                p[i].tat = j;
                p[i].bt = 0;
                printf(" P%d %d", i + 1, p[i].tat);
            }
            else
            {
                p[i].bt -= qntm;
                p[i].wt = p[i].wt + (j - p[i].tat);
                j += qntm;
                p[i].tat = j;
                printf(" P%d %d", i + 1, p[i].tat);
                if (p[i].bt == 0)
                {
                    c++;
                }
            }
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else
            i++;
    }
    for (int i = 0; i < n; i++)
    {
        p[i].bt = p[i].no;
        p[i].no = i + 1;
    }
    printf("\n\nP \tBT \tWT \tTAT");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d \t%d \t%d \t%d", p[i].no, p[i].bt, p[i].wt, p[i].tat);
    }
    avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    avg_tat = (float)avg_tat / n;
    avg_wt = (float)avg_wt / n;
    printf("\nAverage Waiting time is %.2f ", avg_wt);
    printf("\nAverage TAT is %.2f ", avg_tat);
    return 0;
}