#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other; // No state to copy
}

Intern& Intern::operator=(const Intern& other) {
    (void)other; // No state to copy
    return *this;
}

Intern::~Intern() {}

// Helper functions to create forms (could be static member functions or free functions)
static AForm* createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // Array of form names
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Array of function pointers to create forms
    // Using static helper functions defined above
    AForm* (*formCreators[])(const std::string&) = {
        &createShrubberyForm,
        &createRobotomyForm,
        &createPardonForm
    };

    AForm* newForm = NULL;
    for (int i = 0; i < 3; ++i) { // 3 is the number of known forms
        if (formName == formNames[i]) {
            newForm = formCreators[i](target);
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return newForm;
        }
    }

    // If no match found
    std::cerr << "Error: Intern cannot create form named \"" << formName << "\". Unknown form type." << std::endl;
    // Optional: throw Intern::UnknownFormException();
    return NULL; // Or throw exception as required/preferred
}

// Implementation for the custom exception (optional)
const char* Intern::UnknownFormException::what() const throw() {
    return "Unknown form type requested!";
} 