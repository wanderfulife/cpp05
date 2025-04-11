#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing Valid Form Creation --- " << std::endl;
    try {
        Form f1("Tax Form", 50, 25);
        std::cout << f1 << std::endl;
        Form f2("Leave Request", 100, 75);
        std::cout << f2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception during valid form creation: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Invalid Form Creation --- " << std::endl;
    try {
        Form invalidHigh("Invalid High Sign", 0, 50);
        std::cout << "This should not be printed." << std::endl;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    try {
        Form invalidLow("Invalid Low Exec", 100, 151);
        std::cout << "This should not be printed." << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Bureaucrat Signing Forms --- " << std::endl;
    try {
        Bureaucrat signer("Signer", 40);
        Bureaucrat tooLow("TooLow", 60);
        Form f1("Tax Form", 50, 25);

        std::cout << signer << std::endl;
        std::cout << tooLow << std::endl;
        std::cout << f1 << std::endl;

        std::cout << "\nTooLow attempts to sign f1:" << std::endl;
        tooLow.signForm(f1);
        std::cout << f1 << std::endl;

        std::cout << "\nSigner attempts to sign f1:" << std::endl;
        signer.signForm(f1);
        std::cout << f1 << std::endl;

        std::cout << "\nSigner attempts to sign f1 again (already signed):" << std::endl;
        signer.signForm(f1);
        std::cout << f1 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception during signing tests: " << e.what() << std::endl;
    }

     std::cout << "\n--- Testing Bureaucrat::signForm directly calling beSigned exceptions ---" << std::endl;
    try {
        Bureaucrat b("Tester", 100);
        Form f("TestForm", 50, 50);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (const std::exception& e) {
         std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
} 