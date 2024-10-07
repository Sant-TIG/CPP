#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


void	internJob( const std::string &formName, const std::string &formTarget ) {
	AForm	*form;
	Intern	peter;

	try {
		Bureaucrat	perkins("Perkins Perkinson", 1);
		form = peter.makeForm(formName, formTarget);
		if (form) {
			form->beSigned(perkins);
			form->execute(perkins);
			delete form;
		} else {
			std::cout << YELLOW << "Error: Form " << formName << " not recognized." << RESET << std::endl;
		}
	} catch (std::exception &e){
		std::cout << YELLOW << e.what() << RESET << std::endl;
	}
}

int main(){
	internJob("Robotomy Request", "Anderson");
	internJob("Presidential Pardon", "Peterson");
	internJob("Shrubbery Creation", "Roberson");
	internJob("Invent", "Invent");
	return 0;
}