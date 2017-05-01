//
// Created by piotr on 27.04.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <stdexcept>

namespace academia{
    class Pesel{
    public:
        Pesel(std::string pesel){

            pesel_=pesel;
        }

    private:
        std::string pesel_;
    };

    class AcademiaDataValidationError : public std::runtime_error{
    public:
        AcademiaDataValidationError(): std::runtime_error("sth"){}
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum() : std::runtime_error("InvalidPeselChecksum"){}
    };

    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength() : std::runtime_error("InvalidPeselLength"){}
    };
    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter() : std::runtime_error("InvalidPeselCharacter"){}
    };

}

#endif //JIMP_EXERCISES_PESEL_H
