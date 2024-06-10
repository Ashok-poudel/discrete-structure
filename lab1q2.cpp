#include <iostream>
#include <set>
#include <vector>
#include <utility>

void printCartesianProduct(const std::vector<std::pair<int, int>>& cartesianProduct) {
    for (const auto& pair : cartesianProduct) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;
}

std::vector<std::pair<int, int>> cartesianProduct(const std::set<int>& set1, const std::set<int>& set2) {
    std::vector<std::pair<int, int>> product;
    for (const auto& elem1 : set1) {
        for (const auto& elem2 : set2) {
            product.emplace_back(elem1, elem2);
        }
    }
    return product;
}

int main() {
    std::set<int> set1, set2;
    int n1, n2, elem;

    std::cout << "Enter number of elements in set 1: ";
    std::cin >> n1;
    std::cout << "Enter elements of set 1: ";
    for (int i = 0; i < n1; ++i) {
        std::cin >> elem;
        set1.insert(elem);
    }

    std::cout << "Enter number of elements in set 2: ";
    std::cin >> n2;
    std::cout << "Enter elements of set 2: ";
    for (int i = 0; i < n2; ++i) {
        std::cin >> elem;
        set2.insert(elem);
    }

    std::vector<std::pair<int, int>> product = cartesianProduct(set1, set2);

    std::cout << "Cartesian Product: ";
    printCartesianProduct(product);

    return 0;
}

