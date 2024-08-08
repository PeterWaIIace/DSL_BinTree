#ifndef BINTREE_H
#define BINTREE_H
struct bt;

/**
 * @brief binary tree node factory
 * 
 * This functions takes value and creates new node.
 * 
 * @param value value for the new node
 * 
 * @return returns pointer to new node 
 * 
 *  */
struct bt *bt_leaf (int value);

/**
 * @brief binary tree node factory
 * 
 * This functions takes left and right child nodes, and node value and creates new node.
 * 
 * @param left pointer to left child node
 * @param right pointer to right child node
 * @param value value for the new node
 * 
 * @return returns pointer to new node 
 * 
 *  */
struct bt *bt_node (struct bt *left, struct bt *right, int value);

/**
 * @brief binary tree recursive print
 * 
 * This function takes current tree node and white characters buffer together with its length,
 * and performs prints with recursive calls till NILL is met.
 * 
 * @param tree is pointer to tree node structure
 * @param wc is white characters' buffer
 * @param wlen is white characters' buffer length
 * 
 *  */
void bt_print(struct bt *tree);

/**
 * @brief binary tree print
 * 
 * This function takes current tree node and prints entire tree starting from this node
 * 
 * @param tree is pointer to tree node structure
 * 
 *  */
void bt_free(struct bt *tree);
#endif