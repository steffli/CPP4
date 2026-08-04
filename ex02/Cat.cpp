#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){
	std::cout << "Cat copy constructor called." << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other){
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &other){
		Animal::operator=(other);
		Brain* tmp = new Brain(*other.brain);
		delete this->brain;
		this->brain = tmp;
	}
	return *this;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Meow Meow" << std::endl;
}

std::string Cat::getIdea(int index) const{
	return this->brain->getIdea(index);
}

void Cat::setIdea(int index, const std::string& idea){
	this->brain->setIdea(index, idea);
}