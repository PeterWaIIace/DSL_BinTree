#include "btree.h"
#include <stdio.h>
#include <string.h>

struct bt{
    int value;
    struct bt *left;
    struct bt *right;
};


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
struct bt *bt_leaf (int value)
{
    return bt_node(NULL,NULL,value);
};


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

struct bt *bt_node (struct bt *left, struct bt *right, int value)
{
    struct bt* leaf = malloc(sizeof(struct bt));
    leaf->value = value;
    leaf->left  = left;
    leaf->right = right;
    return leaf;
};

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
void bt_r_print(struct bt *tree,char* wc, int wlen)
{
    int new_wlen = wlen + 1;
    char new_wc[new_wlen];
    snprintf(new_wc,new_wlen,"%s ",wc);

    printf("%svalue: %i\n",new_wc,tree->value);
    if(tree->left)
    {
        printf("%sleft: Node {\n",new_wc);
        bt_r_print(tree->left,new_wc,new_wlen);
        printf("%s}\n",new_wc);
    }
    if(tree->right)
    {
        printf("%sright: Node {\n",new_wc);
        bt_r_print(tree->right,new_wc,new_wlen);
        printf("%s}\n",new_wc);
    }
}

/**
 * @brief binary tree print
 * 
 * This function takes current tree node and prints entire tree starting from this node
 * 
 * @param tree is pointer to tree node structure
 * 
 *  */
void bt_print(struct bt *tree)
{
    printf("\nTree: {\n");
    char* wc = "";
    bt_r_print(tree,wc,sizeof(wc));
    printf("\n}\n");
};


/**
 * @brief binary tree memmory deallocation call
 * 
 * This functions takes current tree node and frees recursively starting node and all of the child nodes.
 * 
 * @param tree is pointer to tree node structure
 * 
 *  */

void bt_free(struct bt *tree)
{
    if(tree->left)
    {
        bt_free(tree->left);
    }
    if(tree->right)
    {
        bt_free(tree->right);
    }
    free(tree);
};
