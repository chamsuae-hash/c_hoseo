#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[20];
    int price;
    int in_qty;
    int out_qty;
    int total_sales;
};

struct Product list[5];
int count = 0;

int main() {
    int menu;
    int i;
    int find_index;
    int input_id;
    int input_qty;
    FILE* fp;

    while (1) {
        printf("\n원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료, 6. 저장, 7. 불러오기)\n");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("상품ID : ");
            scanf("%d", &input_id);

            find_index = -1;
            for (i = 0; i < count; i++) {
                if (list[i].id == input_id) {
                    find_index = i;
                    break;
                }
            }

            if (find_index != -1) {
                printf("입고량 : ");
                scanf("%d", &input_qty);
                list[find_index].in_qty += input_qty;
            }
            else {
                if (count >= 5) {
                    printf("상품 갯수 초과 시 메시지 출력\n");
                }
                else {
                    list[count].id = input_id;
                    printf("상품명 : ");
                    scanf("%s", list[count].name);
                    printf("입고량 : ");
                    scanf("%d", &list[count].in_qty);
                    printf("판매가격 : ");
                    scanf("%d", &list[count].price);
                    list[count].out_qty = 0;
                    list[count].total_sales = 0;
                    count++;
                }
            }
        }
        else if (menu == 2) {
            printf("상품ID : ");
            scanf("%d", &input_id);

            find_index = -1;
            for (i = 0; i < count; i++) {
                if (list[i].id == input_id) {
                    find_index = i;
                    break;
                }
            }

            if (find_index == -1) {
                printf("오류메시지 출력\n");
            }
            else {
                printf("판매량 : ");
                scanf("%d", &input_qty);
                list[find_index].out_qty += input_qty;
                list[find_index].total_sales += (input_qty * list[find_index].price);
            }
        }
        else if (menu == 3) {
            printf("상품ID : ");
            scanf("%d", &input_id);

            find_index = -1;
            for (i = 0; i < count; i++) {
                if (list[i].id == input_id) {
                    find_index = i;
                    break;
                }
            }

            if (find_index != -1) {
                printf("ID: %d, 이름: %s, 가격: %d, 입고: %d, 판매: %d, 총매출: %d\n",
                    list[find_index].id, list[find_index].name, list[find_index].price,
                    list[find_index].in_qty, list[find_index].out_qty, list[find_index].total_sales);
            }
            else {
                printf("상품이 없습니다.\n");
            }
        }
        else if (menu == 4) {
            printf("전체 상품 정보 출력\n");
            for (i = 0; i < count; i++) {
                int stock = list[i].in_qty - list[i].out_qty;
                double rate = 0.0;
                if (list[i].in_qty > 0) {
                    rate = (double)list[i].out_qty / list[i].in_qty * 100;
                }
                printf("ID: %d, 이름: %s, 재고: %d, 판매율: %.1lf%%\n",
                    list[i].id, list[i].name, stock, rate);
            }
        }
        else if (menu == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else if (menu == 6) {
            fp = fopen("data.txt", "w");
            if (fp == NULL) {
                printf("파일 저장 실패\n");
            }
            else {
                fprintf(fp, "%d\n", count);
                for (i = 0; i < count; i++) {
                    fprintf(fp, "%d %s %d %d %d %d\n",
                        list[i].id, list[i].name, list[i].price,
                        list[i].in_qty, list[i].out_qty, list[i].total_sales);
                }
                fclose(fp);
                printf("상품정보 저장 완료\n");
            }
        }
        else if (menu == 7) {
            fp = fopen("data.txt", "r");
            if (fp == NULL) {
                printf("파일이 없습니다.\n");
            }
            else {
                fscanf(fp, "%d", &count);
                for (i = 0; i < count; i++) {
                    fscanf(fp, "%d %s %d %d %d %d",
                        &list[i].id, list[i].name, &list[i].price,
                        &list[i].in_qty, &list[i].out_qty, &list[i].total_sales);
                }
                fclose(fp);
                printf("상품정보 불러오기 완료\n");
            }
        }
    }

    return 0;
}
