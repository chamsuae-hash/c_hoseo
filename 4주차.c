//수업
#include <stdio.h>
#include <stdlib.h>
#define PR_COUNT 5

int main() {
    int stock[PR_COUNT] = { 0 };
    int choice;
    int id;
    int amount;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("1. 입고\n");
        printf("2. 판매\n");
        printf("3. 상품현황\n");
        printf("4. 종료\n");
        printf("원하는 메뉴를 선택하세요: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("입고 방법 선택: (1. 전체　상품, 2. 개별　상품): ");
            int subChoice;
            scanf("%d", &subChoice);

            if (subChoice == 1) {
                printf("전체 상품의 입고 수량 입력 (5개): ");
                for (int i = 0; i < PR_COUNT; i++) {
                    scanf("%d", &amount);
                    stock[i] += amount;
                }
            }
            else if (subChoice == 2) {
                printf("상품 ID 입력 (0~4): ");
                scanf("%d", &id);
                if (id >= 0 && id < PR_COUNT) {
                    printf("입고 수량 입력: ");
                    scanf("%d", &amount);
                    stock[id] += amount;
                }
                else {
                    printf("잘못된 상품 ID입니다!\n");
                }
            }
        }
        else if (choice == 2) {
            printf("판매 방법 선택: (1. 전체, 2. 개별): ");
            int subChoice;
            scanf("%d", &subChoice);

            if (subChoice == 1) {
                printf("전체 상품의 판매 수량 입력 (5개): ");
                for (int i = 0; i < PR_COUNT; i++) {
                    scanf("%d", &amount);
                    if (stock[i] >= amount) {
                        stock[i] -= amount;
                    }
                    else {
                        printf("상품 %d 재고 부족 판매 불가.\n", i);
                    }
                }
            }
            else if (subChoice == 2) {
                printf("상품 ID 입력 (0~4): ");
                scanf("%d", &id);
                if (id >= 0 && id < PR_COUNT) {
                    printf("판매 수량 입력: ");
                    scanf("%d", &amount);
                    if (stock[id] >= amount) {
                        stock[id] -= amount;
                    }
                    else {
                        printf("재고 부족! 현재 재고: %d\n", stock[id]);
                    }
                }
                else {
                    printf("잘못된 상품 ID입니다!\n");
                }
            }
        }
        else if (choice == 3) {
            printf("\n--- 상품 현황 ---\n");
            for (int i = 0; i < PR_COUNT; i++) {
                printf("상품 %d : %d개\n", i, stock[i]);
            }
        }
        else if (choice == 4) {
            printf("프로그램　종료.\n");
            break;
        }
        else {
            printf("잘못된　선택\n");
        }
    }

    return 0;
}