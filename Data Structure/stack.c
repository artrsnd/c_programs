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
	data_t data;
} node_t;

typedef node_t stack_t;

/* ---------------- FUNCTIONS ---------------- */

/*
	Push a data into a dynamic stack.

	param: stack_t **stack - stack
	param data_t data - data to be inserted into the refered stack
	return: in success, return 1; in failure, return 0
*/
int push(stack_t **stack, data_t data) {
	node_t *new_node = malloc(sizeof(node_t));

	if (new_node == NULL)
		return 0;

	new_node->data = data;
	new_node->next = (*stack);
	(*stack) = new_node;
	return 1;
}

/*
	Remove a node from the top of the stack.

	param: stack_t **stack - stack
	return: in success, return 1; in failure, return 0
*/
int pop(stack_t **stack) {
	node_t *p;

	if (p == NULL)
		return 0;

	p = *stack;
	*stack = (*stack)->next;
	free(p);
}
