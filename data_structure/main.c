#include <stdio.h>
#include <stdlib.h>

#include "linked-list.c"

int main (void) {
	data_t data;
	int i = 0;
	list_t *list = NULL;

	for(; i < 10; i++) {
		data.id = i;
		insert(&list, data);
	}

	node_t *p;
	node_t *target = search(list, 10);

	remove_by_key(&list, 0);

	p = list;
	while (p != NULL) {
		printf("[main] ID: %d\n", p->data.id);

		p = p->next;
	}

	listclr(&list);

	return 0;
}
