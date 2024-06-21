#include <iostream>

class AbstractProductA
{
public:
	virtual void methodA() = 0;
};

class ProductA1 : public AbstractProductA
{
public: void methodA() override { std::cout << "Product A1 Method A" << std::endl; }
};

class ProductA2 : public AbstractProductA
{
public: void methodA() override { std::cout << "Product A2 Method A" << std::endl; }
};

class AbstractProductB 
{
public:
	virtual void methodB() = 0;
};

class ProductB1 : public AbstractProductB 
{
public:
	void methodB() override { std::cout << "Product B1 method B" << std::endl; }
};
	
class ProductB2 : public AbstractProductB
{
public:
	void methodB() override { std::cout << "Product B2 method B" << std::endl; }
};

class AbstractFactory
{
public:
	virtual AbstractProductA *createProductA() = 0;
	virtual AbstractProductB *createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
	AbstractProductA* createProductA() override { return new ProductA1(); }
	AbstractProductB* createProductB() override { return new ProductB1(); }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
	AbstractProductA* createProductA() override { return new ProductA2(); }
	AbstractProductB* createProductB() override { return new ProductB2(); }
};

int main()
{
	AbstractFactory *factory1 = new ConcreteFactory1();
	AbstractProductA *productA1 = factory1->createProductA(); 
	AbstractProductB* productB1 = factory1->createProductB();
	productA1->methodA(); 
	productB1->methodB();
	AbstractFactory *factory2 = new ConcreteFactory2(); 
	AbstractProductA *productA2 = factory2->createProductA(); 
	AbstractProductB *productB2 = factory2->createProductB();
	productA2->methodA();
	productB2->methodB();

	return 0;
}