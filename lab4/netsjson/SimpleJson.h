//
// Created by piotr on 28.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <string>
#include <experimental/optional>
#include <vector>
#include <map>

namespace nets{
    class JsonValue{
    public:
        JsonValue(int value);
        JsonValue(double value);
        JsonValue(std::string str);
        JsonValue(bool value);
        JsonValue(std::vector<JsonValue> tab);
        JsonValue(std::map<std::string,JsonValue> obj);
        ~JsonValue();

        std::string ToString() const;
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

    private:
        int js_int;
        double js_double;
        std::string js_str;
        bool js_bool;
        std::vector<JsonValue> js_vector;
        std::map<std::string,JsonValue> js_map;
        bool if_int = false;
        bool if_double = false;
        bool if_str = false;
        bool if_bool = false;
        bool if_vector = false;
        bool if_map = false;

    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
