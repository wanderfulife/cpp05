#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other), _target(other._target) {}

// Assignment operator: only copies base class attributes if needed (isSigned)
// target is const and belongs to this specific form type, base name/grades are const.
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other); // Call base class assignment operator
        // _target is const, cannot reassign.
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    // Check conditions first (using base class checks is more elegant)
    AForm::execute(executor); // This checks signed status and executor grade

    // Action: Create file and write ASCII trees
    std::string filename = this->_target + "_shrubbery";
    std::ofstream outfile(filename.c_str()); // Use .c_str() for C++98 compatibility

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return; // Or throw a custom exception
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