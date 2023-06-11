#pragma once

#include <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))


typedef struct intrusive_node
{
	struct intrusive_node* prev;
	struct intrusive_node* next;
} i_node;

typedef struct intrusive_list {
	struct intrusive_node* head;
} i_list;

int get_len(i_list* list);

void add_node(i_list* list, i_node* new_node);

void remove_node(i_list* list, i_node* node);