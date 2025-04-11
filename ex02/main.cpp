#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    try {
        Bureaucrat highGrade("Alice", 1);
        Bureaucrat midGrade("Bob", 50);
        Bureaucrat lowGrade("Charlie", 140);
        std::cout << highGrade << std::endl;
        std::cout << midGrade << std::endl;
        std::cout << lowGrade << std::endl << std::endl;

        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("Ford Prefect");

        std::cout << shrubForm << std::endl;
        std::cout << robotForm << std::endl;
        std::cout << pardonForm << std::endl << std::endl;

        std::cout << "--- Shrubbery Tests --- " << std::endl;
        lowGrade.signForm(shrubForm);
        midGrade.executeForm(shrubForm);
        lowGrade.executeForm(shrubForm);
        highGrade.executeForm(shrubForm);
        std::cout << std::endl;

        std::cout << "--- Robotomy Tests --- " << std::endl;
        midGrade.signForm(robotForm);
        lowGrade.executeForm(robotForm);
        midGrade.executeForm(robotForm);
        midGrade.executeForm(robotForm);
        highGrade.executeForm(robotForm);
        std::cout << std::endl;

        std::cout << "--- Pardon Tests --- " << std::endl;
        highGrade.signForm(pardonForm);
        midGrade.executeForm(pardonForm);
        highGrade.executeForm(pardonForm);
        std::cout << std::endl;

        std::cout << "--- Unsigned Execution Test --- " << std::endl;
        RobotomyRequestForm unsignedRobotForm("Marvin");
        std::cout << unsignedRobotForm << std::endl;
        highGrade.executeForm(unsignedRobotForm);
        std::cout << std::endl;

        std::cout << "--- Low Grade Signing Test --- " << std::endl;
        Bureaucrat veryLow("Daphne", 150);
        ShrubberyCreationForm shrubTest2("garden");
        std::cout << veryLow << std::endl;
        std::cout << shrubTest2 << std::endl;
        veryLow.signForm(shrubTest2);
        veryLow.executeForm(shrubTest2); 

    } catch (const std::exception& e) {
        std::cerr << "\n*** Caught unexpected exception in main: " << e.what() << " ***" << std::endl;
        return 1;
    }

    return 0;
} 