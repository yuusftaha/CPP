NAME = Aform

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = AForm.cpp Bureaucrat.cpp main.cpp  PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean clean all

.PHONY: all clean fclean re