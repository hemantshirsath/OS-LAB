#include <stdio.h>
struct process
{
    int bt, wt, tat, no;
};
int main()
{
    struct process p[10], t;
    float avg_w, avg_t;
    int i, j, k, ch, n, qntm, c;
    printf("\nEnter number of processes ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for P%d ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].no = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].bt > p[j].bt)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }

    p[0].wt = 0;
    p[0].tat = p[0].bt + p[0].wt;
    for (int i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].bt + p[i].wt;
    }
    printf("\nGantt Chart is ");
    printf("\n0 ");
    for (int i = 0; i < n; i++)
    {
        printf(" P%d %d", p[i].no, p[i].tat);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].no > p[j].no)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    printf("\nP \tBT \tWT \tTAT");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d \t%d \t%d \t%d", p[i].no, p[i].bt, p[i].wt, p[i].tat);
    }
    avg_t = 0;
    avg_w = 0;
    for (int i = 0; i < n; i++)
    {
        avg_t += avg_t + p[i].tat;
        avg_w = avg_w + p[i].wt;
    }
    avg_t = (float)avg_t / n;
    avg_w = (float)avg_w / n;
    printf("\nAverage Waiting time %.2f", avg_w);
    printf("\nAverage Turn Around Time %.2f", avg_t);
    return 0;
}