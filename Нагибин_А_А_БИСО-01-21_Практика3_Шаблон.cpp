#include <iostream>

class AbstractClass
{
public:
	void templateMethod()
	{
		step1();
		step2();
		step3();
	}

protected:
	virtual void step1() = 0;
	virtual void step2() = 0;
	virtual void step3() = 0;
};

class TemplateMethodClass : public AbstractClass 
{
protected:
	void step1() override { std::cout << "Step 1 is completed" << std::endl; }
	void step2() override { std::cout << "Step 2 is completed" << std::endl; }
	void step3() override { std::cout << "Step 3 is completed" << std::endl; }
};

int main()
{
	TemplateMethodClass templateMethod;
	templateMethod.templateMethod();
	return 0;
}
