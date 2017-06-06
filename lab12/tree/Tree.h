//
// Created by piotr on 05.06.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#import <memory>
#include <iostream>
namespace tree {
    template<class T>
    class Tree {
    public:
        Tree() : left_(nullptr), right_(nullptr) {}

        Tree(T value) : value_(value), left_(nullptr), right_(nullptr), size_(1), depth_(1) {}

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
                depth_=1;
            } else {
                Tree<T> *new_node =new Tree<T> {new_value};
                Tree *next = this;
                Tree *prev = this;
                int local_depth=1;
                while (next != nullptr) {
                    prev = next;
                    local_depth++;
                    if (new_node->Value() < next->Value()) {
                        std::cout<<"Uno"<<new_value<<new_node->Value()<<next->Value();
                        next = next->left_;

                    } else {
                        std::cout<<"Buno"<<new_value<<next->Value();
                        next = next->right_;

                    }
                }
                if (prev->Value() < new_node->Value()) {
                    prev->right_ = new_node;
                } else {
                    prev->left_ =new_node;
                }
            if(local_depth>depth_) depth_=local_depth;
            }
        }
        int Size(){
            return size_;
        }
        int Depth(){
//            if(this == nullptr) return 0;
//            else {
//                int lchild;
//                int rchild;
//                if(this ->left_!= nullptr) lchild = this->left_->Depth();
//                else lchild=0;
//                if(this->right_ != nullptr) rchild = this->right_->Depth();
//                else rchild=0;
//                if(lchild <= rchild) return rchild+1;
//                else return lchild+1;
//            }
            return depth_;
        }
        ~Tree(){
            if(left_!= nullptr) delete left_;
            if(right_!= nullptr) delete right_;


        }


    public:
        T value_;
        Tree *left_= nullptr;
        Tree *right_= nullptr;
        int size_=0;
        int depth_=0;

    };

}


#endif //JIMP_EXERCISES_TREE_H
