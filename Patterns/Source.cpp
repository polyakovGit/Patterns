#include <iostream>

//fabric
struct Mammal {
	virtual bool laysEggs() = 0;
};

struct Cat : Mammal {
	bool laysEggs() {
		return false;
	}
};

struct Platypus : Mammal {
	bool laysEggs() {
		return true;
	}
};

struct Dog : Mammal {
	bool laysEggs() {
		return false;
	}
};

Mammal* factory() {
	switch (rand() % 3) {
	case 0:return new Cat;
	case 1:return new Platypus;
	case 2:return new Dog;
	}
	return 0;
}
//fabric end

int main() {
	Mammal* ptr;
	const size_t MAX=10;
	int countMammals[3]{0,0,0};
	for (size_t i = 0; i < MAX; ++i) {
		ptr = factory();
		std::cout << "OBJECT TYPE: " << typeid(*ptr).name()<<std::endl;
		if (typeid(*ptr) == typeid(Cat))++countMammals[0];
		if (typeid(*ptr) == typeid(Platypus))++countMammals[1];
		if (typeid(*ptr) == typeid(Dog))++countMammals[2];
	}
	std::cout << "COUNTS:" << std::endl << "CATS: " << countMammals[0] << std::endl
		<< "PLATYPUS: " << countMammals[1] << std::endl
		<< "DOGS: " << countMammals[2] << std::endl;
	return 0;
}