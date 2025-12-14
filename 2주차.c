/*#include<stdio.h>
#include<stdlib.h>
int main()
{
	int score[100];
	for (int i = 0; i < 3; i++) scanf("%d", &array[i]);
	for (int i = 0; i < 3; i++) printf("%d", array[i]);
}

*/

#include <stdio.h>

int main()
{
    int n;
    int in[101];
    int out[101];
    int stock[101];
    int id;
    int i;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &in[i]);
    }

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &out[i]);
    }

    for (i = 1; i <= n; i++)
    {
        stock[i] = in[i] - out[i];
    }

    scanf("%d", &id);

    printf("%d\n", stock[id]);

    for (i = 1; i <= n; i++)
    {
        printf("%d ", stock[i]);
    }

    return 0;
}
