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
        Node* head;
        Node* tail;

    public:
        EggBasket(const char*);
        EggBasket(const char*, const char*);
        EggBasket(const EggBasket&);
        ~EggBasket();

        EggBasket& operator=(const EggBasket&);
        void add(Egg&);
        void remove(const char*);
        void serialize() const;
        void report() const;

        const char* getName() const;
        void setName(const char* name);

    private:
        void allocateAndCopy(const char*);
        void freeList();
};

#endif
