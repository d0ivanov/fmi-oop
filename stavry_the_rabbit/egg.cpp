#include<cstring>
#include<stdexcept>

#include "egg.hpp"

Egg::Egg()
    : size(0),
      id(NULL)
{}

Egg::Egg(const char* id)
{
    if(id == NULL)
    {
        throw std::invalid_argument("Argument id cannot be NULL!");
    }

    size_t idLen = strlen(id);
    this->id = new char[idLen + 1];

    strcpy(this->id, id);
    size = (idLen + 1) * sizeof(char);
}

Egg::Egg(const Egg& other)
{
    if(other.id == NULL)
    {
        throw std::invalid_argument("Invalid source object state!");
    }

    id = new char[strlen(other.id) + 1];

    strcpy(id, other.id);
    size = other.size;
}

Egg::~Egg()
{
    delete [] id;
}

const char* Egg::getId() const
{
    return id;
}

size_t Egg::getSize() const
{
    return size;
}

Egg& Egg::operator=(const Egg& other)
{
    if(this == &other)
    {
        return *this;
    }

    size = other.size;
    if(other.id != NULL)
    {
        strcpy(id, other.id);
    }

    return *this;
}
