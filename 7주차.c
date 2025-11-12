/*

#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;
    char name[50];
    int price;
    int stock;
    int sold;
} Product;

int main() {
    Product p[MAX] = { 0 };
    int count = 0;
    int menu;
    int id, qty;
    char name[50];
    int price;

    while (1) {
        printf("\n1. 입고\n2. 판매\n3. 개별현황\n4. 전체현황\n5. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &menu);

        if (menu == 1) {
            if (count >= MAX) {
                printf("상품이 꽉 찼습니다.\n");
                continue;
            }
            printf("상품ID: ");
            scanf("%d", &id);
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (p[i].id == id) found = i;
            }
            if (found == -1) {
                p[count].id = id;
                printf("상품명: ");
                scanf("%s", p[count].name);
                printf("입고수량: ");
                scanf("%d", &p[count].stock);
                printf("판매가격: ");
                scanf("%d", &p[count].price);
                p[count].sold = 0;
                count++;
            }
            else {
                printf("입고수량 추가: ");
                scanf("%d", &qty);
                p[found].stock += qty;
            }
        }
        else if (menu == 2) {
            printf("상품ID: ");
            scanf("%d", &id);
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (p[i].id == id) found = i;
            }
            if (found == -1) {
                printf("없는 상품입니다.\n");
            }
            else {
                printf("판매수량: ");
                scanf("%d", &qty);
                if (qty > p[found].stock) {
                    printf("재고가 부족합니다.\n");
                }
                else {
                    p[found].stock -= qty;
                    p[found].sold += qty;
                }
            }
        }
        else if (menu == 3) {
            printf("상품ID: ");
            scanf("%d", &id);
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (p[i].id == id) found = i;
            }
            if (found == -1) {
                printf("없는 상품입니다.\n");
            }
            else {
                printf("상품명: %s, 가격: %d, 재고: %d, 판매량: %d\n",
                    p[found].name, p[found].price, p[found].stock, p[found].sold);
            }
        }
        else if (menu == 4) {
            for (int i = 0; i < count; i++) {
                printf("[%d] %s / 가격:%d / 재고:%d / 판매:%d / 총매출:%d\n",
                    p[i].id, p[i].name, p[i].price, p[i].stock, p[i].sold,
                    p[i].price * p[i].sold);
            }
        }
        else if (menu == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}
*/