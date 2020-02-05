#include "bst_viz.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    struct TreeNode *tree = create_empty_tree();
    bst_insert(&tree, 4);
    bst_insert(&tree, 2);
//    bst_insert(&tree, 1);
    bst_insert(&tree, 5);
    bst_insert(&tree, 3);

    FILE *fp = fopen("test.txt", "w");
    if(!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    print_dot(tree, fp, 1);
    fclose(fp);

    destroy_tree(&tree);

    return 0;
}
