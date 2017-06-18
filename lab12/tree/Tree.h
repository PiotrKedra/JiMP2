//
// Created by piotr on 05.06.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#import <memory>
#include <iostream>
namespace tree {
    template<class T>
    class Tree: public std::enable_shared_from_this<Tree<T>> {
    public:

        Tree() : sleft(nullptr), sright(nullptr) {}

        Tree(T value) : value_(value), sleft(nullptr), sright(nullptr), size_(1), depth_(1) {}

        T Value() {
            return value_;
        }

        bool operator<(Tree right) {
            return this->Value() < right.Value();
        }

        void Insert(T new_value) {
            ++size_;
            if (!this->value_ && value_==0) {
                value_ = new_value;
                depth_=1;
            } else {
                std::shared_ptr<Tree<T>> bud=std::make_shared<Tree>(new_value);
                std::shared_ptr<Tree<T>> p1;
                std::shared_ptr<Tree<T>> p2;
                if(this->value_>new_value) p2=this->sleft;
                else p1=this->sleft;
                p1=this->shared_from_this();
                while(p2 !=nullptr){
                    p1=p2;
                    if(p2->value_>new_value) p2=p2->sleft;
                    else p2=p2->sright;
                }
                if(p1->value_>new_value) p1->sleft=bud;
                else p1->sright=bud;

            }
        }
        int Size(){
            return size_;
        }
        int Depth(){
            return depth_;
        }



    public:
        T value_;
        std::shared_ptr<Tree> sleft;
        std::shared_ptr<Tree> sright;
        int size_=0;
        int depth_=0;

    };

}


#endif //JIMP_EXERCISES_TREE_H
