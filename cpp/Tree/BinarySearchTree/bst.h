#ifndef _BST_H
#define _BST_H

#ifdef __cplusplus
extern "C" {
#endif

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create_empty_tree();
void destroy_tree(struct TreeNode **tree);
struct TreeNode* bst_find(struct TreeNode *tree, int data);
struct TreeNode* bst_find_max(struct TreeNode *tree);
struct TreeNode* bst_find_min(struct TreeNode *tree);
void bst_insert(struct TreeNode **tree, int data);
void bst_remove(struct TreeNode **tree, int data);
void preorder_walk(struct TreeNode *tree);
void inorder_walk(struct TreeNode *tree);
void postorder_walk(struct TreeNode *tree);
void print_node(struct TreeNode *node);

#ifdef __cplusplus
}
#endif

#endif //_BST_H
