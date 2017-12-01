typedef struct {
	int id;
} data_t;

typedef struct node_t {
	struct node_t *next;
	data_t data;
} node_t;

typedef node_t list_t;

/*
	Insert into linked-list a data_t in the end.

	param: node_t **list - the list where the data will be inserted
	param: data_t data - the data to be inserted into a node
	return: in success, return 1; in failure, return 0
*/
int insert(list_t **list, data_t data) {
	node_t *new_node = malloc(sizeof(node_t));
	node_t *p = NULL;

	if (new_node == NULL)
		return 0;

	new_node->data = data;
	new_node->next = NULL;

	if (*list == NULL)
		*list = new_node;
	else {
		p = (*list);

		while(p->next != NULL)
			p = p->next;

		p->next = new_node;
	}

	return 1;
}

/*
	Remove a node from the list by his address

	param: node_t **list - the list where the data will be removed
	param: node_t *target - the target to be removed
	return: in success, return 1; in failure, return 0
*/
int remove_by_addr(list_t **list, node_t *target) {
	node_t *p = NULL;

	// Verify if the target is valid and list is valid
	if (target == NULL || (*list) == NULL)
		return 0;

	// Verify if the target is the head of list
	if ((*list) == target)
		*list = target->next;
	else {
		p = (*list);

		// Search for the previous node to the target in the list
		while (p != NULL && p->next != target)
			p = p->next;

		// Verify if target doesn't belong to list
		if (p == NULL)
			return 0;

		p->next = target->next;
	}

	free(target);
}

int remove_by_key(list_t **list, int key) {
	node_t *p = NULL;
	node_t *target = NULL;

	// Verify if the list is valid
	if ((*list) == NULL)
		return 0;

	if ((*list)->data.id == key) {
		target = (*list);
		*list = target->next;
	} else {
		p = (*list);

		while (p->next != NULL && p->next->data.id != key)
			p = p->next;

		// The value doesn't belong to list
		if (p == NULL)
			return 0;

		target = p->next;
		p->next = target->next;
	}

	free(target);

	return 1;
}

/*
	Clear the linked list of the memory

	param: node_t **list - the list to be cleared
	return: ---
*/
void listclr(list_t **list) {
	node_t *p, *q;
	p = q = NULL;

	p = (*list);

		while (p != NULL) {
			q = p;
			p = p->next;
			free(q);
		}

		(*list) = NULL;
}

/*
	Search some node by your primary key.
	This function depends of the data_t data type.

	param: node_t **list - the list where the node will be searched
	return: in success case, returns the address of the node; in failure, returns NULL
*/
node_t* search(list_t *list, int key) {
	node_t *p = list;

	while (p != NULL && p->data.id != key)
		p = p->next;

	return p;
}
