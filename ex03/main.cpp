#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib> // For srand
#include <ctime>   // For time

int main() {
    // Seed random number generator once in main
    srand(time(0));

    Intern someRandomIntern;
    AForm* formPtr;

    std::cout << "--- Testing Intern Form Creation --- " << std::endl;

    // Test creating a valid form: Robotomy Request
    std::cout << "\nAttempting to create 'robotomy request' for 'Bender':" << std::endl;
    formPtr = someRandomIntern.makeForm("robotomy request", "Bender");
    if (formPtr) {
        std::cout << "Successfully created form: " << *formPtr << std::endl;
        // Example of using the created form
        try {
            Bureaucrat high("HighExec", 40);
            high.signForm(*formPtr);
            high.executeForm(*formPtr);
        } catch (const std::exception& e) {
            std::cerr << "Exception using created form: " << e.what() << std::endl;
        }
        delete formPtr; // Clean up allocated memory
    } else {
        std::cerr << "Failed to create 'robotomy request' form." << std::endl;
    }

    // Test creating another valid form: Presidential Pardon
    std::cout << "\nAttempting to create 'presidential pardon' for 'Marvin':" << std::endl;
    formPtr = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (formPtr) {
        std::cout << "Successfully created form: " << *formPtr << std::endl;
        delete formPtr;
    } else {
        std::cerr << "Failed to create 'presidential pardon' form." << std::endl;
    }

    // Test creating a third valid form: Shrubbery Creation
    std::cout << "\nAttempting to create 'shrubbery creation' for 'garden':" << std::endl;
    formPtr = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (formPtr) {
        std::cout << "Successfully created form: " << *formPtr << std::endl;
        delete formPtr;
    } else {
        std::cerr << "Failed to create 'shrubbery creation' form." << std::endl;
    }

    // Test creating an invalid form
    std::cout << "\nAttempting to create 'invalid form type' for 'target':" << std::endl;
    formPtr = someRandomIntern.makeForm("invalid form type", "target");
    if (formPtr) {
        std::cerr << "Error: Should not have created an invalid form!" << std::endl;
        delete formPtr;
    } else {
        std::cout << "Correctly failed to create 'invalid form type'." << std::endl;
    }

    std::cout << "\n--- All Intern tests complete --- " << std::endl;

    return 0;
} 