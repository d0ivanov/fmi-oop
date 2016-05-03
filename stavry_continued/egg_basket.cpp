#include<cstring>
#include<fstream>
#include<stdexcept>

#include "egg_basket.hpp"
#include "egg.hpp"

EggBasket::Node::Node()
    : next(NULL)
{}

EggBasket::Node::Node(const Egg& egg)
    : data(egg),
      next(NULL)
{}

EggBasket::EggBasket(const char* basketName)
    : size(0),
      head(new Node()),
      tail(head)
{
    allocateAndCopy(basketName);
}

EggBasket::EggBasket(const EggBasket& other)
    : head(new Node()),
      tail(head)
{
    allocateAndCopy(other.name);

    Node* current = other.head->next;
    while(current != NULL)
    {
        add(current->data);
        current = current->next;
    }
}

EggBasket::EggBasket(const char* basketFileName, const char* basketName)
    : head(new Node()),
      tail(head)
{
    allocateAndCopy(basketName);

    if(basketFileName == NULL)
        throw std::invalid_argument("File name cannot be NULL!");

    std::ifstream basketFile(basketFileName, std::ios::in | std::ios::binary);

    if(!basketFile.is_open())
        throw std::runtime_error("Error while opening file!");

    while(true)
    {
        size_t eggSize;
        size_t idLen;
        basketFile.read((char*)&eggSize, sizeof(size_t));
        basketFile.read((char*)&idLen, sizeof(size_t));
        char* eggId = new char[idLen];
        basketFile.read(eggId, idLen);

        if(basketFile.eof())
        {
            break; //If that was the EOF just stop now
        }
        else if(basketFile.fail())
        {
            basketFile.close();
            delete head;
            delete [] name;
            throw std::runtime_error("Error while reading from file!");
        }

        Egg egg(eggId, eggSize);
        add(egg);
    }

    basketFile.close();
}

EggBasket::~EggBasket()
{
    delete [] name;
    freeList();
}

EggBasket& EggBasket::operator=(const EggBasket& other)
{
    if(this != &other)
    {
        freeList();
        delete [] name;
        allocateAndCopy(other.name);

        Node* current = other.head->next;
        while(current != NULL)
        {
            add(current->data);

            current = current->next;
        }
    }

    return *this;
}

Egg& EggBasket::operator[](size_t index)
{
    return get(index);
}

const Egg& EggBasket::operator[](size_t index) const
{
    return get(index);
}

Egg& EggBasket::operator[](const char* id)
{
    return get(id);
}

const Egg& EggBasket::operator[](const char* id) const
{
    return get(id);
}

EggBasket& EggBasket::operator+=(const EggBasket& other)
{
    for(size_t i = 0; i < other.size; i++)
        add(other[i]);

    return *this;
}

EggBasket& EggBasket::operator/=(int divisor)
{
    Node* current = head->next;

    while(current != NULL)
    {
        current->data /= divisor;

        current = current->next;
    }

    return *this;
}

EggBasket& EggBasket::operator*=(int multiplier)
{
    Node* current = head->next;

    while(current != NULL)
    {
        current->data *= multiplier;

        current = current->next;
    }

    return *this;
}

EggBasket& EggBasket::operator%=(const EggBasket& other)
{
    Node* current = head->next;
    while(current != NULL)
    {
        if(!other.contains(current->data))
            remove(current->data.getId());

        current = current->next;
    }

    return *this;
}

void EggBasket::add(const Egg& egg)
{
    if(egg.getId() == NULL)
        throw std::invalid_argument("Cannot add element without an ID!");

    tail->next = new Node(egg);
    tail = tail->next;
    size++;
}

void EggBasket::remove(const char* id)
{
    if(id == NULL)
        return;

    Node* curr = head->next;
    Node* prev = head;
    while(curr != NULL)
    {
        if(strcmp(curr->data.getId(), id) == 0)
        {
            prev->next = curr->next;
            delete curr;
            size--;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

bool EggBasket::contains(const Egg& egg) const
{
    Node* current = head->next;
    while(current != NULL)
    {
        if(current->data == egg)
            return true;

        current = current->next;
    }

    return false;
}

void EggBasket::serialize() const
{
    std::ofstream basket(name, std::ios::out | std::ios::binary | std::ios::trunc);

    if(!basket.is_open())
        throw std::runtime_error("Unable to open file and persist data!");

    Node* curr = head->next;
    while(curr != NULL)
    {
        size_t eggSize = curr->data.getSize();
        size_t idLen = curr->data.getIdLen();
        basket.write((const char*)&eggSize, sizeof(size_t));
        basket.write((const char*)&idLen, sizeof(size_t));
        basket.write(curr->data.getId(), curr->data.getSize());

        if(basket.fail())
        {
            basket.close();
            throw std::runtime_error("Failed to write data!");
        }

        curr = curr->next;
    }

    basket.close();
}

void EggBasket::report() const
{
    char* fileName = new char[11 + strlen(name)];
    strcpy(fileName, "report_");
    strcat(fileName, name);
    strcat(fileName, ".txt");

    std::ofstream reportFile(fileName, std::ios::out | std::ios::trunc);
    if(!reportFile.is_open())
        throw std::runtime_error("Unable to open report file");

    Node* current = head->next;
    while(current != NULL)
    {
        reportFile << current->data.getId() << " " << current->data.getSize()
                   << std::endl;

        current = current->next;
    }

    delete [] fileName;
    reportFile.close();
}

char* EggBasket::toString() const
{
    size_t length = 0;

    Node* current = head->next;
    while(current != NULL)
    {
        length += current->data.getSize();
        current = current->next;
    }
    char* result = new char[length + 1];

    current = head->next;
    while(current != NULL)
    {
        strcat(result, current->data.getId());
        current = current->next;
    }

    result[length] = '\0';
    return result;
}

const char* EggBasket::getName() const
{
    return name;
}

size_t EggBasket::getSize() const
{
    return size;
}

void EggBasket::setName(const char* name)
{
    if(name == NULL)
        throw std::invalid_argument("Argument cannot be NULL!");

    delete [] this->name;
    allocateAndCopy(name);
}

void EggBasket::allocateAndCopy(const char* str)
{
    if(str == NULL)
        throw std::invalid_argument("Argument cannot be NULL!");

    name = new char[strlen(str) + 1];
    strcpy(name, str);
}

void EggBasket::freeList()
{
    Node* current = head;
    while(current != NULL)
    {
        Node* temp = current;
        current = current->next;

        delete temp;
    }
}

Egg& EggBasket::get(size_t index) const
{
    if(index >= size)
        throw std::out_of_range("Index out of range!");

    Node* current = head->next;
    for(size_t i = 0; current != NULL; i++)
    {
        if(i == index)
            return current->data;
        current = current->next;
    }
}

Egg& EggBasket::get(const char* id) const
{
    if(id == NULL)
        throw std::invalid_argument("id cannot be NULL!");

    Node* current = head->next;
    while(current != NULL)
    {
        if(strcmp(current->data.getId(), id) == 0)
            return current->data;

        current = current->next;
    }

    throw std::runtime_error("No such element found!");
}

EggBasket operator+(const EggBasket& left, const EggBasket& right)
{
    EggBasket basket = left;
    basket += right;
    return basket;
}

EggBasket operator*(const EggBasket& left, int right)
{
    EggBasket basket = left;
    basket *= right;
    return basket;
}

EggBasket operator/(const EggBasket& left, int right)
{
    EggBasket basket = left;
    basket /= right;
    return basket;
}

char* operator+=(char* left, const EggBasket& right)
{
    left = left + right;
    return left;
}

char* operator+(const char* left, const EggBasket& right)
{

    if(left == NULL)
        throw std::invalid_argument("NULL arguments not permitted!");

    size_t len = strlen(right.toString()) + strlen(left);
    char* result = new char[len + 1];

    strcat(result, left);
    strcat(result, right.toString());

    result[len] = '\0';
    return result;
}

EggBasket operator%(const EggBasket& left, const EggBasket& right)
{
    EggBasket basket = left;

    for(size_t i = 0; i < left.getSize(); i++)
    {
        if(!right.contains(left[i]))
            basket.remove(left[i].getId());
    }

    return basket;
}
