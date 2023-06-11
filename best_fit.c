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

        printf("ALLOCATION BY BEST FIT:-");
        for (j = 1; j <= nr; j++)
        {
            l = 1;
            f = 0;
            for (i = 1; i <= n; i++)
            {
                if (size[i] >= req[j] && fm[i] == 0 && fn[j] == 0)
                {
                    k[i] = size[i] - req[j];
                    f = 1;
                }
                else
                    k[i] = 999;
            }
            if (f == 0)
            {
                printf("\n\t%d is not allocated.", req[j]);
            }
            else
            {
                min = k[1];
                for (i = 1; i <= n; i++)
                {
                    if (min > k[i])
                    {
                        min = k[i];
                        l = i;
                    }
                }
                printf("\n\t%d is allocated by %d internal fragmentation is %d", req[j], size[l], min);
                fm[l] = 1;
            }
        }
    }
    else
        printf("\nYou have requested more holes than available.");
}
