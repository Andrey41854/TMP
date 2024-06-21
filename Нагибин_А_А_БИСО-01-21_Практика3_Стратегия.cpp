#include <iostream>

class IStrategy
{
public:
	virtual void execute() = 0;
	virtual ~IStrategy() {}
};

class Strategyl : public IStrategy
{
public:
	void execute() override 
	{
		std::cout << "Implementation of strategy 1" << std::endl;
	}
};

class Strategy2 : public IStrategy
{
public:
	void execute() override 
	{
		std::cout << "Implementation of strategy 2" << std::endl;
	}
};

class Context
{
private:
	IStrategy* strategy;

public:
	Context(IStrategy* strategy) : strategy(strategy) {}

	void setStrategy(IStrategy* newStrategy) { strategy = newStrategy; }

	void executeStrategy() { strategy->execute(); }
};

int main()
{
		Strategyl strategy1; Strategy2 strategy2;
		Context context(&strategy1);
		context.executeStrategy();
		context.setStrategy(&strategy2);
		context.executeStrategy();
		return 0;
}