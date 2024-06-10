#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Person {
    std::string name;
    int age;
    double membershipA;
    double membershipB;
};

double calculateMembershipA(int age) {
    if (age <= 20) {
        return 1.0;
    } else if (age > 20 && age <= 30) {
        return (30.0 - age) / 10.0;
    } else {
        return 0.0;
    }
}

double calculateMembershipB(int age) {
    if (age <= 15) {
        return 1.0;
    } else if (age > 15 && age <= 35) {
        return (35.0 - age) / 20.0;
    } else {
        return 0.0;
    }
}

void printMembership(const std::vector<Person>& persons) {
    for (const auto& person : persons) {
        std::cout << "Name: " << person.name << ", Age: " << person.age
                  << ", Membership A: " << person.membershipA
                  << ", Membership B: " << person.membershipB << std::endl;
    }
}

void fuzzyUnion(const std::vector<Person>& persons) {
    std::cout << "\nFuzzy Union:\n";
    for (const auto& person : persons) {
        double unionMembership = std::max(person.membershipA, person.membershipB);
        std::cout << "Name: " << person.name << ", Union Membership: " << unionMembership << std::endl;
    }
}

void fuzzyIntersection(const std::vector<Person>& persons) {
    std::cout << "\nFuzzy Intersection:\n";
    for (const auto& person : persons) {
        double intersectionMembership = std::min(person.membershipA, person.membershipB);
        std::cout << "Name: " << person.name << ", Intersection Membership: " << intersectionMembership << std::endl;
    }
}

void fuzzyComplement(const std::vector<Person>& persons) {
    std::cout << "\nFuzzy Complement (A):\n";
    for (const auto& person : persons) {
        double complementMembershipA = 1.0 - person.membershipA;
        std::cout << "Name: " << person.name << ", Complement Membership A: " << complementMembershipA << std::endl;
    }
    std::cout << "\nFuzzy Complement (B):\n";
    for (const auto& person : persons) {
        double complementMembershipB = 1.0 - person.membershipB;
        std::cout << "Name: " << person.name << ", Complement Membership B: " << complementMembershipB << std::endl;
    }
}

int main() {
    std::vector<Person> persons(5);

    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter name of person " << i + 1 << ": ";
        std::cin >> persons[i].name;
        std::cout << "Enter age of person " << i + 1 << ": ";
        std::cin >> persons[i].age;
        persons[i].membershipA = calculateMembershipA(persons[i].age);
        persons[i].membershipB = calculateMembershipB(persons[i].age);
    }

    std::cout << "\nMemberships:\n";
    printMembership(persons);

    fuzzyUnion(persons);
    fuzzyIntersection(persons);
    fuzzyComplement(persons);

    return 0;
}

