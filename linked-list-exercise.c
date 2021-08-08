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

void remove_by_value(node_t ** head, int val) {
    /* TODO: fill in your code here */
    node_t * next_node = NULL;
    int retval = -1;
    node_t * current = *head;
    node_t * new_current = *head;
    node_t * temp_node = NULL;

    int n = 0;

    while (current->next != NULL && current->val != val){
        current = current->next;
        n ++;
    }

    int i;
    for (i = 1; i < n; i++) {
        new_current = new_current->next;
    }
    printf("i is %d, n is %d\n",i,n);
    printf("removing %d at index %d\n",val,n);
    printf("new current %d\n",new_current->val);
    temp_node = new_current->next;
    printf("temp node:%d\n",temp_node->val);
    retval = temp_node->val;
    new_current->next = temp_node->next;
    free(temp_node);

}

int main() {

    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
    return EXIT_SUCCESS;
}