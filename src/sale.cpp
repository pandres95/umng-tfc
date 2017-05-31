#include "sale.h"
#include <iostream>
#include <ctime>

using namespace std;

Sale::Sale() {
    _sale_time = time(nullptr);
}

Sale::Sale(long double cost) {
    _sale_time = time(nullptr);
    _cost = cost;
}

Sale::Sale(long double cost, time_t sale_time) {
    _cost = cost;
    _sale_time = sale_time;
}


long double Sale::cost() {
    return _cost;
}


time_t& Sale::sale_time() {
    return _sale_time;
}


ostream& operator <<(ostream& os, Sale& sale) {
    os << sale.cost() << endl
        << sale.sale_time() << endl;

    return os;
}

istream& operator >>(istream& is, Sale& sale) {
    long double cost;
    is >> cost;

    time_t sale_time;
    is >> sale_time;

    sale = Sale(cost, sale_time);

    return is;
}
