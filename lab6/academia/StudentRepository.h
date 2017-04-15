//
// Created by piotr on 06.04.2017.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <vector>
#include <iostream>

namespace academia{
    class StudyYear{
    public:
        StudyYear(){year=1;}
        StudyYear(int yearr);

        void operator++(){
            year += 1;
        }
        void operator--(){
            year -= 1;
        }
        void Print(){
            std::cout << year << std::endl;
        }
            private:
        int year;
    };
    class Student{
    public:
        Student();
        Student(int idd, std::string firstname, std::string lastname, std::string programm, StudyYear yearr);
        ~Student();

    private:
        int id;
        std::string first_name;
        std::string last_name;
        std::string program;
        StudyYear year;
    };
    class StudentRepository{
        StudentRepository();
        StudentRepository(std::vector<Student> reopz);

    private:
        std::vector<Student> reop;
    };
}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
