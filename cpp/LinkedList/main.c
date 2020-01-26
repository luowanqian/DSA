#include "list.h"
#include <stdio.h>

int main()
{
    struct ListNode* list = create_empty_list();

    // Test empty()
    if (is_empty(list))
        printf("Empty list.\n");
    else
        printf("Not empty.\n");
    printf("\n");

    // Test is_last()
    if (is_last(list))
        printf("The last node.\n");
    else
        printf("Not the last node.\n");
    printf("\n");

    // Test insert_front()
    insert_front(&list, 1);
    insert_front(&list, 2);
    insert_front(&list, 3);
    insert_front(&list, 4);
    print_list(list);
    printf("\n");

    // Test destroy_list()
    destroy_list(&list);

    // Test insert_back()
    insert_back(&list, 1);
    insert_back(&list, 2);
    insert_back(&list, 3);
    insert_back(&list, 4);
    print_list(list);
    printf("\n");
    printf("\n");

    // Test find()
    struct ListNode *pos = find(list, 3);
    if (pos == NULL)
        printf("Could not find 3.\n");
    else
        printf("Found 3.\n");
    pos = find(list, 6);
    if (pos == NULL)
        printf("Could not find 6.\n");
    else
        printf("Found 6.\n");

    printf("\n");

    // Test find_previous()
    struct ListNode *pre = find_previous(list, 3);
    if (pre == NULL)
        printf("Could not find 3 previous node.\n");
    else
        printf("Found 3 previous node.\n");
    pre = find_previous(list, 6);
    if (pre == NULL)
        printf("Could not find 6 previous node.\n");
    else
        printf("Found 6 previous node.\n");

    printf("\n");

    // Test last_node()
    struct ListNode *last = last_node(list);
    pos = find(list, 4);
    if (pos == last && is_last(last))
        printf("Test last_node() successful.\n");
    else
        printf("Test last_node() failed.\n");
    printf("\n");

    // Test insert_node()
    pos = find_previous(list, 1);
    insert_node(pos, 6);
    print_list(list);
    printf("\n");

    pos = find_previous(list, 4);
    insert_node(pos, 6);
    print_list(list);
    printf("\n");

    pos = find(list, 4);
    insert_node(pos, 7);
    print_list(list);
    printf("\n");

    pos = find_previous(list, 9);
    insert_node(pos, 8);
    print_list(list);
    printf("\n");

    pos = first_node(list);
    insert_node(pos, 9);
    print_list(list);
    printf("\n");
    printf("\n");

    remove_node(&list, 1);
    print_list(list);
    printf("\n");
    remove_node(&list, 9);
    print_list(list);
    printf("\n");
    remove_node(&list, 3);
    print_list(list);
    printf("\n");
    remove_node(&list, 7);
    print_list(list);
    printf("\n");
    remove_node(&list, 2);
    print_list(list);
    printf("\n");
    remove_node(&list, 6);
    print_list(list);
    printf("\n");
    remove_node(&list, 4);
    print_list(list);
    printf("\n");

    if (is_empty(list))
        printf("Empty list\n");

    return 0;
}