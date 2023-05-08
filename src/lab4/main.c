#include "header.h"

int main() {
    tree_leaf *root = (tree_leaf *) malloc(sizeof(tree_leaf));
    FILE* f_binary_tree = fopen("klen.txt","w");

    root = readTreeFromFile(f_binary_tree);
    fclose(f_binary_tree);
}