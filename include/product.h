#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <string>

class Product {
private:
    int _id;
    std::string _name;
    long double _cost;
public:
    Product();
    Product(int, std::string, long double);

    int id();
    void id(int);
    std::string name();
    void name(std::string);
    long double cost();
    void cost(long double);

    friend std::ostream& operator<<(std::ostream&, Product&);
    friend std::istream& operator>>(std::istream&, Product&);
};

#endif // PRODUCT_H_INCLUDED
