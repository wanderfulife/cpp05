#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other), _target(other._target) {}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);

    std::string filename = this->_target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }

    outfile << "       _-_         _-_         _-_\n"
               "    /~~   ~~\\     /~~   ~~\\     /~~   ~~\\ \n"
               " /~~         ~~\\ /~~         ~~\\ /~~         ~~\\ \n"
               "{               }{               }{               }\n"
               " \\  _-     -_  / \\  _-     -_  / \\  _-     -_  / \n"
               "   ~  \\\\ //  ~    ~  \\\\ //  ~    ~  \\\\ //  ~ \n"
               "_- -   | | _- _ -   | | _- _ -   | | _- _\n"
               "  _ -  | |   _   _ -  | |   _   _ -  | |   _\n"
               "      // \\\\         // \\\\         // \\\\ \n";

    outfile.close();
} 