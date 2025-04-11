#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

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
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[])(const std::string&) = {
        &createShrubberyForm,
        &createRobotomyForm,
        &createPardonForm
    };

    AForm* newForm = NULL;
    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            newForm = formCreators[i](target);
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return newForm;
        }
    }

    std::cerr << "Error: Intern cannot create form named \"" << formName << "\". Unknown form type." << std::endl;
    return NULL;
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Unknown form type requested!";
} 