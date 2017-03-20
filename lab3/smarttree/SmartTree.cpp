//
// Created by piotr on 18.03.2017.
//

#include "SmartTree.h"
#include <ostream>
#include <string>
#include <memory>

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

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree);

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree);
}