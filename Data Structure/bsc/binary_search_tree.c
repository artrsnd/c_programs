typedef struct {
	int id;
} data_t;

typedef struct node_t {
	int key;
	struct node_t *lchild;
	struct node_t *rchild;
} node_t;

int obtainLevel(node_t *tree,  int num) {
	int level = 0;

	while (tree && tree->key != num) {
		if (num < tree->key)
			tree = tree->lchild;
		else
			tree = tree->rchild;

		level++;
	}

	if (!tree)
		level = -1;

	return level;
}

node_t* search_parent(node_t *tree,  int num) {
	node_t *parent = NULL;

	while (tree && tree->key != num) {
		parent = tree;

		if (num < tree->key)
			tree = tree->lchild;
		else
			tree = tree->rchild;
	}

	if (!tree)
		parent = NULL;

	return parent;
}

int childs(node_t *tree) {
	int grauArvore = 0;

	if (tree) {
		if ((tree->lchild) && (tree->rchild))
			grauArvore = 2;
		else if ((!tree->lchild) && (tree->rchild))
			grauArvore = childs(tree->rchild);
		else if ((!tree->rchild) && (tree->lchild))
			grauArvore = childs(tree->lchild);
		else
			grauArvore = 1;
	}

	return grauArvore;
}

int height(node_t *root) {
   int left_height = 0;
   int right_height = 0;

   if (root == NULL)
      return -1;
   else {
      left_height = height(root->lchild);
      right_height = height(root->rchild);
      if (left_height < right_height) return right_height + 1;
      else return left_height + 1;
   }
}

void clear_tree(node_t *root) {
	if (root != NULL) {
		clear_tree(root->lchild);
		clear_tree(root->rchild);
		free(root);
	}
}

void insert(node_t **root, int key) {
	static node_t *new_node = NULL;

	new_node = malloc(sizeof(node_t));
	new_node->lchild = new_node->rchild = NULL;
	new_node->key = key;

	// Insercao de inicio
	if ((*root) == NULL) {
		(*root) = new_node;
	} else if (new_node->key < (*root)->key) {
		insert(&(*root)->lchild, key);
	} else {
		insert(&(*root)->rchild, key);
	}
}

node_t* search(node_t *root, int key) {
	if (root == NULL || root->key == key) {
		return root;
	} else if (root->key > key) {
		return search(root->lchild, key);
	} else {
    return search(root->rchild, key);
	}
}

void remove(node_t *tree, int num) {
	node_t *target, *parent, *substitute;

	target = search(tree, num);

	if (!target) return;

	parent = search_parent(tree, num);

	if (!target->lchild)
		substitute = target->rchild;
	else {

	}
}
