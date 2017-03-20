//
// Created by piotr on 16.03.2017.
//

#include  "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>

namespace tinyurl {
    struct TinyUrlCodec{
        std::unique_ptr<TinyUrlCodec> yo;
    };

    std::unique_ptr<TinyUrlCodec> Init() {

    }

    void NextHash(std::array<char, 6> *state) {}

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {}

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {}
}