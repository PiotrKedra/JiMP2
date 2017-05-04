//
// Created by piotr on 04.05.2017.
//

#include "Serialization.h"

namespace academia {

    void Room::Serialize(Serializer *serializ) {
        serializ->IntegerField("id",id_);
        serializ->StringField("name",name_);
        serializ->StringField("type","COMPUTER_LAB");
        serializ->Header("Room");
        serializ->Footer("sth");

    }
}
