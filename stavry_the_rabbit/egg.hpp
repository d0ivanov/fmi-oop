#ifndef __EGG_HPP__
#define __EGG_HPP__

#include<stddef.h>

class Egg
{
    private:
        size_t size;
        char* id;

    public:
        Egg();
        Egg(const char*);
        Egg(const Egg&);
        ~Egg();

        Egg& operator=(const Egg&);
        const char* getId() const;
        size_t getSize() const;
};

#endif
