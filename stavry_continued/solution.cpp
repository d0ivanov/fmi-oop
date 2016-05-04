#include<iostream>

#include "egg_basket.hpp"
#include "egg.hpp"

using namespace std;

void generate()
{
    EggBasket stavri("Stavri");
    EggBasket balkan("Balkan");

    for(int i = 0; i < 10; i++)
    {
        stavri.add(Egg("Stavri_Egg", i));
        balkan.add(Egg("Balkan_Egg", i));
    }

    stavri.report();
    stavri.serialize();

    balkan.report();
    balkan.serialize();
}

void section()
{
    EggBasket stavri("Stavri", "Stavri_loaded");
    EggBasket balkan("Balkan", "Balkan_loaded");

    EggBasket section = stavri % balkan;
    section.setName("Section_Stavri_Balkan");

    section.report();
}

void divide()
{
    EggBasket stavri("Stavri", "Stavri_divided");
    stavri /= 3;

    stavri.report();
}

void multiply()
{
    EggBasket stavri("Stavri", "Stavri_multiplied");
    stavri *= 3;
    stavri.report();
}

void compare()
{
    EggBasket stavri("Stavri", "Stavri_loaded");
    EggBasket balkan("Balkan", "Balkan_loaded");

    cout << "stavri == balkan: " << (stavri == balkan) << endl;
    cout << "stavri != balkan: " << (stavri != balkan) << endl;
    cout << "stavri > balkan: " << (stavri > balkan) << endl;
    cout << "stavri < balkan: " << (stavri < balkan) << endl;
    cout << "stavri >= balkan: " << (stavri >= balkan) << endl;
    cout << "stavri <= balkan: " << (stavri <= balkan) << endl;
}

int main()
{
    generate();

    EggBasket stavri("Stavri", "Stavri");
    EggBasket balkan("Balkan", "Balkan");

    cout << "Basket: " << stavri.getName() << endl;
    for(size_t i = 0; i < stavri.getSize(); i++)
    {
        cout << stavri[i] << endl;
    }
    cout << "End!" << endl << endl;

    cout << "Basket: " << balkan.getName() << endl;
    for(size_t i = 0; i < balkan.getSize(); i++)
    {
        cout << balkan[i] << endl;
    }
    cout << "End!" << endl << endl;

    section();
    divide();
    multiply();
    compare();


    return 0;
}
