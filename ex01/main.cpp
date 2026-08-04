#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(){
	std::cout << "===== Subject leak test =====" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // must not leak the Brain
	delete i;

	std::cout << "\n===== Array of Animals =====" << std::endl;
	const int N = 4;
	Animal* animals[N];
	for (int k = 0; k < N / 2; k++)
		animals[k] = new Dog();
	for (int k = N / 2; k < N; k++)
		animals[k] = new Cat();
	for (int k = 0; k < N; k++)
		delete animals[k];

	std::cout << "\n===== Deep copy verification (Dog) =====" << std::endl;
	Dog original;
	original.setIdea(0, "Chase the cat");
	std::cout << "original idea[0]: " << original.getIdea(0) << std::endl;

	Dog copy = original; 
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

	return 0;
}
