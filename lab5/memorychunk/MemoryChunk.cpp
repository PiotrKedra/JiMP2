//
// Created by piotr on 29.03.2017.
//

#include <cstdint>
#include <algorithm>
#include <cstring>
#include "MemoryChunk.h"


namespace memorychunk {
    MemoryChunk::MemoryChunk() : name_{new char[1024]} {}


    MemoryChunk::MemoryChunk(const std::string name){}

    MemoryChunk::MemoryChunk(size_t sz){}
    int8_t *MemoryChunk::MemoryAt(size_t offset) const{}
    size_t MemoryChunk::ChunkSize() const{}


    //Rule of Five

    MemoryChunk::~MemoryChunk() {
        delete[] name_;
    }

//konstruktor kopiujący:
    MemoryChunk::MemoryChunk(const MemoryChunk &xxx) {
        size_t sz = strlen(xxx.name_);
        name_ = new char[sz];
        strcpy(name_, xxx.name_);
        //Teraz nowy obiekt pokazuje na nowy fragment pamięci,
        //ale ze skopiowaną informacją
    }

//operator przypisania:
    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &xxx) {
        //jeśli ktoś wpadł na pomysł x = x;
        if (this == &xxx) {
            return *this;
        }
        //w przyciwynym wypadku mamy x = y;
        //musimy sami zwolnic pamięć po x (czyli this):
        delete[] name_;
        //i wreszcie kopiowanie, ten kod jest
        //jest identyczny więc można by go wydzielić do innej metody...
        size_t sz = strlen(xxx.name_);
        name_ = new char[sz];
        strcpy(name_, xxx.name_);
    }

//konstruktor przenoszący:
    MemoryChunk::MemoryChunk(MemoryChunk && xxx) : name_{nullptr} {
        swap(name_, xxx.name_);
        //Bardzo popularna szutczka
        //wiemy, ze za chwilę xxx zostanie zniszczony
        //za pomocą destrukotra, więc inicjalizujemy
        //this na nullptr i wymieniamy się z xxx
        //delete nullptr jest bezpieczna operacją i nic się nie stanie...
    }

//operator przenoszący:
    MemoryChunk &MemoryChunk::operator=(MemoryChunk && xxx) {
        //jeśli ktoś wpadł na pomsył x = move(x);
        if (this == &xxx) {
            return xxx;
        }
        //w przyciwynym wypadku mamy x = move(y);
        //musimy sami zwolnic pamięć po x (czyli this):
        delete[] name_;
        //i wreszcie przenosimy stan, ten kod jest
        //jest identyczny więc można by go wydzielić do innej metody...
        name_ = nullptr;
        swap(name_, xxx.name_);
    }
}