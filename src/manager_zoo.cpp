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

bool zoo_info(Zoo&);
bool zoo_edit(Zoo&);
long zoo_animal_pick(Zoo&, const char*);
bool zoo_animal_list(Zoo&);
bool zoo_animal_add(Zoo&);
bool zoo_animal_edit(Animal&);
bool zoo_animal_delete(Zoo&, int);

bool Manager::menu_zoo_print(Zoo& zoo) {

    cout << tab << tab << "TFC > Zoologicos > " << zoo.name() << endl << endl
        << tab << "1. Ver informacion" << endl
        << tab << "2. Editar informacion" << endl
        << tab << "3. Listar animales" << endl
        << tab << "4. Agregar animal" << endl
        << tab << "5. Informacion del animal" << endl
        << tab << "6. Editar animal" << endl
        << tab << "7. Eliminar animal" << endl
        << tab << "8. Regresar" << endl;

    int option = menu_read(1, 8);
    cout << endl << endl;

    switch(option) {
        case 1: zoo_info(zoo); break;
        case 2: zoo_edit(zoo); break;
        case 3: zoo_animal_list(zoo); break;
        case 4: zoo_animal_add(zoo); break;
        case 5: {
            if(zoo.animals().size() > 0) {
                long i = zoo_animal_pick(zoo, "editar");
                if(i != -1) {
                    zoo.get_animal(i - 1).print(cout);
                }
            } else {
                cout << tab << "Error: Este zoologico no tiene animales"
                    << endl << endl;
            }
        } break;
        case 6: {
            if(zoo.animals().size() > 0) {
                long i = zoo_animal_pick(zoo, "editar");
                if(i != -1) {
                    zoo_animal_edit(zoo.get_animal(i - 1));
                }
            } else {
                cout << tab << "Error: Este zoologico no tiene animales"
                    << endl << endl;
            }
        } break;
        case 7: {
            if(zoo.animals().size() > 0) {
                long i = zoo_animal_pick(zoo, "eliminar");
                if(i != -1) {
                    zoo.erase_animal(i);
                }
            } else {
                cout << tab << "Error: Este zoologico no tiene animales"
                    << endl;
            }
        } break;
    }

    return option != 8;
}

bool zoo_info(Zoo& zoo) {

    cout << tab << "Nombre: " << zoo.name() << endl
        << tab << "Ubicacion: " << zoo.city() << ", " << zoo.country()
        << endl
        << tab << "Area: " << zoo.size() << "m2" << endl
        << tab << "Presupuesto anual: $" << put_money(zoo.yearly_budget())
        << endl << endl;

    return false;
}

bool zoo_edit(Zoo& zoo) {
    string name, city, country, s_size, s_yearly_budget;
    long size;
    double yearly_budget;

    getline(cin, name);

    cout << tab << "Nombre del zoologico [" << zoo.name() << "]: ";
    getline(cin, name);
    if(!name.empty()) {
        zoo.name(name);
    }

    cout << tab << "Ciudad [" << zoo.city() << "]: ";
    getline(cin, city);
    if(!city.empty()) {
        zoo.city(city);
    }

    cout << tab << "Pais [" << zoo.country() << "]: ";
    getline(cin, country);
    if(!country.empty()) {
        zoo.country(country);
    }

    bool not_read = true;

    do {
        cout << tab << "Tamaño (m2) [" << zoo.size() << "]: ";
        getline(cin, s_size);

        if(!s_size.empty()) {
            try {
                size = stol(s_size);
                zoo.size(size);
                not_read = false;
            } catch(const std::invalid_argument& ia) {
                cerr << tab << "Error: El valor ingresado [" << s_size
                    << "] es invalido. Por favor ingreselo de nuevo." << endl;
            }  catch(const std::out_of_range& ia) {
                cerr << tab << "Error: El valor ingresado [" << s_size
                    << "] esta fuera de rango. Por favor ingreselo de nuevo."
                    << endl;
            }
        } else {
            not_read = false;
        }
    } while(not_read);

    do {
        cout << tab << "Presupuesto anual ($) ["
            << zoo.yearly_budget() << "]: ";
        getline(cin, s_yearly_budget);

        if(!s_yearly_budget.empty()) {
            try {
                yearly_budget = stod(s_yearly_budget);
                zoo.yearly_budget(yearly_budget);
                not_read = false;
            } catch(int e) {
                cout << tab << "Error: El valor ingresado [" << s_yearly_budget
                    << "] es invalido. Por favor ingreselo de nuevo." << endl;
            }
        } else {
            not_read = false;
        }
    } while(not_read);

    cout << endl;

    return false;
}

/*
 *
 * Manejo de animales del Zoologico
 *
 */

long zoo_animal_pick(Zoo& zoo, const char* extra_message) {
    string s_i;
    int i;

    do {
        cout << tab << "Ingrese el numero del animal a " << extra_message
            << "(1 - " << zoo.animals().size() << "/C para cancelar): ";

        try {
            getline(cin, s_i);
            if(s_i == "c" || s_i == "C") {
                return -1;
            }
            i = stoi(s_i);
            if(i < 1 || i > zoo.animals().size()) {
                throw std::out_of_range("");
            }
        } catch(const std::invalid_argument& ia) {
            cout << tab << "Opcion incorrecta." << endl;
            i = 0;
        }  catch(const std::out_of_range& ia) {
            cout << tab << "Opcion incorrecta." << endl;
            i = 0;
        }

    } while(i < 1 || i > zoo.animals().size());

    cout << endl;

    return i;
}

bool zoo_animal_list(Zoo& zoo) {
    cout << tab << "Numero de animales: " << zoo.animals().size()
        << endl << endl;

    for(auto &animal : zoo.animals()) {
        animal.print(cout);
    }

    cout << endl;

    return false;
}

bool zoo_animal_add(Zoo& zoo) {
    // Informacion de la especie
    string s_temp, common_name, scientific_name, family;
    bool in_extinction_danger;
    // Informacion del animal
    int id;
    string sex, date_of_birth, origin_country, continent;


    bool not_read;

    not_read = true;
    do {
        cout << tab << "Id: ";
        getline(cin, s_temp);

        try {
            id = stoi(s_temp);
            not_read = false;
        } catch(const std::invalid_argument &a) {
            cerr << tab << "Valor invalido. Intente de nuevo" << endl;
        } catch(const std::out_of_range &a) {
            cerr << tab << "Fuera de rango. Intente de nuevo" << endl;
        }
    } while(not_read);

    cout << tab << "Nombre comun: ";
    getline(cin, common_name);

    cout << tab << "Nombre cientifico: ";
    getline(cin, scientific_name);

    cout << tab << "Familia: ";
    getline(cin, family);

    not_read = true;
    do {
        cout << tab << "En riesgo de extincion? [s/N]: ";
        getline(cin, s_temp);
        in_extinction_danger = false;

        if(s_temp.empty() || s_temp == "n" || s_temp == "N") {
            not_read = false;
        } else if(s_temp == "S" || s_temp == "s") {
            in_extinction_danger = true;
            not_read = false;
        } else {
            cerr << tab << "Valor invalido. Intente de nuevo" << endl;
        }
    } while(not_read);

    cout << tab << "Sexo: ";
    getline(cin, sex);

    cout << tab << "Fecha de nacimiento: ";
    getline(cin, date_of_birth);

    cout << tab << "Pais de origen: ";
    getline(cin, origin_country);

    cout << tab << "Continente: ";
    getline(cin, continent);

    zoo.add_animal(Animal(
        id, sex, date_of_birth, origin_country, continent, Species(
            common_name, scientific_name, family, in_extinction_danger
        )
    ));

    cout << endl << endl;

    return false;
}

bool zoo_animal_edit(Animal& animal) {
    // Informacion de la especie
    string s_temp, common_name, scientific_name, family;
    bool in_extinction_danger;
    // Informacion del animal
    int id;
    string sex, date_of_birth, origin_country, continent;


    bool not_read;

    not_read = true;
    do {
        cout << tab << "Id [" << animal.id() << "]: ";
        getline(cin, s_temp);

        try {
            if(s_temp.empty()) {
                not_read = false;
            } else {
                id = stoi(s_temp);
                animal.id(id);
                not_read = false;
            }
        } catch(const std::invalid_argument &a) {
            cerr << tab << "Valor invalido. Intente de nuevo" << endl;
        } catch(const std::out_of_range &a) {
            cerr << tab << "Fuera de rango. Intente de nuevo" << endl;
        }
    } while(not_read);

    cout << tab << "Nombre comun [" << animal.species().common_name() << "]: ";
    getline(cin, common_name);
    animal.species().common_name(common_name);

    cout << tab << "Nombre cientifico ["
            << animal.species().scientific_name()
        << "]: ";

    getline(cin, scientific_name);
    if(!scientific_name.empty()) {
        animal.species().scientific_name(scientific_name);
    }

    cout << tab << "Familia [" << animal.species().family() << "]: ";
    getline(cin, family);
    if(!family.empty()) {
        animal.species().family(family);
    }

    not_read = true;
    do {
        cout << tab << "En riesgo de extincion? [s/N]: ";
        getline(cin, s_temp);
        in_extinction_danger = false;

        if(s_temp.empty() || s_temp == "n" || s_temp == "N") {
            not_read = false;
        } else if(s_temp == "S" || s_temp == "s") {
            in_extinction_danger = true;
            not_read = false;
        } else {
            cerr << tab << "Valor invalido. Intente de nuevo" << endl;
        }
    } while(not_read);

    cout << tab << "Sexo [" << animal.sex() << "]: ";
    getline(cin, sex);
    if(!sex.empty()) {
        animal.sex(sex);
    }

    cout << tab << "Fecha de nacimiento [" << animal.date_of_birth() << "]: ";
    getline(cin, date_of_birth);
    if(!date_of_birth.empty()) {
        animal.date_of_birth(date_of_birth);
    }

    cout << tab << "Pais de origen [" << animal.origin_country() << "]: ";
    getline(cin, origin_country);
    if(!origin_country.empty()) {
        animal.origin_country(origin_country);
    }

    cout << tab << "Continente [" << animal.continent() << "]: ";
    getline(cin, continent);
    if(!continent.empty()) {
        animal.continent(continent);
    }

    cout << endl << endl;

    return false;
}
