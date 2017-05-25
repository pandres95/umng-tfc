#ifndef SPECIES_H_INCLUDED
#define SPECIES_H_INCLUDED

#include <string>

class Species {
    private:
        std::string _common_name;
        std::string _scientific_name;
        std::string _family;
        bool _in_extinction_danger;
    public:
        Species();
        Species(std::string, std::string, std::string, bool);

        void common_name(std::string);
        std::string common_name();
        void scientific_name(std::string);
        std::string scientific_name();
        void family(std::string);
        std::string family();
        void in_extinction_danger(bool);
        bool in_extinction_danger();

        friend std::ostream& operator<<(std::ostream&, Species&);
        friend std::istream& operator>>(std::istream&, Species&);

        void print(std::ostream&);
};

#endif // SPECIES_H_INCLUDED
