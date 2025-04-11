#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib> // For srand
#include <ctime>   // For time

int main() {
    // Seed random number generator once in main
    srand(time(0));

    try {
        // Create Bureaucrats
        Bureaucrat highGrade("Alice", 1);
        Bureaucrat midGrade("Bob", 50);
        Bureaucrat lowGrade("Charlie", 140);
        std::cout << highGrade << std::endl;
        std::cout << midGrade << std::endl;
        std::cout << lowGrade << std::endl << std::endl;

        // Create Forms
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("Ford Prefect");

        std::cout << shrubForm << std::endl;
        std::cout << robotForm << std::endl;
        std::cout << pardonForm << std::endl << std::endl;

        // --- Test Shrubbery Creation Form ---
        std::cout << "--- Shrubbery Tests --- " << std::endl;
        lowGrade.signForm(shrubForm); // Low grade signs (should succeed)
        midGrade.executeForm(shrubForm); // Mid grade executes (should fail, grade too low)
        lowGrade.executeForm(shrubForm); // Low grade executes (should succeed)
        highGrade.executeForm(shrubForm); // High grade executes (should succeed)
        std::cout << std::endl;

        // --- Test Robotomy Request Form ---
        std::cout << "--- Robotomy Tests --- " << std::endl;
        midGrade.signForm(robotForm); // Mid grade signs (should succeed)
        lowGrade.executeForm(robotForm); // Low grade executes (should fail, grade too low)
        midGrade.executeForm(robotForm); // Mid grade executes (should succeed, 50% chance)
        midGrade.executeForm(robotForm); // Try again
        highGrade.executeForm(robotForm); // High grade executes (should succeed, 50% chance)
        std::cout << std::endl;

        // --- Test Presidential Pardon Form ---
        std::cout << "--- Pardon Tests --- " << std::endl;
        highGrade.signForm(pardonForm); // High grade signs (should succeed)
        midGrade.executeForm(pardonForm); // Mid grade executes (should fail, grade too low)
        highGrade.executeForm(pardonForm); // High grade executes (should succeed)
        std::cout << std::endl;

        // --- Test Execution without Signing ---
        std::cout << "--- Unsigned Execution Test --- " << std::endl;
        RobotomyRequestForm unsignedRobotForm("Marvin");
        std::cout << unsignedRobotForm << std::endl;
        highGrade.executeForm(unsignedRobotForm); // Should fail (not signed)
        std::cout << std::endl;

         // --- Test Signing with too low grade ---
        std::cout << "--- Low Grade Signing Test --- " << std::endl;
        Bureaucrat veryLow("Daphne", 150);
        ShrubberyCreationForm shrubTest2("garden");
        std::cout << veryLow << std::endl;
        std::cout << shrubTest2 << std::endl;
        veryLow.signForm(shrubTest2); // Should fail signing
        veryLow.executeForm(shrubTest2); // Should fail execution (not signed)

    } catch (const std::exception& e) {
        std::cerr << "\n*** Caught unexpected exception in main: " << e.what() << " ***" << std::endl;
        return 1;
    }

    return 0;
} 