//
// Created by piotr on 23.03.2017.
//

#ifndef JIMP_EXERCISES_NAME_H
#define JIMP_EXERCISES_NAME_H

#include <string>
namespace name{
    class Name{
    public:
        Name(std::string firstname, std::string surname, std::string _2, std::string _3);
        ~Name();

        void FirstName();
        void Surname();
        void SecondName();
        void ThirdName();

        void ToFullInitials();
        void ToFirstNamesInitials();
        void ToSurnameNames();
        void ToNamesSurname();

    private:
        std::string first_name;
        std::string second_name;
        std::string third_name;
        std::string surname;
    };
}

#endif //JIMP_EXERCISES_NAME_H
