#include "header.h"

//CMAKE
//SONAR

int main () {
    system("chcp 1251");
    setlocale(LC_ALL, "RUS");
    COMPANIES_STRUCT *mas_struct;
    FILE *f;
    int num;
    int menu_switch = 1;
    f = fopen("Struct.txt", "r");
    if (f == NULL) {
        perror("ERROR_0");
        return 0;
    }
    printf("������� ���-�� ��������\n");
    num = init_x(1, 15);
    mas_struct_init(&mas_struct, num);
    mas_struct_parsing(&mas_struct, f, num);
    do {
        printf("\t\t����\n"
               "\t�������:\n"
               "\t\t1 - ������� ��� ��������\n"
               "\t\t2 - ������� 1-� ��������\n"
               "\t\t3 - �������� ����� ��������\n"
               "\t\t4 - ������� ��������\n"
               "\t\t5 - ������������� �������� �� ������� ������\n"
               "\t\t0 - ��������� ������\n");
        menu_switch = init_x(0, 5);
        int choice;
        switch (menu_switch) {
            case 1:
                system("cls");
                mas_struct_output(mas_struct, num);
                getchar();
                break;
            case 2:
                system("cls");
                printf("\t\t������� ����� �������� ��� ������:\n");
                choice = init_x(1, num) - 1;
                mas_struct_output_i(mas_struct, choice);
                getchar();
                break;
            case 3:
                system("cls");
                mas_struct_add(&mas_struct, &num);
                printf("\t\t���������\n");
                getchar();
                break;
            case 4:
                system("cls");
                printf("\t\t������� ����� �������� ��� ��������:\n");
                choice = init_x(1, num) - 1;
                mas_struct_delete(&mas_struct, &num, choice);
                printf("\t\t�������\n");
                if (num <= 0) {
                    printf("\t\t��� ��������, �������� ����� ?\n"
                           "\t\t1 - ��\n"
                           "\t\t0 - ��������� ������\n");
                    int que = init_x(0, 1);
                    if (que == 1)
                        mas_struct_add(&mas_struct, &num);
                    else
                        return 0;
                }
                getchar();
                break;
            case 5:
                system("cls");
                insertion_sort(mas_struct, num);
                printf("\t\t��������������\n");
                getchar();
                break;
            case 0:
                system("cls");
                printf("\t\t������ ����������...\n");
                getchar();
                break;
            default:
                perror("default_ERROR:");
                getchar();
                return 0;
        }
        system("cls");
    } while (menu_switch != 0);
    fclose(f);
    delete_all_mas(&mas_struct, &num);
    return EXIT_SUCCESS;
}