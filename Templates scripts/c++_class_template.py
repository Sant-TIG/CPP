def	generate_zombie_hpp(class_name):
	hpp_content = f'''
#ifndef {class_name.upper()}_H

# define {class_name.upper()}_H

# include "Colors.hpp"

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
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
{class_name}::{class_name}( void ) {{
	std::cout << GREEN << "{class_name} default constructor called" << RESET << std::endl;
}}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
{class_name}::{class_name}(  ) {{
	std::cout << GREEN << "{class_name} parameterized constructor called" << RESET << std::endl;
}}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
{class_name}::{class_name}( const {class_name} &one{class_name} ) {{
	*this = one{class_name};
	std::cout << GREEN << "{class_name} copy constructor called" << RESET << std::endl;
}}

/*
 * Overloading of the assignment operator.
 */
{class_name} & {class_name}::operator=( const {class_name} &one{class_name} ) {{
	if (this != &one{class_name}) {{

	}}
	return *this;
}}

/*
 * Destructor.
 */
{class_name}::~{class_name}( void ) {{
	std::cout << RED << "{class_name} destructor called" << RESET << std::endl;
}}

/*
 * GETTER METHODS
 */


/*
 * SETTER METHODS
 */

'''

	with open(f"{class_name}.cpp", "w") as cpp_file:
		cpp_file.write(cpp_content)

if __name__=="__main__":
	num_classes = int(input("Enter the number of classes to create: "))
	for i in range(num_classes):
		class_name = input("Enter the class name: ")
		generate_zombie_hpp(class_name)
		generate_zombie_cpp(class_name)