#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // _name is const, cannot be reassigned.
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << "." << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->_name << " couldn't sign " << f.getName() << " because of an unknown reason: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << "." << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because grade is too low: " << e.what() << std::endl;
    } catch (const AForm::FormNotSignedException& e) {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because the form is not signed: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because of an error: " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
} 