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
    : head(new Node()),
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
    {
        throw std::invalid_argument("File name cannot be NULL!");
    }

    std::ifstream basketFile(basketFileName, std::ios::in | std::ios::binary);

    if(!basketFile.is_open())
    {
        throw std::runtime_error("Error while opening file!");
    }

    while(true)
    {
        size_t eggSize;
        basketFile.read((char*)&eggSize, sizeof(size_t));
        char* eggId = new char[eggSize];
        basketFile.read(eggId, eggSize);

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

        Egg egg(eggId);
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

void EggBasket::add(Egg& egg)
{
    if(egg.getId() == NULL)
    {
        throw std::invalid_argument("Cannot add element without an ID!");
    }

    tail->next = new Node(egg);
    tail = tail->next;
}

void EggBasket::remove(const char* id)
{
    if(id == NULL)
    {
        return;
    }

    Node* curr = head->next;
    Node* prev = head;
    while(curr != NULL)
    {
        if(strcmp(curr->data.getId(), id) == 0)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

void EggBasket::serialize() const
{
    std::ofstream basket(name, std::ios::out | std::ios::binary | std::ios::trunc);

    if(!basket.is_open())
    {
        throw std::runtime_error("Unable to open file and persist data!");
    }

    Node* curr = head->next;
    while(curr != NULL)
    {
        size_t eggSize = curr->data.getSize();
        basket.write((const char*)&eggSize, sizeof(size_t));
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
    {
        throw std::runtime_error("Unable to open report file");
    }

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

const char* EggBasket::getName() const
{
    return name;
}

void EggBasket::setName(const char* name)
{
    if(name == NULL)
    {
        throw std::invalid_argument("Argument cannot be NULL!");
    }

    delete [] this->name;
    allocateAndCopy(name);
}

void EggBasket::allocateAndCopy(const char* str)
{
    if(str == NULL)
    {
        throw std::invalid_argument("Argument cannot be NULL!");
    }

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
