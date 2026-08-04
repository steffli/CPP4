#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"


class Dog : public Animal{
	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Animal& other);
		Dog& operator=(const Animal& other);
		virtual ~Dog();
};
#endif
