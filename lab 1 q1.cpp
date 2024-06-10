#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

void printSet(const std::set<int>& s) {
    for (const int& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
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

    // Union
    std::set<int> unionSet;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(unionSet, unionSet.begin()));
    std::cout << "Union: ";
    printSet(unionSet);

    // Intersection
    std::set<int> intersectionSet;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(intersectionSet, intersectionSet.begin()));
    std::cout << "Intersection: ";
    print

