#include "treeheader.h"

#define STR_LENGTH 255

tree_leaf *get_tree_leaf(char *value, tree_leaf *past) {
    tree_leaf *tmp = (tree_leaf *) malloc(sizeof(tree_leaf));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->text = (char *) malloc(sizeof(value) + 1);
    strcpy(tmp->text, value);
    tmp->past = past;
    return tmp;
}

void show_leafs(tree_leaf *leaf) {
    if (leaf == NULL) return;
    printf("%s \n", leaf->text);
    show_leafs(leaf->left);
    show_leafs(leaf->right);
}

void write_tree_to_file(tree_leaf *root, FILE *fp) {
    if (root == NULL) {
        fputs("N\n", fp);
        return;
    }
    fputs(root->text, fp);
    fputs("\n", fp);
    write_tree_to_file(root->left, fp);
    write_tree_to_file(root->right, fp);
}

tree_leaf *read_tree_from_file(FILE *fp) {
    if (feof(fp)) {
        return NULL;
    }
    char *buffer = (char *) calloc(1, 1);
    fgets(buffer, STR_LENGTH, fp);
    if (strcmp("N\n", buffer) == 0) {
        return NULL;
    }

    tree_leaf *root = (tree_leaf *) malloc(sizeof(tree_leaf));
    root->text = buffer;
    //root->text = malloc(sizeof(buffer) + 1);
    //strcpy(root->text, buffer);
    free(buffer);
    root->left = read_tree_from_file(fp);
    root->right = read_tree_from_file(fp);

    return root;
}