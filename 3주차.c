#include <stdio.h>

int main()
{
    int n;
    int in[101];
    int out[101];
    int stock[101];
    int i;

    int total_in = 0;
    int total_out = 0;

    int max_id = 1;
    int min_id = 1;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &in[i]);
        total_in += in[i];
    }

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &out[i]);
        total_out += out[i];
    }

    for (i = 1; i <= n; i++)
    {
        stock[i] = in[i] - out[i];
    }

    for (i = 2; i <= n; i++)
    {
        if (out[i] > out[max_id])
            max_id = i;
        if (out[i] < out[min_id])
            min_id = i;
    }

    printf("재고수량 : ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", stock[i]);
    }
    printf("\n");

    printf("총 판매량 : %d (판매율 %.2f%%)\n", total_out, (double)total_out / total_in * 100);

    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", max_id, out[max_id]);
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", min_id, out[min_id]);

    for (i = 1; i <= n; i++)
    {
        if (stock[i] <= 2)
        {
            printf("상품 ID %d : 재고부족(%d)\n", i, stock[i]);
        }
    }

    return 0;
}
