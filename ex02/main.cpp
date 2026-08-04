#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	// Animal a;              // error: cannot declare variable of abstract type 'Animal'
	// const Animal* a = new Animal(); // error: invalid new-expression of abstract class type 'Animal'

	std::cout << "===== Polymorphism through abstract Animal* =====" << std::endl;
	{
		const Animal* d = new Dog();
		const Animal* c = new Cat();
		std::cout << "d->getType():   " << d->getType() << std::endl;
		std::cout << "d->makeSound(): "; d->makeSound();
		std::cout << "c->getType():   " << c->getType() << std::endl;
		std::cout << "c->makeSound(): "; c->makeSound();
		delete d;
		delete c;
	}

	std::cout << "\n===== Array of abstract Animals =====" << std::endl;
	{
		const int N = 4;
		Animal* animals[N];
		for (int k = 0; k < N / 2; k++)
			animals[k] = new Dog();
		for (int k = N / 2; k < N; k++)
			animals[k] = new Cat();
		for (int k = 0; k < N; k++)
			delete animals[k];
	}

	std::cout << "\n===== WrongAnimal: no virtual dispatch =====" << std::endl;
	{
		WrongAnimal* w = new WrongCat();
		std::cout << "w->getType():   " << w->getType() << std::endl;
		std::cout << "w->makeSound(): "; w->makeSound();
		delete w;
	}

	std::cout << "\n===== Deep copy verification (Dog Brain) =====" << std::endl;
	{
		Dog original;
		original.setIdea(0, "Chase the cat");
		std::cout << "original idea[0]: " << original.getIdea(0) << std::endl;

		Dog copy = original; // copy ctor -> deep copy of Brain
		std::cout << "copy idea[0]:    " << copy.getIdea(0) << std::endl;

		original.setIdea(0, "Eat the bone");
		std::cout << "after changing original->idea[0] to 'Eat the bone'..." << std::endl;
		std::cout << "original idea[0]: " << original.getIdea(0) << std::endl;
		std::cout << "copy idea[0]:    " << copy.getIdea(0) << std::endl;

		std::cout << "\n--- assignment deep copy test ---" << std::endl;
		Dog assigned;
		assigned = original;
		std::cout << "assigned idea[0]: " << assigned.getIdea(0) << std::endl;
		original.setIdea(0, "Sleep");
		std::cout << "after changing original->idea[0] to 'Sleep'..." << std::endl;
		std::cout << "original idea[0]:  " << original.getIdea(0) << std::endl;
		std::cout << "assigned idea[0]:  " << assigned.getIdea(0) << std::endl;
	}

	return 0;
}
