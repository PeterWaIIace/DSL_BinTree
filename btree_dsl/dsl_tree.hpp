#pragma once

#include <string>
#include <vector>
#include <regex>
#include <map>
#include <variant>
#include <functional>
#include "dsl_tokenizer.hpp"

namespace BT_DSL{
    class Node{
        public:
            int   value;
            Node *left;
            Node *right;

            Node() : value(0), left(nullptr), right(nullptr){};

            int parse_node(tokens tkns, int c_index);
            void addRight(Node *right);
            void addLeft(Node *left);
            std::string emit();
            std::string emit_iter(int tmp_index, int &max_index);
    };

    class Tree{
        public:
            Node *main_node;

            Tree() : main_node(nullptr){};

            int parse_tree(tokens tkns, int c_index);
            void addNode(Node *main_node);
            std::string emit();
            std::string emit_iter();
    };

    class AST
    {
        private:
            Tree *tree;
        public:
            AST(tokens tkns);
            std::string emit();
            std::string emit_iter();
    };
}