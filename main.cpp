#include "menu.h"

int main() {
    try {
        menu menu;
        menu.run();
    } catch (const std::exception& e) {
        std::cerr << "Fatal error occurred " << e.what() << std::endl;
        return 1;
    }
    return 0;
}