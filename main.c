#include <stdio.h>
#include "btree.h"

void task_1()
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

void task_2()
{
    struct bt* tree = bt_node(bt_node(bt_leaf(2),bt_node(NULL,bt_leaf(19),7),5),bt_node(bt_node(NULL,bt_leaf(89),12),bt_leaf(20),15),10);
    bt_print(tree);
    bt_free(tree);
}

void task_3()
{

    struct bt* tmp2 = bt_leaf(2);
    struct bt* tmp4 = bt_leaf(19);
    struct bt* tmp3 = bt_node(NULL,tmp4,7);
    struct bt* tmp1 = bt_node(tmp2,tmp3,5);
    tmp4 = bt_leaf(89);
    tmp3 = bt_node(NULL,tmp4,12);
    tmp4 = bt_leaf(20);
    tmp2 = bt_node(tmp3,tmp4,15);
    struct bt* bintree = bt_node(tmp1,tmp2,10);
    bt_print(bintree);
    bt_free(bintree);
}

int main()
{
    task_1();
    task_2();
    task_3();
    return 0;
}