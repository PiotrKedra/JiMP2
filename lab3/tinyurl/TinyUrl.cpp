//
// Created by piotr on 16.03.2017.
//

#include  "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>
#include <vector>

namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> init = std::make_unique<TinyUrlCodec>();
        init->hash.fill('a');
        return init;
    }

    void NextHash(std::array<char, 6> *state){
        for(int i=5;i>=0;--i){
            if((*state)[i] == 'z'){
                (*state)[i] = '0';
                continue;
            }
            else if((*state)[i] == '9'){
                (*state)[i] = 'A';
                break;
            }
            else if((*state)[i] == 'Z'){
                (*state)[i] = 'a';
                break;
            }
            else{
                (*state)[i]+=1;
                break;
            }
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        std::string code = "";
        (*codec)->url_tab.emplace_back(url);
        for(char v: (*codec)->hash){
            code+=v;
        }
        (*codec)->hash_tab.emplace_back(code);
        NextHash(&(*codec)->hash);
        return code;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        int index;
        for(std::string v: codec->hash_tab) {
            index++;
            if(hash == v) break;
        }
        return codec->url_tab[index];
    }
}