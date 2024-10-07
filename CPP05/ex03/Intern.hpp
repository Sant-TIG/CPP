/**
 * @file Intern.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Definition of the Inern class.
 * @date 2024-07-29
 * 
 * @details The Intern class is responsible for creating different types of forms
 * based on the given name and target. It has no unique characteristics and
 * serves solely to fulfill form creation requests.
 */

#ifndef INTERN_HPP

# define INTERN_HPP

# include "../incs/Colors.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>
# include <string>

class Intern {
    public:
		Intern( void );
        Intern( const Intern &otherIntern );
		~Intern( void );

		Intern & operator=( const Intern &otherIntern );

        AForm    *makeForm( const std::string &name, const std::string &target );

    private:
        std::string transformCase( const std::string &str, const std::string &type );
};

#endif