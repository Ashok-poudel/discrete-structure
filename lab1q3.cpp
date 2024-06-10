#include <iostream>
#include <cmath>

int main() {
    double num;

    std::cout << "Enter a real number: ";
    std::cin >> num;

    int floorValue = std::floor(num);
    int ceilValue = std::ceil(num);

    std::cout << "Floor: " << floorValue << std::endl;
    std::cout << "Ceiling: " << ceilValue << std::endl;

    return 0;
}

