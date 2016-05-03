#ifndef __EGG_BASKET_HPP__
#define __EGG_BASKET_HPP__

#include<fstream>

#include "egg.hpp"

class EggBasket
{
    private:
        struct Node
        {
            Egg data;
            Node* next;

            Node();
            Node(const Egg&);
        };

        char* name;
        size_t size;
        Node* head;
        Node* tail;

    public:
        EggBasket(const char*);
        EggBasket(const char*, const char*);
        EggBasket(const EggBasket&);
        ~EggBasket();

        EggBasket& operator=(const EggBasket&);

        Egg& operator[](size_t);
        const Egg& operator[](size_t) const;

        Egg& operator[](const char*);
        const Egg& operator[](const char*) const;

        EggBasket& operator+=(const EggBasket&);
        EggBasket& operator/=(int);
        EggBasket& operator*=(int);
        EggBasket& operator%=(const EggBasket&);

        void add(const Egg&);
        void remove(const char*);
        bool contains(const Egg&) const;
        void serialize() const;
        void report() const;

        char* toString() const;

        const char* getName() const;
        size_t getSize() const;
        void setName(const char* name);

    private:
        void allocateAndCopy(const char*);
        void freeList();
        Egg& get(size_t) const;
        Egg& get(const char*) const;
};

EggBasket operator+(const EggBasket&, const EggBasket&);
EggBasket operator*(const EggBasket&, int);
EggBasket operator/(const EggBasket&, int);
EggBasket operator%(const EggBasket&, const EggBasket&);

char* operator+(const char*, const EggBasket&);
char* operator+=(const char*, const EggBasket&);

#endif
