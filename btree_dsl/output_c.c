#include <stdio.h>
#include "btree.h"
int main(){
    struct bt* tree = bt_node(bt_node(bt_leaf(2),bt_node(NULL,bt_leaf(19),7),5),bt_node(bt_node(NULL,bt_leaf(89),12),bt_leaf(20),15),10);
    bt_print(tree);
    bt_free(tree);

    return 0;
};
