#include <iostream>
#include "tab.h"
#include "species.h"

using namespace std;


Species::Species() {}

Species::Species(
    string common_name, string scientific_name, string family,
    bool in_extinction_danger
){
    _common_name = common_name;
    _scientific_name = scientific_name;
    _family = family;
    _in_extinction_danger = in_extinction_danger;
}

void Species::common_name(string value) {
    _common_name = value;
}

string Species::common_name() {
    return _common_name;
}

void Species::scientific_name(string value) {
    _scientific_name = value;
}

string Species::scientific_name() {
    return _scientific_name;
}

void Species::family(string value) {
    _family = value;
}

string Species::family() {
    return _family;
}

void Species::in_extinction_danger(bool value) {
    _in_extinction_danger = value;
}

bool Species::in_extinction_danger() {
    return _in_extinction_danger;
}

void Species::print(ostream& cout) {
    cout
        << tab << "  " << "Nombre común: " << _common_name << endl
        << tab << "  " << "Nombre cientifico: " << _scientific_name << endl
        << tab << "  " << "Familia: " << _family << endl
        << tab << "  " << "En riesgo de extinción: " << (
            _in_extinction_danger ? "Si" : "No"
        ) << endl;
}

ostream& operator <<(ostream& os, Species& species) {

    os << species._common_name.c_str() << endl
        << species._scientific_name.c_str() << endl
        << species._family.c_str() << endl;
    os << species._in_extinction_danger << endl;

    return os;
}

istream& operator >>(istream& is, Species& species) {
    string common_name, scientific_name, family;
    bool in_extinction_danger;

    getline(is, common_name);
    getline(is, scientific_name);
    getline(is, family);
    is >> in_extinction_danger;

    species.common_name(common_name);
    species.scientific_name(scientific_name);
    species.family(family);
    species.in_extinction_danger(in_extinction_danger);

    return is;
}
