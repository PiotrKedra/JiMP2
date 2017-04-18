//
// Created by piotr on 17.04.2017.
//

#include "Counts.h"

namespace datastructures {
    Counts::Counts() {counts_=1;}
    Counts::Counts(int value) {counts_=value;}
    Counts& Counts::operator++() {
        this->counts_++;
        return *this;
    }
    bool operator==(const Counts& left, const int right){
        return left.GetCounts()==right;
    }
    bool operator<(const Counts& left, const Counts& right){
        return left.GetCounts() < right.GetCounts();
    }
    bool operator>(const Counts& left, const Counts& right){
        return left.GetCounts() < right.GetCounts();
    }
}
