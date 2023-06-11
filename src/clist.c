#include "../src_h/clist.h"

void add_node(i_list* list, i_node* new_node) {
	if (list->head != NULL) {
		new_node->prev = NULL;
		new_node->next = list->head;
		(list->head)->prev = new_node;
		list->head = new_node;
	}
	else 
		list->head = new_node;
}

int get_len(i_list* list) {
	i_node* curr_node = list->head;
	int len = 0;
	while (curr_node) {
		++len;
		curr_node = curr_node->next;
	}
	return len;
}

void remove_node(i_list* list, i_node* node) {
	if (node->prev != NULL) (node->prev)->next = node->next;
	else list->head = node->next;
	if (node->next != NULL) (node->next)->prev = node->prev;
}