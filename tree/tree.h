/**
 * @file
 * Struct tree_node is a structure for a node of tree.
 */
struct tree_node;

/**
 * Struct index is a structure for the index of a tree node.
 */
struct index;

/**
 * Struct tree represents a hierarchical structure. 
 */
//struct tree;

/**
 * @brief Function to create an empty tree.
 */
struct tree* tree_create();

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
 * @brief Function to return tree node index by given data.
 *
 * @param root is the given tree.
 * @param num is the given data.
 *
 * @return 0 if tree node with the given data is not found in the tree.
 */
struct index tree_node_index_by_data(struct tree* tree, int num);

/**
 * @brief Function to return tree node by given data.
 *
 * @param tree is the given tree.
 * @param num is the given data.
 *
 * @return 0 if tree node with the given data is not found in the tree
.
 */
struct tree_node* tree_node_search(struct tree* tree, int num);

/**
 * @brief Function to return the number of nodes in the tree.
 *
 * @param tree is the given tree.
 */
int tree_size(struct tree* tree);

/**
 * @brief Function to return the tree node with the given index from the tree.
 *
 * @param tree is the tree.
 * @param ind is the index.
 *
 * @pre ind has to be valid(tree has to have a node with given index in it).
 */
struct tree_node* tree_node_find_by_index(struct tree* tree, struct index ind);

/**
 * @brief Function to remove the node by it's index.
 *
 * @param tree is the given tree.
 * @param ind is the given index.
 *
 * @pre ind has to be valid(tree has to have a node with given index in it).
 */
void tree_remove_node_by_index(struct tree* tree, struct index ind);
