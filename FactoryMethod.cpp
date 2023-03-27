#include <iostream>
#include <string>
#include <vector>

// Base class for products
class Product {
public:
	virtual ~Product() {}
	virtual void use() = 0;
};

// Concrete product 1
class Product1 : public Product {
public:
	void use() override {
		std::cout << "Using product 1" << std::endl;
	}
};

// Concrete product 2
class Product2 : public Product {
public:
	void use() override {
		std::cout << "Using product 2" << std::endl;
	}
};

// Factory interface
class Factory {
public:
	virtual ~Factory() {}
	virtual Product* createProduct() = 0;
};

// Concrete factory 1
class Factory1 : public Factory {
public:
	Product* createProduct() override {
		return new Product1();
	}
};

// Concrete factory 2
class Factory2 : public Factory {
public:
	Product* createProduct() override {
		return new Product2();
	}
};

int main() {
	std::vector<Factory*> factories = {new Factory1(), new Factory2()};

	// Use products created by different factories
	for(auto factory : factories) {
		Product* product = factory->createProduct();
		product->use();
		delete product;
	}

	// Clean up
	for(auto factory : factories) {
		delete factory;
	}

	return 0;
}
