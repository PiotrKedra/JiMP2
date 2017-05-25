//
// Created by piotr on 25.05.2017.
//

#include "Tree.h"

template <class T>
void Tree<T>::Add(T new_value){
    if(!this->value_){
        value_=new_value;
    }else {
        Tree new_node(new_value);
        Tree *next = this;
        Tree *prev = this;
        while (next != nullptr) {
            prev = next;
            if (new_node < this) {
                next = this->left_;
            } else {
                next = this->right_;
            }
        }
        if (prev < new_node) {
            prev->left_ = new_node;
        }else{
            prev->right_ = new_node;
        }
    }

}
