#include "header.h"

#define STACK_OVERFLOW  (-100)
#define STACK_UNDERFLOW (-101)

//char *strncpy(char *dest, const char *src, size_t n)
//Копирует до n символов из строки, на которую указывает src, в dest.

void push(Node_word **head, char *buffer) {
    Node_word *tmp = malloc(sizeof(Node_word));
    if (tmp == NULL) {
        exit(STACK_OVERFLOW);
    }
    tmp->next = *head;
    tmp->word = buffer;
    *head = tmp;
}

char *pop(Node_word **head) {
    Node_word *out;
    char *buffer;
    if (*head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    out = *head;
    *head = (*head)->next;
    buffer = out->word;
    free(out);
    return buffer;
}

void free_stack(Node_word **head) {
    Node_word *temp;
    while (*head) {
        free((*head)->word);
        *head = (*head)->next;
    }
}

void print_stack(const Node_word *head) {
    printf("stack >");
    while (head) {
        printf("%s ", head->word);
        head = head->next;
    }
}

int if_space(char c) {
    if (c == 32) return 1;
    else
        return 0;
};

void stack_completion(FILE *f, Node_word **head) {
    char *str = (char *) calloc(600, 1);
    while (!feof(f)) {
        if (NULL != fgets(str, 255, f)) {
            if (strcmp(str, "$\n") == 0) break;
            int i = 0;
            while (str[i] != '\0') {
                if ((if_space(str[i]) == 0 && if_space(str[i - 1]) == 1) || (i == 0 && if_space(str[i]) == 0)) {
                    int count = 0;
                    int i_start = i;
                    char *buffer = (char *) calloc(255, 1);
                    while (if_space(str[i]) == 0 && str[i] != '\n') {
                        count++;
                        i++;
                    }
                    strncpy(buffer, &str[i_start], count);
                    buffer[count] = '\0';
                    push(head, buffer);
                } else i++;
            }
        }
    }
    free(str);
}

void mas_from_vocabulary(FILE *f, Vocabulary_mas *mas, int num) {
    char *buffer = calloc(255, 1);
    char *str = calloc(255, 1);
    while (!feof(f)) {
        if (NULL != fgets(str, 255, f)) {
            if(strcmp(str, "\n") == 0) continue;
            int j = 0;
            int flag_word = 0;
            while (str[j] != '\0') {
                if (((if_space(str[j]) == 0 && if_space(str[j - 1]) == 1) ||
                     (j == 0 && if_space(str[j]) == 0))) {
                    int count = 0;
                    int i_start = j;
                    while (if_space(str[j]) == 0 && str[j] != '\0' && (str[j] != '\n' && str[j - 1] != '\n')) {        //&& str[i] != '\n'
                        count++;
                        j++;
                    }
                    if (flag_word == 1) {
                        mas[j].word_big = calloc( 50, 1);
                        strncpy(mas[j].word_big, &str[i_start], count);
                        mas[j].word_big[count] = '\0';  //считано слово из f_vocabulary
                        num++;
                    }
                    if (flag_word == 0) {
                        mas[j].word_lit = calloc( 50, 1);
                        strncpy(mas[j].word_lit, &str[i_start], count);
                        mas[j].word_lit[count] = '\0';  //считано слово из f_vocabulary
                        flag_word = 1;
                        num++;
                    }
                } else j++;
            }
        }
    }
    for(int i = 0; i < num; i++){
        puts(mas[i].word_big);
        puts(mas[i].word_lit);
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

void file_uncompressed_completion(FILE *f, FILE *f2, FILE *f_vocabulary, long int vocabulary_pos) {
    char *str = (char *) calloc(600, 1);
    char *str2 = (char *) calloc(600, 1);
    fseek(f, 0, SEEK_SET);
    while (!feof(f)) {
        if (NULL != fgets(str, 255, f)) {
            if (strcmp("$\n", str) == 0) break;
            int i = 0;
            puts(str);
            printf("hui\n");
            while (str[i] != '\0') {
                if ((if_space(str[i]) == 0 && if_space(str[i - 1]) == 1) || (i == 0 && if_space(str[i]) == 0)) {
                    int count = 0;
                    int i_start = i;
                    char *buffer = (char *) calloc(255, 1);
                    while (if_space(str[i]) == 0 && str[i] != '\0') {        //&& str[i] != '\n'
                        count++;
                        i++;
                    }
                    strncpy(buffer, &str[i_start], count);
                    buffer[count] = '\0';  //считано слово из f1
                    char *buffer_lit = (char *) calloc(255, 1);
                    char *buffer_big = (char *) calloc(255, 1);
                    fseek(f_vocabulary, vocabulary_pos, SEEK_SET);
                    while (!feof(f_vocabulary)) {
                        if (NULL != fgets(str2, 255, f_vocabulary)) {
                            int j = 0;
                            int flag_word = 0;
                            while (str2[j] != '\0') {
                                if (((if_space(str2[j]) == 0 && if_space(str2[j - 1]) == 1) ||
                                     (j == 0 && if_space(str2[j]) == 0))) {
                                    int count2 = 0;
                                    int i_start2 = j;
                                    while (if_space(str2[j]) == 0 && str2[j] != '\0' &&
                                           str2[j] != '\n') {        //&& str[i] != '\n'
                                        count2++;
                                        j++;
                                    }
                                    if (flag_word == 1) {
                                        strncpy(buffer_big, &str2[i_start2], count2);
                                        buffer_big[count2] = '\0';  //считано слово из f_vocabulary
                                    }
                                    if (flag_word == 0) {
                                        strncpy(buffer_lit, &str2[i_start2], count2);
                                        buffer_lit[count2] = '\0';  //считано слово из f_vocabulary
                                        flag_word = 1;
                                    }
                                } else j++;
                            }
                        }
                        if (strcmp(buffer, buffer_lit) == 0) {
                            fputs(buffer_big, f2);
                            fputs(" ", f2);
                            break;
                        } else if (strcmp(buffer, buffer_big) == 0) {
                            fputs(buffer_lit, f2);
                            fputs(" ", f2);
                            break;
                        }
                    }
                    if (feof(f_vocabulary)) {
                        fputs(buffer, f2);
                        fputs(" ", f2);
                    }
                } else i++;
            }
        }
    }
    free(str);
    free(str2);
}