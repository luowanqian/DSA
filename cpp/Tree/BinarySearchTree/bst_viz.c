#include "bst_viz.h"

void print_dot_null(int data, int null_count, FILE *stream, int invisible)
{
    if (invisible == 1) {
        fprintf(stream, "    null%d [style=\"invis\", shape=point];\n", null_count);
        fprintf(stream, "    %d -> null%d [style=\"invis\"];\n", data, null_count);
    } else {
        fprintf(stream, "    null%d [shape=point];\n", null_count);
        fprintf(stream, "    %d -> null%d;\n", data, null_count);
    }
}

void print_dot_aux(struct TreeNode *node, FILE *stream, int invisible)
{
    static int null_count = 0;

    if (node->left != NULL) {
        fprintf(stream, "    %d -> %d;\n", node->data, node->left->data);
        print_dot_aux(node->left, stream, invisible);
    } else {
        print_dot_null(node->data, null_count++, stream, invisible);
    }

    if (node->right != NULL) {
        fprintf(stream, "    %d -> %d;\n", node->data, node->right->data);
        print_dot_aux(node->right, stream, invisible);
    } else {
        print_dot_null(node->data, null_count++, stream, invisible);
    }
}

void print_dot(struct TreeNode *tree, FILE *stream, int invisible)
{
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [frontname=\"Arial\"];\n");

    if (tree == NULL)
        fprintf(stream, "\n");
    else if (tree->right == NULL && tree->left == NULL)
        fprintf(stream, "    %d;\n", tree->data);
    else
        print_dot_aux(tree, stream, invisible);

    fprintf(stream, "}\n");
}