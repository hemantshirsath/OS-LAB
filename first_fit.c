
#include <stdio.h>
int main()
{
    int i, j, n, t, size[10], req[10], nr, min, f, w = 1, l;
    int ch, fp[10], fm[10], fn[10], intfrg, k[10];

    printf("\nEnter no. of block of memory:-\t");
    scanf("%d", &n);
    printf("\nEnter size of memory:-\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &size[i]);
    }
    printf("Enter number of memory requested:-\t");
    scanf("%d", &nr);
    printf("\nEnter request size of memory:-\n");
    for (i = 1; i <= nr; i++)
    {
        scanf("%d", &req[i]);
    }
    if (nr <= n)
    {

        for (i = 1; i <= n; i++)
        {
            fm[i] = 0;
            fp[i] = 0;
        }

        for (i = 1; i <= nr; i++)
        {
            fn[i] = 0;
        }
        printf("\n\tALLOCATION BY FIRST FIT:-");
        for (j = 1; j <= nr; j++)
        {
            for (i = 1; i <= n; i++)
            {
                if (size[i] >= req[j] && fm[i] == 0 && fn[j] == 0)
                {
                    fm[i] = 1;
                    fn[j] = 1;
                    intfrg = size[i] - req[j];
                    printf("\n\t%d memory size is allocated to %d and internal fragmentation is %d.", req[j], size[i], intfrg);
                }
            }
            if (fn[j] == 0)
            {
                printf("\n\t%d is not allocated.", req[j]);
            }
        }
    }
    else
        printf("\nYou have requested more holes than available.");
}
