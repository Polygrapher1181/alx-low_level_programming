#include <stdlib.h>
#include <string.h>

typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

list_t *add_node(list_t **head, const char *str) {
    list_t *new_node = malloc(sizeof(list_t));
    if (!new_node) {
        return NULL; // Memory allocation failed
    }
    new_node->str = strdup(str);
    if (!new_node->str) {
        free(new_node); // Memory allocation failed
        return NULL;
    }
    new_node->next = *head;
    *head = new_node;
    return new_node;
}

