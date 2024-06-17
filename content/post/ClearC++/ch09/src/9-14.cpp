#include <iostream>

namespace en {
    int x = 1;
    void print() {
        std::cout << "en: " << x << std::endl;
    }
}

namespace zh {
    int x = 3;
    void print() {
        std::cout << "zh: " << x << std::endl;
    }
}

namespace jp {
    extern int x;
    void print();
}

int jp::x = 4;
void jp::print() {
    std::cout << "jp: " << x << std::endl;
}

int main() {
    en::print();
    zh::print();
}