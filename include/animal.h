#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include "species.h"

class Animal {
    private:
        int _id;
        std::string _sex;
        std::string _date_of_birth;
        std::string _origin_country;
        std::string _continent;
        Species _species;
    public:
        Animal();
        Animal(
            int, std::string, std::string, std::string, std::string, Species
        );

        void id(int);
        int id();
        void sex(std::string);
        std::string sex();
        void date_of_birth(std::string);
        std::string date_of_birth();
        void origin_country(std::string);
        std::string origin_country();
        void continent(std::string);
        std::string continent();
        void species(Species);
        Species species();

        friend std::ostream& operator<<(std::ostream&, Animal&);
        friend std::istream& operator>>(std::istream&, Animal&);

        void print(std::ostream&);
};

#endif // ANIMAL_H_INCLUDED
