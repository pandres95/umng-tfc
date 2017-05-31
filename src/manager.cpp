#include <iostream>
#include "manager.h"

using namespace std;

void Manager::load_files() {
    load_zoos_file();
}

void Manager::save_files() {
    save_zoos_file();
}

bool Manager::menu_print() {
    cout << tab << tab << "Trabajo final del curso" << endl << endl
        << tab << "Opción 1. Portada." << endl
        << tab << "Opción 2. Zoológico" << endl
        << tab << "Opción 3. Fabrica y venta de ropa" << endl
        << tab << "Opción 4. Salir" << endl;

    int option = menu_read(1, 4);
    cout << endl << endl;

    switch(option) {
        case 1: menu_cover_print(); break;
        case 2: {
            bool res;
            do {
                res = menu_zoos_print();
            } while(res);
        } break;
        case 3: {
            bool res;
            do {
                res = menu_store_print();
            } while(res);
        } break;
    }

    return option != 4;
}

int Manager::menu_read(int min, int max) {
    string s_i;
    int i = 0;

    do {
        cout << tab << "Escoja una opcion: ";

        try {
            getline(cin, s_i);
            i = stoi(s_i);
            if(i < min || i > max) {
                throw std::out_of_range("");
            }
        } catch(const std::invalid_argument& ia) {
            cout << tab << "Opcion incorrecta." << endl;
            i = min-1;
        }  catch(const std::out_of_range& ia) {
            cout << tab << "Opcion incorrecta." << endl;
            i = min-1;
        }
    } while(i < min || i > max);

    return i;
}

bool Manager::menu_cover_print() {
    return false;
}

bool Manager::menu_store_print() {
    return false;
}
