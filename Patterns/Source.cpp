#include <iostream>
#include <ctime>

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

class Grand {
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	virtual void Speak() const { std::cout << "GRAND CLASS" << std::endl; }
	virtual int Value() const { return hold; }
};

class Superb : public Grand {
public:
	Superb(int h = 0) : Grand(h) {}
	void Speak()const { std::cout << "SUPERB CLASS" << std::endl; }
	virtual void Say() const { std::cout << "I HOLD SUPERB VALUE: " << Value() << std::endl; }
};

class Magnificient : public Superb {
	char ch;
public:
	Magnificient(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	void Speak()const { std::cout << "MAGNIFICIENT CLASS" << std::endl; }
	void Say() const {
		std::cout << "I HOLD MAGNIFICIENT VALUE:" << Value() << std::endl
			<< "AND CHARACTER:" << ch << std::endl;
	}
};

Grand* GetOneFactory() {
	Grand* ptr = nullptr;
	switch (std::rand() % 3) {
	case 0:ptr = new Grand(std::rand() % 100);
		break;
	case 1:ptr = new Superb(std::rand() % 100);
		break;
	case 2:ptr = new Magnificient(std::rand() % 100, 'A' + std::rand() % 26);
		break;
	}
	return ptr;
}

int main() {
	std::srand(std::time(0));
	Grand* pg;
	Superb* ps;
	for (size_t i = 0; i < 5; ++i) {
		pg = GetOneFactory();
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
			ps->Say();
	}
	//Mammal* ptr;
	//const size_t MAX=10;
	//int countMammals[3]{0,0,0};
	//for (size_t i = 0; i < MAX; ++i) {
	//	ptr = factory();
	//	std::cout << "OBJECT TYPE: " << typeid(*ptr).name()<<std::endl;
	//	if (typeid(*ptr) == typeid(Cat))++countMammals[0];
	//	if (typeid(*ptr) == typeid(Platypus))++countMammals[1];
	//	if (typeid(*ptr) == typeid(Dog))++countMammals[2];
	//}
	//std::cout << "COUNTS:" << std::endl << "CATS: " << countMammals[0] << std::endl
	//	<< "PLATYPUS: " << countMammals[1] << std::endl
	//	<< "DOGS: " << countMammals[2] << std::endl;
	return 0;
}