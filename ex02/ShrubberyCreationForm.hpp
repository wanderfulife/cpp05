#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>
# include <fstream> // For file operations

class ShrubberyCreationForm : public AForm {

private:
    const std::string _target;
    ShrubberyCreationForm(); // Default constructor private

public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    std::string getTarget() const;

    virtual void execute(Bureaucrat const & executor) const; // Override

};

#endif 