#include <iostream>
#include <string>

// Component interface
class Beverage {
public:
	virtual ~Beverage() {}
	virtual std::string getDescription() const = 0;
	virtual double      cost() const           = 0;
};

// Concrete component
class Espresso : public Beverage {
public:
	std::string getDescription() const {
		return "Espresso";
	}
	double cost() const override {
		return 1.99;
	}
};

// Decorator abstract class
class CondimentDecorator : public Beverage {
public:
	CondimentDecorator(Beverage* beverage) : beverage_(beverage) {}
	std::string getDescription() const override {
		return beverage_->getDescription();
	}
	double cost() const override {
		return beverage_->cost();
	}

protected:
	Beverage* beverage_;
};

// Concrete decorator classes
class Milk : public CondimentDecorator {
public:
	Milk(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() const override {
		return beverage_->getDescription() + ", Milk";
	}
	double cost() const override {
		return beverage_->cost() + 0.10;
	}
};

class Mocha : public CondimentDecorator {
public:
	Mocha(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() const override {
		return beverage_->getDescription() + ", Mocha";
	}
	double cost() const override {
		return beverage_->cost() + 0.20;
	}
};

int main() {
	// Create a beverage without condiments
	Beverage* beverage1 = new Espresso();
	std::cout << beverage1->getDescription() << " $" << beverage1->cost() << std::endl;

	// Add milk to the beverage
	Beverage* beverage2 = new Milk(new Espresso());
	std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;

	// Add milk and mocha to the beverage
	Beverage* beverage3 = new Mocha(new Milk(new Espresso()));
	std::cout << beverage3->getDescription() << " $" << beverage3->cost() << std::endl;

	// Clean up dynamic memory
	delete beverage1;
	delete beverage2;
	delete beverage3;

	return 0;
}
