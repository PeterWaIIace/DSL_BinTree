#include "dsl_tree.hpp"
#include <sstream>
#include <iostream>
#include <vector>

void BT_DSL::Node::addRight(Node *right)
{
    this->right = right;
};

void BT_DSL::Node::addLeft(Node *left)
{
    this->left = left;
};

std::string BT_DSL::Node::emit_iter(int tmp_index, int &max_index)
{
    bool tmp_exists = tmp_index <= max_index ? true : false;

    if(not tmp_exists)
    {
        max_index = tmp_index;
    }

    std::stringstream ss;
    std::stringstream ss_fin;
    if(!left and !right)
    {
        if(tmp_exists)
        {
            ss << "    tmp"<<tmp_index<<" = bt_leaf(" << this->value << ");\n";

        }
        else
        {
            ss << "    struct bt* tmp"<<tmp_index<<" = bt_leaf(" << this->value << ");\n";
        }
    }
    else
    {
        if(0 == tmp_index)
        {
            ss_fin << "    struct bt* bintree = bt_node(";
        }
        else
        {
            if(tmp_exists)
            {
                ss_fin << "    tmp"<<tmp_index<<" = bt_node(";
            }
            else
            {
                ss_fin << "    struct bt* tmp"<<tmp_index<<" = bt_node(";
            }
        }

        if(left)
        {
            tmp_index = tmp_index + 1;
            ss << left->emit_iter(tmp_index,max_index);
            ss_fin << "tmp" << tmp_index << ",";
        }
        else
        {
            ss_fin << "NULL,";
            // ss << "\n";
        }
        if(right)
        {
            tmp_index = tmp_index + 1;
            ss << right->emit_iter(tmp_index,max_index);
            ss_fin << "tmp" << tmp_index << ",";
        }
        else
        {
            ss_fin << "NULL,";
        }
        ss_fin << this->value << ");\n";
        ss << ss_fin.str();
    }
    return ss.str();
};



std::string BT_DSL::Node::emit()
{
    std::stringstream ss;
    if(!left and !right)
    {
        ss << "bt_leaf(" << this->value << ")";
    }
    else
    {
        ss << "bt_node(";
        if(left)
        {
            ss << left->emit();
        }
        else
        {
            ss << "NULL";
        }
        ss << ",";
        if(right)
        {
            ss << right->emit();
        }
        else
        {
            ss << "NULL";
        }
        ss << "," << this->value << ")";
    }
    return ss.str();
};

void BT_DSL::Tree::addNode(Node *main_node)
{
    this->main_node = main_node;
};


std::string BT_DSL::Tree::emit_iter(){
    std::stringstream ss;
    int index = 0;
    ss << main_node->emit_iter(0,index);
    ss << "    bt_print(bintree);\n";
    ss << "    bt_free(bintree);\n";
    return ss.str();
}

std::string BT_DSL::Tree::emit(){
    std::stringstream ss;
    ss << "    struct bt* tree = ";
    ss << main_node->emit();
    ss << ";\n";
    ss << "    bt_print(tree);\n";
    ss << "    bt_free(tree);\n";
    return ss.str();
}

int BT_DSL::Tree::parse_tree(BT_DSL::tokens tkns, int c_index)
{
    int index = c_index;
    while(index < tkns.size())
    {
        if(tkns[index].type == NODE)
        {
            main_node = new Node;
            if(tkns[index+1].type == BRACKET_OPEN)
            {
                index+=2;
                index = main_node->parse_node(tkns,index);
            }
            else
            {
                // malformed expression
                return index;
            }
        }

        if(tkns[index].type == BRACKET_CLOSE)
        {
            index+=1;
            return index;
        }
    }
    return index;
};

int BT_DSL::Node::parse_node(BT_DSL::tokens tkns, int c_index)
{
    int index = c_index;
    while(index < tkns.size())
    {
        if(tkns[index].type == VALUE)
        {
            value = std::stoi(tkns[index+1].value);
            index+=2;
        }
        else if(tkns[index].type == LEFT)
        {
            index+=1;
            if(tkns[index].type == NODE)
            {
                left = new Node;
                if(tkns[index+1].type == BRACKET_OPEN)
                {
                    index+=2;
                    index = left->parse_node(tkns,index);
                }
                else
                {
                    // malformed expression
                    std::cout << "Error: malformed expression" << std::endl;
                    return index;
                }
            }
            else
            {
                // malformed expression
                std::cout << "Error: malformed expression" << std::endl;
                return index;
            }
        }
        else if(tkns[index].type == RIGHT)
        {
            index+=1;
            if(tkns[index].type == NODE)
            {
                right = new Node;
                if(tkns[index+1].type == BRACKET_OPEN)
                {
                    index+=2;
                    index = right->parse_node(tkns,index);
                }
                else
                {
                    // malformed expression
                    std::cout << "Error: malformed expression" << std::endl;
                    return index;
                }
            }
            else
            {
                // malformed expression
                std::cout << "Error: malformed expression" << std::endl;
                return index;
            }
        }
        if(tkns[index].type == BRACKET_CLOSE)
        {
            index+=1;
            return index;
        }
    }
};

BT_DSL::AST::AST(tokens tkns)
{
    int index = 0;
    while(index < tkns.size())
    {
        if(tkns[index].type == TREE)
        {
            tree = new Tree;
            if(tkns[index+1].type == BRACKET_OPEN)
            {
                index = index+2;
                index = tree->parse_tree(tkns,index);
            }
            if(tkns[index].type == BRACKET_CLOSE)
            {
                break;
            }
        }
    }
};

std::string BT_DSL::AST::emit()
{
    return tree->emit();
};


std::string BT_DSL::AST::emit_iter()
{
    return tree->emit_iter();
};
