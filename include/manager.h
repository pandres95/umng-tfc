#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "tab.h"
#include "zoo.h"
#include <vector>

class Manager {
    public:
        void load_files();
        void save_files();

        bool menu_print();
    private:
        int menu_read(int, int);

        // Cover module
        bool menu_cover_print();

        // Zoo module
        std::vector<Zoo> zoos;
        bool menu_zoos_print();
        bool menu_zoo_print(Zoo&);

        void load_zoos_file();
        void save_zoos_file();

        // Store module
        bool menu_store_print();
};

#endif // MANAGER_H_INCLUDED
