#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) :
    _name(other._name),
    _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // name, gradeToSign, gradeToExecute are const
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return this->_name;
}

bool AForm::isSigned() const {
    return this->_isSigned;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    this->_isSigned = true;
}

// Base class execute checks preconditions before calling derived executeAction
void AForm::execute(Bureaucrat const & executor) const {
    if (!this->_isSigned) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->_gradeToExecute) {
        throw AForm::GradeTooLowException();
    }
    // No need to call a derived executeAction if we implement it in the concrete class
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName() << ", Signed: " << (f.isSigned() ? "Yes" : "No")
       << ", Grade to sign: " << f.getGradeToSign()
       << ", Grade to execute: " << f.getGradeToExecute() << ".";
    return os;
} 