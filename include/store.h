#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#import "product.h"
#import "sale.h"
#import <vector>

class Store {
private:
    std::vector<Product> _products;
    std::vector<Sale> _sales;
public:
    Store();
    std::vector<Product>& products();
    std::vector<Sale>& sales();

    friend std::ostream& operator<<(std::ostream&, Store&);
    friend std::istream& operator>>(std::istream&, Store&);
};

#endif // STORE_H_INCLUDED
