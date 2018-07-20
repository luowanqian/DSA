#include "bst.h"
#include <stdio.h>

int main()
{
    // create binary search tree
    struct TreeNode *tree = create_empty_tree();
    bst_insert(&tree, 12);
    bst_insert(&tree, 5);
    bst_insert(&tree, 18);
    bst_insert(&tree, 2);
    bst_insert(&tree, 9);
    bst_insert(&tree, 15);
    bst_insert(&tree, 19);
    bst_insert(&tree, 17);

    printf("Preorder Walk: ");
    preorder_walk(tree);
    printf("\n");
    printf("Inorder Walk: ");
    inorder_walk(tree);
    printf("\n");
    printf("Postorder Walk: ");
    postorder_walk(tree);
    printf("\n");
    printf("\n");

    // Test bst_find()
    struct TreeNode *node = bst_find(tree, 17);
    printf("Find 17: ");
    print_node(node);
    printf("\n");
    printf("\n");

    node = bst_find(tree, 20);
    printf("Find 20: ");
    if (node == NULL)
        printf("Could not find 20.\n");
    printf("\n");

    // Test find_min()
    node = bst_find_min(tree);
    printf("Find min: ");
    print_node(node);
    printf("\n");
    printf("\n");

    // Test find_max()
    node = bst_find_max(tree);
    printf("Find max: ");
    print_node(node);
    printf("\n");
    printf("\n");

    // Test bst_insert()
    printf("Insert 13\n");
    bst_insert(&tree, 13);
    printf("Preorder Walk: ");
    preorder_walk(tree);
    printf("\n");
    printf("Inorder Walk: ");
    inorder_walk(tree);
    printf("\n");
    printf("Postorder Walk: ");
    postorder_walk(tree);
    printf("\n");
    printf("\n");

    // Test remove()
    printf("Remove 2\n");
    bst_remove(&tree, 2);
    printf("Remove 18\n");
    bst_remove(&tree, 18);
    printf("Remove 13\n");
    bst_remove(&tree, 13);
    printf("Remove 12\n");
    bst_remove(&tree, 12);
    printf("Remove 5\n");
    bst_remove(&tree, 5);
    printf("Remove 9\n");
    bst_remove(&tree, 9);
    printf("Preorder Walk: ");
    preorder_walk(tree);
    printf("\n");
    printf("Inorder Walk: ");
    inorder_walk(tree);
    printf("\n");
    printf("Postorder Walk: ");
    postorder_walk(tree);
    printf("\n");
    printf("\n");

    return 0;
}
