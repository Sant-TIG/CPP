def	generate_zombie_hpp(class_name):
	hpp_content = f'''
#ifndef {class_name.upper()}_HPP

# define {class_name.upper()}_HPP

# include "Colors.hpp"

# include <iostream>

class {class_name} {{
	private:

	public:
		{class_name}( void );
		{class_name}( const {class_name} &one{class_name} );
		{class_name} & operator=( const {class_name} &one{class_name} );
		~{class_name}( void );
}};

#endif
'''
	with open(f"{class_name}.hpp", "w") as hpp_file:
		hpp_file.write(hpp_content)

def generate_zombie_cpp(class_name):
	cpp_content = f'''
#include "{class_name}.hpp"


/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new {class_name} object with default values.
 */
{class_name}::{class_name}( void ) {{
	std::cout << GREEN << "{class_name} default constructor called" << RESET << std::endl;
}}

/**
 * @brief Construct a new {class_name} object with the values passed as parameters.
 *
 * @param 
 */
{class_name}::{class_name}(  ) {{
	std::cout << GREEN << "{class_name} parameterized constructor called" << RESET << std::endl;
}}

/**
 * @brief Construct a new {class_name} object by copying the values from another object.
 *
 * @param one{class_name} A reference to the {class_name} object to be copied.
 */
{class_name}::{class_name}( const {class_name} &one{class_name} ) {{
	*this = one{class_name};
	std::cout << GREEN << "{class_name} copy constructor called" << RESET << std::endl;
}}

/**
 * @brief Destroy the {class_name} object.
 */
{class_name}::~{class_name}( void ) {{
	std::cout << RED << "{class_name} destructor called" << RESET << std::endl;
}}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloads the assignment operator for the {class_name} class.
 *
 * @param one{class_name} The source {class_name} object to assign from.
 * @return {class_name}& A reference to the current {class_name} object after assignment.
 */
{class_name} & {class_name}::operator=( const {class_name} &one{class_name} ) {{
	if (this != &one{class_name}) {{

	}}
	return *this;
}}


/* ------------ GETTER METHODS ------------ */


/* ------------ SETTER METHODS ------------ */


'''

	with open(f"{class_name}.cpp", "w") as cpp_file:
		cpp_file.write(cpp_content)

if __name__=="__main__":
	num_classes = int(input("Enter the number of classes to create: "))
	for i in range(num_classes):
		class_name = input("Enter the class name: ")
		generate_zombie_hpp(class_name)
		generate_zombie_cpp(class_name)