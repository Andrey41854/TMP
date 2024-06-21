#include <iostream>
#include <string>
#include <vector>

class Mediator;

class Colleague
{
public:
	virtual ~Colleague() {}
	virtual void receiveMessage(const std::string &message) = 0;
	virtual void sendMessage(const std::string &message) const = 0;
	virtual void setMediator(Mediator* mediator) { mediator_ = mediator; }

protected:
	Mediator* mediator_;
};

class Mediator
{
public:
	virtual ~Mediator() {}
	virtual void sendMessage(const std::string &message, Colleague* colleague) const = 0;
};

class SomeColleague : public Colleague
{
public:
	SomeColleague(const std::string& name) : name_(name) {}

	void receiveMessage(const std::string &message) override { std::cout << name_ << " received: " << message << std::endl; }
	void sendMessage(const std::string &message) const override { mediator_->sendMessage(message, const_cast<SomeColleague *>(this)); }

private:
	std::string name_;
};

class SomeMediator : public Mediator 
{
public:
	void addColleague(Colleague* colleague)
	{
		colleagues_.push_back(colleague);
		colleague->setMediator(this);
	}
	void sendMessage(const std::string &message, Colleague* colleague) 
	const override
	{
		for (auto col : colleagues_)
		{
			if (col != colleague)
			{
				col->receiveMessage(message);
			}
		}
	}
private:
	std::vector<Colleague *> colleagues_;
};

int main()
{
	SomeMediator mediator;
	SomeColleague colleaguel("Kolega 1");
	SomeColleague colleague2("Kolega 2");
	mediator.addColleague(&colleaguel);
	mediator.addColleague(&colleague2);
	colleaguel.sendMessage("Greetings from the College 1");
	colleague2.sendMessage("Greetings from the College 2");
	return 0;
}