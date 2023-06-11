#include "../src_h/clist.h"

#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x, y;
    i_node node;
};

typedef struct Point point;

void add_point(i_list* list, int x, int y)
{
    point* new_point = malloc(sizeof(point));
    if (new_point == NULL) exit(1);
    new_point->x = x;
    new_point->y = y;
    new_point->node.next = NULL;
    new_point->node.prev = NULL;
    add_node(list, &(new_point->node));
}

void remove_point(i_list* list, int x, int y) 
{
    i_node* curr_node = list->head;
    while (curr_node) {
        point* del_point = container_of(curr_node, point, node);
        if (del_point->x == x && del_point->y == y) {
            i_node* tmp = curr_node->next;
            remove_node(list, curr_node);
            free(del_point);
            curr_node = tmp;
        }
        else
            curr_node = curr_node->next;
    }
}

void show_all_points(i_list* list) {
    if (get_len(list) != 0) {
        i_node* curr_node = list->head;
        while (curr_node) {
            point* curr_point = container_of(curr_node, point, node);
            printf("(%d %d)", curr_point->x, curr_point->y);
            curr_node = curr_node->next;
            if (curr_node != NULL) printf(" ");
        }
    }
    printf("\n");
}

void remove_all_points(i_list* list) {
    i_node* curr_node = list->head;
    while (curr_node) {
        point* del_point = container_of(curr_node, point, node);
        i_node* tmp = curr_node->next;
        remove_node(list, curr_node);
        free(del_point);
        curr_node = tmp;
    }
    list->head = NULL;
}

int main() {
    i_list l = { NULL };
    char command[240];
    while (1) {
        scanf("%s", command, 240);
        if (strcmp(command, "add") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            add_point(&l, x, y);
        }
        else if (strcmp(command, "rm") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            remove_point(&l, x, y);
        }
        else if (strcmp(command, "print") == 0) show_all_points(&l);
        else if (strcmp(command, "rma") == 0) remove_all_points(&l);
        else if (strcmp(command, "len") == 0) printf("%d\n", get_len(&l));
        else if (strcmp(command, "exit") == 0) {
            remove_all_points(&l);
            return 0;
        }
        else printf("Unknown command\n");
    }
}
