/* ---------------- DATA DEFINITIONS ---------------- */

/*
	Type of data to be stored in the queue.
*/
typedef struct {
	int id;
} data_t;

/*
	The structure that define the stack.

	Do not change that structure: every node in queue need a pointer to next node
	and a data_t to storage information.
*/
typedef struct node_t {
	struct node_t *next;
	data_t data;
} node_t;

typedef node_t queue_t;

/* ---------------- FUNCTIONS ---------------- */

/*
	Enqueue a data_t structure into queue.

	param: queue_t **queue - queue
	param data_t data - data to be inserted into the refered queue
	return: in success, return 1; in failure, return 0
*/
int enqueue(queue_t **queue, data_t data) {
	node_t *new_node = malloc(sizeof(node_t));
	node_t *p = NULL;

	if (new_node == NULL)
		return 0;

	new_node->data = data;
	new_node->next = NULL;

	if (*queue == NULL) {
		*queue = new_node;
	} else {
		p = *queue;

		while (p->next != NULL)
			p = p->next;

		p->next = new_node;
	}

	return 1;
}

/*
	Remove the first element of the queue.

	param: queue_t **queue - queue
	return: in success, return 1; in failure, return 0
*/
int dequeue(queue_t **queue) {
	node_t *p;

	if (queue == NULL)
		return 0;

	p = *queue;
	*queue = (*queue)->next;
	free(p);

	return 1;
}
