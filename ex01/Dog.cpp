#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other){
	std::cout << "Dog copy constructor called." << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other){
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &other){
		Animal::operator=(other);
		Brain* tmp = new Brain(*other.brain);
		delete this->brain;
		this->brain = tmp;
	}
	return *this;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Wau Wau" << std::endl;
}

std::string Dog::getIdea(int index) const{
	return this->brain->getIdea(index);
}

void Dog::setIdea(int index, const std::string& idea){
	this->brain->setIdea(index, idea);
}