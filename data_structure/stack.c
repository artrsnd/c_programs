typedef struct {
	int id;
} data_t;

typedef struct node_t {
	struct node_t *next;
	data_t data;	
} node_t;

typedef node_t stack;

/*
	Push a data into a dynamic stack.

	param: node_t **stack - stack
	param data_t data - data to be inserted into the refered stack
	return: in success, return 1; in failure, return 0
*/
int push(node_t **stack, data_t data) {
	node_t *new_node = malloc(sizeof(node_t));
	
	if (new_node == NULL)
		return 0;
		
	new_node->data = data;
	new_node->next = (*stack);
	(*stack) = new_node;
	return 1;
}

int pop(node_t **stack) {
	node_t *p;
	
	if (p == NULL)
		return 0;
	
	p = *stack;
	*stack = (*stack)->next;
	free(p);
}
