#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode* create_empty_list()
{
    return NULL;
}

void destroy_list(struct ListNode **pList)
{
    if (pList == NULL) {
        fprintf(stderr, "Pointer of list is NULL.\n");
        exit(1);
    }

    struct ListNode *next, *pos;

    next = pos = *pList;
    while (pos != NULL) {
        next = pos->next;
        free(pos);
        pos = next;
    }

    *pList = NULL;
}

int is_empty(struct ListNode *list)
{
    return list == NULL;
}

int is_last(struct ListNode *node)
{
    return (node == NULL) || (node != NULL && node->next == NULL);
}

void insert_node(struct ListNode *pre, int data)
{
    if (pre == NULL)
        return;

    struct ListNode *node;

    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        fprintf(stderr, "Out of space.\n");
        exit(1);
    }

    node->data = data;
    node->next = pre->next;
    pre->next = node;
}

struct ListNode* find(struct ListNode *list, int data)
{
    struct ListNode *pos;

    pos = list;
    while (pos != NULL && pos->data != data)
        pos = pos->next;

    return pos;
}

struct ListNode* find_previous(struct ListNode *list, int data)
{
    struct ListNode *pre, *pos;

    pre = NULL;
    pos = list;
    while (pos != NULL && pos->data != data) {
        pre = pos;
        pos = pos->next;
    }

    if (pos == NULL)
        pre = NULL;

    return pre;
}

struct ListNode* first_node(struct ListNode *list)
{
    return list;
}

struct ListNode* last_node(struct ListNode *list)
{
    struct ListNode *pre, *pos;

    pre = NULL;
    pos = list;
    while (pos != NULL) {
        pre = pos;
        pos = pos->next;
    }

    return pre;
}

void insert_front(struct ListNode **pList, int data)
{
    if (pList == NULL) {
        fprintf(stderr, "Pointer of list is NULL.\n");
        exit(1);
    }

    struct ListNode *node;

    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        fprintf(stderr, "Out of space.\n");
        exit(1);
    }
    node->data = data;
    node->next = *pList;
    *pList = node;

}

void insert_back(struct ListNode **pList, int data)
{
    if (pList == NULL) {
        fprintf(stderr, "Pointer of list is NULL.\n");
        exit(1);
    }

    struct ListNode *node, *pre;

    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        fprintf(stderr, "Out of space.\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;

    if (*pList == NULL) {
        *pList = node;
        return;
    }

    pre = last_node(*pList);
    insert_node(pre, data);
}

void remove_node(struct ListNode **pList, int data)
{
    if (pList == NULL) {
        fprintf(stderr, "Pointer of list is NULL.\n");
        exit(1);
    }

    if (*pList != NULL) {
        struct ListNode *pre, *tmp;

        pre = find_previous(*pList, data);

        // The first one
        if (pre == NULL && (*pList)->data == data) {
            tmp = *pList;
            *pList = (*pList)->next;
            free(tmp);
        } else if (pre != NULL) {   // Not the first one
            tmp = pre->next;
            pre->next = tmp->next;
            free(tmp);
        }
    }
}

void print_list(struct ListNode* list)
{
    struct ListNode *pos;

    pos = list;
    while (pos != NULL) {
        printf("%d ", pos->data);
        pos = pos->next;
    }
}
