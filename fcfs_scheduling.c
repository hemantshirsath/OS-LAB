#include <stdio.h>
struct process
{
    int bt, wt, tat, no, prio;
};
int main()
{
    struct process p[10], t;
    float avg_w, avg_t;
    int i, j, k, ch, n, qntm, c;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for P%d:  ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].no = i + 1;
    }
    p[0].wt = 0;
    p[0].tat = p[0].wt + p[0].bt;
    for (int i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }
    printf("\nGantt Chart is : ");
    printf("\n0 ");
    for (int i = 0; i < n; i++)
    {
        printf(" P%d %d", p[i].no, p[i].tat);
    }
    printf("\nP \tBT \tWT \tTAT");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d", i + 1, p[i].bt, p[i].wt, p[i].tat);
    }
    avg_w = 0, avg_t = 0;
    for (int i = 0; i < n; i++)
    {
        avg_w += p[i].wt;
        avg_t += p[i].tat;
    }
    avg_t = (float)avg_t / n;
    avg_w = (float)avg_w / n;
    printf("\n\nAverage waiting time is %.2f", avg_w);
    printf("\nAverage Turn Around time is %.2f", avg_t);
    return 0;
}