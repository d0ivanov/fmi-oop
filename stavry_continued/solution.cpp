#include<iostream>

#include "egg_basket.hpp"
#include "egg.hpp"

using namespace std;

void getBasketReport(const EggBasket&);

int main()
{
    Egg e1 = Egg("Egg 1");
    Egg e2 = Egg("Egg 2");
    Egg e3 = Egg("Egg 3");
    Egg e4 = Egg("Egg 4");
    Egg e5 = Egg("Egg 5");
    Egg e6 = Egg("Egg 6");
    Egg e7 = Egg("Egg 7");
    Egg e8 = Egg("Egg 8");
    Egg e9 = Egg("Egg 9");
    Egg e10("Egg 10");
    Egg e11("Egg 11");
    Egg e12("Egg 12");
    Egg e13("Egg 13");
    Egg e14("Egg 14");
    Egg e15("Egg 15");
    Egg e16("Egg 16");
    Egg e17("Egg 17");
    Egg e18("Egg 18");
    Egg e19("Egg 19");
    Egg e20("Egg 20");

    EggBasket basket("stavris_basket");
    basket.add(e1);
    basket.add(e2);
    basket.add(e3);
    basket.add(e4);
    basket.add(e5);
    basket.add(e6);
    basket.add(e7);
    basket.add(e8);
    basket.add(e9);
    basket.add(e10);
    basket.add(e11);
    basket.add(e12);
    basket.add(e13);
    basket.add(e14);
    basket.add(e15);
    basket.add(e16);
    basket.add(e17);
    basket.add(e18);
    basket.add(e19);
    basket.add(e20);

    basket.serialize();
    getBasketReport(basket);

    EggBasket basket2("stavris_basket", "balkans_basket");
    basket2.remove("Egg 1");
    basket2.remove("Egg 3");
    basket2.remove("Egg 5");
    basket2.remove("Egg 7");
    basket2.remove("Egg 9");
    basket2.remove("Egg 11");
    basket2.remove("Egg 13");
    basket2.remove("Egg 15");
    basket2.remove("Egg 17");
    basket2.remove("Egg 19");


    EggBasket basket3 = basket2;
    basket3.setName("fluff");

    basket2.add(e17);
    getBasketReport(basket2);

    basket3.report();

    return 0;
}

void getBasketReport(const EggBasket& basket)
{
    basket.report();
}
