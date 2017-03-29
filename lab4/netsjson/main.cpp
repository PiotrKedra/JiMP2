//
// Created by piotr on 28.03.2017.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;

int main() {

    JsonValue bob{"abc"};
    vector<JsonValue> js{JsonValue{56.6}, JsonValue{45}, JsonValue{"abc"s}};
    JsonValue js1{{JsonValue{56.6}, JsonValue{45}, JsonValue{"abc"s}}};
    map<string, JsonValue> obj_v{{"values", JsonValue{js}},
                                 {"name",   JsonValue{"Test name"}},
                                 {"age",    JsonValue{13}}};
    JsonValue obj{obj_v};
    // {"age": 13, "name": "Test name", "values": [56.6, 45, "abc"]} kolejność argumentów nie ma znaczenia w przypadku obiektu

    cout << bob.ToString() << " LOL" << endl;

    return 0;
}