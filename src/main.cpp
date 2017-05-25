#include "manager.h"

int main() {
    Manager manager;

    manager.load_files();

    bool menu_result;

    do {
        menu_result = manager.menu_print();
    } while(menu_result);

    manager.save_files();
}
