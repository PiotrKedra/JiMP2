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
    bool operator<(Tree left, Tree right) {
        return left.GetValue() < right.GetValue();
    }
    void Add(T new_node);
private:
    T value_;
    Tree* left_,right_;
};

#endif //JIMP_EXERCISES_TREE_H
