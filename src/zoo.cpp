#include <iostream>
#include "zoo.h"

using namespace std;

Zoo::Zoo() {
    this->_animals.clear();
}

Zoo::Zoo(
    string name, string city, string country, long size,
    double yearly_budget
) {
    Zoo();
    _name = name;
    _city = city;
    _country = country;
    _size = size;
    _yearly_budget = yearly_budget;
}

string Zoo::name(){
    return _name;
}

void Zoo::name(string value) {
    _name = value;
}

string Zoo::city(){
    return _city;
}

void Zoo::city(string value) {
    _city = value;
}


string Zoo::country(){
    return _country;
}

void Zoo::country(string value) {
    _country = value;
}

long Zoo::size(){
    return _size;
}

void Zoo::size(long value) {
    _size = value;
}

double Zoo::yearly_budget(){
    return _yearly_budget;
}

void Zoo::yearly_budget(double value) {
    _yearly_budget = value;
}

void Zoo::print(ostream& cout) {
    cout
        << _name << endl
        << _city << ", " << _country
        << endl << endl
        << "Size: " << _size << "m2" << endl
        << "Yearly budget: " << _yearly_budget
        << endl << endl
        << " == Animals == " << endl
        << "Size: " << _animals.size() << endl << endl << endl;

    for(auto &animal : _animals) {
        animal.print(cout);
    }
}

vector<Animal> Zoo::animals() {
    return _animals;
}

void Zoo::add_animal(Animal animal) {
    _animals.push_back(animal);
}

Animal& Zoo::get_animal(int i) {
    return _animals.at(i);
}

void Zoo::erase_animal(int i) {
    _animals.erase(_animals.begin() + i);
}

ostream& operator <<(ostream& os, Zoo& zoo) {

    os << zoo._name.c_str() << endl
        << zoo._city.c_str() << endl
        << zoo._country.c_str() << endl;

    os << zoo._size << " " << zoo._yearly_budget << endl;

    os << zoo._animals.size() << endl;

    for(auto &animal: zoo._animals) {
        os << animal;
    }

    return os;
}

istream& operator >>(istream& is, Zoo& zoo) {
    string name, city, country;
    long size, animals_size;
    double yearly_budget;

    string c;

    getline(is, name);
    getline(is, city);
    getline(is, country);

    is >> size >> yearly_budget;

    zoo.name(name);
    zoo.city(city);
    zoo.country(country);
    zoo.size(size);
    zoo.yearly_budget(yearly_budget);

    is >> animals_size;

    for(int i = 0; i < animals_size; i++) {
        Animal animal;
        is >> animal;
        zoo.add_animal(animal);
    }

    return is;
}
