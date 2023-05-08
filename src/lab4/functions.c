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

void add_new_answer(){

}

void questions(tree_leaf *leaf) {
    if (leaf->right == NULL && leaf->left == NULL){
        give_answer(leaf->text);
        if(ask(""))
            puts("It could not be otherwise\n");
        else

        return;
    }
    if (ask(leaf->text))
        show_leafs(leaf->right);
    else
        show_leafs(leaf->left);
}

void akinator(tree_leaf *root) {

}