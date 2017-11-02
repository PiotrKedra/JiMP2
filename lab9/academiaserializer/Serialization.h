//
// Created by piotr on 04.05.2017.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <fstream>

namespace academia {
    class Serializer;
    class Serializable{
        virtual void Serialize(Serializer *serializ)=0;
    };
    class Serializer{
    public:
        Serializer(std::ostream *out) : out_(out){}
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value) {}
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;

    private:
        std::ostream *out_;

        };
    class Room : public Serializable {
    public:
        enum class Type{COMPUTER_LAB};
        Room(int id, std::string name, Room::Type type) : id_(id),name_(name),type_(type){}
        void Serialize(Serializer *serializ) override;


    private:
        int id_;
        std::string name_;
        Room::Type type_;
    };
    class XmlSerializer{

    };

    class Building{

    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
