NAME = internFucks

# Source files
SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp \
       Intern.cpp

OBJS = $(SRCS:.cpp=.o)

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

# Header files (for dependency tracking)
HDRS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Update dependency rules for new files and dependencies
main.o: main.cpp Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Bureaucrat.o: Bureaucrat.cpp Bureaucrat.hpp AForm.hpp
	$(CXX) $(CXXFLAGS) -c Bureaucrat.cpp -o Bureaucrat.o

AForm.o: AForm.cpp AForm.hpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c AForm.cpp -o AForm.o

ShrubberyCreationForm.o: ShrubberyCreationForm.cpp ShrubberyCreationForm.hpp AForm.hpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c ShrubberyCreationForm.cpp -o ShrubberyCreationForm.o

RobotomyRequestForm.o: RobotomyRequestForm.cpp RobotomyRequestForm.hpp AForm.hpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c RobotomyRequestForm.cpp -o RobotomyRequestForm.o

PresidentialPardonForm.o: PresidentialPardonForm.cpp PresidentialPardonForm.hpp AForm.hpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c PresidentialPardonForm.cpp -o PresidentialPardonForm.o

Intern.o: Intern.cpp Intern.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
	$(CXX) $(CXXFLAGS) -c Intern.cpp -o Intern.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re 