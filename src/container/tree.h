/**
 * @file
 * Struct tree_node is a structure for a node of tree.
 */
struct tree_node;

/**
 * Struct tree represents a hierarchical structure. 
 */
//struct tree;

struct tree_node* tree_node_create(int num);

/**
 * @brief Function to create an empty tree.
 */
struct tree* tree_create();

int max(int a, int b);

int tree_get_height (struct tree_node* root);

struct tree_node* tree_right_rotate(struct tree_node* y);

struct tree_node* tree_left_rotate(struct tree_node* x);

int tree_is_balanced (struct tree_node* root);

struct tree_node* tree_balance_node(struct tree_node* root, int num);

struct tree_node* tree_insert_node(struct tree_node* root, int num);

void tree_insert_array(struct tree* t, int arr[], int size);

void tree_insert_file_data(struct tree* t, char* file);

void tree_preorder(struct tree_node* root);

void tree_preorder_print(struct tree* t);

void tree_remove_element(struct tree_node* root, int el);

void tree_remove(struct tree* t, int el);

int tree_size_helper(struct tree_node* root);

int tree_height_helper(struct tree_node* root);

int tree_empty(struct tree* t);
/**
 * @brief Inserts node with given data into the tree.
 *
 * @param tree is the given tree.
 * @param num is the given data.
 *
 * @details num is inserted into the tree in a way that the tree is balanced the most.
 */
void tree_insert(struct tree* tree, int num);

/**
 * @brief Function to return tree height.
 */
int tree_height(struct tree* t);

/**
 * @brief Function to return the number of nodes in the tree.
 *
 * @param tree is the given tree.
 */
int tree_size(struct tree* tree);
