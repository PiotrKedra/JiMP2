//
// Created by piotr on 26.03.2017.
//

#include "SimpleTemplateEngine.h"
#include <string>
#include <unordered_map>
#include <regex>
#include <iostream>

namespace nets{
    View::View(std::string message):
            view(message) {}
    View::~View(){}

    std::string View::Render(const std::unordered_map <std::string, std::string> &model) const{
        const std::regex valid {R"(\{\{+([A-Za-z0-9_\\]){1,}\}\}+)"};
        std::string rendered = "";
        std::string tmp = "";
        std::string keeper = "";
        int tmp_i;
        int quantity; //the number of '{' in keeper
        int j;
        int sth;

        for(int i=0;i<view.size();++i){
            quantity=0;
            sth=0;
            j=0;
            tmp_i=0;
            keeper = "";
            tmp = "";
            if(view[i]=='{') {
                tmp_i = i;
                while (view[i]!='}') {
                    keeper += view[i];
                    ++i;
                }
                while (view[i]=='}'){
                    keeper += view[i];
                    ++sth;
                    ++i;
                }
                if (std::regex_match(keeper, valid)) {
                    j=0;
                    while(keeper[j]=='{'){
                        ++quantity;
                        ++j;
                    }
                    while (keeper[j]!='}') {
                        tmp += keeper[j];
                        ++j;
                    }
                    if(model.find(tmp)==model.end()){
                        tmp = "";
                        if (keeper.size() - j - 1 > 2) {
                            for (int k = 0; k < (keeper.size() - j - 1 - 2); ++k) i+=keeper.size()-1;
                        }
                        keeper = "";
                    }
                    else {
                        for (auto e: model) {
                            if (e.first == tmp) {
                                tmp = e.second;
                            }
                        }
                        while (quantity != 2) {
                            --quantity;
                            rendered += '{';
                        }
                        rendered += tmp;
                        tmp = "";
                        while(sth > 2){
                            rendered += '}';
                            --sth;
                        }
                        keeper = "";
                    }
                } else {
                    i=tmp_i;
                    while(view[i]=='{'){
                        rendered += view[i];
                        ++i;
                    }
                }
            }
            if(view[i]!= '\0') rendered += view[i];
        }
        return rendered;
    }
}
