//
// Created by piotr on 05.06.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#import <memory>

namespace tree {
    template<class T>
    class Tree {
    public:
        Tree() : left_(nullptr), right_(nullptr) {}

        Tree(T value) : value_(value), left_(nullptr), right_(nullptr), size_(1) {}

        T Value() {
            return value_;
        }

        bool operator<(Tree right) {
            return this->Value() < right.Value();
        }

        void Insert(T new_value) {
            ++size_;
            if (!this->value_) {
                value_ = new_value;
            } else {
                Tree new_node(new_value);
                Tree *next = this;
                Tree *prev = this;
                while (next != nullptr) {
                    prev = next;
                    if (new_node.Value() < next->Value()) {
                        next = next->left_;
                    } else {
                        next = next->right_;
                    }
                }
                if (prev->Value() < new_node.Value()) {
                    prev->left_ = &new_node;
                } else {
                    prev->right_ = &new_node;
                }
            }
        }
        int Size(){
            return size_;
        }
        int Depth(){
            if(this == nullptr) return 0;
            else {
                int lchild = this->left_->Depth();
                int rchild = this->right_->Depth();
                if(lchild <= rchild) return rchild+1;
                else return lchild+1;
            }
        }
    public:
        T value_;
        Tree *left_, *right_;
        int size_=0;

    };
    
}


#endif //JIMP_EXERCISES_TREE_H
