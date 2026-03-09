#include <stdio.h>
#include <string.h>

int main()
{
    int arr[100], n = 0;
    int N, i, j, x, min, pos;
    char op[10];

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            arr[n] = x;
            n++;
        }

        else if(strcmp(op, "delete") == 0)
        {
            if(n == 0)
            {
                printf("-1\n");
                continue;
            }

            min = arr[0];
            pos = 0;

            for(j = 1; j < n; j++)
            {
                if(arr[j] < min)
                {
                    min = arr[j];
                    pos = j;
                }
            }

            printf("%d\n", min);

            for(j = pos; j < n-1; j++)
                arr[j] = arr[j+1];

            n--;
        }

        else if(strcmp(op, "peek") == 0)
        {
            if(n == 0)
            {
                printf("-1\n");
                continue;
            }

            min = arr[0];

            for(j = 1; j < n; j++)
            {
                if(arr[j] < min)
                    min = arr[j];
            }

            printf("%d\n", min);
        }
    }

    return 0;
}