#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <stdexcept> // Include for std::exception
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

    // Optional: Custom exception for unknown form type
    class UnknownFormException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif 