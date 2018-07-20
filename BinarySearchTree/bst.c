#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create_empty_tree()
{
    return NULL;
}

void destroy_tree(struct TreeNode **tree)
{
    if (*tree != NULL) {
        destroy_tree(&(*tree)->left);
        destroy_tree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}

struct TreeNode* bst_find(struct TreeNode *tree, int data)
{
    struct TreeNode *node;

    node = tree;
    while (node != NULL) {
        if (node->data == data)
            break;
        else if (data < node->data)
            node = node->left;
        else
            node = node->right;
    }

    return node;
}

struct TreeNode* bst_find_max(struct TreeNode *tree)
{
    struct TreeNode *node;

    node = tree;
    while (node != NULL && node->right != NULL)
        node = node->right;

    return node;
}

struct TreeNode* bst_find_min(struct TreeNode *tree)
{
    struct TreeNode *node;

    node = tree;
    while (node != NULL && node->left != NULL)
        node = node->left;

    return node;
}

void bst_insert(struct TreeNode **tree, int data)
{
    struct TreeNode *parent, *node, *tmp;

    tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (tmp == NULL) {
        fprintf(stderr, "Out of space.\n");
        exit(1);
    }
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    parent = NULL;
    node = *tree;
    while (node != NULL) {
        parent = node;
        if (data < node->data)
            node = node->left;
        else if (data > node->data)
            node = node->right;
        else
            return;
    }

    if (parent == NULL)
        *tree = tmp;
    else if (data < parent->data)
        parent->left = tmp;
    else if (data > parent->data)
        parent->right = tmp;
}

void bst_transplant(struct TreeNode **tree, struct TreeNode *parent1,
                struct TreeNode *node1, struct TreeNode *node2)
{
    if (parent1 == NULL)
        *tree = node2;
    else if (parent1->left == node1)
        parent1->left = node2;
    else if (parent1->right == node1)
        parent1->right = node2;
}

void bst_remove(struct TreeNode **tree, int data)
{
    struct TreeNode *parent, *node;

    // search node which contains data
    parent = NULL;
    node = *tree;
    while (node != NULL && node->data != data) {
        parent = node;
        if (data < node->data)
            node = node->left;
        else if (data > node->data)
            node = node->right;
    }

    struct TreeNode *parent_min, *node_min;
    if (node != NULL) {
        if (node->left == NULL) {
            bst_transplant(tree, parent, node, node->right);
        } else if (node->right == NULL) {
            bst_transplant(tree, parent, node, node->left);
        } else {
            // Find min in the right tree
            parent_min = node;
            node_min = node->right;
            while (node_min != NULL && node_min->left != NULL) {
                parent_min = node_min;
                node_min = node_min->left;
            }

            if (parent_min != node) {
                bst_transplant(tree, parent_min, node_min, node_min->right);
                node_min->right = node->right;
            }
            bst_transplant(tree, parent, node, node_min);
            node_min->left = node->left;
        }

        free(node);
    }
}

void preorder_walk(struct TreeNode *tree)
{
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorder_walk(tree->left);
        preorder_walk(tree->right);
    }
}

void inorder_walk(struct TreeNode *tree)
{
    if (tree != NULL) {
        inorder_walk(tree->left);
        printf("%d ", tree->data);
        inorder_walk(tree->right);
    }
}

void postorder_walk(struct TreeNode *tree)
{
    if (tree != NULL) {
        postorder_walk(tree->left);
        postorder_walk(tree->right);
        printf("%d ", tree->data);
    }
}

void print_node(struct TreeNode *node)
{
    int left, right;

    left = right = 0;
    if (node != NULL) {
        if (node->left != NULL)
            left = node->left->data;
        if (node->right != NULL)
            right = node->right->data;
        printf("%d(%d, %d) ", node->data, left, right);
    }
}
