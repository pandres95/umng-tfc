#include <iostream>
#include <vector>
#include <string>

#include "product.h"
#include "sale.h"
#include "store.h"

using namespace std;

Store::Store() {}

vector<Product>& Store::products() {
    return _products;
}

vector<Sale>& Store::sales() {
    return _sales;
}

std::ostream& operator<<(std::ostream& os, Store& store) {
    os << store.products().size() << endl;

    for(auto& product : store.products()) {
        os << product;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Store& store) {
    int n;
    string c;

    is >> n;
    getline(is, c);

    for(int i = 0; i < n; i++){
        Product product;
        is >> product;
        store.products().push_back(product);
    }

    /*is >> n;
    getline(is, c);

    for(int i = 0; i < n; i++){
        Sale sale;
        is >> sale;
        store.sales().push_back(sale);
    }*/

    return is;
}
