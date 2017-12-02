/* ---------------- DATA DEFINITIONS ---------------- */

/*
	Type of data to be stored in the list.

	The structure can be changed as you wish, but I
	recommend the use of some Primary Key (PK) to locate the data.
*/
typedef struct {
	int id;
} data_t;

/*
	The structure that define the linked-list.

	Do not change that structure: every node in list need a pointer to next node
	and a data_t to storage information.
*/
typedef struct node_t {
	struct node_t *next;
	struct node_t *prev;
	data_t data;
} node_t;

typedef node_t dlist_t;

/* ---------------- FUNCTIONS ---------------- */

/*
	Search some node by your primary key.
	This function depends of the data_t data type.

	param: dlist_t **list - the list where the node will be searched
	return: in success case, returns the address of the node; in failure, returns NULL
*/
node_t* search(dlist_t *list, int key) {
	node_t *p = list;

	while (p != NULL && p->data.id != key)
		p = p->next;

	return p;
}

/*
	Insert into linked-list a data_t in the end.
	If the list only accept unique values, call search() function to
	verify if have a node with the PK value in the list.

	param: dlist_t **list - the list where the data will be inserted
	param: data_t data - the data to be inserted into a node
	return: in success, return 1; in failure, return 0
*/
int insert(dlist_t **list, data_t data) {
	node_t *new_node = malloc(sizeof(node_t));
	node_t *p = NULL;

	if (new_node == NULL)
		return 0;

	new_node->data = data;

	if (*list == NULL) {
		new_node->next = new_node->prev = NULL;
		*list = new_node;
	} else {
		p = (*list);

		while(p->next != NULL)
			p = p->next;

		new_node->next = p->next;
		new_node->prev = p;
		p->next = new_node;
	}

	return 1;
}

/*
	Remove a node from the list by his primary key

	param: dlist_t **list - the list where the data will be removed
	param: int key - the target key to be removed
	return: in success, return 1; in failure, return 0
*/
int remove_by_key(dlist_t **list, int key) {
	node_t *target = search(*list, key);

	// Verify if the list is valid
	if ((*list) == NULL || target == NULL)
		return 0;

	// If the node is the first
	if (target->prev == NULL) {
		(*list) = target->next;

		if (*list != NULL)
			(*list)->prev = NULL;
	} else if (target->next == NULL) { // last
		target->prev->next = NULL;
	} else { // middle
		target->next->prev = target->prev;
		target->prev->next = target->next;
	}

	free(target);

	return 1;
}

/*
	Clear the linked list of the memory

	param: dlist_t **list - the list to be cleared
	return: ---
*/
void listclr(dlist_t **list) {
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
