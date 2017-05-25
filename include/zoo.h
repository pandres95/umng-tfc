#ifndef ZOOLOGICO_H_INCLUDED
#define ZOOLOGICO_H_INCLUDED

#include "animal.h"
#include <vector>

class Zoo {

private:
    std::string _name;
    std::string _city;
    std::string _country;
    long _size;
    double _yearly_budget;
    std::vector<Animal> _animals;
public:
    Zoo();
    Zoo(std::string, std::string, std::string, long, double);

    void name(std::string);
    std::string name();
    void city(std::string);
    std::string city();
    void country(std::string);
    std::string country();
    void size(long);
    long size();
    void yearly_budget(double);
    double yearly_budget();
    std::vector<Animal> animals();
    void add_animal(Animal);
    Animal& get_animal(int);
    void erase_animal(int);

    friend std::ostream& operator<<(std::ostream&, Zoo&);
    friend std::istream& operator>>(std::istream&, Zoo&);

    void print(std::ostream&);
};

#endif // ZOOLOGICO_H_INCLUDED
