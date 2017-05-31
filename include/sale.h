#ifndef SALE_H_INCLUDED
#define SALE_H_INCLUDED

#include <iostream>
#include <ctime>

class Sale {
private:
    long double _cost;
    time_t _sale_time;
    Sale(long double, time_t);
public:
    Sale();
    Sale(long double);
    long double cost();
    time_t& sale_time();

    friend std::ostream& operator<<(std::ostream&, Sale&);
    friend std::istream& operator>>(std::istream&, Sale&);
};

#endif // SALE_H_INCLUDED
