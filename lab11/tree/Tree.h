//
// Created by piotr on 25.05.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

template <class T>
class Tree{
public:
    Tree():left_(nullptr),right_(nullptr){}
    Tree(T value): value_(value), left_(nullptr),right_(nullptr){}
    T GetValue(){
        return value_;
    }
    bool operator<(Tree right) {
        return this->GetValue() < right.GetValue();
    }
    void Add(T new_value){
        if(!this->value_){
            value_=new_value;
        }else {
            Tree new_node(new_value);
            Tree *next = this;
            Tree *prev = this;
            while (next != nullptr) {
                prev = next;
                if (new_node < this) {
                    next = next->left_;
                } else {
                    next = next->right_;
                }
            }
            if (prev < new_node) {
                prev->left_ = &new_node;
            }else{
                prev->right_ = &new_node;
            }
        }
    }
private:
    T value_;
    Tree* left_,*right_;
};

#endif //JIMP_EXERCISES_TREE_H
