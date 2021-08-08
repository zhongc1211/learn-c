#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t ** head, int val) {
    node_t *previous, *current;
    /* return if head is empty */
    if (*head == NULL) {
        return -1;
    }
    /* return if head value is the value to remove */
    if ((*head)->val == val) {
        return pop(head);
    }
    /*  */
    previous = current = (*head)->next;
    while (current) {
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            printf("return %d\n",val);
            return val;
        }
        /* align previous with current, so that previous is updated */
        printf("----------\ncurrent:%d,previous:%d\n",current->val,previous->val);
        previous = current;
        /* while previous contains current's value, forward current to next value, so that at the end of each while loop, current is always one node foward than previous */
        current  = current->next;
        printf("current:%d,previous:%d\n",current->val,previous->val);
    }
    return -1;
}

void delete_list(node_t *head) {
    node_t  *current = head, 
            *next = head;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void) {
    node_t * test_list = (node_t *) malloc(sizeof(node_t));

    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 4);

    print_list(test_list);
    delete_list(test_list);

    return EXIT_SUCCESS;
}