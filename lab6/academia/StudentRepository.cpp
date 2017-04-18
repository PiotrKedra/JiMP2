//
// Created by piotr on 06.04.2017.
//

#include "StudentRepository.h"

namespace academia{
    StudyYear::StudyYear(int yearr):
            year(yearr) {}
    Student::Student() {}
    Student::Student(int idd, std::string firstname, std::string lastname, std::string programm, StudyYear yearr):
            Id(idd), first_name(firstname), last_name(lastname), program(programm), year(yearr){}
    Student::~Student(){}
}