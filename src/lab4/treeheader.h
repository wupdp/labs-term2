#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdint.h"


typedef struct tree {
    char *text;
    struct tree *left;
    struct tree *right;
} tree_leaf;

tree_leaf *get_tree_leaf(char *value, tree_leaf *past);

void show_leafs(tree_leaf *leaf);

void write_tree_to_file(tree_leaf *root, FILE *fp);

tree_leaf *readTreeFromFile(FILE *fp);