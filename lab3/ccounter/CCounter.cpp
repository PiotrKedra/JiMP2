//
// Created by piotr on 21.03.2017.
//

#include "CCounter.h"
#include <string>
#include <memory>
#include <map>

using std::string;

namespace ccounter{
    std::unique_ptr<Counter> Init(){
        std::unique_ptr<Counter> init = std::make_unique<Counter>();
        return init;
    }
    void Inc(std::string key, std::unique_ptr<Counter>* counter){

    }
    int Counts(const std::unique_ptr<Counter> &counter, std::string key);
    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);
}
