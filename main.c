#include <stdio.h>
#include "btree.h"

int task_1()
{
    // create and display one leaf
    struct bt* leaf = bt_leaf(5);
    bt_print(leaf);
    bt_free(leaf);
    
    // create and display simple tree
    struct bt* rleaf = bt_leaf(5);
    struct bt* lleaf = bt_leaf(6);
    struct bt* tree = bt_node(rleaf,lleaf,8);
    bt_print(tree);
    bt_free(tree);

    // create and display more complex tree
    rleaf = bt_leaf(5);
    lleaf = bt_leaf(6);
    struct bt* ltree = bt_node(rleaf,lleaf,8);
    
    rleaf = bt_leaf(15);
    lleaf = bt_leaf(26);
    struct bt* rtree = bt_node(rleaf,lleaf,28);
    
    tree = bt_node(rtree,ltree,198);
    bt_print(tree);
    bt_free(tree);

    // create and display more complex tree recursively 
    tree = bt_node(bt_node(bt_leaf(5),bt_leaf(6),8),bt_node(bt_leaf(15),bt_leaf(26),28),198);
    bt_print(tree);
    bt_free(tree);
}

int main()
{
    task_1();
    return 0;
}