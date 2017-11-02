//
// Created by piotr on 26.03.2017.
//
#include <iostream>
#include <unordered_map>
#include <regex>
#include "SimpleTemplateEngine.h"

int main(){
    nets::View view {"test {{{test}}} of {test} but {{test} or {test}} and {{{test}}}"};
    std::cout << view.Render({{"test", "888"}}) << std::endl;

    std::regex valid {R"(\{\{+([A-Za-z0-9_]){1,}\}\}+)"};
    if(std::regex_match("{{template_with_underscore}}",valid)){
        std::cout << "Ol yeahhh" ;
    }
    return 0;
}


