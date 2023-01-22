#pragma once
#include <iostream>

class Bazowa {
public:
    virtual void fun() { std::cout << "Hi \n"; }
};

class Pochodna : public Bazowa {
public:
    void fun() { std::cout << "Goodbay \n"; }
};
