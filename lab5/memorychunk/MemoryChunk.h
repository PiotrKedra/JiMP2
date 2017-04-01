//
// Created by piotr on 29.03.2017.
//

#ifndef JIMP_EXERCISES_XXX_H
#define JIMP_EXERCISES_XXX_H

#include <string>
#include <cstdint>
#include <algorithm>

using ::std::swap;

namespace memorychunk {
    class MemoryChunk {
    public:
        MemoryChunk();

        MemoryChunk(const std::string name);

        MemoryChunk(size_t sz);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;

        //Rule of five://
        //1. konstruktor kopiujący (powieli jego stan)
        MemoryChunk(const MemoryChunk &xxx);

        //2. konstruktor przenoszący
        MemoryChunk(MemoryChunk &&xxx);

        //3. operator przypisania kopiujący operatory dodatkowo kasuja stan poprzedniego
        MemoryChunk &operator=(const MemoryChunk &xxx);

        //4. operator przypisania przenoszący  X x4{move(x3)}; move zamienia L i R wartosc na R
        MemoryChunk &operator=(MemoryChunk &&xxx);

        //5. Destruktor
        ~MemoryChunk();

    private:
        char* name_;
        size_t size;
    };
}
#endif //JIMP_EXERCISES_XXX_H
