#ifndef __EGG_HPP__
#define __EGG_HPP__

#include<stddef.h>
#include<ostream>

class Egg
{
    private:
        size_t size;
        size_t idLen;
        char* id;

    public:
        Egg();
        Egg(const char*, size_t);
        Egg(const Egg&);
        ~Egg();

        Egg& operator=(const Egg&);
        Egg& operator*=(int);
        Egg& operator/=(int);
        bool operator==(const Egg&);
        bool operator!=(const Egg&);
        bool operator<(const Egg&);
        bool operator>(const Egg&);
        bool operator>=(const Egg&);
        bool operator<=(const Egg&);
        std::ostream& operator<<(std::ostream&);

        const char* getId() const;
        size_t getIdLen() const;
        size_t getSize() const;
};

#endif
