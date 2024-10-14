#include "Serializer.hpp"

#include <iostream>

int main()
{
	Data	*ptr = new Data;

	ptr->i = 42;
	ptr->len = 2;
	ptr->c = 'c';
	
	std::cout << "ptr: " << ptr << " ptr->i: " << ptr->i << " ptr->len: " << ptr->len << " ptr->c: " << ptr->c << std::endl;
	uintptr_t	i = Serializer::serialize(ptr);
	std::cout << "i: " << i << std::endl;
	Data	*d = Serializer::deserialize(i);
	std::cout << "d: " << d << " d->i: " << d->i << " d->len: " << d->len << std::endl;
	
	return 0;
}