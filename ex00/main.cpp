#include "Bureaucrat.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        Bureaucrat b3("Charlie", 75);
        std::cout << b3 << std::endl;

        Bureaucrat b4 = b3;
        std::cout << "Copy of Charlie: " << b4 << std::endl;
        Bureaucrat b5;
        b5 = b1;
        std::cout << "Assigned Alice: " << b5 << std::endl;

        std::cout << "\nTesting grade changes for Charlie:" << std::endl;
        std::cout << b3 << std::endl;
        b3.incrementGrade();
        std::cout << "After increment: " << b3 << std::endl;
        b3.decrementGrade();
        std::cout << "After decrement: " << b3 << std::endl;

        std::cout << "\nTesting boundary conditions:" << std::endl;
        try {
            std::cout << b1 << std::endl;
            b1.incrementGrade();
            std::cout << "This should not be printed." << std::endl;
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "Caught expected exception: " << e.what() << std::endl;
        }

        try {
            std::cout << b2 << std::endl;
            b2.decrementGrade();
             std::cout << "This should not be printed." << std::endl;
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "Caught expected exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception during valid tests: " << e.what() << std::endl;
    }

    std::cout << "\nTesting invalid grade exceptions during construction:" << std::endl;
    try {
        Bureaucrat invalidHigh("Invalid High", 0);
        std::cout << "This should not be printed." << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidLow("Invalid Low", 151);
         std::cout << "This should not be printed." << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
} 