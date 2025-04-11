#include "RobotomyRequestForm.hpp"
#include <iostream>

// Initialize random seed once
// Note: Placing this in a .cpp might lead to multiple seeds if included elsewhere.
// A better approach involves a static initializer class or ensuring main calls srand.
// For this exercise, placing it here is acceptable but not ideal in larger projects.
// Alternatively, call srand(time(0)); in main.
// static bool seeded = false;

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("Robotomy Request", 72, 45), _target(target) {
    // if (!seeded) {
    //     srand(time(0));
    //     seeded = true;
    // }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        // _target is const
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor); // Check preconditions

    std::cout << "* drilling noises * BZZZZZZZZZZ... VRRRRRRRR... *" << std::endl;

    // Seed random number generator here ensures it's seeded before use in execute
    // Calling srand multiple times is okay, though seeding once is more common.
    srand(time(0));

    if (rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << this->_target << "." << std::endl;
    }
} 