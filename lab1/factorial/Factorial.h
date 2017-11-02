//
// Created by mwypych on 02.02.17.
//

#ifndef JIMP_EXERCISES_FACTORIAL_H
#define JIMP_EXERCISES_FACTORIAL_H

int factorial(int value);

template <class T>
class node{
public:
    node(){}
    node *next;
    node *prev;
    T elem;
};

template <class T>
class lista{
public:
    node *first;
    node *last;
    lista(){first= nullptr; last= nullptr;}
    ~lista(){
        node *tmp;
        while(first){
            tmp=first;
            first=first->next;
            delete tmp;
        }
    }
    void pushBack(const T &t){
        if(!first){
            first=new node;
            first->elem = t;
            first->next=nullptr;
            first->prev=nullptr;
            last=first;
        }else{
            last->next=new node;
            last->next->elem = t;
            last->next->next = nullptr;
            last->next->prev = last;
            last=last->next;
        }
    }
};

#endif //JIMP_EXERCISES_FACTORIAL_H
