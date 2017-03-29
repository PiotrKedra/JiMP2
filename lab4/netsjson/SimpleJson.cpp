//
// Created by piotr on 28.03.2017.
//

#include "SimpleJson.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <experimental/optional>

using std::string;
using ::std::literals::operator""s;

namespace nets{
    JsonValue::JsonValue(int value):
            js_int(value){
        if_int = true;
    }
    JsonValue::JsonValue(double value):
            js_double(value){
        if_double = true;
    }
    JsonValue::JsonValue(string str):
            js_str(str){
        if_str = true;
    }
    JsonValue::JsonValue(bool value):
            js_bool(value){
        if_bool = true;
    }
    JsonValue::JsonValue(std::vector<JsonValue> tab):
            js_vector(tab){
        if_vector = true;
    }
    JsonValue::JsonValue(std::map<string,JsonValue> obj):
            js_map(obj){
        if_map = true;
    }
    JsonValue::~JsonValue(){}

    string JsonValue::ToString() const{
        if(if_int) return std::to_string(js_int);
        else if(if_double){
            string cus = std::to_string(js_double);
            string result = "";
            int i=0;
            while(cus[i]!='0'){
                result += cus[i];
                ++i;
            }
            return result;
        }
        else if(this->if_str){
            if(js_str=="") return "";
            return ("\"" + js_str + "\"");
        }
        else if(if_bool){
            if(js_bool) return "true";
            else return "false";
        }
        else if(if_vector){
            string result = "[";
            for(int i=0;i<js_vector.size();++i){
                result += js_vector[i].ToString();
                if(i+1<js_vector.size()) result += ", ";
            }
            return result+"]";
        }
        else if(if_map){
            string result = "";
            string tmp = "";
            unsigned long int size = js_map.size()-1;
            for(auto e: js_map){
                result += "\"" + e.first + "\": ";
                result += e.second.ToString();
                if(size!=0) result += ", ";
                --size;
            }
            return result;
        }

    }
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const string &name) const{
        if(!if_map) return {};
        for(auto v: this->js_map){
            if(v.first == name){
                return std::experimental::make_optional(JsonValue {v.second});            }
        }
    }
}
