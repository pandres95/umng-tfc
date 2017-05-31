#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

#include "file.h"
#include "store.h"
#include "product.h"
#include "sale.h"
#include "manager.h"

using namespace std;

void Manager::load_store_file() {
    if(File::exists("store.dat")) {
        ifstream file;
        file.open("store.dat", ifstream::in);

        file >> store;

        file.close();
    } else {
        save_store_file();
    }
}

void Manager::save_store_file() {
    ofstream file;
    file.open("store.dat", ofstream::out);

    file << store;

    file.close();
}

bool Manager::menu_store_print() {
    cout << tab << tab << "TFC > Fabrica y venta de ropa" << endl << endl
        << tab << "1. Manejar productos." << endl
        << tab << "2. Manejar ventas" << endl
        << tab << "3. Regresar" << endl;

    int option = menu_read(1, 3);
    cout << endl << endl;

    switch(option) {
        case 1: {
            bool res;
            do {
                res = menu_products_print();
            } while(res);
        } break;
        case 2: {
            bool res;
            do {
                res = menu_sales_print();
            } while(res);
        } break;
    }

    return option != 3;
}

bool products_list(vector<Product>&);
Product products_add();

bool Manager::menu_products_print() {
    cout << tab << tab << "TFC > Fabrica... > Productos" << endl << endl
        << tab << "1. Listar productos." << endl
        << tab << "2. Agregar producto." << endl
        << tab << "3. Regresar" << endl;

    int option = menu_read(1, 3);
    cout << endl << endl;

    switch(option) {
        case 1: products_list(store.products()); break;
        case 2: store.products().push_back(products_add()); break;
    }

    return option != 3;
}

bool products_list(vector<Product>& products) {
    cout << tab << "Total de productos: " << products.size() << endl;

    for(auto& product: products) {
        cout << tab << "Id: " << product.id() << endl
            << tab << "Nombre: " << product.name() << endl
            << tab << "Costo: $" << put_money(product.cost()) << endl
            << endl;
    }

    cout << endl;

    return false;
}

Product products_add() {
    int id;
    string name;
    long double cost;
    Product product;

    cout << tab << "Id: ";
    cin >> id;
    product.id(id);

    getline(cin, name);
    cout << tab << "Nombre: ";
    getline(cin, name);
    product.name(name);

    cout << tab << "Costo: ";
    cin >> cost;
    product.cost(cost);

    cout << endl;

    return product;
}

bool sales_list(vector<Sale>&);
Sale sales_add();

bool Manager::menu_sales_print() {
    cout << tab << tab << "TFC > Fabrica... > Ventas" << endl << endl
        << tab << "1. Listar ventas." << endl
        << tab << "2. Agregar ventas." << endl
        << tab << "3. Regresar" << endl;

    int option = menu_read(1, 3);
    cout << endl << endl;

    switch(option) {
        case 1: sales_list(store.sales()); break;
        case 2: store.sales().push_back(sales_add()); break;
    }

    return option != 3;
}

bool sales_list(vector<Sale>& sales) {
    cout << tab << "Numero de ventas: " << sales.size() << endl
        << endl;

    for(auto& sale : sales) {
        time_t sale_time = sale.sale_time();
        tm current = *localtime(&sale_time);
        cout << tab << put_time(&current, "%c")
            << " - $" << setw(10) << put_money(sale.cost()) << endl;
    }

    cout << endl;

    return false;
}

Sale sales_add() {
    long double cost;

    cout << tab << "Costo: ";
    cin >> cost;

    cout << endl;

    return Sale(cost);
}
