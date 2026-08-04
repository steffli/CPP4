#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	//Tests from the subject
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "----- WrongAnimal tests -----" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();
	std::cout << wrongI->getType() << " " << std::endl;
	wrongI->makeSound(); //will output the WrongAnimal sound!
	wrongMeta->makeSound();
	delete wrongMeta;
	delete wrongI;

	std::cout << "----- Extra tests -----" << std::endl;
	const WrongCat* wrongCat = new WrongCat();
	wrongCat->makeSound(); //direct WrongCat object still meows
	delete wrongCat;

	Dog dog;
	Dog dogCopy(dog);
	Cat cat;
	cat = cat;
	std::cout << dogCopy.getType() << " " << std::endl;
	dogCopy.makeSound();
	return 0;
}
