#include <stdio.h>
struct process
{
    int bt, wt, tat, no, prio;
};
int main()
{
    struct process p[10], t;
    float avg_w, avg_t;
    int n;
    printf("Enter number of processes ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter burst time for P%d ", i + 1);
        scanf("%d", &p[i].bt);
        printf("\nEnter priority for p%d : ", i + 1);
        scanf("%d", &p[i].prio);
        p[i].no = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].prio > p[j].prio)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    p[0].wt = 0;
    p[0].tat = p[0].wt + p[0].bt;
    for (int i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }
    printf("\nGantt Chart ");
    printf("\n0 ");
    for (int i = 0; i < n; i++)
    {
        printf(" P%d %d", p[i].no, p[i].tat);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (p[i].no > p[j].no)
    //         {
    //             t = p[i];
    //             p[i] = p[j];
    //             p[j] = t;
    //         }
    //     }
    // }
    printf("\nP \tBT \tWT \tTAT \tPRI");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d \t%d \t%d \t%d \t%d", p[i].no, p[i].bt, p[i].wt, p[i].tat, p[i].prio);
    }
    for (int i = 0; i < n; i++)
    {
        avg_w += p[i].wt;
        avg_t += p[i].tat;
    }
    avg_w = (float)avg_w / n;
    avg_t = (float)avg_t / n;
    printf("\nAverage WT is %.2f", avg_w);
    printf("\nAverage TAT is %.2f", avg_t);

    return 0;
}