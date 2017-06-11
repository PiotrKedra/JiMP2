//
// Created by piotr on 05.06.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>
#include <iostream>

namespace tree {
    template<class T>
    class Node {
    public:
        Node(T value) : value_(value) {}

        std::unique_ptr<Node<T>> left_ = nullptr;
        std::unique_ptr<Node<T>> right_ = nullptr;
        T value_;

    };

    template<class T>
    class Tree {
    public:
        Tree() {}

        Tree(T value) : value_(value), size_(1) {}

        T Value() {
            return value_;
        }

        bool operator<(Tree right) {
            return this->Value() < right.Value();
        }

        bool operator=(Tree right) {
            return this->Value() = right.Value();
        }

        void Insert(T new_value) {
            ++size_;
            if (!this) {
                value_ = new_value;
            } else {
                Tree new_node(new_value);
                std::unique_ptr<Tree<T>> next = this;
                std::unique_ptr<Tree<T>> prev = this;
                while (next != nullptr) {
                    prev = next;
                    if (new_node.Value() < next->value_) {
                        next = next->left_;
                    } else {
                        next = next->right_;
                    }
                }
                if (prev->value_ < new_node.Value()) {
                    prev->left_ = new_node;
                } else {
                    prev->right_ = new_node;
                }
            }
        }

        int Size() {
            return size_;
        }

        int Depth() {
            return DepthPreorder(left_);
        }

    private:
        int size_ = 1;
        std::unique_ptr<Node<T>> left_ = nullptr;
        std::unique_ptr<Node<T>> right_ = nullptr;
        std::unique_ptr<Node<T>> value_;
        int DepthPreorder(const std::unique_ptr<Node<T>> &root);

    };

    template<class T>
    int Tree<T>::DepthPreorder(const std::unique_ptr<Node<T>> &root)  {
        if (root != nullptr)
            return 1 + std::max(this->DepthPreorder(root->left_), this->DepthPreorder(root->right_));
        return 0;
    }
}


#endif //JIMP_EXERCISES_TREE_H
