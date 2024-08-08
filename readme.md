# Binary tree builder:

This is codebase presenting domain specific language for building binary trees.

# How to run: 

These commands will build and run basic program in main.c

```sh
./build.sh;
./btree
```

The `btree` program is showing how to use `btree` library.

```
struct bt *bt_leaf (int value);
struct bt *bt_node (struct bt *left, struct bt *right, int value);
void bt_print(struct bt *tree);
void bt_free(struct bt *tree);
```


# DSL compiler:

## How to run:

Go to `btree_dsl` and run:

```sh
./build.sh;
./bt_compiler tree.bt my_output_file.c
```

This will generate recursive binary tree in C:

```C
```

To generate iterative constructor calls for binary tree, call:

```sh
./bt_compiler tree.bt my_output_file.c -i
```

This will generate iterative constructors in C:

```C
```

## `.bt` dsl format:

Binary tree dsl provide json-like format to build binary trees:

```
Tree {
    Node {
        value: 10
        left: Node {
            value: 5
            left: Node {
                value: 2
            }
            right: Node {
                value: 7
                right: Node {
                    value: 19
                }
            }
        }
        right: Node {
            value: 15
            left: Node {
                value: 12
                right: Node {
                    value: 89
                }
            }
            right: Node {
                value: 20
            }
        }
    }
}
```

White characters are being escaped and keywords are not case sensitive. To construct new binary tree create `Tree` node:

```
Tree {
}
```

Then it can be populated with `Nodes`. `Node` accept 3 keywords: `value:`, `left:`, and `right:`. It is important to notice that all keywords have colon at the end.

```
Node {
    value: 10
    left: // incorrect
    right: // incorrect
}
```

Following `Node` is incorrect as both `left:` and `right:` have to be followed by another `Node` definition. If you want to make final `Node`, or `Node` with only one child, then do not declare `left:` or `right:` or both.

Final node:
```
Node {
    value: 10
}
```

Node only with one node which is final node at the same time:
```
Node {
    value: 10
    left: Node {
        value: 9
    }
}
```

Full Tree would look like:

```
Tree {
    Node {
    value: 10
    left: Node {
        value: 9
        }
    }
}
```

# Author:
Piotr Walas, walas.piotr@outlook.com 
