#include<cstring>
#include<stdexcept>

#include "egg.hpp"

Egg::Egg()
    : size(0),
      id(NULL)
{}

Egg::Egg(const char* id, size_t size)
    : size(size)
{
    if(id == NULL)
    {
        throw std::invalid_argument("Argument id cannot be NULL!");
    }

    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);
}

Egg::Egg(const Egg& other)
{
    if(other.id == NULL)
        throw std::invalid_argument("Invalid source object state!");

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
    else
    {
        delete [] id;
        id = NULL;
    }

    return *this;
}

Egg& Egg::operator*=(int multiplier)
{
    size *= multiplier;

    return *this;
}

Egg& Egg::operator/=(int divisor)
{
    if(divisor == 0)
        throw std::invalid_argument("Division by zero!");

    size /= divisor;

    return *this;
}

Egg& Egg::operator++()
{
    size++;
    return *this;
}

Egg Egg::operator++(int)
{
    Egg other = *this;
    size++;
    return other;
}

bool Egg::operator==(const Egg& other)
{
    return strcmp(id, other.id) == 0;
}

bool Egg::operator!=(const Egg& other)
{
    return !(*this == other);
}

bool Egg::operator<(const Egg& other)
{
    return strcmp(id, other.id) < 0;
}

bool Egg::operator>(const Egg& other)
{
    return strcmp(id, other.id) > 0;
}

bool Egg::operator>=(const Egg& other)
{
    return *this == other || *this > other;
}

bool Egg::operator<=(const Egg& other)
{
    return *this == other || *this < other;
}

std::ostream& operator<<(std::ostream& stream, const Egg& egg)
{
    stream << "Size: " << " " << egg.getSize()
           << " " << "id: " << egg.getId() << std::endl;

    return stream;
}
