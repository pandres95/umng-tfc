#include "product.h"
#include <iostream>

using namespace std;

Product::Product() { }

Product::Product(int id, string name, long double cost) {
    _id = id;
    _name = name;
    _cost = cost;
}


int Product::id() {
    return _id;
}

void Product::id(int value) {
    _id = value;
}


string Product::name() {
    return _name;
}

void Product::name(string value) {
    _name = value;
}


long double Product::cost() {
    return _cost;
}

void Product::cost(long double value) {
    _cost = value;
}


ostream& operator <<(ostream& os, Product& product) {
    os << product.id() << endl
        << product.name().c_str() << endl
        << product.cost() << endl;

    return os;
}

istream& operator >>(istream& is, Product& product) {
    int id;
    is >> id;
    product.id(id);

    string tmp, name;
    getline(is, tmp);

    getline(is, name);
    product.name(name);

    long double cost;
    is >> cost;
    product.cost(cost);

    return is;
}
