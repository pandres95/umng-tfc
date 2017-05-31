#include <iostream>
#include "tab.h"
#include "animal.h"

using namespace std;


Animal::Animal() {
}

Animal::Animal(
    int id, string sex, string date_of_birth, string origin_country,
    string continent, Species species
){
    _id = id;
    _sex = sex;
    _date_of_birth = date_of_birth;
    _origin_country = origin_country;
    _continent = continent;
    _species = species;
}

void Animal::id(int value) {
    _id = value;
}

int Animal::id() {
    return _id;
}

void Animal::sex(string value) {
    _sex = value;
}

string Animal::sex() {
    return _sex;
}

void Animal::date_of_birth(string value) {
    _date_of_birth = value;
}

string Animal::date_of_birth() {
    return _date_of_birth;
}

void Animal::origin_country(string value) {
    _origin_country = value;
}

string Animal::origin_country() {
    return _origin_country;
}

void Animal::continent(string value) {
    _continent = value;
}

string Animal::continent() {
    return _continent;
}

void Animal::species(Species value) {
    _species = value;
}

Species Animal::species() {
    return _species;
}

void Animal::print(ostream& cout) {
    cout
        << tab << "Id: " << _id << endl
        << tab << "Sexo: " << _sex << endl
        << tab << "Fecha de nacimiento: " << _date_of_birth << endl
        << tab << "Pais de origen: " << _origin_country << " ("
            << _continent
        << ")" << endl
        << tab << " === Datos de Especie === " << endl;

    _species.print(cout);

    cout << endl;
}

ostream& operator <<(ostream& os, Animal& animal) {

    os << animal._id << endl;
    os << animal._sex.c_str() << endl
        << animal._date_of_birth.c_str() << endl
        << animal._origin_country.c_str() << endl
        << animal._continent.c_str() << endl;
    os << animal._species;

    return os;
}

istream& operator >>(istream& is, Animal& animal) {
    string sex, dob, country, continent;
    int id;
    Species species;

    string c;

    is >> id;

    getline(is, c);
    getline(is, sex);
    getline(is, dob);
    getline(is, country);
    getline(is, continent);
    is >> species;

    animal.id(id);
    animal.sex(sex);
    animal.date_of_birth(dob);
    animal.origin_country(country);
    animal.continent(continent);
    animal.species(species);

    return is;
}
