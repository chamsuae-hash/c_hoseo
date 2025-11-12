/*

#include <stdio.h>
#include <string.h>

#define MAX 5

int main() {
    int stock[MAX] = { 0 };
    int sold[MAX] = { 0 };
    char names[MAX][50];
    int choice;

    for (int i = 0; i < MAX; i++) {
        sprintf(names[i], "상품%d", i + 1);
    }

    while (1) {
        printf("\n===== 쇼핑몰 재고 관리 =====\n");
        printf("1. 입고\n");
        printf("2. 판매\n");
        printf("3. 상품현황\n");
        printf("4. 상품명 입력\n");
        printf("5. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id, amount;
            printf("입고할 상품 ID(1~5): ");
            scanf("%d", &id);
            printf("입고 수량: ");
            scanf("%d", &amount);
            if (id >= 1 && id <= MAX) {
                stock[id - 1] += amount;
                printf("%s 입고 완료! 현재 재고: %d\n", names[id - 1], stock[id - 1]);
            }
            else {
                printf("잘못된 상품 ID!\n");
            }
        }
        else if (choice == 2) {
            int id, amount;
            printf("판매할 상품 ID(1~5): ");
            scanf("%d", &id);
            printf("판매 수량: ");
            scanf("%d", &amount);
            if (id >= 1 && id <= MAX) {
                if (stock[id - 1] >= amount) {
                    stock[id - 1] -= amount;
                    sold[id - 1] += amount;
                    printf("%s 판매 완료! 남은 재고: %d\n", names[id - 1], stock[id - 1]);
                }
                else {
                    printf("재고 부족! 현재 재고: %d\n", stock[id - 1]);
                }
            }
            else {
                printf("잘못된 상품 ID!\n");
            }
        }
        else if (choice == 3) {
            int totalStock = 0, totalSold = 0;
            for (int i = 0; i < MAX; i++) {
                totalStock += stock[i];
                totalSold += sold[i];
            }
            printf("\n--- 상품현황 ---\n");
            printf("재고수량: ");
            for (int i = 0; i < MAX; i++) {
                printf("%d ", stock[i]);
            }
            printf("\n총 판매량: %d\n", totalSold);
            if (totalStock + totalSold > 0) {
                double rate = (double)totalSold / (totalStock + totalSold) * 100;
                printf("판매율: %.2f%%\n", rate);
            }

            int maxIdx = 0, minIdx = 0;
            for (int i = 1; i < MAX; i++) {
                if (sold[i] > sold[maxIdx]) maxIdx = i;
                if (sold[i] < sold[minIdx]) minIdx = i;
            }
            printf("가장 많이 판매된 상품: ID %d, %s, 판매량 %d\n",
                maxIdx + 1, names[maxIdx], sold[maxIdx]);
            printf("가장 적게 판매된 상품: ID %d, %s, 판매량 %d\n",
                minIdx + 1, names[minIdx], sold[minIdx]);
        }
        else if (choice == 4) {
            for (int i = 0; i < MAX; i++) {
                printf("ID %d 상품명 입력: ", i + 1);
                scanf("%s", names[i]);
            }
        }
        else if (choice == 5) {
            printf("프로그램 종료!\n");
            break;
        }
        else {
            printf("잘못된 메뉴 선택!\n");
        }
    }
    return 0;
}

*/