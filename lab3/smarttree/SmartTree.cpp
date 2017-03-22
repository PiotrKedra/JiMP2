//
// Created by piotr on 18.03.2017.
//

#include "SmartTree.h"
#include <ostream>
#include <string>
#include <memory>
#include <sstream>

namespace datastructures{


    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        leaf->value =  value;
        leaf->left = nullptr;
        leaf->right = nullptr;

        return leaf;
    }

    std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        if(!tree) return nullptr;
        tree->left = std::move(left_subtree);

        return tree;
    }

    std::unique_ptr<SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        if(!tree) return nullptr;
        tree->right = std::move(right_subtree);

        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr->left) PrintTreeInOrder(unique_ptr->left, out);
        *out << std::to_string(unique_ptr->value) << ", ";
        if(unique_ptr->right) PrintTreeInOrder(unique_ptr->right, out);
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        if(!tree) return "[none]";
        else {
            return "["+std::to_string(tree->value)+" "+DumpTree(tree->left)+" "+DumpTree(tree->right)+"]";
        }
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree){
        const std::string str_tree = tree;
        std::string value;
        std::unique_ptr<SmartTree> tree_out;
        int right_brackets = 0;
        int left_brackets = 0;
        int i=0,j=0;

        do{
            if(str_tree[i] == '['){
                i++;
                left_brackets++;
                if(left_brackets == 1){
                    while(str_tree[i] != 32 and str_tree[i] != ']'){
                        value += str_tree[i];
                        ++i;
                    }
                    if(value == "none") return nullptr;
                    tree_out = std::move(CreateLeaf(std::stoi(value)));
                    value = "";
                }
                if(left_brackets == 2 and j==0){
                    tree_out->left = std::move(RestoreTree(&(str_tree[i-1])));
                    j++;
                }
                if(left_brackets == 2 and j==1){
                    tree_out->right = std::move(RestoreTree(&(str_tree[i-1])));
                }
            }
            if(str_tree[i] == ']'){
                left_brackets--;
                right_brackets++;
            }
            i++;
        }while(left_brackets != 0);
        return tree_out;
    }
}