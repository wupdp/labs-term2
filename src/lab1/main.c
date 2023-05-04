#include "header.h"

int main () {
    system("chcp 1251");
    setlocale(LC_ALL, "RUS");
    COMPANIES_STRUCT *mas_struct;
    FILE *f;
    int num;
    int menu_switch;
    f = fopen("Struct.txt", "r");
    if (f == NULL) {
        perror("ERROR_0");
        return 0;
    }
    printf("Введите кол-во структур\n");
    num = init_x(1, 15);
    mas_struct_init(&mas_struct, num);
    mas_struct_parsing(&mas_struct, f, num);
    do {
        printf("\t\tМеню\n"
               "\tВведите:\n"
               "\t\t1 - вывести все компании\n"
               "\t\t2 - вывести 1-у компанию\n"
               "\t\t3 - добавить новую компанию\n"
               "\t\t4 - удалить компанию\n"
               "\t\t5 - отсортировать компании по размеру оклада\n"
               "\t\t0 - завершить работу\n");
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
                printf("\t\tВведите номер компании для вывода:\n");
                choice = init_x(1, num) - 1;
                mas_struct_output_i(mas_struct, choice);
                getchar();
                break;
            case 3:
                system("cls");
                mas_struct_add(&mas_struct, &num);
                printf("\t\tДобавлено\n");
                getchar();
                break;
            case 4:
                system("cls");
                printf("\t\tВведите номер компании для удаления:\n");
                choice = init_x(1, num) - 1;
                mas_struct_delete(&mas_struct, &num, choice);
                printf("\t\tУдалено\n");
                if (num <= 0) {
                    printf("\t\tНет компаний, добавить новую ?\n"
                           "\t\t1 - да\n"
                           "\t\t0 - завершить работу\n");
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
                printf("\t\tОтсортированно\n");
                getchar();
                break;
            case 0:
                system("cls");
                printf("\t\tХорошо поработали...\n");
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