//
// Created by piotr on 22.03.2017.
//

#include "SimpleForwardList.h"


ForwardList *CreateNode(int value){
    ForwardList *node = new ForwardList;
    node->value = value;
    node->next = nullptr;
    return node;
}
void DestroyList(ForwardList *list){
    ForwardList *tmp;
    while(list) {
        tmp = list->next;
        delete list;
        list = tmp;
    }
}
ForwardList *PushFront(ForwardList *list, int value){
    if(list == nullptr) return nullptr;
    ForwardList *new_node = CreateNode(value);
    new_node->next = list;
    return new_node;
}
void Append(ForwardList *list, ForwardList *tail){
    if(list == nullptr) return;
    ForwardList *tmp = list;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = tail;
}
