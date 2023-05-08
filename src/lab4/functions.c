#include "header.h"

int ask(char *buffer) {
    puts(buffer);
    puts("\n");
    char answer[1];
    gets(answer);
    if (strcmp("1", answer))
        return 1;
    return 0;
}

void give_answer(char *buffer){
    puts("Have you guessed this person ? - ");
    puts(buffer);
    puts("/n");
}

void add_new_question(tree_leaf *past, char* ques, char* answer){
    tree_leaf *right = (tree_leaf *) malloc(sizeof(tree_leaf));
    right->left = NULL;
    right->right = NULL;
    right->text = answer;
    tree_leaf *left = (tree_leaf *) malloc(sizeof(tree_leaf));
    left->left = NULL;
    left->right = NULL;
    left->text = past->text;
    past->text = ques;
}

void fix_akinator(tree_leaf *past){
    puts("What did u guessed?\n");
    char *answer = (char *) calloc(1, 1);
    char *question = (char *) calloc(1, 1);
    gets(answer);
    puts("What is the difference?\n");
    gets(question);
    add_new_question(past, question, answer);
}

void questions(tree_leaf *leaf) {
    if (leaf->right == NULL && leaf->left == NULL){
        puts(leaf->text);
        if(ask("\nHave you guessed this person ?\n"))
            puts("It could not be otherwise\n");
        else
            fix_akinator(leaf);
        return;
    }
    if (ask(leaf->text))
        show_leafs(leaf->right);
    else
        show_leafs(leaf->left);
}

void akinator(tree_leaf *root) {

}