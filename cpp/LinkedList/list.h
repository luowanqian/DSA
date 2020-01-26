#ifndef _LIST_H
#define _LIST_H

#ifdef __cplusplus
extern "C" {
#endif

struct ListNode;

struct ListNode* create_empty_list();
void destroy_list(struct ListNode **list);
int is_empty(struct ListNode *pList);
int is_last(struct ListNode *node);
void insert_node(struct ListNode *pre, int data);
void insert_front(struct ListNode **pList, int data);
void insert_back(struct ListNode **pList, int data);
void remove_node(struct ListNode **pList, int data);
struct ListNode* find(struct ListNode *list, int data);
struct ListNode* find_previous(struct ListNode *list, int data);
struct ListNode* first_node(struct ListNode *list);
struct ListNode* last_node(struct ListNode *list);
void print_list(struct ListNode* list);

#ifdef __cplusplus
}
#endif

#endif //_LIST_H
