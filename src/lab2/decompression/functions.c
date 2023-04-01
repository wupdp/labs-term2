#include "header.h"

//char *strncpy(char *dest, const char *src, size_t n)
//Копирует до n символов из строки, на которую указывает src, в dest.

int if_space(char c) {
    if (c == 32) return 1;
    else
        return 0;
};

void mas_from_vocabulary(FILE *f, Vocabulary_mas **mas, int *num) {
    rewind(f);
    char *str = calloc(255, 1);
    while (!feof(f)) {
        if (NULL != fgets(str, 255, f)) {
            if (strcmp(str, "$\n") == 0) {
                int i = 0;
                while (!feof(f)) {
                    if (NULL != fgets(str, 255, f)) {
                        if (strcmp(str, "\n") == 0) continue;
                        int j = 0;
                        int flag_word = 0;
                        while (str[j] != '\0' && str[j] != '\n') {
                            if (((if_space(str[j]) == 0 && if_space(str[j - 1]) == 1) ||
                                 (j == 0 && if_space(str[j]) == 0))) {
                                int count = 0;
                                int i_start = j;
                                while (if_space(str[j]) == 0 && str[j] != '\0' &&
                                       str[j] != '\n') {        //&& str[i] != '\n'
                                    count++;
                                    j++;
                                }
                                char *buffer = calloc(15, 1);
                                if (flag_word == 1) {
                                    (*mas) = (Vocabulary_mas *) realloc((*mas), (*num) * sizeof(Vocabulary_mas));
                                    strncpy(buffer, &str[i_start], count);
                                    buffer[count] = '\0'; //считано слово из f_vocabulary
                                    (*mas)[i].word_big = buffer;
                                    i++;
                                }
                                if (flag_word == 0) {
                                    (*num)++;
                                    (*mas) = (Vocabulary_mas *) realloc((*mas), (*num) * sizeof(Vocabulary_mas));
                                    strncpy(buffer, &str[i_start], count);
                                    buffer[count] = '\0';  //считано слово из f_vocabulary
                                    (*mas)[i].word_lit = buffer;
                                    flag_word = 1;
                                }
                            } else j++;
                        }
                    }
                }
            }
        }
    }
}

long long get_file_size(const char *file_name) {
    long long file_size = 0;
    FILE *fd = fopen(file_name, "rb");
    if (fd == NULL) {
        file_size = -1;
    } else {
        fseek(fd, 0, SEEK_END);
        file_size = ftell(fd);
    }
    return file_size;
}

void file_uncompressed_completion(FILE *f, FILE *f2, Vocabulary_mas *mas, int size) {
    char *str = (char *) calloc(600, 1);
    fseek(f, 0, SEEK_SET);
    int str_flag = 1;
    while (!feof(f)) {
        if (NULL != fgets(str, 255, f)) {
            if (strcmp("$\n", str) == 0) break;
            int i = 0;
            int space_1 = 1;
            if (str_flag == 0) fputs("\n", f2);
            str_flag = 0;
            while (str[i] != '\0' && str[i] != '\n') {
                if ((if_space(str[i]) == 0 && if_space(str[i - 1]) == 1) || (i == 0 && if_space(str[i]) == 0)) {
                    int count = 0;
                    int i_start = i;
                    char *buffer = (char *) calloc(255, 1);
                    while (if_space(str[i]) == 0 && str[i] != '\0' && str[i] != '\n') {        //&& str[i] != '\n'
                        count++;
                        i++;
                    }
                    strncpy(buffer, &str[i_start], count);
                    buffer[count] = '\0';  //считано слово из f1
                    for (int j = 0; j < size + 1; j++) {
                        if (j == size) {
                            if (space_1 == 0) fputs(" ", f2);
                            fputs(buffer, f2);
                            space_1 = 0;
                            break;
                        }
                        if (strcmp(buffer, mas[j].word_lit) == 0) {
                            buffer = mas[j].word_big;
                            if (space_1 == 0) fputs(" ", f2);
                            fputs(buffer, f2);
                            space_1 = 0;
                            break;
                        } else if (strcmp(buffer, mas[j].word_big) == 0) {
                            buffer = mas[j].word_lit;
                            if (space_1 == 0) fputs(" ", f2);
                            fputs(buffer, f2);
                            space_1 = 0;
                            break;
                        }
                    }
                } else i++;
            }
        }
    }
    free(str);
}