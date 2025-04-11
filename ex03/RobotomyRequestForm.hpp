#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <cstdlib> // For rand() and srand()
# include <ctime>   // For time()

class RobotomyRequestForm : public AForm {

private:
    const std::string _target;
    RobotomyRequestForm(); // Default constructor private

public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

    std::string getTarget() const;

    virtual void execute(Bureaucrat const & executor) const; // Override

};

#endif 