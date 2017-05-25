#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "species.h"
#include "animal.h"
#include "zoo.h"
#include "file.h"
#include "manager.h"

using namespace std;

void Manager::load_zoos_file() {
    zoos.clear();

    if(File::exists("zoo.dat")) {
        ifstream file;
        file.open("zoo.dat", ifstream::in);

        string c;
        int zoos_size;
        file >> zoos_size;

        for(int i = 0; i < zoos_size; i++) {
            Zoo zoo;
            getline(file, c);
            file >> zoo;
            zoos.push_back(zoo);
        }

        file.close();
    } else {
        save_zoos_file();
    }
}

void Manager::save_zoos_file() {
    ofstream file;
    file.open("zoo.dat", ofstream::out);

    file << zoos.size() << endl;

    for(auto &zoo : zoos) {
        file << zoo;
    }

    file.close();
}

long zoo_pick(vector<Zoo>&, const char*);
bool zoos_list(vector<Zoo>&);
bool zoos_add(vector<Zoo>&);
bool zoos_delete(vector<Zoo>&);

bool Manager::menu_zoos_print() {
    cout << tab << tab << "TFC > Zoologicos" << endl << endl
        << tab << "1. Listar zoologicos." << endl
        << tab << "2. Agregar zoologico" << endl
        << tab << "3. Manejar zoologico" << endl
        << tab << "4. Eliminar zoologico" << endl
        << tab << "5. Regresar" << endl;

    int option = menu_read(1, 5);
    cout << endl << endl;

    switch(option) {
        case 1: zoos_list(zoos); break;
        case 2: zoos_add(zoos); break;
        case 3: {
            int i = zoo_pick(zoos, "manejar") - 1;
            bool res;
            do {
                res = menu_zoo_print(zoos.at(i));
            } while(res);
        } break;
        case 4: zoos_delete(zoos); break;
    }

    return option != 5;
}

long zoo_pick(vector<Zoo> &zoos, const char* extra_message) {
    string s_i;
    int i;

    do {
        cout << tab << "Ingrese el número del zoologico a " << extra_message
            << "(1 - " << zoos.size() << "): ";

        try {
            getline(cin, s_i);
            i = stoi(s_i);
            if(i < 1 || i > zoos.size()) {
                throw std::out_of_range("");
            }
        } catch(const std::invalid_argument& ia) {
            cout << tab << "Opción incorrecta." << endl;
            i = 0;
        }  catch(const std::out_of_range& ia) {
            cout << tab << "Opción incorrecta." << endl;
            i = 0;
        }
    } while(i < 1 || i > zoos.size());

    return i;
}

bool zoos_list(vector<Zoo> &zoos) {
    cout << tab << "Total de zoologicos: " << zoos.size() << endl << endl;

    for(auto &zoo : zoos) {
        cout << tab << "Nombre: " << zoo.name() << endl
            << tab << "Ubicacion: " << zoo.city() << ", " << zoo.country()
            << endl
            << tab << "Area: " << zoo.size() << "m2" << endl
            << tab << "Presupuesto anual: $" << put_money(zoo.yearly_budget())
            << endl << endl;
    }

    return false;
}

bool zoos_add(vector<Zoo> &zoos) {
    string name, city, country;
    long size;
    double yearly_budget;

    string s;
    getline(cin, s);

    cout << tab << "Nombre del zoologico: ";
    getline(cin, name);
    cout << tab << "Ciudad: ";
    getline(cin, city);
    cout << tab << "País: ";
    getline(cin, country);
    cout << tab << "Tamaño (m2): ";
    cin >> size;
    cout << tab << "Presupuesto anual ($): ";
    cin >> yearly_budget;

    zoos.push_back(Zoo(name, city, country, size, yearly_budget));

    cout << endl;

    return false;
}

bool zoos_delete(vector<Zoo> &zoos) {
    zoos.erase(zoos.begin() + (zoo_pick(zoos, "eliminar") - 1));
    return false;
}
