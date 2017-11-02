//
// Created by piotr on 23.03.2017.
//

#include <string>
#include <iostream>
#include "Name.h"

namespace name{
    Name::Name(std::string firstname, std::string surname, std::string _2 = "", std::string _3 = ""):
            first_name(firstname),surname(surname),second_name(""),third_name("")
    {
        if(_2 != "") second_name = _2;
        if(_3 != "") third_name = _3;
    }
    Name::~Name() {}

    void Name::FirstName() {
        std::cout << first_name << std::endl;
    }
    void Name::Surname() {
        std::cout << surname << std::endl;
    }
    void Name::SecondName(){
        if(second_name == "") std::cout << "LACK" << std::endl;
        std::cout << second_name << std::endl;
    }
    void Name::ThirdName(){
        if(third_name == "") std::cout << "LACK" << std::endl;
        std::cout << third_name << std::endl;
    }
    void Name::ToFullInitials(){
        if(second_name == ""){
            std::cout << first_name[0] << "." << surname[0] << "." << std::endl;
        }
        else if(third_name == ""){
            std::cout << first_name[0] << "." << second_name[0] <<"." << surname[0] << "." << std::endl;
        }
        else{
            std::cout << first_name[0] << "." << second_name[0] << "." << third_name[0] <<"." << surname[0] << "." << std::endl;
        }
    }
    void Name::ToFirstNamesInitials(){
        if(second_name == ""){
            std::cout << first_name[0] << "." << surname << std::endl;
        }
        else if(third_name == ""){
            std::cout << first_name[0] << "." << second_name[0] <<"." << surname << std::endl;
        }
        else{
            std::cout << first_name[0] << "." << second_name[0] << "." << third_name[0] <<"." << surname << std::endl;
        }
    }
    void Name::ToSurnameNames(){
        if(second_name == ""){
            std::cout << surname << " " << first_name << std::endl;
        }
        else if(third_name == ""){
            std::cout << surname << " " << first_name << " " << second_name << std::endl;
        }
        else{
            std::cout << surname << " " << first_name << " " << second_name << " " << third_name << std::endl;
        }
    }
    void Name::ToNamesSurname(){
        if(second_name == ""){
            std::cout << first_name << " " << surname << std::endl;
        }
        else if(third_name == ""){
            std::cout << first_name << " " << second_name << " " << surname << std::endl;
        }
        else{
            std::cout << first_name << " " << second_name << " " << third_name << " " << surname << std::endl;
        }
    }
}