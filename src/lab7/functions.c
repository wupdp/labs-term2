#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int init_x(int min, int max) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

int if_letter(char s) {
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        return 1;
    return 0;
}

int if_A_letter(char s) {
    if ((s >= 'A' && s <= 'Z'))
        return 1;
    return 0;
}

int if_a_letter(char s) {
    if ((s >= 'a' && s <= 'z'))
        return 1;
    return 0;
}

int choose_ex() {
    printf("Choose the ex., little boy:\n   1. Given a string. Convert all\n the first letters of each word in it to uppercase.\n   2. Positive integers N1 and N2 and strings S1 and S2 are given. Get from these strings a new string containing\n the first N1 characters of string S1 and the last N2 characters of string S2 (in the specified order).\n");
    printf("    Enter 0, if you want to exit the program\n");
    int x = init_x(0, 2);
    system("CLS");
    return x;
}

char *get_string(char *s, int *k) {
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
        (*k)++;
    }
    s[i] = '\0';
    return s;
}

void show_string(char *str) {
    for (int i = 0; (str[i]) != '\0'; i++) {
        printf("%c", (str[i]));
    }
    printf("\n");
}

void task1(char *string) {
    int i = 0;
    if (if_a_letter(string[0]) == 1)
        string[0] -= 32;
    while (string[i] != '\0') {
        if (if_a_letter(string[i]) == 1 && string[i - 1] == ' ') {
            string[i] = string[i] - 32;
            i--;
        }
        i++;
    }
}

void ex1() {
    char *string = calloc(200, 1);
    int length = 2;
    printf("\tEnter the string here:\n");
    string = get_string(string, &length);
    task1(string);
    printf("\tYour string ;) now:\n");
    show_string(string);
    free(string);
    printf("\n\n");
}

char *string_cat(char *s1, char *s2, int start1, int start2, int n1) {
    int i;
    for (i = 0; i < n1; i++)
        s1[i + start1] = s2[i + start2];
    return s1;
}

void ex2() {
    char *string1 = calloc(200, 1);
    char *string2 = calloc(200, 1);
    int length = 0, length1 = 0, length2 = 0;
    printf("\tEnter the first string here:\n");
    string1 = get_string(string1, &length1);
    printf("\tEnter the second string here:\n");
    string2 = get_string(string2, &length2);
    printf("\tEnter N1 here:\n");
    int N1 = init_x(1, length1);
    printf("\tEnter N2 here:\n");
    int N2 = init_x(1, length2);
    char *string3 = calloc((N1 + N2) * 2, 1);
    string3 = string_cat(string3, string1, 0, 0, N1);
    string3 = string_cat(string3, string2, N1, length2 - N2, N2);
    printf("\tCheck your final string:\n");
    show_string(string3);
    free(string1);
    free(string2);
}

void start_ex(void (*ex)(), int x) {
    printf("Exercise %d:\n", x);
    ex();
}

