#include <stdio.h>
 #include "btree.h"
int main(){
    struct bt* tmp2 = bt_leaf(2);
    struct bt* tmp4 = bt_leaf(19);
    struct bt* tmp3 = bt_node(NULL,tmp4,7);
    struct bt* tmp1 = bt_node(tmp2,tmp3,5);
    tmp4 = bt_leaf(89);
    tmp3 = bt_node(NULL,tmp4,12);
    tmp4 = bt_leaf(20);
    tmp2 = bt_node(tmp3,tmp4,15);
    struct bt* bintree = bt_node(tmp1,tmp2,10);

    return 0;
};
